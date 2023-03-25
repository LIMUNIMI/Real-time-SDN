#pragma once
#include <JuceHeader.h>

#define ORDER2NSH(order) ((order+1)*(order+1))

//holds all the generic constants used in the project and the function to generate plugin parameters
namespace Parameters
{
	constexpr auto SOUND_SPEED = 343;
	constexpr char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };
	constexpr int NUM_WALLS = 6;
	constexpr int NUM_FREQ = 8;
	constexpr int STEREO_CHANNELS = 2;
	constexpr int NUM_WAVEGUIDES_TO_OUTPUT = 7;
	constexpr int NUM_OUT_MODES = 7;
	constexpr float SMOOTHING_TIME_SECONDS = 0.015f;
	constexpr char* outputModes[NUM_OUT_MODES] = {"Mono", "Stereo",
		"1st order Ambisonic", "2nd order Ambisonic", "3rd order Ambisonic", "4th order Ambisonic", "5th order Ambisonic" };


	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
}