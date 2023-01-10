#include "Room.h"
#include <MathUtils.h>


Room::Room()
{
	int numConnectionsPerNode = Parameters::NUM_WALLS - 1;

	wallNodes = std::vector<ScatteringNode>(Parameters::NUM_WALLS);
	sourceNode = std::vector<WaveGuide>(Parameters::NUM_WALLS);
	nodeListener = std::vector<WaveGuide>(Parameters::NUM_WALLS);
	NodeToNode = std::vector<WaveGuide>(Parameters::NUM_WALLS * (numConnectionsPerNode));
}

void Room::setListenerPos(float newPos, const char& axis)
{
	player.setNormalPos(newPos, dimensions, axis);
	hasChanged = true;
}

void Room::setListenerRotation(float newValue, const char& axis)
{
	player.setRotation(DEG2RAD(newValue), axis);
	player.updateQuaternion();
}

void Room::setSourcePos(float newPos, const char& axis)
{
	source.setNormalPos(newPos, dimensions, axis);
	hasChanged = true;
}

void Room::setDimensions(float newValue, const char& axis)
{
	source.scaleToDim(newValue, axis);
	player.scaleToDim(newValue, axis);
	switch (axis)
	{
		case 'x':
			dimensions.x = newValue;
			break;
		case 'y':
			dimensions.y = newValue;
			break;
		case 'z':
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

void Room::setWallFreqAbsorption(float newValue, int wallIndex, int freqIndex)
{
	wallNodes[wallIndex].setFreqAbsorption(newValue, freqIndex);
	wallNodes[wallIndex].updateFilterCoeffs(source.getSamplerate());
}

void Room::initWalls(double samplerate)
{
	//setNumberOfWalls(6);
	//char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };
	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	int nChann = source.getNChannels();
	int numConnectionsPerNode = Parameters::NUM_WALLS - 1;

	//sourceNode = std::vector<WaveGuide>(wallNumber);
	//nodeListener = std::vector<WaveGuide>(wallNumber);
	//NodeToNode = std::vector<WaveGuide>(wallNumber * (numConnectionsPerNode));

	//wallNodes = std::vector<ScatteringNode>(wallNumber);

	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{

		Point3d refl = MathUtils::reflectionPoint(source.getPosition(), player.getPosition(), Parameters::axishelper[i], dimHelper[i]);
		wallNodes[i].init(samplerate, refl, nChann, numConnectionsPerNode, &sourceNode[i], &nodeListener[i]);

	}
}

void Room::initVariables(int numSamples)
{
	currentSample.setSize(source.getNChannels(), 1);
}

void Room::initWaveguides(double samplerate)
{

	int nChann = source.getNChannels();
	int numConnectionsPerNode = Parameters::NUM_WALLS - 1;

	float sourceListenerDist = MathUtils::distanceCalc(source.getPosition(), player.getPosition());
	sourceListener.prepare(samplerate, nChann, &source, &player, sourceListenerDist);
	sourceListener.setAttenuation(1 / sourceListenerDist);
	source.outWaveguides[Parameters::NUM_WALLS] = &sourceListener;
	player.inWaveguides[Parameters::NUM_WALLS] = &sourceListener;

	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		float sourceNodeDistance = MathUtils::distanceCalc(source.getPosition(), wallNodes[i].getPosition());
		float nodeListenerDistance = MathUtils::distanceCalc(wallNodes[i].getPosition(), player.getPosition());

		sourceNode[i].prepare(samplerate, nChann, &source, &wallNodes[i], sourceNodeDistance);
		sourceNode[i].setAttenuation(1 / sourceNodeDistance);
		source.outWaveguides[i] = &sourceNode[i];

		nodeListener[i].prepare(samplerate, nChann, &wallNodes[i], &player, nodeListenerDistance);
		nodeListener[i].setAttenuation(1 / (1 + (nodeListenerDistance / sourceNodeDistance)));
		player.inWaveguides[i] = &nodeListener[i];

		for (int j = i + 1; j < Parameters::NUM_WALLS; j++)
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
	source.init(sourcePos, nChannels, numSamples, Parameters::NUM_WALLS + 1, samplerate);
	player.init(playerPos, numSamples, Parameters::NUM_WALLS + 1);

	initVariables(numSamples);
	initWalls(samplerate);
	initWaveguides(samplerate);
	
}

void Room::updatePositions()
{
	int numConnectionsPerNode = Parameters::NUM_WALLS - 1;

	source.updatePosition();
	player.updatePosition();

	//char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };

	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		Point3d refl = MathUtils::reflectionPoint(source.getPosition(), player.getPosition(), Parameters::axishelper[i], dimHelper[i]);
		wallNodes[i].setPosition(refl);
	}

	float sourceListenerDist = MathUtils::distanceCalc(source.getPosition(), player.getPosition());
	sourceListener.setDistance(sourceListenerDist);
	sourceListener.setAttenuation(1 / sourceListenerDist);


	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		float sourceNodeDistance = MathUtils::distanceCalc(source.getPosition(), wallNodes[i].getPosition());
		float nodeListenerDistance = MathUtils::distanceCalc(wallNodes[i].getPosition(), player.getPosition());

		sourceNode[i].setDistance(sourceNodeDistance);
		sourceNode[i].setAttenuation(1 / sourceNodeDistance);
		nodeListener[i].setDistance(nodeListenerDistance);
		nodeListener[i].setAttenuation(1 / (1 + (nodeListenerDistance / sourceNodeDistance)));

		for (int j = i + 1; j < Parameters::NUM_WALLS; j++)
		{
			float nodeDist = MathUtils::distanceCalc(wallNodes[j].getPosition(), wallNodes[i].getPosition());

			NodeToNode[(j * numConnectionsPerNode) + i].setDistance(nodeDist); //j node to i node

			NodeToNode[(i * numConnectionsPerNode) + (j - 1)].setDistance(nodeDist); //i node to j node

		}
	}

	hasChanged = player.isChanging() || source.isChanging();
}

void Room::process(AudioBuffer<float>& sourceBuffer)
{

	int bufferDim = sourceBuffer.getNumSamples();
	int nChannels = sourceBuffer.getNumChannels();
	int maxIndex = bufferDim - 1;
	const float** currentReadPointers = currentSample.getArrayOfReadPointers();
	
	if (hasChanged)
	{
		for (int i = 0; i < bufferDim; i++)
		{
			updatePositions();
			processSample(sourceBuffer, currentReadPointers, nChannels, i, maxIndex);
		}
	}
	else
	{
		for (int i = 0; i < bufferDim; i++)
		{
			processSample(sourceBuffer, currentReadPointers, nChannels, i, maxIndex);
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

void Room::processSample(AudioBuffer<float>& sourceBuffer, const float** currentReadPointers, int nChannels, int sampleIndex, int maxIndex)
{
	source.process(currentSample, sourceBuffer, currentReadPointers, sampleIndex);
	processNodes();
	player.process(nChannels, currentSample, sourceBuffer, sampleIndex, maxIndex);
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

	player.sync();

}