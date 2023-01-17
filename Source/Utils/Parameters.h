#pragma once
#include <JuceHeader.h>

namespace Parameters
{
	constexpr auto SOUND_SPEED = 343;
	constexpr char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };
	constexpr int NUM_WALLS = 6;
	constexpr int NUM_FREQ = 8;

	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
}