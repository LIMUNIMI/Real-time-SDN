#include "Ambisonic.h"

using namespace Eigen;

void Ambisonic::init()
{
	nSH = ORDER2NSH(ambisonicOrder);
	setGainsToZero();
}

void Ambisonic::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation,
	AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged, bool isRotating)
{

	int i = 0;
	float newAzi, newElev;

	for (WaveGuide* guide : inWaveguides)
	{
		inputs[i] = guide->getCurrentSample();

		if (hasChanged)
		{
			//get azimuth and elevation
			microphoneToNodeVector = MathUtils::dirVector(guide->getStart()->getPosition(), position);
			newAzi = -atan2f(microphoneToNodeVector.x(), microphoneToNodeVector.z());
			newElev = asinf(microphoneToNodeVector.y() / microphoneToNodeVector.norm());

			//if different then update spherical harmonics values for this waveguide
			if (newAzi != AZIMUTH(i) || newElev != ELEVATION(i))
			{
				AZIMUTH(i) = newAzi;
				ELEVATION(i) = newElev;
				getSphericalHarmonics(i);
			}
		}

		i++;
	}

	//convert input to ambisonic B format
	output = channelGains * inputs;

	for (int ch = 0; ch < nSH; ch++)
	{
		sourceBuffer.copyFrom(ch, sampleIndex, &output(ch), 1);
	}
}

void Ambisonic::getSphericalHarmonics(int channel)
{
	float Nn0, Nnm;
	int index_n = 0;

	// cos(inclination) = sin(elevation)
	sin_el = sinf(ELEVATION(channel));

	for (int i = 0; i < ambisonicOrder + 1; i++)
	{
		if (i == 0)
		{
			channelGains(0, channel) = 1.0f;
			index_n = 1;
		}
		else
		{
			unnormalisedLegendrePoly(i, sin_el, leg_n_1, leg_n_2, leg_n);

			Nn0 = sqrtf(2 * (float) i + 1);

			for (int j = 0; j < i + 1; j++)
			{
				if (j == 0)
					channelGains(index_n + i, channel) = Nn0 * leg_n[j];
				else
				{
					Nnm = Nn0 * sqrtf(2 * factorials[i - j] / factorials[i + j]);
					channelGains(index_n + i - j, channel) = Nnm * leg_n[j] * sinf(j * AZIMUTH(channel));
					channelGains(index_n + i + j, channel) = Nnm * leg_n[j] * cosf(j * AZIMUTH(channel));
				}
			}

			index_n += 2 * i + 1;

		}

		std::copy(leg_n_1, &leg_n_1[5], leg_n_2);
		std::copy(leg_n, &leg_n[5], leg_n_1);
	}

}

void Ambisonic::unnormalisedLegendrePoly(int polyOrder, float x, float* poly1, float* poly2, float* outPoly)
{

	int x2 = x * x;
	
	switch (polyOrder)
	{
	case 0:
		outPoly[0] = 1.0f;
		break;

	case 1:
		outPoly[0] = x;
		outPoly[1] = sqrtf(1.0f - x2);
		break;

	case 2:
		outPoly[0] = (3.0f * x2 - 1.0f) / 2.0f;
		outPoly[1] = x * 3.0f * sqrtf(1.0f - x2);
		outPoly[2] = 3.0f * (1.0f - x2);
		break;

	default:
		int k = 2 * polyOrder - 1;
		float dfact_k = 1.0f;

		if ((k % 2) == 0)
			for (int i = 1; i < k / 2 + 1; i++)
				dfact_k *= 2.0f * i;
		else
			for (int i = 1; i < (k + 1) / 2 + 1; i++)
				dfact_k *= (2.0f * i - 1.0f);

		outPoly[polyOrder] = dfact_k * powf(1.0f - x2, (float)polyOrder/2.0f);
		outPoly[polyOrder - 1] = k * x * poly1[polyOrder - 1];

		for (int i = 0; i < polyOrder - 1; i++)
			outPoly[i] = ((k * x * poly1[i]) - ((polyOrder + i - 1) * poly2[i])) / (float)(polyOrder - i);

		break;
	}

}
