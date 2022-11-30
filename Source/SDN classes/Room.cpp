#include "Room.h"
#include <MathUtils.h>

void Room::setListenerPos(float newPos, const char& axis)
{
	switch (axis)
	{
		case 'x':
			listenerX.setTargetValue(newPos * dimensions.x);
			break;
		case 'y':
			listenerY.setTargetValue(newPos * dimensions.y);
			break;
		case 'z':
			listenerZ.setTargetValue(newPos * dimensions.z);
			break;
		default:
			break;
	}

	hasChanged = true;
}

void Room::setSourcePos(float newPos, const char& axis)
{
	switch (axis)
	{
		case 'x':
			sourceX.setTargetValue(newPos * dimensions.x);
			break;
		case 'y':
			sourceY.setTargetValue(newPos * dimensions.y);
			break;
		case 'z':
			sourceZ.setTargetValue(newPos * dimensions.z);
			break;
		default:
			break;
	}

	hasChanged = true;
}

void Room::setDimensions(float newValue, const char& axis)
{
	switch (axis)
	{
		case 'x':
			sourceX.setCurrentAndTargetValue((source.getPosition().x / dimensions.x) * newValue);
			listenerX.setCurrentAndTargetValue((player.getPosition().x / dimensions.x) * newValue);
			dimensions.x = newValue;
			break;
		case 'y':
			sourceY.setCurrentAndTargetValue((source.getPosition().y / dimensions.y) * newValue);
			listenerY.setCurrentAndTargetValue((player.getPosition().y / dimensions.y) * newValue);
			dimensions.y = newValue;
			break;
		case 'z':
			sourceZ.setCurrentAndTargetValue((source.getPosition().z / dimensions.z) * newValue);
			listenerZ.setCurrentAndTargetValue((player.getPosition().z / dimensions.z) * newValue);
			dimensions.z = newValue;
			break;
		default:
			break;
	}

	hasChanged = true;
}

void Room::setWallAbsorption(float newValue)
{
	for ( ScatteringNode& wall : wallNodes )
	{
		wall.setAbsorption(1 - newValue);
	}
}

void Room::initWalls(double samplerate, std::vector<float>& octaveCoeffs)
{
	setNumberOfWalls(6);
	char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };
	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	int nChann = source.getNChannels();
	int numConnectionsPerNode = wallNumber - 1;

	sourceNode = std::vector<WaveGuide>(wallNumber);
	nodeListener = std::vector<WaveGuide>(wallNumber);
	NodeToNode = std::vector<WaveGuide>(wallNumber * (numConnectionsPerNode));

	wallNodes = std::vector<ScatteringNode>(wallNumber);

	for (int i = 0; i < wallNumber; i++)
	{

		Point3d refl = MathUtils::reflectionPoint(source.getPosition(), player.getPosition(), axishelper[i], dimHelper[i]);
		wallNodes[i].init(samplerate, refl, nChann, numConnectionsPerNode, &sourceNode[i], &nodeListener[i], octaveCoeffs);

	}
}

void Room::initVariables(int numSamples)
{
	sourceX.reset(numSamples);
	sourceY.reset(numSamples);
	sourceZ.reset(numSamples);
	listenerX.reset(numSamples);
	listenerY.reset(numSamples);
	listenerZ.reset(numSamples);

	sourceX.setCurrentAndTargetValue(source.getPosition().x);
	sourceY.setCurrentAndTargetValue(source.getPosition().y);
	sourceZ.setCurrentAndTargetValue(source.getPosition().z);
	listenerX.setCurrentAndTargetValue(player.getPosition().x);
	listenerY.setCurrentAndTargetValue(player.getPosition().y);
	listenerZ.setCurrentAndTargetValue(player.getPosition().z);

	currentSample.setSize(source.getNChannels(), 1);
}

void Room::initWaveguides(double samplerate)
{

	int nChann = source.getNChannels();
	int numConnectionsPerNode = wallNumber - 1;

	float sourceListenerDist = MathUtils::distanceCalc(source.getPosition(), player.getPosition());
	sourceListener.prepare(samplerate, nChann, &source, &player, sourceListenerDist);
	sourceListener.setAttenuation(1 / sourceListenerDist);
	source.outWaveguides[wallNumber] = &sourceListener;
	player.inWaveguides[wallNumber] = &sourceListener;

	for (int i = 0; i < wallNumber; i++)
	{
		float sourceNodeDistance = MathUtils::distanceCalc(source.getPosition(), wallNodes[i].getPosition());
		float nodeListenerDistance = MathUtils::distanceCalc(wallNodes[i].getPosition(), player.getPosition());

		sourceNode[i].prepare(samplerate, nChann, &source, &wallNodes[i], sourceNodeDistance);
		sourceNode[i].setAttenuation(1 / sourceNodeDistance);
		source.outWaveguides[i] = &sourceNode[i];

		nodeListener[i].prepare(samplerate, nChann, &wallNodes[i], &player, nodeListenerDistance);
		nodeListener[i].setAttenuation(1 / (1 + (nodeListenerDistance / sourceNodeDistance)));
		player.inWaveguides[i] = &nodeListener[i];

		for (int j = i + 1; j < wallNumber; j++)
		{
			float nodeDist = MathUtils::distanceCalc(wallNodes[j].getPosition(), wallNodes[i].getPosition());

			wallNodes[i].inWaveguides[(j - 1)] = &NodeToNode[(j * numConnectionsPerNode) + i]; //j node to i node
			wallNodes[j].outWaveguides[i] = wallNodes[i].inWaveguides[(j - 1)];

			wallNodes[i].outWaveguides[(j - 1)] = &NodeToNode[(i * numConnectionsPerNode) + (j - 1)]; //i node to j node
			wallNodes[j].inWaveguides[i] = wallNodes[i].outWaveguides[(j - 1)];

			wallNodes[i].inWaveguides[(j - 1)]->prepare(samplerate, nChann,
				&wallNodes[j], &wallNodes[i], nodeDist);
			wallNodes[i].inWaveguides[(j - 1)]->setAttenuation(1.0f);

			wallNodes[i].outWaveguides[(j - 1)]->prepare(samplerate, nChann,
				&wallNodes[i], &wallNodes[j], nodeDist);
			wallNodes[i].outWaveguides[(j - 1)]->setAttenuation(1.0f);

		}
	}

}

void Room::prepare(double samplerate, Point3d dimensions, Point3d sourcePos, Point3d playerPos, int nChannels, int numSamples)
{
	this->dimensions = dimensions;
	source.init(sourcePos, nChannels, numSamples, wallNumber + 1);
	player.init(playerPos, wallNumber + 1);
	std::vector<float> octaveCoeffs{ 0.3f, 0.3f, 0.3f, 0.4f, 0.5f, 0.7f };

	initVariables(numSamples);
	initWalls(samplerate, octaveCoeffs);
	initWaveguides(samplerate);
	
}

void Room::updatePositions()
{
	int numConnectionsPerNode = wallNumber - 1;

	source.setX(sourceX.getNextValue());
	source.setY(sourceY.getNextValue());
	source.setZ(sourceZ.getNextValue());
	player.setX(listenerX.getNextValue());
	player.setY(listenerY.getNextValue());
	player.setZ(listenerZ.getNextValue());

	char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };
	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	for (int i = 0; i < wallNumber; i++)
	{
		Point3d refl = MathUtils::reflectionPoint(source.getPosition(), player.getPosition(), axishelper[i], dimHelper[i]);
		wallNodes[i].setPosition(refl);
	}

	float sourceListenerDist = MathUtils::distanceCalc(source.getPosition(), player.getPosition());
	sourceListener.setDistance(sourceListenerDist);
	sourceListener.setAttenuation(1 / sourceListenerDist);


	for (int i = 0; i < wallNumber; i++)
	{
		float sourceNodeDistance = MathUtils::distanceCalc(source.getPosition(), wallNodes[i].getPosition());
		float nodeListenerDistance = MathUtils::distanceCalc(wallNodes[i].getPosition(), player.getPosition());

		sourceNode[i].setDistance(sourceNodeDistance);
		sourceNode[i].setAttenuation(1 / sourceNodeDistance);
		nodeListener[i].setDistance(nodeListenerDistance);
		nodeListener[i].setAttenuation(1 / (1 + (nodeListenerDistance / sourceNodeDistance)));

		for (int j = i + 1; j < wallNumber; j++)
		{
			float nodeDist = MathUtils::distanceCalc(wallNodes[j].getPosition(), wallNodes[i].getPosition());

			NodeToNode[(j * numConnectionsPerNode) + i].setDistance(nodeDist); //j node to i node

			NodeToNode[(i * numConnectionsPerNode) + (j - 1)].setDistance(nodeDist); //i node to j node

		}
	}
}

void Room::process(AudioBuffer<float>& sourceBuffer)
{

	int bufferDim = sourceBuffer.getNumSamples();
	int nChannels = sourceBuffer.getNumChannels();
	const float** currentReadPointers = currentSample.getArrayOfReadPointers();
	
	if (hasChanged)
	{
		for (int i = 0; i < bufferDim; i++)
		{
			updatePositions();
			processSample(sourceBuffer, currentReadPointers, nChannels, i);
		}

		hasChanged = false;
	}
	else
	{
		for (int i = 0; i < bufferDim; i++)
		{
			processSample(sourceBuffer, currentReadPointers, nChannels, i);
		}
	}

}

void Room::processNodes()
{
	for (ScatteringNode& node : wallNodes)
	{
		node.process();
	}
}

void Room::processSample(AudioBuffer<float>& sourceBuffer, const float** currentReadPointers, int nChannels, int sampleIndex)
{
	source.process(currentSample, sourceBuffer, currentReadPointers, sampleIndex);
	processNodes();
	player.process(nChannels, currentSample, sourceBuffer, sampleIndex);
	timeStep();
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