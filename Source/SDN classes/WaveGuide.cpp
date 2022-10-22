#include "WaveGuide.h"
#define SOUND_SPEED 343

WaveGuide::WaveGuide()
{
	startNode = 0;
	endNode = 0;
	distance = 0;
	attenuation = 1;
	delayInSamples = 0;

}

void WaveGuide::prepare(double samplerate, int samplesPerBlock, uint32 nChannels, Node* start, Node* end, float dist)
{
	startNode = start;
	endNode = end;
	distance = dist;
	Point3d startPos = startNode->getPosition();
	Point3d endPos = endNode->getPosition();

	delayInSamples = (samplerate * distance) / SOUND_SPEED;
	delay.prepare(samplerate, nChannels, samplerate * 5, delayInSamples);

}