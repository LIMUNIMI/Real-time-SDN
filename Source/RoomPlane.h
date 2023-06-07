#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


class RoomPlane : public juce::Component, public Timer
{
public:
    RoomPlane(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, char horizAxis, char vertAxis);
    ~RoomPlane();

    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;

private:

    float verticalPosToPointCoord(String positionParam);
    float horizontalPosToPointCoord(String positionParam);
    float getRoomAspectRatio();

    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    char horizontalAxis, verticalAxis;
    float drawableAspectRatio = 1.0f;
    juce::Rectangle<int> roomArea; 
    juce::Rectangle<float> sourceRect;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoomPlane)
};
