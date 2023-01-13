#include "Listener.h"
#include <Panner.h>

using namespace Eigen;

Listener::Listener()
{
	setPosition({ 0, 0, 0 });
	//newBuffer(0, 0);
}

void Listener::init(Point3d normalPosition, int bufferSize, int nOfConnections, Point3d dimensions)
{
	initRange(bufferSize, normalPosition, dimensions);
	setPosition(getSmoothedPos());
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);
	xyzRotation = Vector3f(0, 0, 0);
	prevRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	currentRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	playerToNodeVector = Vector3f(0, 0, 0);

	monoToStereoDummy = std::vector<float>(2, 0.0f);
	//rotationMatrix = Matrix3D<float>::rotation(xyzRotation);
	//newBuffer(nChannels, numSamples);
	//cleanBuffer();
}

void Listener::process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex)
{
	currentSample.clear();
	float panValue;
	currentRotation = prevRotation.slerp((float)sampleIndex / maxIndex, targetRotation).normalized().toRotationMatrix();

	for (WaveGuide* guide : inWaveguides)
	{
		playerToNodeVector = MathUtils::dirVector(guide->getStart()->getPosition(), getPosition());
		playerToNodeVector = currentRotation * playerToNodeVector;
		float azi = atan2f(playerToNodeVector.x(), playerToNodeVector.z());
		panValue = sin(azi);

		//float& guideSample = guide->getCurrentSample();

		monoToStereoDummy.at(0) = guide->getCurrentSample();
		monoToStereoDummy.at(1) = 0.0f;

		Panner::panMonoToStereo(monoToStereoDummy, panValue);

		for (int ch = 0; ch < currentSample.getNumChannels(); ch++)
		{
			float sampleToAdd = monoToStereoDummy[ch];
			currentSample.addSample(ch, 0, sampleToAdd);
		}
	}

	for (int ch = 0; ch < sourceBuffer.getNumChannels(); ch++)
	{
		sourceBuffer.copyFrom(ch, sampleIndex, currentSample, ch, 0, 1);
	}
}

void Listener::setRotation(float newValue, const char axis)
{

	switch (axis)
	{
	case 'x':
		xyzRotation.x() = newValue;
		break;
	case 'y':
		xyzRotation.y() = newValue;
		break;
	case 'z':
		xyzRotation.z() = newValue;
		break;
	}

}

//void Listener::updateRotationMatrix()
//{
//	rotationMatrix = Matrix3D<float>::rotation(xyzRotation);
//}

void Listener::updateQuaternion()
{
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
}

void Listener::sync()
{
	if(prevRotation != targetRotation) prevRotation = targetRotation;
}

void Listener::updatePosition()
{
	setPosition(getSmoothedPos());
}