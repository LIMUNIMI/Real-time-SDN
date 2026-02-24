#pragma once

#include <JuceHeader.h>
#include "Absorption2DPanel.h"


class Absorption2DUI : public juce::Component
{
public:
    Absorption2DUI(RealtimeSDNAudioProcessor& p, juce::AudioProcessorValueTreeState& vts);
    ~Absorption2DUI();

    void paint(juce::Graphics&) override;
    void resized() override;

    void setSliderValues(float x, float y);

    std::unique_ptr<Absorption2DPanel> absorptionPanel;

    float getXsliderValue() { return xSlider->getValue(); };
    float getYsliderValue() { return ySlider->getValue(); };

private:

    std::unique_ptr<juce::Slider> xSlider;
    std::unique_ptr<juce::Slider> ySlider;

    RealtimeSDNAudioProcessor& processor;
    juce::AudioProcessorValueTreeState& valueTreeState;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Absorption2DUI)
};
