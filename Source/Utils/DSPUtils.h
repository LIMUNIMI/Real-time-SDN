#pragma once

#include <JuceHeader.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <unsupported/Eigen/Polynomials>
#include <unsupported/Eigen/FFT>

namespace dspUtils
{

	//[b, a] = invfreqz(h, w, numOrder, denOrder, [], iter) from matlab, does not work for filter orders higher than 7th
	std::vector<std::vector<double>> invfreqz(std::complex<double>* h, double* w, int numOrder, int denOrder, int wSize, 
		double* weights, int iter, double tol);

	std::vector<double> polystab(std::vector<double>& a);

	//returns coeffs in format [b, a]
	std::vector<std::vector<double>> getWallFilterCoeffs(double sampleRate, double f125, double f250, double f500, double f1000, 
		double f2000, double f4000, double f8000, double f16000);

	void util_interp1(Eigen::VectorXd& x, Eigen::VectorXd& v, Eigen::VectorXd& interpPoints, Eigen::VectorXd& out);
}