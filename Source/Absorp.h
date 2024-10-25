/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "FilterPresets.h"


typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class WallFiltersUI;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Absorp  : public juce::Component,
                public Timer,
                public juce::Button::Listener
{
public:
    //==============================================================================
    Absorp (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, int wi, WallFiltersUI* par);
    ~Absorp() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void setAllAbsorptionToTarget(float newValue);
    void setAbsorptionToPreset(int preset);

    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    int wallID;

    std::unique_ptr<SliderAttachment> freq1Attachment;
    std::unique_ptr<SliderAttachment> freq2Attachment;
    std::unique_ptr<SliderAttachment> freq3Attachment;
    std::unique_ptr<SliderAttachment> freq4Attachment;
    std::unique_ptr<SliderAttachment> freq5Attachment;
    std::unique_ptr<SliderAttachment> freq6Attachment;
    std::unique_ptr<SliderAttachment> freq7Attachment;
    std::unique_ptr<SliderAttachment> freq8Attachment;

    PopupMenu presets;

    WallFiltersUI* parent;
    Point<float> pickerCoords;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> abs1;
    std::unique_ptr<juce::Slider> abs2;
    std::unique_ptr<juce::Slider> abs3;
    std::unique_ptr<juce::Slider> abs4;
    std::unique_ptr<juce::Slider> abs5;
    std::unique_ptr<juce::Slider> abs6;
    std::unique_ptr<juce::Slider> abs7;
    std::unique_ptr<juce::Slider> abs8;
    std::unique_ptr<juce::TextButton> presets_button;
    std::unique_ptr<juce::TextButton> Absorption_window_button;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Absorp)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

