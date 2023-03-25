#pragma once

#include <Microphone.h>
#include <WaveGuide.h>
#include <Parameters.h>
#include <Eigen/Geometry>

/**
 * Converts spherical harmonic order to number of spherical harmonic components
 * i.e: (order+1)^2 */

#define AZIMUTH(channel) inputs_angles(channel, 0)
#define ELEVATION(channel) inputs_angles(channel, 1)

class Ambisonic : public Microphone
{
public:
	Ambisonic() {};
	~Ambisonic() {};

	void init() override;

	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& currentSample,
		AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged) override;

	void setAmbisonicOrder(int newOrder)
	{
		ambisonicOrder = newOrder;
		nSH = ORDER2NSH(newOrder);
		setGainsToZero();
		for (int i = 0; i < Parameters::NUM_WAVEGUIDES_TO_OUTPUT; i++)
		{
			getSphericalHarmonics(i);
		}
	}

private:

	//real spherical harmonics WITHOUT the 1/sqrt(4*pi) term
	//ACN channel ordering / N3D normalization convention
	void getSphericalHarmonics(int channel);

	// does not include Condon-Shortley phase term
	void unnormalisedLegendrePoly(int polyOrder, float x, float* poly1, float* poly2, float* outPoly);

	void setGainsToZero() 
	{
		channelGains.setZero();
		inputs.setZero();
		output.setZero();

		for (int i = 0; i < 6; i++)
		{
			leg_n[i] = 0;
			leg_n_1[i] = 0;
			leg_n_2[i] = 0;
		}
	}


	Eigen::Matrix<float, ORDER2NSH(5), Parameters::NUM_WAVEGUIDES_TO_OUTPUT> channelGains;
	Eigen::Vector<float, ORDER2NSH(5)>  output;
	Eigen::Vector<float, Parameters::NUM_WAVEGUIDES_TO_OUTPUT> inputs;
	Eigen::Matrix<float, Parameters::NUM_WAVEGUIDES_TO_OUTPUT, 2> inputs_angles; //[0]azimuth, [1]elevation
	Eigen::Vector3f microphoneToNodeVector;

	float leg_n[6] = { 0.0f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f, }, 
		leg_n_1[6] = { 0.0f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f, }, 
		leg_n_2[6] = { 0.0f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f, }, 
		sin_el = 0.0f;
	float factorials[11] = { 1.0f, 1.0f, 2.0f, 6.0f, 24.0f, 120.0f, 720.0f, 5040.0f, 40320.0f, 362880.0f, 3628800.0f };

	int ambisonicOrder = 0;
	int nSH = 0;

	//const int piDivided180 = MathConstants<float>::pi / 180;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Ambisonic);

};