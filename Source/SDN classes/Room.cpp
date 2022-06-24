#include "Room.h"

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

Room::Room(Point3d dimensions, std::shared_ptr<Source> source, std::shared_ptr<Listener> player):
	source(source),
	player(player),
	dimensions(dimensions)
{
	
	setNumberOfWalls(6);
	char axishelper[6] = {'x', 'x', 'y', 'y', 'z', 'z'};
	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	int bufferSize = source->getBufferSize();
	int nChann = source->getNChannels();
	int numConnectionsPerNode = wallNumber - 1;

	sourceNode = std::vector<WaveGuide>( wallNumber);
	nodeListener = std::vector<WaveGuide>(wallNumber);
	NodeToNode = std::vector<WaveGuide>(wallNumber * (numConnectionsPerNode));

	wallNodes = std::vector<std::shared_ptr<ScatteringNode>>(wallNumber);
	currentNodeBuffers = std::vector<AudioBuffer<float>>(wallNumber);

	for (int i = 0; i < wallNumber; i++)
	{

		Point3d refl = reflectionPoint(source->getPosition(), player->getPosition(), axishelper[i], dimHelper[i]);
		printf("(%f, %f, %f)", refl.x, refl.y, refl.z);
		wallNodes[i] = std::make_shared<ScatteringNode>(ScatteringNode(refl, nChann, bufferSize));
		sourceNode[i] =  WaveGuide(source, wallNodes[i]);
		nodeListener[i] =  WaveGuide(wallNodes[i], player);
		for (int j = 0; j < i; j++)
		{
			NodeToNode[(j * (numConnectionsPerNode)) + (i - 1)] =  WaveGuide(wallNodes[j], wallNodes[i]);
			NodeToNode[(i * (numConnectionsPerNode)) + j] =  WaveGuide(wallNodes[i], wallNodes[j]);
		}

		currentNodeBuffers[i] = AudioBuffer<float>(nChann, bufferSize);
		currentNodeBuffers[i].clear();
	}
	isInstance = true;
	//for (int i = 0; i < wallNumber * (numConnectionsPerNode); i++)
		//printf("(%f, %f) ", NodeToNode[i]->getStart()->getPosition().y, NodeToNode[i]->getEnd()->getPosition().y);

}

void Room::prepare(double samplerate)
{
	int bufferSize = source->getBufferSize();
	int nChann = source->getNChannels();
	int numConnectionsPerNode = wallNumber - 1;

	for (int i = 0; i < wallNumber; i++)
	{
		sourceNode[i].prepare(samplerate, bufferSize, nChann);
		nodeListener[i].prepare(samplerate, bufferSize, nChann);
		for (int j = 0; j < numConnectionsPerNode; j++)
		{
			NodeToNode[(i * (numConnectionsPerNode)) + j].prepare(samplerate, bufferSize, nChann, wallNumber);
		}
	}
}

void Room::process(AudioBuffer<float>& sourceBuffer)
{
	int numConnectionsPerNode = wallNumber - 1;
	sourceBuffer.applyGain(2.5);
	getPlayer()->cleanBuffer();


	for (int i = 0; i < wallNumber; i++)
	{
		currentNodeBuffers[i].makeCopyOf(*wallNodes[i]->getBuffer());
		wallNodes[i]->cleanBuffer();
	}

	for (int i = 0; i < wallNumber; i++)
	{
		sourceNode[i].process(sourceBuffer);

		//currentNodeBuffers[i].applyGain(0.6);
		nodeListener[i].process(currentNodeBuffers[i]);


		
		for (int j = 0; j < numConnectionsPerNode; j++)
		{
			NodeToNode[(i * numConnectionsPerNode) + j].process(currentNodeBuffers[i]);
		}

		/*int numSamples = getPlayer()->getBuffer()->getNumSamples();
		for (int channel = 0; channel < getPlayer()->getBuffer()->getNumChannels(); ++channel)
		{
			auto* channelData = getPlayer()->getBuffer()->getReadPointer(channel);
			for (int j = 0; j < numSamples; j++)
			{
				printf(" %f ", channelData[j]);
			}
		}*/
	}
}

void Room::printTest()
{
	for (int i = 0; i < wallNumber; i++)
		printf("(%f, %f) ", nodeListener[i].getStart()->getPosition().y, nodeListener[i].getEnd()->getPosition().y);

}