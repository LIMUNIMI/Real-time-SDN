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

    void mouseDown(const MouseEvent& event) override;
    void mouseDrag(const MouseEvent& event) override;
    void mouseUp(const MouseEvent& event) override;

private:

    float horizontalPosToPointCoord(String positionParam);
    float verticalPosToPointCoord(String positionParam);
    float getRoomAspectRatio();
    void positionChangeOnMouseDrag(const MouseEvent& event, String& horizontalParam, String& veticalParam);

    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    
    char horizontalAxis, verticalAxis;
    String listenerHorizParam, listenerVertParam, sourceHorizParam, sourceVertParam;
    
    float drawableAspectRatio = 1.0f;
    float figureSize = 0.0f;
    juce::Rectangle<int> roomArea; 
    juce::Rectangle<float> listenerRect, sourceRect;

    bool movingListener = false, 
        movingSource = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoomPlane)
};
