#pragma once
#include <WaveGuide.h>
#include <Listener.h>
#include <Source.h>
#include <ScatteringNode.h>
#include <Panner.h>

class Room
{

public:
	Room();
	~Room() {};

	//int getNumberOfWalls() { return wallNumber; };
	//void setNumberOfWalls(int newWalls) { wallNumber = newWalls; };

	Source* getSource() { return &source; };
	Listener* getPlayer() { return &player; };

	void process(AudioBuffer<float>& sourceBuffer);
	void prepare(double samplerate, Point3d dimensions, Point3d sourcePos, Point3d playerPos, int nChannels, int numSamples);

	void updatePositions();
	void setSourcePos(float newPos, const char& axis);
	void setListenerPos(float newPos, const char& axis);
	void setListenerRotation(float newValue, const char& axis);
	void setDimensions(float newValue, const char& axis);

	void setWallAbsorption(float newValue);
	void setWallFreqAbsorption(float newValue, int wallIndex, int freqIndex);

private:

	void initWalls(double samplerate);
	void initVariables(int numSamples);
	void initWaveguides(double samplerate);
	void timeStep();
	void processNodes();
	void processSample(AudioBuffer<float>& sourceBuffer, const float** currentReadPointers, int nChannels, int sampleIndex, int maxIndex);


	bool hasChanged = false;
	//int wallNumber = 6;
	WaveGuide sourceListener;
	std::vector<WaveGuide> sourceNode;
	std::vector<WaveGuide> NodeToNode;
	std::vector<WaveGuide> nodeListener;

	std::vector<ScatteringNode> wallNodes;

	Source source;
	Listener player;

	Point3d dimensions = { 0.0f, 0.0f, 0.0f };


	AudioBuffer<float> currentSample;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Room);
};

