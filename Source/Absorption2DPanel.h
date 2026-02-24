#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <Eigen/Geometry>
#include "AbsorptionSpace.h"
#include "Absorp.h"
#include <mutex>

class Absorption2DUI;

class Absorption2DPanel : public juce::Component, public juce::Timer
{
public:
    Absorption2DPanel(RealtimeSDNAudioProcessor& p, juce::AudioProcessorValueTreeState& vts, Absorption2DUI& parent);
    ~Absorption2DPanel();

    void paint(juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;
    void paintOverChildren(juce::Graphics& g) override;

    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;

    void setCurrentWallId(int newId);
    int getCurrentWallId() { return currentWallId; };
    
    void setWallCoords(juce::Point<float>* newCoords, Absorp* wal);
    void update2DCoords(float x, float y);
    void updateX(float x);
    void updateY(float y);

    Absorp* wall;

private:

    void positionChangeOnMouseDrag(const juce::MouseEvent& event);
    void updatePluginParams();
    void findFilter();

    RealtimeSDNAudioProcessor& processor;
    juce::AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<juce::Drawable> backgroundImg;
    std::array<float, Parameters::NUM_FREQ> tempFilter;
    juce::File svgFile, pngFile;
    bool movingFilter, filterChanged, validPosition;
    int currentWallId = 0;

    std::mutex mut;
    juce::Path convexHull;
    std::array<juce::Path, AbsorptionSpace::NUM_SIMPLICES> uiSimplices;
    std::array<float, 3> baricentricCoord;
    juce::Line<float> intersectionLine;
    juce::Point<float> newCoord, v0, v1, v2, clickoffset;
    juce::Point<float>* wallCoords;

    juce::Rectangle<float> pickerRect, pickerRectInternal;

    Absorption2DUI& ui;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Absorption2DPanel)
};
