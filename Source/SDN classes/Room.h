#pragma once
#include <WaveGuide.h>
#include <Listener.h>
#include <Source.h>
#include <ScatteringNode.h>
#include <Panner.h>

class Room
{

public:
	Room() {};
	~Room() {};

	int getNumberOfWalls() { return wallNumber; };
	void setNumberOfWalls(int newWalls) { wallNumber = newWalls; };

	Source* getSource() { return &source; };
	Listener* getPlayer() { return &player; };

	//bool hasInstance() { return isInstance; };

	void process(AudioBuffer<float>& sourceBuffer);
	void prepare(double samplerate, Point3d dimensions, Point3d sourcePos, Point3d playerPos, int nChannels, int numSamples);

	void updatePositions();
	void setSourcePos(float newPos, const char& axis);
	void setListenerPos(float newPos, const char& axis);
	void setDimensions(float newValue, const char& axis);


	void setWallAbsorption(float newValue);

private:

	void initWalls(double samplerate, std::vector<float>& octaveCoeffs);
	void initVariables(int numSamples);
	void initWaveguides(double samplerate);
	void timeStep();
	void processNodes();
	void processSample(AudioBuffer<float>& sourceBuffer, const float** currentReadPointers, int nChannels, int sampleIndex);


	bool hasChanged = false;
	int wallNumber = 6;
	WaveGuide sourceListener;
	std::vector<WaveGuide> sourceNode;
	std::vector<WaveGuide> NodeToNode;
	std::vector<WaveGuide> nodeListener;

	std::vector<ScatteringNode> wallNodes;

	SmoothedValue<float, ValueSmoothingTypes::Linear> sourceX;
	SmoothedValue<float, ValueSmoothingTypes::Linear> sourceY;
	SmoothedValue<float, ValueSmoothingTypes::Linear> sourceZ;

	SmoothedValue<float, ValueSmoothingTypes::Linear> listenerX;
	SmoothedValue<float, ValueSmoothingTypes::Linear> listenerY;
	SmoothedValue<float, ValueSmoothingTypes::Linear> listenerZ;

	Source source;
	Listener player;

	//bool isInstance = false;
	Point3d dimensions = { 0.0f, 0.0f, 0.0f };


	AudioBuffer<float> currentSample;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Room);
};

