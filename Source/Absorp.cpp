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

//[Headers] You can add your own extra header files here...
#include "WallFiltersUI.h"

//[/Headers]

#include "Absorp.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Absorp::Absorp (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, int wi, WallFiltersUI* par)
    : processor(p), valueTreeState(vts), wallID(wi), parent(par)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    presets_button.reset (new juce::TextButton ("presets_button"));
    addAndMakeVisible (presets_button.get());
    presets_button->setButtonText (TRANS("Presets"));
    presets_button->addListener (this);
    presets_button->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff080808));

    presets_button->setBounds (8, 5, 88, 22);

    Absorption_window_button.reset (new juce::TextButton ("Absorption_window_button"));
    addAndMakeVisible (Absorption_window_button.get());
    Absorption_window_button->setButtonText (TRANS("Picker"));
    Absorption_window_button->addListener (this);
    Absorption_window_button->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff080808));

    Absorption_window_button->setBounds (168, 5, 88, 22);


    //[UserPreSize]

    abs1.reset(new Slider_reverse("abs1"));
    addAndMakeVisible(abs1.get());
    abs1->setRange(0, 10, 0);
    abs1->setSliderStyle(juce::Slider::LinearVertical);
    abs1->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs1->setBounds(5, 24, 32, 112);

    abs2.reset(new Slider_reverse("abs2"));
    addAndMakeVisible(abs2.get());
    abs2->setRange(0, 10, 0);
    abs2->setSliderStyle(juce::Slider::LinearVertical);
    abs2->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs2->setBounds(37, 24, 32, 112);

    abs3.reset(new Slider_reverse("abs3"));
    addAndMakeVisible(abs3.get());
    abs3->setRange(0, 10, 0);
    abs3->setSliderStyle(juce::Slider::LinearVertical);
    abs3->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs3->setBounds(69, 24, 32, 112);

    abs4.reset(new Slider_reverse("abs4"));
    addAndMakeVisible(abs4.get());
    abs4->setRange(0, 10, 0);
    abs4->setSliderStyle(juce::Slider::LinearVertical);
    abs4->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs4->setBounds(101, 24, 32, 112);

    abs5.reset(new Slider_reverse("abs5"));
    addAndMakeVisible(abs5.get());
    abs5->setRange(0, 10, 0);
    abs5->setSliderStyle(juce::Slider::LinearVertical);
    abs5->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs5->setBounds(133, 24, 32, 112);

    abs6.reset(new Slider_reverse("abs6"));
    addAndMakeVisible(abs6.get());
    abs6->setRange(0, 10, 0);
    abs6->setSliderStyle(juce::Slider::LinearVertical);
    abs6->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs6->setBounds(165, 24, 32, 112);

    abs7.reset(new Slider_reverse("abs7"));
    addAndMakeVisible(abs7.get());
    abs7->setRange(0, 10, 0);
    abs7->setSliderStyle(juce::Slider::LinearVertical);
    abs7->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs7->setBounds(197, 24, 32, 112);

    abs8.reset(new Slider_reverse("abs8"));
    addAndMakeVisible(abs8.get());
    abs8->setRange(0, 10, 0);
    abs8->setSliderStyle(juce::Slider::LinearVertical);
    abs8->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);

    abs8->setBounds(229, 24, 32, 112);

    freq1Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "0", *abs1));
    freq2Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "1", *abs2));
    freq3Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "2", *abs3));
    freq4Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "3", *abs4));
    freq5Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "4", *abs5));
    freq6Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "5", *abs6));
    freq7Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "6", *abs7));
    freq8Attachment.reset(new SliderAttachment(valueTreeState, String("freq") + String(wallID) + "7", *abs8));

    for (int i = 0; i < FilterPresets::NUM_PRESETS; i++)
    {
        presets.addItem(i + 1, FilterPresets::PRESETS_NAMES[i]);
    }

    abs1->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    abs2->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    abs3->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    abs4->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    abs5->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    abs6->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    abs7->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    abs8->onDragStart = [this] { parent->hidePickerWindow(); pickerCoords.setXY(-1, -1); };
    pickerCoords.setXY(-1, -1);

    startTimerHz(60);
    //[/UserPreSize]

    setSize (265, 140);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Absorp::~Absorp()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

    freq1Attachment.reset();
    freq2Attachment.reset();
    freq3Attachment.reset();
    freq4Attachment.reset();
    freq5Attachment.reset();
    freq6Attachment.reset();
    freq7Attachment.reset();
    freq8Attachment.reset();

    //[/Destructor_pre]

    presets_button = nullptr;
    Absorption_window_button = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Absorp::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff151e23));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Absorp::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Absorp::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == presets_button.get())
    {
        //[UserButtonCode_presets_button] -- add your button handler code here..
        presets.showMenuAsync(PopupMenu::Options(),
            [&](int result)
        {
            if (result == 0)
            {

            }
            else
            {
                setAbsorptionToPreset(result - 1);
            }
        }
        );

        //[/UserButtonCode_presets_button]
    }
    else if (buttonThatWasClicked == Absorption_window_button.get())
    {
        //[UserButtonCode_Absorption_window_button] -- add your button handler code here..
        parent->openPickerWindow(wallID, getScreenBounds().getTopRight(), &pickerCoords);
        //[/UserButtonCode_Absorption_window_button]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void Absorp::timerCallback()
{
    repaint();
}

void Absorp::setAllAbsorptionToTarget(float newValue)
{
    parent->hidePickerWindow();
    pickerCoords.setXY(-1, -1);
    for (int i = 0; i < Parameters::NUM_FREQ; i++)
    {
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->beginChangeGesture();
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->setValueNotifyingHost(newValue);
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->endChangeGesture();
    }
}

void Absorp::setAbsorptionToPreset(int preset)
{
    parent->setPickerToPreset(wallID, preset, &pickerCoords);
    for (int i = 0; i < Parameters::NUM_FREQ; i++)
    {
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->beginChangeGesture();
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->setValueNotifyingHost(FilterPresets::PRESETS_VALUES[preset][i]);
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->endChangeGesture();
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Absorp" componentName=""
                 parentClasses="public juce::Component, public Timer" constructorParams="RealtimeSDNAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts, int wi, WallFiltersUI* par"
                 variableInitialisers="processor(p), valueTreeState(vts), wallID(wi), parent(par)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="265" initialHeight="140">
  <BACKGROUND backgroundColour="ff151e23"/>
  <TEXTBUTTON name="presets_button" id="d5d561af5de52dbb" memberName="presets_button"
              virtualName="" explicitFocusOrder="0" pos="8 5 88 22" bgColOff="ff080808"
              buttonText="Presets" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Absorption_window_button" id="e0c6b7f87944682b" memberName="Absorption_window_button"
              virtualName="" explicitFocusOrder="0" pos="168 5 88 22" bgColOff="ff080808"
              buttonText="Picker" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

