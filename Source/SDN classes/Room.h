#pragma once
#include "WaveGuide.h"
#include "Listener.h"
#include "Source.h"

class Room
{

private:
	int wallNumber;
	std::vector<WaveGuide> sourceNode;
	std::vector<WaveGuide> NodeToNode;
	std::vector<WaveGuide> nodeListener;

	std::vector<AudioBuffer<float>> currentNodeBuffers;

	std::vector< std::shared_ptr<ScatteringNode>> wallNodes;

	std::shared_ptr<Source> source;
	std::shared_ptr<Listener> player;

	bool isInstance = false;
	Point3d dimensions;

public:
	Room() {};
	Room(Point3d dimensions, std::shared_ptr<Source> source, std::shared_ptr<Listener> player);

	int getNumberOfWalls() { return wallNumber; };
	void setNumberOfWalls(int newWalls) { wallNumber = newWalls; };

	std::shared_ptr<Source> getSource() { return source; };
	std::shared_ptr<Listener> getPlayer() { return player; };

	bool hasInstance() { return isInstance; };

	void process(AudioBuffer<float>& sourceBuffer);
	void prepare(double samplerate);
	void printTest();
};

