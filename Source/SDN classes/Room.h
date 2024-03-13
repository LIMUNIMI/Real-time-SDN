#pragma once
#include <WaveGuide.h>
#include <Receiver.h>
#include <Source.h>
#include <ScatteringNode.h>

class Room
{

public:
	Room();
	~Room() { };

	Source* getSource() { return &source; };
	Receiver* getPlayer() { return &receiver; };

	//initialize all SDN components
	void prepare(double samplerate, Point3d dimensions, Point3d sourcePos, Point3d playerPos, int nChannels, int numSamples);
	
	//main SDN processing function
	void process(AudioBuffer<float>& sourceBuffer, int numInputChannels);


	void setSourcePos(float newPos, const char& axis);
	void setListenerPos(float newPos, const char& axis);
	void setListenerRotation(float newValue, const char& axis);
	void setDimensions(float newValue, const char& axis);
	void setWallFreqAbsorption(float newValue, int wallIndex, int freqIndex);
	void setSourceGain(float newValue);

	//choose output mode
	void setOutputMode(int mode, int numChannels);
	
	//mute and unmute LOS component
	void muteLOS(bool condition);

	void enableAirAbsorption(bool absorb);

#ifdef _BRT_LIBRARY_
	bool setHRTF(std::string& newPath);
#endif

	bool geometryHasChanged() { return hasChanged || receiver.isRotating(); }

private:

	//initialize wall nodes
	void initWalls(double samplerate);

	//initialize waveguides and link to correct wall nodes
	void initWaveguides(double samplerate);

	//recalculate position of wall nodes and update variables accordingly
	void updatePositions();

	//process a sample insertion into the system
	void processSample(AudioBuffer<float>& sourceBuffer, const float* currentReadPointer, int sampleIndex, int maxIndex);

	//process wall nodes
	void processNodes();
	
	//advance simulation by one sample
	void timeStep();


	bool hasChanged = false;

	WaveGuide sourceListener;
	std::vector<WaveGuide> sourceNode;
	std::vector<WaveGuide> NodeToNode;
	std::vector<WaveGuide> nodeListener;

	std::vector<ScatteringNode> wallNodes;

	Source source;
	Receiver receiver;

	Point3d dimensions = { 0.0f, 0.0f, 0.0f };

	bool mutedLOS = false;
	float dimHelper[6] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Room);
};

