#pragma once
#include <JuceHeader.h>

namespace Parameters
{
	constexpr auto SOUND_SPEED = 343;


	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
}