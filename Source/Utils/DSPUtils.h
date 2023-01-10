#pragma once

#include <JuceHeader.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <unsupported/Eigen/Polynomials>
#include <armadillo>

namespace dspUtils
{

	//[b, a] = invfreqz(h, w, numOrder, denOrder, [], iter) from matlab
	std::vector<std::vector<double>> invfreqz(std::complex<double>* h, double* w, int numOrder, int denOrder, int wSize, int iter, double tol);

	std::vector<double> polystab(std::vector<double>& a);

	//returns coeffs in format [b, a]
	std::vector<std::vector<double>> getWallFilterCoeffs(double sampleRate, double f125, double f250, double f500, double f1000, double f2000, double f4000);

}