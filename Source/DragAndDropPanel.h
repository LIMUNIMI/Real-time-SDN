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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DragAndDropPanel  : public juce::Component,
                          public juce::FileDragAndDropTarget
{
public:
    //==============================================================================
    DragAndDropPanel (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~DragAndDropPanel() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    bool isInterestedInFileDrag(const StringArray& files) override;
    void fileDragEnter(const StringArray& files, int x, int y) override;
    void fileDragMove(const StringArray& files, int x, int y) override;
    void fileDragExit(const StringArray& files) override;
    void filesDropped(const StringArray& files, int x, int y) override;
    void visibilityChanged() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    juce::Colour customColour = juce::Colour(0xff3d92a3);
    RealtimeSDNAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> fileName_label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DragAndDropPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

