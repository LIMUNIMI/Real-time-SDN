#include "Parameters.h"

AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> params;

	//Does not go to 0 and 1 to avoid clipping into the wall
	params.push_back(std::make_unique<AudioParameterFloat>("SourceX", "Source X", 0.0f, 1.0f, 0.50f));
	params.push_back(std::make_unique<AudioParameterFloat>("SourceY", "Source Y", 0.0f, 1.0f, 0.70f));
	params.push_back(std::make_unique<AudioParameterFloat>("SourceZ", "Source Z", 0.0f, 1.0f, 0.75f));

	params.push_back(std::make_unique<AudioParameterFloat>("ListenerX", "Listener X", 0.0f, 1.0f, 0.50f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerY", "Listener Y", 0.0f, 1.0f, 0.60f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerZ", "Listener Z", 0.0f, 1.0f, 0.25f));

	params.push_back(std::make_unique<AudioParameterFloat>("ListenerRotx", "Listener Pitch", -180.0f, 180.0f, 0.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerRoty", "Listener Yaw", -180.0f, 180.0f, 0.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerRotz", "Listener Roll", -180.0f, 180.0f, 0.0f));

	params.push_back(std::make_unique<AudioParameterChoice>("OutputMode", "Output mode", 
		StringArray(outputModes, NUM_OUT_MODES), 0));

	params.push_back(std::make_unique<AudioParameterFloat>("sourceGain", "Source Gain (dB)", -12.0f, 12.0f, 0.0f));

	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsX", "Dimensions X (m)", NormalisableRange<float>(1.0f, ROOM_MAX_DIMENSION, 0.01, 0.3), 06.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsY", "Dimensions Y (m)", NormalisableRange<float>(1.0f, ROOM_MAX_DIMENSION, 0.01, 0.3), 03.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsZ", "Dimensions Z (m)", NormalisableRange<float>(1.0f, ROOM_MAX_DIMENSION, 0.01, 0.3), 4.50f));

	//freq + wallIndex + freqIndex
	for (int i = 0; i < NUM_WALLS; i++)
	{
		for (int j = 0; j < NUM_FREQ; j++)
		{
			params.push_back(std::make_unique<AudioParameterFloat>("freq" + String(i) + String(j), String(125 * pow(2, j)) + "HZ Wall " + String::charToString(axishelper[i]).toUpperCase() + " " + String(i % 2), 0.0001f, 1.0f, 0.25f + 0.5f * (float)j/NUM_FREQ));
		}
	}

	params.push_back(std::make_unique<AudioParameterBool>("LOS", "Render Line-of-sight", true));

	return { params.begin(), params.end() };
}
