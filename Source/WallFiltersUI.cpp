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

#include "WallFiltersUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WallFiltersUI::WallFiltersUI (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    wall1.reset (new Absorp (processor, valueTreeState, 2));
    addAndMakeVisible (wall1.get());
    wall1->setName ("new component");

    wall1->setBounds (8, 80, 296, 128);

    wall2.reset (new Absorp (processor, valueTreeState, 4));
    addAndMakeVisible (wall2.get());
    wall2->setName ("new component");

    wall2->setBounds (8, 264, 296, 128);

    wall3.reset (new Absorp (processor, valueTreeState, 0));
    addAndMakeVisible (wall3.get());
    wall3->setName ("new component");

    wall3->setBounds (8, 448, 296, 128);

    wall4.reset (new Absorp (processor, valueTreeState, 3));
    addAndMakeVisible (wall4.get());
    wall4->setName ("new component");

    wall4->setBounds (328, 80, 296, 128);

    wall5.reset (new Absorp (processor, valueTreeState, 5));
    addAndMakeVisible (wall5.get());
    wall5->setName ("new component");

    wall5->setBounds (328, 264, 296, 128);

    wall6.reset (new Absorp (processor, valueTreeState, 1));
    addAndMakeVisible (wall6.get());
    wall6->setName ("new component");

    wall6->setBounds (328, 448, 296, 128);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (630, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WallFiltersUI::~WallFiltersUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    wall1 = nullptr;
    wall2 = nullptr;
    wall3 = nullptr;
    wall4 = nullptr;
    wall5 = nullptr;
    wall6 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WallFiltersUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 6, y = 50, width = 296, height = 23;
        juce::String text (TRANS("Floor"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 326, y = 58, width = 296, height = 23;
        juce::String text (TRANS("Ceiling"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 6, y = 242, width = 296, height = 23;
        juce::String text (TRANS("Front"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 326, y = 242, width = 296, height = 23;
        juce::String text (TRANS("Back"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 6, y = 426, width = 296, height = 23;
        juce::String text (TRANS("Left"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 326, y = 426, width = 296, height = 23;
        juce::String text (TRANS("Right"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 0, y = 10, width = 624, height = 24;
        juce::String text (TRANS("Walls absorption coefficients:"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WallFiltersUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WallFiltersUI" componentName=""
                 parentClasses="public juce::Component" constructorParams="RealtimeSDNAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="processor(p), valueTreeState(vts)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="630" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="6 50 296 23" fill="solid: ffffffff" hasStroke="0" text="Floor"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="326 58 296 23" fill="solid: ffffffff" hasStroke="0" text="Ceiling"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="6 242 296 23" fill="solid: ffffffff" hasStroke="0" text="Front"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="326 242 296 23" fill="solid: ffffffff" hasStroke="0" text="Back"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="6 426 296 23" fill="solid: ffffffff" hasStroke="0" text="Left"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="326 426 296 23" fill="solid: ffffffff" hasStroke="0" text="Right"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="0 10 624 24" fill="solid: ffffffff" hasStroke="0" text="Walls absorption coefficients:"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="new component" id="28e5ac1a4cac4c04" memberName="wall1"
                    virtualName="" explicitFocusOrder="0" pos="8 80 296 128" class="Absorp"
                    params="processor, valueTreeState, 2"/>
  <GENERICCOMPONENT name="new component" id="f48b2a76dbd4d152" memberName="wall2"
                    virtualName="" explicitFocusOrder="0" pos="8 264 296 128" class="Absorp"
                    params="processor, valueTreeState, 4"/>
  <GENERICCOMPONENT name="new component" id="f1737d42e43f94ce" memberName="wall3"
                    virtualName="" explicitFocusOrder="0" pos="8 448 296 128" class="Absorp"
                    params="processor, valueTreeState, 0"/>
  <GENERICCOMPONENT name="new component" id="384f4c598c80770d" memberName="wall4"
                    virtualName="" explicitFocusOrder="0" pos="328 80 296 128" class="Absorp"
                    params="processor, valueTreeState, 3"/>
  <GENERICCOMPONENT name="new component" id="eccd39e48289ca7" memberName="wall5"
                    virtualName="" explicitFocusOrder="0" pos="328 264 296 128" class="Absorp"
                    params="processor, valueTreeState, 5"/>
  <GENERICCOMPONENT name="new component" id="11aaf23cd9b2f28d" memberName="wall6"
                    virtualName="" explicitFocusOrder="0" pos="328 448 296 128" class="Absorp"
                    params="processor, valueTreeState, 1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

