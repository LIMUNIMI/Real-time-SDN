#include "WaveGuide.h"

WaveGuide::WaveGuide()
{
	startNode = 0;
	endNode = 0;
	distance = 0;
	attenuation = 1;

}

void WaveGuide::prepare(double samplerate, Node* start, Node* end, float dist)
{
	startNode = start;
	endNode = end;
	distance = dist;
	Point3d startPos = startNode->getPosition();
	Point3d endPos = endNode->getPosition();
	toSamplesConst = samplerate / Parameters::SOUND_SPEED;

	delay.prepare(samplerate, ceilf(sqrtf(Parameters::ROOM_MAX_DIMENSION * Parameters::ROOM_MAX_DIMENSION * 3.0f) * toSamplesConst), 
		distance * toSamplesConst);

}

void WaveGuide::setDistance(float newDist)
{
	distance = newDist;
	delay.setDelay(distance * toSamplesConst);
}