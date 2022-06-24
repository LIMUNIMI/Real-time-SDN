#pragma once
#include "Point3d.h"
#include "HasBuffer.h"
#include <JuceHeader.h>

class ScatteringNode : public HasBuffer
{
public:
	ScatteringNode();
	ScatteringNode(Point3d position, int numChannels, int numSamples);
	ScatteringNode(Point3d SourcePos, Point3d ListenerPos, int numChannels, int numSamples);
};

