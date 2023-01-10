#include "ScatteringNode.h"

ScatteringNode::ScatteringNode()
{
	setPosition({0, 0, 0});
}

void ScatteringNode::init(double samplerate, Point3d position, int numChannels, int nOfConnections,
	WaveGuide* sourceNodeGuide, WaveGuide* nodeListenerGuide)
{
	nChannels = numChannels;
	setPosition(position);
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);
	outWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);
	scatteringCoeff = 2.0f / nOfConnections;
	this->nOfConnections = nOfConnections;
	sourceGuide = sourceNodeGuide;
	listenerGuide = nodeListenerGuide;

	inSamples = std::vector<std::vector<float>>(nOfConnections);
	toListenerSample.setSize(numChannels, 1);
	wallFilters = std::vector<std::vector<IIRBase>>(nOfConnections);
	totLoudness = std::vector<float>(nChannels, 0.0f);

	std::vector<std::vector<double>> coeffs = dspUtils::getWallFilterCoeffs(samplerate, absorption[0],
		absorption[1], absorption[2], absorption[3], absorption[4], absorption[5]);

	a = coeffs[1];
	b = coeffs[0];
	
	for (std::vector<IIRBase>& connectionFilters : wallFilters)
	{
		connectionFilters = std::vector<IIRBase>(nChannels);
		for (IIRBase& filter : connectionFilters)
		{
			filter.init(samplerate, &a, &b);
		}
	}

}

void ScatteringNode::process()
{

	for (float& value : totLoudness)
	{
		value = 0.0f;
	}
	std::vector<float>& sourceSample = sourceGuide->getCurrentSample();

	for (int i = 0; i < nOfConnections; i++)
	{
		inSamples[i] = inWaveguides[i]->getCurrentSample();
		for (int ch = 0; ch < nChannels; ch++)
		{
			inSamples[i][ch] += sourceSample[ch] / 2.0f;
			totLoudness[ch] += inSamples[i][ch];
		}
	}
	
	getAllOutSamples();

}

void ScatteringNode::getAllOutSamples()
{

	toListenerSample.clear();
	int inSampleIndex = 0;

	for (int i = 0; i < nOfConnections; i++)
	{

		if (inWaveguides[i]->getStart() == outWaveguides[i]->getEnd()) //should always enter here by vector construction
		{
			inSampleIndex = i;
		}
		else
		{
			for (int j = 0; j < nOfConnections; j++)
			{
				if (inWaveguides[j]->getStart() == outWaveguides[i]->getEnd())
				{
					inSampleIndex = j;
					break;
				}
			}
		}


		for (int ch = 0; ch < nChannels; ch++)
		{
			float chInSample = inSamples[inSampleIndex][ch];

			float chSample = totLoudness[ch] - chInSample;
			chSample *= scatteringCoeff;
			chSample += chInSample * (scatteringCoeff - 1);

			//chSample *= wallAbsorption;
			wallFilters[inSampleIndex][ch].process(chSample);

			outWaveguides[i]->pushNextSample(chSample, ch);
			toListenerSample.addSample(ch, 0, chSample);
		}
	}

	toListenerSample.applyGain(scatteringCoeff);
	listenerGuide->pushNextSample(toListenerSample);

}