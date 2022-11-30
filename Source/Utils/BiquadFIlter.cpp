#include "BiquadFIlter.h"

BiquadFilter::BiquadFilter()
{
	b0 = 0; 
	b1 = 0; 
	b2 = 0;
	a1 = 0; 
	a2 = 0;

	buffer1 = 0;
	buffer2 = 0;

	sampleRate = 0;
}

void BiquadFilter::init(double samplerate, float centerFreq, float gain)
{
	sampleRate = samplerate;

	peakingEQ(centerFreq, gain);
}

void BiquadFilter::process(float& sample)
{
	float inAcc;

	inAcc = sample;
	inAcc -= a1 * buffer1;
	inAcc -= a2 * buffer2;

	sample = inAcc * b0;
	sample += b1 * buffer1;
	sample += b2 * buffer2;

	buffer2 = buffer1;
	buffer1 = inAcc;


}

void BiquadFilter::normalizeByA0(float a0)
{
	b0 /= a0;
	b1 /= a0;
	b2 /= a0;
	a1 /= a0;
	a2 /= a0;
}

void BiquadFilter::peakingEQ(float centerFreq, float gain)
{
	float bw = centerFreq / 2;
	//float A = pow(10.0f, gain / 40.0f);
	Q = sampleRate / bw;
	float w0 = MathConstants<float>::twoPi * centerFreq / sampleRate;
	float K = tan(w0/2);
	float V = gain;
	//float cosw0 = cos(w0);
	//float alpha = sin(w0) / (2.0f * q);

	b0 = 1 + V * K / Q + (K * K);
	b1 = 2 * ((K * K) - 1);
	b2 = 1 - V * K / Q + (K * K);

	float a0 = 1 + K / Q + (K * K);
	a1 = 2 * ((K * K) - 1);
	a2 = 1 - K / Q + (K * K);

	/*float A = pow(10.0f, gain / 40.0f);
	float w0 = MathConstants<float>::twoPi * centerFreq / sampleRate;
	float cosw0 = cos(w0);
	float alpha = sin(w0) / (2.0f * q);

	float a0 = 1 + (alpha / A);

	b0 = 1 + (alpha * A);
	b1 = -2 * cosw0;
	b2 = 1 - (alpha * A);

	a1 = b1;
	a2 = 1 - (alpha / A);*/

	normalizeByA0(a0);
}

