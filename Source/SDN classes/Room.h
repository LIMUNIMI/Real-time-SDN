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

	bool hasInstance() { return isInstance; };

	void process(AudioBuffer<float>& sourceBuffer);
	void prepare(double samplerate, Point3d dimensions, Point3d sourcePos, Point3d playerPos, int nChannels, int numSamples);

private:

	void initRoom();
	void timeStep();
	void processNodes();
	void processListener(int nChannels, AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex);


	int wallNumber = 6;
	WaveGuide sourceListener;
	std::vector<WaveGuide> sourceNode;
	std::vector<WaveGuide> NodeToNode;
	std::vector<WaveGuide> nodeListener;

	std::vector<ScatteringNode> wallNodes;

	Source source;
	Listener player;

	bool isInstance = false;
	Point3d dimensions = { 0, 0, 0 };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Room);
};

