#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <Eigen/Geometry>

#define forward Eigen::Vector3f(0, 0, 1)

class RoomPlane : public juce::Component, public juce::Timer
{
public:
    RoomPlane(RealtimeSDNAudioProcessor& p, juce::AudioProcessorValueTreeState& vts,
        char horizAxis, char vertAxis, char depthAxis, bool negateDepth);
    ~RoomPlane();

    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;

    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;

    void setRotationEnabled(bool shouldBeRotating)
    {
        rotationEnabled = shouldBeRotating;
        updateRotation();
        repaint();
    }

private:

    float horizontalPosToPointCoord(juce::String positionParam);
    float verticalPosToPointCoord(juce::String positionParam);
    float getRoomAspectRatio();
    void positionChangeOnMouseDrag(const juce::MouseEvent& event, juce::String& horizontalParam, juce::String& veticalParam);
    void updatePlaneCoords();
    void updateRotation();

    RealtimeSDNAudioProcessor& processor;
    juce::AudioProcessorValueTreeState& valueTreeState;
    
    juce::String horizontalAxis, verticalAxis;
    juce::String listenerHorizParam, listenerVertParam, sourceHorizParam, sourceVertParam;
    
    float drawableAspectRatio = 1.0f;
    float figureSize = 0.0f;
    float arrowHeadsize = 1.0f;
    juce::Line<float> widthArrow, heightArrow;
    juce::Rectangle<int> roomArea, maxRoomArea, horizTextRect, vertTextRect;
    juce::Rectangle<float> listenerRect, sourceRect, listenerRotRect;
    Eigen::Matrix3f listenerRot;
    Eigen::Vector3f rotatedListener;
    float *horizRot, *vertRot, *depthRot;
    bool nDepth;

    bool movingListener = false, 
        movingSource = false,
        rotationEnabled = true;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoomPlane)
};
