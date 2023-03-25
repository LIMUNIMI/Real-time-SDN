#pragma once
#include "Point3d.h"
#include <Parameters.h>
#include <JuceHeader.h>

//normalized and smoothed position for any node object
class NormalPosition
{
public:
	NormalPosition();
	~NormalPosition() {};

	void initRange(int samplerate, Point3d& startNormalPos, Point3d dimensions);

	//update current smoothed value to reflect now environment scale
	void scaleToDim(float newValue, const char& axis);
	//set new position in normalized values
	void setNormalPos(float newPos, Point3d& dimensions, const char& axis);

	Point3d getSmoothedPos() { return { smoothedX.getNextValue(), smoothedY.getNextValue(), smoothedZ.getNextValue()}; };
	
	//returns true if any axis is changing in value
	bool isChanging() { return smoothedX.isSmoothing() || smoothedY.isSmoothing() || smoothedZ.isSmoothing(); };

private:
	

	Point3d normalPos;
	SmoothedValue<float, ValueSmoothingTypes::Linear> smoothedX, smoothedY, smoothedZ;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NormalPosition)

};