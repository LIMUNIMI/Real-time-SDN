#include "DSPUtils.h"
#include <Parameters.h>

using namespace Eigen;

std::vector<std::vector<double>> dspUtils::invfreqz(std::complex<double>* h, double* w, int numOrder, int denOrder, int wSize, 
	double* weights, int iter = 0, double tol = 0.01)
{
	int nm = std::max(numOrder, denOrder);
	numOrder++;
	
	MatrixXd OM_m = VectorXd::LinSpaced(nm + 1, 0, nm) * Map<MatrixXd>(w, 1, wSize);
	
	std::complex<double> c(0, -1);
	
	MatrixXcd OM = OM_m * c;
	OM = OM.array().exp();


	MatrixXcd Dva_a = OM.block(1, 0, denOrder, OM.cols()).transpose();
	MatrixXcd h_t = Map<MatrixXcd>(h, 1, wSize).transpose();
	MatrixXcd Dva_b = h_t * MatrixXd::Ones(1, denOrder);

	MatrixXcd Dva = Dva_a.array() * Dva_b.array();
	MatrixXcd Dvb = -(OM.block(0, 0, numOrder, OM.cols()).transpose());

	MatrixXcd D(Dva.rows(), Dva.cols() + Dvb.cols());
	D << Dva, Dvb;

	MatrixXd wf = (Map<MatrixXd>(weights, 1, wSize).transpose()).cwiseSqrt();
	MatrixXd D_b = wf * MatrixXd::Ones(1, numOrder + denOrder);

	D = D.array() * D_b.array();

	MatrixXd R = (D.adjoint() * D).real();
	MatrixXd Vd = (D.adjoint() * (-h_t.array() * wf.array()).matrix()).real();

	MatrixXd th = R.partialPivLu().solve(Vd).eval();
	th = th.transpose();

	std::vector<double> a;
	std::vector<double> b;

	a.push_back(1);
	std::copy(th.data(), &th.data()[denOrder], back_inserter(a));
	std::copy(&th.data()[denOrder], &th.data()[denOrder + numOrder], back_inserter(b));

	if (iter == 0)
	{
		std::vector<std::vector<double>> out;
		out.push_back(b);
		out.push_back(a);

		return out;
	}

	a =  polystab(a);

	VectorXd bV = Map<VectorXd>(b.data(), b.size());
	VectorXd aV = Map<VectorXd>(a.data(), a.size());

	MatrixXcd GC_b = bV.transpose() * OM.block(0, 0, numOrder, OM.cols());
	MatrixXcd GC_a = aV.transpose() * OM.block(0, 0, denOrder + 1, OM.cols());

	MatrixXcd GC = (GC_b.array() / GC_a.array()).transpose();
	MatrixXcd e = (GC - h_t).array() * wf.array();
	MatrixXcd Vcap = e.adjoint() * e;

	MatrixXd t(a.size() - 1 + b.size(), 1);
	t << Map<VectorXd>(&a.data()[1], a.size() - 1), bV;

	double gndir = 2 * tol + 1;
	int l = 0;
	int st = 0;
	MatrixXd gndirMat;

	while (gndir > tol && l < iter && st!= 1)
	{
		l++;

		MatrixXcd D31_a = OM.block(1, 0, denOrder, OM.cols()).transpose();
		MatrixXcd D31_b = -GC.array() / (aV.transpose() * OM.block(0, 0, denOrder + 1, OM.cols())).transpose().array();
		MatrixXd D31_c = MatrixXd::Ones(1, denOrder);
		MatrixXcd D31 = D31_a.array() * (D31_b * D31_c).array();

		MatrixXcd D32_a = OM.block(0, 0, numOrder, OM.cols()).transpose();
		MatrixXcd D32_b = (aV.transpose() * OM.block(0, 0, denOrder + 1, OM.cols())).transpose();
		MatrixXd D32_c = MatrixXd::Ones(1, numOrder);
		MatrixXcd D32 = D32_a.array() / (D32_b * D32_c).array();

		MatrixXcd D3(D31.rows(), D31.cols() + D32.cols());
		D3 << D31, D32;
		MatrixXd D3_b = wf * MatrixXd::Ones(1, numOrder + denOrder);
		D3 = D3.array() * D3_b.array();

		e = (GC - h_t).array() * wf.array();
		R = (D3.adjoint() * D3).real();
		Vd = (D3.adjoint() * e).real();

		gndirMat = R.partialPivLu().solve(Vd).eval();
		int ll = 0;
		double k = 1.0;
		MatrixXcd V1 = Vcap.array() + 1;
		MatrixXd t1;

		while (V1(0,0).real() > Vcap(0, 0).real() && ll < 20)
		{

			t1 = t - k * gndirMat;
			if (ll == 19)
				t1 = t;

			std::vector<double> t1_v(t1.transpose().data(), &t1.transpose().data()[t1.rows()]);
			std::copy(t1_v.begin(), t1_v.begin() + denOrder, a.begin() + 1);
			a = polystab(a);

			std::copy(a.begin() + 1, a.end(), t1_v.begin());
			std::copy(t1_v.begin() + denOrder, t1_v.end(), b.begin());

			bV = Map<VectorXd>(b.data(), b.size());
			aV = Map<VectorXd>(a.data(), a.size());

			GC_b = bV.transpose() * OM.block(0, 0, numOrder, OM.cols());
			GC_a = aV.transpose() * OM.block(0, 0, denOrder + 1, OM.cols());

			GC = (GC_b.array() / GC_a.array()).transpose();

			V1 = (GC - h_t).array() * wf.array();
			V1 = V1.adjoint() * V1;
			t1 = Map<VectorXd>(t1_v.data(), t1_v.size());

			k /= 2;
			ll++;
			if (ll == 20)
				st = 1;
			if (ll == 10)
			{
				gndirMat = Vd / R.norm() * R.rows();
				k = 1;
			}

		}

		t = t1;
		Vcap(0,0) = V1(0, 0);

		gndir = gndirMat.norm();
	}

	std::vector<std::vector<double>> out;
	out.push_back(b);
	out.push_back(a);

	return out;
}

std::vector<double> dspUtils::polystab(std::vector<double>& a)
{

	if (a.size() <= 1)
		return a;

	std::vector<double> aMirror(a.size());
	std::reverse_copy(a.begin(), a.end(), aMirror.begin());

	PolynomialSolver<double, Eigen::Dynamic> solver;
	VectorXd aV = Map<VectorXd>(aMirror.data(), a.size());
	solver.compute(aV);
	VectorXcd v = solver.roots();

	int non0index = -1;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != std::complex<double>(0, 0))
		{
			double vs = 0.5 * (copysign(abs(v[i]) - 1 == 0 ? 0 : 1, abs(v[i]) - 1) + 1);
			v[i] = (1 - vs) * v[i] + vs / std::conj(v[i]);
			if (non0index < 0 && v[i] != std::complex<double>(0, 0))
			{
				non0index = i;
			}
		}
	}
	VectorXcd polCoeffs;
	roots_to_monicPolynomial(v, polCoeffs);

	VectorXd b = (a[non0index] * polCoeffs).real();

	std::vector<double> out(b.size());

	std::reverse_copy(b.data(), b.data() + b.size(), out.begin());

	return out;
}

std::vector<std::vector<double>> dspUtils::getWallFilterCoeffs(double sampleRate, double f125, double f250, double f500, 
	double f1000, double f2000, double f4000, double f8000, double f16000)
{

	int N = 3;
	double	Fs = sampleRate;
	double sizeFFT = 1024;

	double amplitude[Parameters::NUM_FREQ] = { f125, f250, f500, f1000, f2000, f4000, f8000, f16000 };
	double freq[Parameters::NUM_FREQ] = { 125, 250, 500, 1000, 2000, 4000, 8000, 16000 };

	for (int i = 0; i < Parameters::NUM_FREQ; i++)
	{
		amplitude[i] = Decibels::gainToDecibels(sqrt(1 - amplitude[i]));
	}

	float ampExtended[Parameters::NUM_FREQ + 2], freqExtended[Parameters::NUM_FREQ + 2];
	ampExtended[0] = amplitude[0];
	freqExtended[0] = 0;
	ampExtended[Parameters::NUM_FREQ + 1] = amplitude[Parameters::NUM_FREQ - 1];
	freqExtended[Parameters::NUM_FREQ + 1] = Fs / 2.0;
	std::copy(amplitude, &amplitude[Parameters::NUM_FREQ], &ampExtended[1]);
	std::copy(freq, &freq[Parameters::NUM_FREQ], &freqExtended[1]);
	
	arma::vec interpPoints = arma::linspace(0, sizeFFT / 2, (sizeFFT / 2) + 1);
	interpPoints *= (Fs/sizeFFT);
	int nSamples = interpPoints.size();

	arma::vec ampEV(std::vector<double>(ampExtended, &ampExtended[Parameters::NUM_FREQ + 2]));
	arma::vec freqEV(std::vector<double>(freqExtended, &freqExtended[Parameters::NUM_FREQ + 2]));

	arma::vec hInterp(nSamples);
	
	arma::interp1(freqEV, ampEV, interpPoints, hInterp);

	arma::cx_vec logSpectrum(arma::join_vert(hInterp, arma::reverse(hInterp(arma::span(1, nSamples - 2)))), arma::zeros<arma::vec>((nSamples - 1) * 2));
	arma::cx_vec cepstrum = arma::ifft(logSpectrum);

	arma::cx_vec foldedCep(arma::join_vert(arma::cx_vec(1), 
		cepstrum(arma::span(1, nSamples - 2)) + arma::reverse(cepstrum(arma::span(nSamples, sizeFFT - 1))), 
		arma::cx_vec(1),
		arma::zeros<arma::cx_vec>(sizeFFT - nSamples)));
	foldedCep(0) = cepstrum(0);
	foldedCep(nSamples - 1) = cepstrum(nSamples - 1);

	arma::cx_vec minPhLogSpectrum = arma::fft(foldedCep);

	arma::cx_vec hVec = minPhLogSpectrum(arma::span(0, nSamples - 1));
	std::vector<std::complex<double>> h = arma::conv_to<std::vector<std::complex<double>>>::from(hVec);

	for (std::complex<double>& val : h)
	{
		val = pow(10.0, (val / 20.0));
	}

	arma::vec w = (interpPoints / Fs) * MathConstants<double>::twoPi;

	arma::vec wWeights = 1.0 / (24.7 * (4.37 * (interpPoints * 0.001) + 1));

	return invfreqz(h.data(), w.memptr(), N, N, w.size(), wWeights.memptr(), 10);
}
