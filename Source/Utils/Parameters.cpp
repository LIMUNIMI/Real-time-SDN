#include "Parameters.h"

AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> params;

	params.push_back(std::make_unique<AudioParameterFloat>("SourceX", "SourceX", 0.0001f, 0.9999f, 0.5f));
	params.push_back(std::make_unique<AudioParameterFloat>("SourceY", "SourceY", 0.0001f, 0.9999f, 0.2f));
	params.push_back(std::make_unique<AudioParameterFloat>("SourceZ", "SourceZ", 0.0001f, 0.9999f, 0.1f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerX", "ListenerX", 0.0001f, 0.9999f, 0.5f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerY", "ListenerY", 0.0001f, 0.9999f, 0.2f));
	params.push_back(std::make_unique<AudioParameterFloat>("ListenerZ", "ListenerZ", 0.0001f, 0.9999f, 0.5f));

	params.push_back(std::make_unique<AudioParameterFloat>("WallAbsorption", "WallAbsorption", 0.0f, 1.0f, 0.2f));

	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsX", "DimensionsX", 1.0f, 100.0f, 10.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsY", "DimensionsY", 1.0f, 100.0f, 10.0f));
	params.push_back(std::make_unique<AudioParameterFloat>("DimensionsZ", "DimensionsZ", 1.0f, 100.0f, 10.0f));

	return { params.begin(), params.end() };
}
