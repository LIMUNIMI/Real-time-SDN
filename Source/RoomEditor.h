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
                    public juce::Button::Listener
{
public:
    //==============================================================================
    RoomEditor (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~RoomEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;

    std::unique_ptr<SliderAttachment> emitterXAttachment;
    std::unique_ptr<SliderAttachment> emitterYAttachment;
    std::unique_ptr<SliderAttachment> emitterZAttachment;
    std::unique_ptr<SliderAttachment> listenerXAttachment;
    std::unique_ptr<SliderAttachment> listenerYAttachment;
    std::unique_ptr<SliderAttachment> listenerZAttachment;
    std::unique_ptr<SliderAttachment> listenerYawAttachment;
    std::unique_ptr<SliderAttachment> listenerPitchAttachment;
    std::unique_ptr<SliderAttachment> listenerRollAttachment;
    std::unique_ptr<SliderAttachment> gainAttachment;
    std::unique_ptr<SliderAttachment> roomXAttachment;
    std::unique_ptr<SliderAttachment> roomYAttachment;
    std::unique_ptr<SliderAttachment> roomZAttachment;
    std::unique_ptr<SliderAttachment> microphoneAttachment;
    std::unique_ptr<ButtonAttachment> losAttachment;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> emitterX;
    std::unique_ptr<juce::Slider> emitterY;
    std::unique_ptr<juce::Slider> emitterZ;
    std::unique_ptr<juce::Slider> listenerX;
    std::unique_ptr<juce::Slider> listenerY;
    std::unique_ptr<juce::Slider> listenerZ;
    std::unique_ptr<juce::Slider> listenerYaw;
    std::unique_ptr<juce::Slider> listenerPitch;
    std::unique_ptr<juce::Slider> listenerRoll;
    std::unique_ptr<juce::Slider> gain;
    std::unique_ptr<juce::Slider> microphone;
    std::unique_ptr<juce::ToggleButton> los;
    std::unique_ptr<juce::Slider> roomX;
    std::unique_ptr<juce::Slider> roomY;
    std::unique_ptr<juce::Slider> roomZ;
    std::unique_ptr<Absorp> wall1;
    std::unique_ptr<Absorp> wall2;
    std::unique_ptr<Absorp> wall3;
    std::unique_ptr<Absorp> wall4;
    std::unique_ptr<Absorp> wall5;
    std::unique_ptr<Absorp> wall6;
    std::unique_ptr<juce::TextButton> load;
    std::unique_ptr<juce::TextButton> save;
    std::unique_ptr<juce::TextButton> undo;
    std::unique_ptr<juce::TextButton> redo;
    std::unique_ptr<RoomPlane> TopDown;
    std::unique_ptr<RoomPlane> TopDown2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoomEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

