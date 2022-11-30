#include "HasBuffer.h"

//void HasBuffer::addToBuffer(AudioBuffer<float>& inWave)
//{
//	int numSamples = inWave.getNumSamples();
//	for (int channel = 0; channel < inWave.getNumChannels(); ++channel)
//	{
//		auto* channelData = inWave.getReadPointer(channel);
//		auto* destination = buffer.getWritePointer(channel);
//
//		/*for (int j = 0; j < numSamples; j++)
//		{
//			printf(" %f ", destination[j]);
//		}
//		printf("\n\n\n");*/
//
//
//		std::transform(channelData, channelData + numSamples, destination, destination, std::plus<float>());
//
//		
//
//	}
//}