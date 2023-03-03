#pragma once
#include "Point3d.h"
#include <JuceHeader.h>

class NormalPosition
{
public:
	NormalPosition();
	~NormalPosition() {};

	void initRange(int numSamples, Point3d& startNormalPos, Point3d dimensions);

	void scaleToDim(float newValue, const char& axis);
	void setNormalPos(float newPos, Point3d& dimensions, const char& axis);

	Point3d getSmoothedPos() { return { smoothedX.getNextValue(), smoothedY.getNextValue(), smoothedZ.getNextValue()}; };
	bool isChanging() { return smoothedX.isSmoothing() || smoothedY.isSmoothing() || smoothedZ.isSmoothing(); };

private:
	

	Point3d normalPos;
	SmoothedValue<float, ValueSmoothingTypes::Linear> smoothedX, smoothedY, smoothedZ;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NormalPosition)

};