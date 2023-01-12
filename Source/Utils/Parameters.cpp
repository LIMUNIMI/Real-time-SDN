#include "Parameters.h"

AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> params;

	//Does not go to 0 and 1 to avoid clipping into the wall
	params.push_back(std::make_unique<AudioParameterFloat>("SourceX", "Source X", 0.0001f, 0.9999f, 0.5f));
	params.push_back(std::make_unique<AudioParameterFloat>("SourceY", "Source Y", 0.0001f, 0.9999f, 0.2f));
	params.push_back(std::make_unique<AudioParameterFloat>("SourceZ", "Source Z", 0.0001f, 0.9999f, 0.5f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerX", "Listener X", 0.0001f, 0.9999f, 0.5f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerY", "Listener Y", 0.0001f, 0.9999f, 0.2f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerZ", "Listener Z", 0.0001f, 0.9999f, 0.2f));

	params.push_back(std::make_unique<AudioParameterFloat>("ListenerRotx", "Listener Pitch", 0.0f, 360.0f, 0.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerRoty", "Listener Yaw", 0.0f, 360.0f, 0.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerRotz", "Listener Roll", 0.0f, 360.0f, 0.0f));

	params.push_back(std::make_unique<AudioParameterFloat>("WallAbsorption", "WallAbsorptions", 0.0f, 1.0f, 0.2f));

	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsX", "Dimensions X", 1.0f, 100.0f, 10.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsY", "Dimensions Y", 1.0f, 100.0f, 10.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsZ", "Dimensions Z", 1.0f, 100.0f, 10.0f));

	//freq + wallIndex + freqIndex
	for (int i = 0; i < NUM_WALLS; i++)
	{
		for (int j = 0; j < NUM_FREQ; j++)
		{
			params.push_back(std::make_unique<AudioParameterFloat>("freq" + String(i) + String(j), String(125 * pow(2, j)) + "HZ Wall " + String::charToString(axishelper[i]).toUpperCase() + " " + String(i % 2), 0.0001f, 1.0f, 0.5f));
		}
	}

	return { params.begin(), params.end() };
}
