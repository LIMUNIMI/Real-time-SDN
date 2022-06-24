#include "ScatteringNode.h"

ScatteringNode::ScatteringNode()
{
	setPosition({0, 0, 0});
	newBuffer(0, 0);
}

ScatteringNode::ScatteringNode(Point3d position, int numChannels, int numSamples)
{
	setPosition(position);
	newBuffer(numChannels, numSamples);
	cleanBuffer();
}

/*void ScatteringNode::addToBuffer(AudioBuffer<float> inWave)
{
	for (int channel = 0; channel < inWave.getNumChannels(); ++channel)
	{
		auto* channelData = inWave.getReadPointer(channel);
		auto* destination = getBuffer().getWritePointer(channel);

		std::transform(channelData, channelData + inWave.getNumSamples(), destination, destination, std::plus<float>());
	}
}*/