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
#include "Absorp.h"
#include "Absorption2DWindow.h"

typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WallFiltersUI  : public juce::Component,
                       public juce::Button::Listener
{
public:
    //==============================================================================
    WallFiltersUI (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~WallFiltersUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void openPickerWindow(int wallId, Point<int>& position, Point<float>* pickerCoord);
    void hidePickerWindow();
    void setPickerToPreset(int wallId, int preset, Point<float>* pickerCoord);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<ButtonAttachment> airAbosrptionAttachment;

    std::unique_ptr<Absorption2DWindow> absorptionPickerWindow;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Absorp> wall1;
    std::unique_ptr<Absorp> wall2;
    std::unique_ptr<Absorp> wall3;
    std::unique_ptr<Absorp> wall4;
    std::unique_ptr<Absorp> wall5;
    std::unique_ptr<Absorp> wall6;
    std::unique_ptr<juce::ToggleButton> airAbsortion_button;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WallFiltersUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

