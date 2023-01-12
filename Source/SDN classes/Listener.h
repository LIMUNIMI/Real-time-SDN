#pragma once
#include "Point3d.h"
#include "Node.h"
#include "NormalPosition.h"
#include <WaveGuide.h>
#include "MathUtils.h"
#include <Eigen/Geometry>

class Listener : public Node, public NormalPosition
{
public:

	Listener();
	~Listener() {};

	void init(Point3d normalPosition, int bufferSize, int nOfConnections, Point3d dimensions);
	void process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex);

	void updatePosition();
	void setRotation(float newValue, const char axis);
	//void updateRotationMatrix();
	void updateQuaternion();
	void sync();

	Eigen::Vector3f forward = Eigen::Vector3f(0, 0, 1);
	std::vector<WaveGuide*> inWaveguides;

private:

	std::vector<float> monoToStereoDummy;
	Eigen::Quaternionf prevRotation, targetRotation;
	Eigen::Matrix3f currentRotation;
	//Matrix3D<float> rotationMatrix;
	Eigen::Vector3f xyzRotation, playerToNodeVector;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Listener);

};

