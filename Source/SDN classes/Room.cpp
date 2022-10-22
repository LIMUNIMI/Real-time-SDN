#include "Room.h"

#define SOUND_SPEED 343

Point3d dirVector(Point3d a, Point3d b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

Point3d reflectionPoint(Point3d a, Point3d b, char reflAxis, float wallPosition)
{
	Point3d direction;
	float positionParam;

	switch (reflAxis)
	{
	case 'x':
		a.x = (2 * wallPosition) - a.x;
		direction = dirVector(a, b);
		positionParam = (wallPosition - a.x) / direction.x;
		return { wallPosition, a.y + direction.y * positionParam, a.z + direction.z * positionParam };
		break;

	case 'y':
		a.y = (2 * wallPosition) - a.y;
		direction = dirVector(a, b);
		positionParam = (wallPosition - a.y) / direction.y;
		return { a.x + direction.x * positionParam, wallPosition, a.z + direction.z * positionParam };
		break;

	case 'z':
		a.z = (2 * wallPosition) - a.z;
		direction = dirVector(a, b);
		positionParam = (wallPosition - a.z) / direction.z;
		return { a.x + direction.x * positionParam, a.y + direction.y * positionParam, wallPosition };
		break;
	}

	return { 0, 0, 0 };

}

float distanceCalc(Point3d startPos, Point3d endPos)
{
	float distance = sqrt(pow((startPos.x - endPos.x), 2) + pow((startPos.y - endPos.y), 2)
		+ pow((startPos.z - endPos.z), 2));

	if (distance < 1) distance = 1.0f;

	return distance;
}

void Room::initRoom()
{
	setNumberOfWalls(6);
	char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };
	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	int bufferSize = source.getBufferSize();
	int nChann = source.getNChannels();
	int numConnectionsPerNode = wallNumber - 1;

	sourceNode = std::vector<WaveGuide>(wallNumber);
	nodeListener = std::vector<WaveGuide>(wallNumber);
	NodeToNode = std::vector<WaveGuide>(wallNumber * (numConnectionsPerNode));

	wallNodes = std::vector<ScatteringNode>(wallNumber);
	currentNodeBuffers = std::vector<AudioBuffer<float>>(wallNumber);

	for (int i = 0; i < wallNumber; i++)
	{

		Point3d refl = reflectionPoint(source.getPosition(), player.getPosition(), axishelper[i], dimHelper[i]);
		wallNodes[i].init(refl, nChann, bufferSize, numConnectionsPerNode, &sourceNode[i], &nodeListener[i]);

		currentNodeBuffers[i].setSize(nChann, bufferSize);
		currentNodeBuffers[i].clear();
	}
	isInstance = true;
}

void Room::prepare(double samplerate, Point3d dimensions, Point3d sourcePos, Point3d playerPos, int nChannels, int numSamples)
{
	this->dimensions = dimensions;
	source.init(sourcePos, nChannels, numSamples);
	player.init(playerPos, nChannels, numSamples);

	initRoom();

	int bufferSize = source.getBufferSize();
	int nChann = source.getNChannels();
	int numConnectionsPerNode = wallNumber - 1;

	float sourceListenerDist = distanceCalc(source.getPosition(), player.getPosition());
	sourceListener.prepare(samplerate, bufferSize, nChann, &source, &player, sourceListenerDist);
	sourceListener.setAttenuation(1 / sourceListenerDist);

	for (int i = 0; i < wallNumber; i++)
	{
		float sourceNodeDistance = distanceCalc(source.getPosition(), wallNodes[i].getPosition());
		float nodeListenerDistance = distanceCalc(wallNodes[i].getPosition(), player.getPosition());

		sourceNode[i].prepare(samplerate, bufferSize, nChann, &source, &wallNodes[i], sourceNodeDistance);
		sourceNode[i].setAttenuation(1 / sourceNodeDistance);
		nodeListener[i].prepare(samplerate, bufferSize, nChann, &wallNodes[i], &player, nodeListenerDistance);
		nodeListener[i].setAttenuation( 1 / (1 + (nodeListenerDistance / sourceNodeDistance)));

		for (int j = i + 1; j < wallNumber; j++)
		{
			float nodeDist = distanceCalc(wallNodes[j].getPosition(), wallNodes[i].getPosition());

			wallNodes[i].inWaveguides[(j - 1)] = &NodeToNode[(j * numConnectionsPerNode) + i]; //j node goes to i node
			wallNodes[j].outWaveguides[i] = wallNodes[i].inWaveguides[(j - 1)];

			wallNodes[i].outWaveguides[(j - 1)] = &NodeToNode[(i * numConnectionsPerNode) + (j - 1)]; //i node goes to j node
			wallNodes[j].inWaveguides[i] = wallNodes[i].outWaveguides[(j - 1)];

			wallNodes[i].inWaveguides[(j - 1)]->prepare(samplerate, bufferSize, nChann,
				&wallNodes[j], &wallNodes[i],nodeDist);
			wallNodes[i].inWaveguides[(j - 1)]->setAttenuation(1.0f);

			wallNodes[i].outWaveguides[(j - 1)]->prepare(samplerate, bufferSize, nChann,
				&wallNodes[i], &wallNodes[j], nodeDist);
			wallNodes[i].outWaveguides[(j - 1)]->setAttenuation(1.0f);

		}
	}
}

void Room::process(AudioBuffer<float>& sourceBuffer)
{
	player.cleanBuffer();
	int bufferDim = sourceBuffer.getNumSamples();
	int nChannels = sourceBuffer.getNumChannels();
	int numConnectionsPerNode = wallNumber - 1;
	AudioBuffer<float> currentSample;
	AudioBuffer<float> temp;
	
	for (int i = 0; i < bufferDim; i++)
	{
		currentSample.clear();
		temp.clear();
		currentSample.setSize(nChannels, 1);
		
		for (int ch = 0; ch < nChannels; ch++)
		{
			currentSample.copyFrom(ch, 0, sourceBuffer, ch, i, 1);
		}

		temp.makeCopyOf(currentSample);
		sourceListener.pushNextSample(temp);

		for (WaveGuide& guide : sourceNode)
		{
			temp.makeCopyOf(currentSample);
			guide.pushNextSample(temp);
		}

		processNodes();

		processListener(nChannels, currentSample, sourceBuffer, i);

		timeStep();
	}


}

void Room::processNodes()
{
	for (ScatteringNode& node : wallNodes)
	{
		node.process();
	}
}

void Room::processListener(int nChannels, AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex)
{
	currentSample.clear();

	for (int ch = 0; ch < nChannels; ch++)
	{
		float sampleToAdd = sourceListener.getCurrentSample()[ch];
		currentSample.addSample(ch, 0, sampleToAdd);
	}

	for (WaveGuide& guide : nodeListener)
	{
		for (int ch = 0; ch < nChannels; ch++)
		{
			float sampleToAdd = guide.getCurrentSample()[ch];
			currentSample.addSample(ch, 0, sampleToAdd);
		}
	}

	for (int ch = 0; ch < nChannels; ch++)
	{
		sourceBuffer.copyFrom(ch, sampleIndex, currentSample, ch, 0, 1);
	}
}

void Room::timeStep()
{

	for (WaveGuide& guide : sourceNode)
	{
		guide.stepForward();
	}

	for (WaveGuide& guide : NodeToNode)
	{
		guide.stepForward();
	}

	for (WaveGuide& guide : nodeListener)
	{
		guide.stepForward();
	}

	sourceListener.stepForward();

}