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
#include "RoomPlane.h"
#include "WallFiltersUI.h"
#include "DragAndDropPanel.h"
#include "GeometryPanel.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RoomEditor  : public juce::Component,
                    public juce::Timer,
                    public juce::Button::Listener,
                    public juce::ComboBox::Listener
{
public:
    //==============================================================================
    RoomEditor (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~RoomEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;

    std::unique_ptr<SliderAttachment> gainAttachment;
    std::unique_ptr<ButtonAttachment> losAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> outputModeAttachment;
    int numOutChannels = 0;

    void setDropDownAvailableOptions(int numCh);

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> gain;
    std::unique_ptr<juce::ToggleButton> los;
    std::unique_ptr<juce::TextButton> load;
    std::unique_ptr<juce::TextButton> save;
    std::unique_ptr<juce::TextButton> undo;
    std::unique_ptr<juce::TextButton> redo;
    std::unique_ptr<RoomPlane> backView;
    std::unique_ptr<RoomPlane> TopDown2;
    std::unique_ptr<juce::TextButton> load_HRTF;
    std::unique_ptr<juce::TabbedComponent> juce__tabbedComponent;
    std::unique_ptr<juce::Viewport> HRTF_dragAndDrop;
    std::unique_ptr<juce::ComboBox> Output_mode_comboBox;
    std::unique_ptr<juce::ToggleButton> OSCToggle;
    std::unique_ptr<juce::TextEditor> OSC_port_selector;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoomEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

