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
//[/Headers]

#include "Absorp.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Absorp::Absorp (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, int wi)
    : processor(p), valueTreeState(vts), wallID(wi)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    abs1.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs1.get());
    abs1->setRange (0, 10, 0);
    abs1->setSliderStyle (juce::Slider::LinearVertical);
    abs1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs1->setBounds (5, 8, 32, 112);

    abs2.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs2.get());
    abs2->setRange (0, 10, 0);
    abs2->setSliderStyle (juce::Slider::LinearVertical);
    abs2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs2->setBounds (37, 8, 32, 112);

    abs3.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs3.get());
    abs3->setRange (0, 10, 0);
    abs3->setSliderStyle (juce::Slider::LinearVertical);
    abs3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs3->setBounds (69, 8, 32, 112);

    abs4.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs4.get());
    abs4->setRange (0, 10, 0);
    abs4->setSliderStyle (juce::Slider::LinearVertical);
    abs4->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs4->setBounds (101, 8, 32, 112);

    abs5.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs5.get());
    abs5->setRange (0, 10, 0);
    abs5->setSliderStyle (juce::Slider::LinearVertical);
    abs5->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs5->setBounds (133, 8, 32, 112);

    abs6.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs6.get());
    abs6->setRange (0, 10, 0);
    abs6->setSliderStyle (juce::Slider::LinearVertical);
    abs6->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs6->setBounds (165, 8, 32, 112);

    abs7.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs7.get());
    abs7->setRange (0, 10, 0);
    abs7->setSliderStyle (juce::Slider::LinearVertical);
    abs7->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs7->setBounds (197, 8, 32, 112);

    abs8.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (abs8.get());
    abs8->setRange (0, 10, 0);
    abs8->setSliderStyle (juce::Slider::LinearVertical);
    abs8->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    abs8->setBounds (229, 8, 32, 112);

    to1.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (to1.get());
    to1->setButtonText (TRANS("1"));
    to1->addListener (this);
    to1->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff051111));

    to1->setBounds (267, 8, 24, 24);

    toHalf.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (toHalf.get());
    toHalf->setButtonText (TRANS("P"));
    toHalf->addListener (this);
    toHalf->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff051111));

    toHalf->setBounds (267, 44, 24, 24);

    to0.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (to0.get());
    to0->setButtonText (TRANS("0"));
    to0->addListener (this);
    to0->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff051111));

    to0->setBounds (267, 80, 24, 24);


    //[UserPreSize]

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

    //[/UserPreSize]

    setSize (296, 128);


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

    abs1 = nullptr;
    abs2 = nullptr;
    abs3 = nullptr;
    abs4 = nullptr;
    abs5 = nullptr;
    abs6 = nullptr;
    abs7 = nullptr;
    abs8 = nullptr;
    to1 = nullptr;
    toHalf = nullptr;
    to0 = nullptr;


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

    if (buttonThatWasClicked == to1.get())
    {
        //[UserButtonCode_to1] -- add your button handler code here..
        setAllAbsorptionToTarget(1.0f);
        //[/UserButtonCode_to1]
    }
    else if (buttonThatWasClicked == toHalf.get())
    {
        //[UserButtonCode_toHalf] -- add your button handler code here..

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
        //[/UserButtonCode_toHalf]
    }
    else if (buttonThatWasClicked == to0.get())
    {
        //[UserButtonCode_to0] -- add your button handler code here..
        setAllAbsorptionToTarget(0.0f);
        //[/UserButtonCode_to0]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void Absorp::setAllAbsorptionToTarget(float newValue)
{
    for (int i = 0; i < Parameters::NUM_FREQ; i++)
    {
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->beginChangeGesture();
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->setValueNotifyingHost(newValue);
        valueTreeState.getParameter(String("freq") + String(wallID) + String(i))->endChangeGesture();
    }
}

void Absorp::setAbsorptionToPreset(int preset)
{
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
                 parentClasses="public juce::Component" constructorParams="RealtimeSDNAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts, int wi"
                 variableInitialisers="processor(p), valueTreeState(vts), wallID(wi)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="296" initialHeight="128">
  <BACKGROUND backgroundColour="ff151e23"/>
  <SLIDER name="new slider" id="b4b171872c85c136" memberName="abs1" virtualName=""
          explicitFocusOrder="0" pos="5 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="new slider" id="598b52f443341c0f" memberName="abs2" virtualName=""
          explicitFocusOrder="0" pos="37 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="new slider" id="e1150341e40ea0a3" memberName="abs3" virtualName=""
          explicitFocusOrder="0" pos="69 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="new slider" id="2a33624419138f8e" memberName="abs4" virtualName=""
          explicitFocusOrder="0" pos="101 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="new slider" id="7a240c37526ae377" memberName="abs5" virtualName=""
          explicitFocusOrder="0" pos="133 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="new slider" id="920a09d6d9d59cd6" memberName="abs6" virtualName=""
          explicitFocusOrder="0" pos="165 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="new slider" id="7104ac664bc507a6" memberName="abs7" virtualName=""
          explicitFocusOrder="0" pos="197 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="new slider" id="6009a5f8ebb42858" memberName="abs8" virtualName=""
          explicitFocusOrder="0" pos="229 8 32 112" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <TEXTBUTTON name="new button" id="fc8177dc40c04905" memberName="to1" virtualName=""
              explicitFocusOrder="0" pos="267 8 24 24" bgColOff="ff051111"
              buttonText="1" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="7d7768b1aebd5283" memberName="toHalf" virtualName=""
              explicitFocusOrder="0" pos="267 44 24 24" bgColOff="ff051111"
              buttonText="P" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="b7e60a045cc4019d" memberName="to0" virtualName=""
              explicitFocusOrder="0" pos="267 80 24 24" bgColOff="ff051111"
              buttonText="0" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

