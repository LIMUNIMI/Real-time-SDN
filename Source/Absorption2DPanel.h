#pragma once

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <Eigen/Geometry>
#include "AbsorptionSpace.h"
#include <mutex>


class Absorption2DPanel : public juce::Component, public Timer
{
public:
    Absorption2DPanel(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~Absorption2DPanel();

    void paint(juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;
    void paintOverChildren(Graphics& g) override;

    void mouseDown(const MouseEvent& event) override;
    void mouseDrag(const MouseEvent& event) override;
    void mouseUp(const MouseEvent& event) override;

    void setCurrentWallId(int newId);
    int getCurrentWallId() { return currentWallId; };
    void setWallCoords(Point<float>* newCoords);

private:

    void positionChangeOnMouseDrag(const MouseEvent& event);
    void updatePluginParams();

    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<Drawable> backgroundImg;
    std::array<float, Parameters::NUM_FREQ> tempFilter;
    File svgFile, pngFile;
    bool movingFilter, filterChanged, validPosition;
    int currentWallId = 0;

    std::mutex mut;
    Path convexHull;
    std::array<Path, AbsorptionSpace::NUM_SIMPLICES> uiSimplices;
    std::array<float, 3> baricentricCoord;
    Line<float> intersectionLine;
    Point<float> newCoord, v0, v1, v2, clickoffset;
    Point<float>* wallCoords;

    juce::Rectangle<float> pickerRect, pickerRectInternal;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Absorption2DPanel)
};
