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

	sampleFreq = samplerate;

	if (samplerate<= 46050)
	{
		a.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][FilterPresets::N_AIR_FILTER_COEFFS], &FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][FilterPresets::N_AIR_FILTER_COEFFS] + FilterPresets::N_AIR_FILTER_COEFFS);
		b.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][0], &FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][0] + FilterPresets::N_AIR_FILTER_COEFFS);
	}
	else if (samplerate > 46050 && samplerate <= 72000)
	{
		a.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][FilterPresets::N_AIR_FILTER_COEFFS], &FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][FilterPresets::N_AIR_FILTER_COEFFS] + FilterPresets::N_AIR_FILTER_COEFFS);
		b.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][0], &FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][0] + FilterPresets::N_AIR_FILTER_COEFFS);
	}
	else if (samplerate > 72000)
	{
		a.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][FilterPresets::N_AIR_FILTER_COEFFS], &FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][FilterPresets::N_AIR_FILTER_COEFFS] + FilterPresets::N_AIR_FILTER_COEFFS);
		b.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][0], &FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][0] + FilterPresets::N_AIR_FILTER_COEFFS);
	}

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
	int intDist = (int)jlimit(1.0f, 173.0f, newDist) - 1;
	if (sampleFreq <= 46050)
	{
		a.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][FilterPresets::N_AIR_FILTER_COEFFS], &FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][FilterPresets::N_AIR_FILTER_COEFFS] + FilterPresets::N_AIR_FILTER_COEFFS);
		b.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][0], &FilterPresets::AIR_ABSORPTION_FILTERS_44100[intDist][0] + FilterPresets::N_AIR_FILTER_COEFFS);
	}
	else if (sampleFreq > 46050 && sampleFreq <= 72000)
	{
		a.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][FilterPresets::N_AIR_FILTER_COEFFS], &FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][FilterPresets::N_AIR_FILTER_COEFFS] + FilterPresets::N_AIR_FILTER_COEFFS);
		b.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][0], &FilterPresets::AIR_ABSORPTION_FILTERS_48000[intDist][0] + FilterPresets::N_AIR_FILTER_COEFFS);
	}
	else if (sampleFreq > 72000)
	{
		a.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][FilterPresets::N_AIR_FILTER_COEFFS], &FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][FilterPresets::N_AIR_FILTER_COEFFS] + FilterPresets::N_AIR_FILTER_COEFFS);
		b.assign(&FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][0], &FilterPresets::AIR_ABSORPTION_FILTERS_96000[intDist][0] + FilterPresets::N_AIR_FILTER_COEFFS);
	}
}