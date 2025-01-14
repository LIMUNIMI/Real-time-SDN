#include "ScatteringNode.h"

ScatteringNode::ScatteringNode()
{
	setPosition({ 0, 0, 0 });
}

void ScatteringNode::init(double samplerate, Point3d position, int nOfConnections,
	WaveGuide* sourceNodeGuide, WaveGuide* nodeListenerGuide)
{
	setPosition(position);
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);
	outWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);
	scatteringCoeff = 2.0f / nOfConnections;
	this->nOfConnections = nOfConnections;
	sourceGuide = sourceNodeGuide;
	listenerGuide = nodeListenerGuide;

	inSamples = std::vector<float>(nOfConnections);
	toListenerSample = 0;
	wallFilters = std::vector<IIRBase>(nOfConnections);
	totLoudness = 0.0f;

	std::vector<std::vector<double>> coeffs = dspUtils::getWallFilterCoeffs(samplerate, absorption[0],
		absorption[1], absorption[2], absorption[3], absorption[4], absorption[5], absorption[6], absorption[7]);

	a = coeffs[1];
	b = coeffs[0];
	
	for (IIRBase& filter : wallFilters)
	{
		filter.init(samplerate, &a, &b);
	}

}

void ScatteringNode::process()
{

	totLoudness = 0;
	float sourceSample = sourceGuide->getCurrentSample() / 2.0f;

	for (int i = 0; i < nOfConnections; i++)
	{
		inSamples[i] = inWaveguides[i]->getCurrentSample() + sourceSample;

		totLoudness += inSamples[i];
	}
	totLoudness *= scatteringCoeff;
	getAllOutSamples();

}

void ScatteringNode::getAllOutSamples()
{

	toListenerSample = 0;
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

		float chSample = totLoudness - inSamples[inSampleIndex];

		wallFilters[i].process(chSample);

		outWaveguides[i]->pushNextSample(chSample);
		toListenerSample += chSample;
	}

	toListenerSample *= scatteringCoeff;
	listenerGuide->pushNextSample(toListenerSample);

}