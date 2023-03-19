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
	receiver.setNormalPos(newPos, dimensions, axis);
	hasChanged = true;
}

void Room::setListenerRotation(float newValue, const char& axis)
{
	receiver.setRotation(DEG2RAD(newValue), axis);
	receiver.updateQuaternion();
}

void Room::setSourcePos(float newPos, const char& axis)
{
	source.setNormalPos(newPos, dimensions, axis);
	hasChanged = true;
}

void Room::setDimensions(float newValue, const char& axis)
{
	source.scaleToDim(newValue, axis);
	receiver.scaleToDim(newValue, axis);
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
}

void Room::setOutputMode(int mode, int numChannels)
{
	receiver.setOutputMode(mode);
	currentSample.setSize(numChannels, 1);
	hasChanged = true;
}

//void Room::setAmbisonicOrder(int newOrder)
//{
//	receiver.setAmbisonicOrder(newOrder);
//}

void Room::initWalls(double samplerate)
{
	//setNumberOfWalls(6);
	//char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };
	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	int numConnectionsPerNode = Parameters::NUM_WALLS - 1;

	//sourceNode = std::vector<WaveGuide>(wallNumber);
	//nodeListener = std::vector<WaveGuide>(wallNumber);
	//NodeToNode = std::vector<WaveGuide>(wallNumber * (numConnectionsPerNode));

	//wallNodes = std::vector<ScatteringNode>(wallNumber);

	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{

		Point3d refl = MathUtils::reflectionPoint(source.getPosition(), receiver.getPosition(), Parameters::axishelper[i], dimHelper[i]);
		wallNodes[i].init(samplerate, refl, numConnectionsPerNode, &sourceNode[i], &nodeListener[i]);

	}
}

void Room::initVariables(int numSamples, int nChannels)
{
	currentSample.setSize(nChannels, 1);
}

void Room::initWaveguides(double samplerate)
{

	int numConnectionsPerNode = Parameters::NUM_WALLS - 1;

	float sourceListenerDist = MathUtils::distanceCalc(source.getPosition(), receiver.getPosition());
	sourceListener.prepare(samplerate, &source, &receiver, sourceListenerDist);
	sourceListener.setAttenuation(1 / sourceListenerDist);
	source.outWaveguides[Parameters::NUM_WALLS] = &sourceListener;
	receiver.inWaveguides[Parameters::NUM_WALLS] = &sourceListener;

	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		float sourceNodeDistance = MathUtils::distanceCalc(source.getPosition(), wallNodes[i].getPosition());
		float nodeListenerDistance = MathUtils::distanceCalc(wallNodes[i].getPosition(), receiver.getPosition());

		sourceNode[i].prepare(samplerate, &source, &wallNodes[i], sourceNodeDistance);
		sourceNode[i].setAttenuation(1 / sourceNodeDistance);
		source.outWaveguides[i] = &sourceNode[i];

		nodeListener[i].prepare(samplerate, &wallNodes[i], &receiver, nodeListenerDistance);
		nodeListener[i].setAttenuation(1 / (1 + (nodeListenerDistance / sourceNodeDistance)));
		receiver.inWaveguides[i] = &nodeListener[i];

		for (int j = i + 1; j < Parameters::NUM_WALLS; j++)
		{
			float nodeDist = MathUtils::distanceCalc(wallNodes[j].getPosition(), wallNodes[i].getPosition());

			wallNodes[i].inWaveguides[(j - 1)] = &NodeToNode[(j * numConnectionsPerNode) + i]; //j node to i node
			wallNodes[j].outWaveguides[i] = wallNodes[i].inWaveguides[(j - 1)];

			wallNodes[i].outWaveguides[(j - 1)] = &NodeToNode[(i * numConnectionsPerNode) + (j - 1)]; //i node to j node
			wallNodes[j].inWaveguides[i] = wallNodes[i].outWaveguides[(j - 1)];

			wallNodes[i].inWaveguides[(j - 1)]->prepare(samplerate, &wallNodes[j], &wallNodes[i], nodeDist);
			wallNodes[i].inWaveguides[(j - 1)]->setAttenuation(1.0f);

			wallNodes[i].outWaveguides[(j - 1)]->prepare(samplerate, &wallNodes[i], &wallNodes[j], nodeDist);
			wallNodes[i].outWaveguides[(j - 1)]->setAttenuation(1.0f);

		}
	}

}

void Room::prepare(double samplerate, Point3d dimensions, Point3d sourcePos, Point3d playerPos, int nChannels, int numSamples)
{
	this->dimensions = dimensions;
	source.init(sourcePos, numSamples, Parameters::NUM_WALLS + 1, samplerate, dimensions);
	receiver.init(playerPos, Parameters::NUM_WALLS + 1, samplerate, dimensions, nChannels);

	initVariables(numSamples, nChannels);
	initWalls(samplerate);
	initWaveguides(samplerate);
	
}

void Room::updatePositions()
{
	int numConnectionsPerNode = Parameters::NUM_WALLS - 1;

	source.updatePosition();
	receiver.updatePosition();

	//char axishelper[6] = { 'x', 'x', 'y', 'y', 'z', 'z' };

	float dimHelper[6] = { 0, dimensions.x, 0, dimensions.y, 0, dimensions.z };

	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		Point3d refl = MathUtils::reflectionPoint(source.getPosition(), receiver.getPosition(), Parameters::axishelper[i], dimHelper[i]);
		wallNodes[i].setPosition(refl);
	}

	float sourceListenerDist = MathUtils::distanceCalc(source.getPosition(), receiver.getPosition());
	sourceListener.setDistance(sourceListenerDist);
	sourceListener.setAttenuation(1 / sourceListenerDist);


	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		float sourceNodeDistance = MathUtils::distanceCalc(source.getPosition(), wallNodes[i].getPosition());
		float nodeListenerDistance = MathUtils::distanceCalc(wallNodes[i].getPosition(), receiver.getPosition());

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
}

void Room::process(AudioBuffer<float>& sourceBuffer, int numInputChannels)
{

	int bufferDim = sourceBuffer.getNumSamples();
	int nChannels = numInputChannels;

	if (nChannels >= 2)
	{
		for (int ch = 1; ch < nChannels; ch++)
		{
			sourceBuffer.addFrom(0, 0, sourceBuffer, ch, 0, bufferDim); // source to mono
		}
	}

	int maxIndex = bufferDim - 1;
	const float* currentReadPointer = currentSample.getReadPointer(0);
	
	if (hasChanged)
	{
		for (int i = 0; i < bufferDim; i++)
		{
			updatePositions();
			processSample(sourceBuffer, currentReadPointer, i, maxIndex);
			hasChanged = receiver.isChanging() || source.isChanging();
		}
	}
	else
	{
		for (int i = 0; i < bufferDim; i++)
		{
			processSample(sourceBuffer, currentReadPointer, i, maxIndex);
		}
	}

}

void Room::processNodes()
{
	for (ScatteringNode& node : wallNodes)
	{
		if (node.hasNewAbsorption())
			node.updateFilterCoeffs(source.getSamplerate());

		node.process();
	}
}

void Room::processSample(AudioBuffer<float>& sourceBuffer, const float* currentReadPointer, int sampleIndex, int maxIndex)
{
	source.process(currentSample, sourceBuffer, currentReadPointer, sampleIndex);
	processNodes();
	receiver.process(currentSample, sourceBuffer, sampleIndex, maxIndex, hasChanged);
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

	receiver.sync();

}