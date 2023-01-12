#include "WaveGuide.h"

WaveGuide::WaveGuide()
{
	startNode = 0;
	endNode = 0;
	distance = 0;
	attenuation = 1;
	//delayInSamples = 0;

}

void WaveGuide::prepare(double samplerate, Node* start, Node* end, float dist)
{
	startNode = start;
	endNode = end;
	distance = dist;
	Point3d startPos = startNode->getPosition();
	Point3d endPos = endNode->getPosition();
	toSamplesConst = samplerate / Parameters::SOUND_SPEED;

	//delayInSamples = (samplerate * distance) / SOUND_SPEED;
	delay.prepare(samplerate, (int)samplerate * 5, distance * toSamplesConst);

}

void WaveGuide::setDistance(float newDist)
{
	distance = newDist;
	//delayInSamples = (delay.getSampleRate() * distance) / SOUND_SPEED;
	delay.setDelay(distance * toSamplesConst);
}