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

	int intDist = (int)jlimit(1.0f, 100.0f, dist) - 1;
	a.assign(&FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][2], &FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][2] + 2);
	b.assign(&FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][0], &FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][0] + 2);
	airAbsorptionFilter.init(samplerate, &a, &b);

}

float& WaveGuide::getCurrentSample()
{
	float sample = delay.readNextSample();
	if(airAbsorption)
		airAbsorptionFilter.process(sample);

	return sample;
}

void WaveGuide::setDistance(float newDist)
{
	distance = newDist;
	delay.setDelay(distance * toSamplesConst);
	int intDist = (int)jlimit(1.0f, 100.0f, newDist) - 1;
	a.assign(&FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][2], &FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][2] + 2);
	b.assign(&FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][0], &FilterPresets::AIR_ABSOPRTION_FILTERS[intDist][0] + 2);
}