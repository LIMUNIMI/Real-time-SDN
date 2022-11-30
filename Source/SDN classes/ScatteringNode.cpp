#include "ScatteringNode.h"

ScatteringNode::ScatteringNode()
{
	setPosition({0, 0, 0});
}

void ScatteringNode::init(double samplerate, Point3d position, int numChannels, int nOfConnections,
	WaveGuide* sourceNodeGuide, WaveGuide* nodeListenerGuide, std::vector<float>& octaveCoeffs)
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
	wallFilter = std::vector<std::vector<WallFilters>>(nOfConnections);
	totLoudness = std::vector<float>(nChannels, 0.0f);
	
	for (std::vector<WallFilters>& filterVector : wallFilter)
	{
		filterVector = std::vector<WallFilters>(nChannels);
		for (WallFilters& filter : filterVector)
		{
			filter.prepare(samplerate, octaveCoeffs);
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
	//std::fill(toListenerSample.begin(), toListenerSample.end(), 0.0f);
	toListenerSample.clear();
	//std::vector<float> inSample(nChannels, 0.0f);
	int inSampleIndex = 0;
	//inSample.setSize(nChannels, 1);
	//float** insampleWritePointers = inSample.getArrayOfWritePointers();

	/*AudioBuffer<float> outSample;
	outSample.setSize(nChannels, 1);*/

	for (int i = 0; i < nOfConnections; i++)
	{
		//outSample.clear();

		if (inWaveguides[i]->getStart() == outWaveguides[i]->getEnd()) //should always enter here by vector construction
		{
			/*for (int ch = 0; ch < nChannels; ch++)
			{
				inSample[ch] = inSamples[i][ch];
			}*/
			inSampleIndex = i;
		}
		else
		{
			for (int j = 0; j < nOfConnections; j++)
			{
				if (inWaveguides[j]->getStart() == outWaveguides[i]->getEnd())
				{
					/*<for (int ch = 0; ch < nChannels; ch++)
					{
						inSample[ch] = inSamples[j][ch];
					}*/
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

			//wallFilter[i][ch].process(chSample);
			chSample *= wallAbsorption;

			//outSample.setSample(ch, 0, chSample);
			outWaveguides[i]->pushNextSample(chSample, ch);
			toListenerSample.addSample(ch, 0, chSample);
			//toListenerSample[ch] = toListenerSample[ch] + chSample;
		}
		//outSample.applyGain(wallAbsorption);
		//outWaveguides[i]->pushNextSample(outSample);
	}

	/*for (int ch = 0; ch < nChannels; ch++)
	{
		toListenerSample[ch] = toListenerSample[ch] * scatteringCoeff;
		listenerGuide->pushNextSample(toListenerSample[ch], ch);
	}*/
	toListenerSample.applyGain(scatteringCoeff);
	listenerGuide->pushNextSample(toListenerSample);
}