#include "WaveGuide.h"
#define SOUND_SPEED 343;

WaveGuide::WaveGuide()
{
	startNode = std::make_shared<HasBuffer>();
	endNode = std::make_shared<HasBuffer>();
	distance = 0;
	attenuation = 1;
	delay = 0;
	processorChain = dsp::ProcessorChain<dsp::Gain<float>, dsp::DelayLine<float>>();
}
WaveGuide::WaveGuide(std::shared_ptr<HasBuffer> start, std::shared_ptr<HasBuffer> end) : startNode(start), endNode(end)
{
	
	Point3d startPos =  startNode->getPosition();
	Point3d endPos = endNode->getPosition();

	distance = sqrt(pow((startPos.x - endPos.x), 2) + pow((startPos.y - endPos.y), 2)
		+ pow((startPos.z - endPos.z), 2));

	attenuation = 1 / distance;

	delay = 0;


}

void WaveGuide::prepare(double samplerate, int samplesPerBlock, uint32 nChannels)
{
	delay = (samplerate * distance) / SOUND_SPEED;
	//printf("\n(%f) ", delay);

	processorChain.prepare({ samplerate, (uint32)samplesPerBlock, nChannels });
	processorChain.get<1>().setMaximumDelayInSamples(samplerate * 5);
	processorChain.get<1>().setDelay(delay);
	processorChain.get<0>().setGainLinear(attenuation);
}

void WaveGuide::prepare(double samplerate, int samplesPerBlock, uint32 nChannels, uint32 nNodes)
{
	delay = (samplerate * distance) / SOUND_SPEED;
	//printf("\n(%f) ", delay);

	processorChain.prepare({ samplerate, (uint32)samplesPerBlock, nChannels });
	processorChain.get<1>().setMaximumDelayInSamples(samplerate * 5);
	processorChain.get<1>().setDelay(delay);
	processorChain.get<0>().setGainLinear(attenuation * (1.0/ (nNodes - 1)));
}

void WaveGuide::process(AudioBuffer<float>& currentBuffer)
{
	AudioBuffer<float> outBuffer;
	outBuffer.makeCopyOf(currentBuffer);
	auto outContext = dsp::ProcessContextReplacing<float>(dsp::AudioBlock<float>(outBuffer));
	processorChain.process(outContext);

	/*int numSamples = outBuffer.getNumSamples();
	for (int channel = 0; channel < outBuffer.getNumChannels(); ++channel)
	{
		auto* channelData = outBuffer.getReadPointer(channel);
		for (int j = 0; j < numSamples; j++)
		{
			printf(" %f ", channelData[j]);
		}
	}*/

	//printf("\n(%f) ", endNode->getPosition().y);
	endNode->addToBuffer(outBuffer);

}