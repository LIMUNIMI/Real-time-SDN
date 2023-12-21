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

#include "GeometryPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GeometryPanel::GeometryPanel (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    emitterX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterX.get());
    emitterX->setRange (0, 10, 0);
    emitterX->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterX->setBounds (33, 119, 257, 24);

    emitterY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterY.get());
    emitterY->setRange (0, 10, 0);
    emitterY->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterY->setBounds (33, 159, 257, 24);

    emitterZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterZ.get());
    emitterZ->setRange (0, 10, 0);
    emitterZ->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterZ->setBounds (33, 199, 257, 24);

    listenerX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerX.get());
    listenerX->setRange (0, 10, 0);
    listenerX->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerX->setBounds (31, 354, 257, 24);

    listenerY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerY.get());
    listenerY->setRange (0, 10, 0);
    listenerY->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerY->setBounds (31, 394, 257, 24);

    listenerZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerZ.get());
    listenerZ->setRange (0, 10, 0);
    listenerZ->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerZ->setBounds (31, 434, 257, 24);

    listenerPitch.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerPitch.get());
    listenerPitch->setRange (0, 10, 0);
    listenerPitch->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    listenerPitch->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    listenerPitch->setBounds (313, 359, 95, 96);

    listenerYaw.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerYaw.get());
    listenerYaw->setRange (0, 10, 0);
    listenerYaw->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    listenerYaw->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    listenerYaw->setBounds (417, 359, 95, 96);

    listenerRoll.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerRoll.get());
    listenerRoll->setRange (0, 10, 0);
    listenerRoll->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    listenerRoll->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    listenerRoll->setBounds (513, 359, 95, 96);

    roomX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomX.get());
    roomX->setRange (0, 10, 0);
    roomX->setSliderStyle (juce::Slider::LinearHorizontal);
    roomX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomX->setBounds (335, 123, 257, 24);

    roomY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomY.get());
    roomY->setRange (0, 10, 0);
    roomY->setSliderStyle (juce::Slider::LinearHorizontal);
    roomY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomY->setBounds (335, 163, 257, 24);

    roomZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomZ.get());
    roomZ->setRange (0, 10, 0);
    roomZ->setSliderStyle (juce::Slider::LinearHorizontal);
    roomZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomZ->setBounds (335, 203, 257, 24);

    lookAtButton.reset (new juce::TextButton ("lookAtButton"));
    addAndMakeVisible (lookAtButton.get());
    lookAtButton->setButtonText (TRANS("Look at emitter"));
    lookAtButton->addListener (this);

    lookAtButton->setBounds (384, 488, 150, 24);


    //[UserPreSize]
    emitterXAttachment.reset(new SliderAttachment(valueTreeState, "SourceX", *emitterX));
    emitterYAttachment.reset(new SliderAttachment(valueTreeState, "SourceY", *emitterY));
    emitterZAttachment.reset(new SliderAttachment(valueTreeState, "SourceZ", *emitterZ));
    listenerXAttachment.reset(new SliderAttachment(valueTreeState, "ListenerX", *listenerX));
    listenerYAttachment.reset(new SliderAttachment(valueTreeState, "ListenerY", *listenerY));
    listenerZAttachment.reset(new SliderAttachment(valueTreeState, "ListenerZ", *listenerZ));
    listenerPitchAttachment.reset(new SliderAttachment(valueTreeState, "ListenerRotx", *listenerPitch));
    listenerYawAttachment.reset(new SliderAttachment(valueTreeState, "ListenerRoty", *listenerYaw));
    listenerRollAttachment.reset(new SliderAttachment(valueTreeState, "ListenerRotz", *listenerRoll));
    roomXAttachment.reset(new SliderAttachment(valueTreeState, "DimensionsX", *roomX));
    roomYAttachment.reset(new SliderAttachment(valueTreeState, "DimensionsY", *roomY));
    roomZAttachment.reset(new SliderAttachment(valueTreeState, "DimensionsZ", *roomZ));
    //[/UserPreSize]

    setSize (630, 600);


    //[Constructor] You can add your own custom stuff here..
    addListener(this, "/SDN/SourceX");
    addListener(this, "/SDN/SourceY");
    addListener(this, "/SDN/SourceZ");
    addListener(this, "/SDN/ListenerX");
    addListener(this, "/SDN/ListenerY");
    addListener(this, "/SDN/ListenerZ");
    addListener(this, "/SDN/ListenerPitch");
    addListener(this, "/SDN/ListenerYaw");
    addListener(this, "/SDN/ListenerRoll");
    //[/Constructor]
}

GeometryPanel::~GeometryPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    emitterXAttachment.reset();
    emitterYAttachment.reset();
    emitterZAttachment.reset();
    listenerXAttachment.reset();
    listenerYAttachment.reset();
    listenerZAttachment.reset();
    listenerYawAttachment.reset();
    listenerPitchAttachment.reset();
    listenerRollAttachment.reset();
    roomXAttachment.reset();
    roomYAttachment.reset();
    roomZAttachment.reset();
    //[/Destructor_pre]

    emitterX = nullptr;
    emitterY = nullptr;
    emitterZ = nullptr;
    listenerX = nullptr;
    listenerY = nullptr;
    listenerZ = nullptr;
    listenerPitch = nullptr;
    listenerYaw = nullptr;
    listenerRoll = nullptr;
    roomX = nullptr;
    roomY = nullptr;
    roomZ = nullptr;
    lookAtButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GeometryPanel::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 44, y = 82, width = 244, height = 30;
        juce::String text (TRANS("Emitter"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 44, y = 314, width = 244, height = 30;
        juce::String text (TRANS("Listener"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 4, y = 124, width = 32, height = 20;
        juce::String text (TRANS("X"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 4, y = 164, width = 32, height = 20;
        juce::String text (TRANS("Y"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 4, y = 204, width = 32, height = 20;
        juce::String text (TRANS("Z"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 308, y = 124, width = 32, height = 20;
        juce::String text (TRANS("X"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 308, y = 164, width = 32, height = 20;
        juce::String text (TRANS("Y"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 308, y = 204, width = 32, height = 20;
        juce::String text (TRANS("Z"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 344, y = 88, width = 248, height = 30;
        juce::String text (TRANS("Room"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 4, y = 356, width = 32, height = 20;
        juce::String text (TRANS("X"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 4, y = 396, width = 32, height = 20;
        juce::String text (TRANS("Y"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 4, y = 436, width = 32, height = 20;
        juce::String text (TRANS("Z"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 324, y = 332, width = 76, height = 20;
        juce::String text (TRANS("Pitch"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 428, y = 332, width = 76, height = 20;
        juce::String text (TRANS("Yaw"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 524, y = 332, width = 76, height = 20;
        juce::String text (TRANS("Roll"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GeometryPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GeometryPanel::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == lookAtButton.get())
    {
        //[UserButtonCode_lookAtButton] -- add your button handler code here..
        processor.lookAtSource();
        //[/UserButtonCode_lookAtButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GeometryPanel::oscMessageReceived(const juce::OSCMessage& message)
{
    if (message.getAddressPattern() == "/SDN/SourceX")
        if (message.size() == 1 && message[0].isFloat32())
            emitterX->setValue(juce::jlimit(0.0f, 1.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/SourceY")
        if (message.size() == 1 && message[0].isFloat32())
            emitterY->setValue(juce::jlimit(0.0f, 1.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/SourceZ")
        if (message.size() == 1 && message[0].isFloat32())
            emitterZ->setValue(juce::jlimit(0.0f, 1.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/ListenerX")
        if (message.size() == 1 && message[0].isFloat32())
            listenerX->setValue(juce::jlimit(0.0f, 1.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/ListenerY")
        if (message.size() == 1 && message[0].isFloat32())
            listenerY->setValue(juce::jlimit(0.0f, 1.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/ListenerZ")
        if (message.size() == 1 && message[0].isFloat32())
            listenerZ->setValue(juce::jlimit(0.0f, 1.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/ListenerPitch")
        if (message.size() == 1 && message[0].isFloat32())
            listenerPitch->setValue(juce::jlimit(-180.0f, 180.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/ListenerYaw")
        if (message.size() == 1 && message[0].isFloat32())
            listenerYaw->setValue(juce::jlimit(-180.0f, 180.0f, message[0].getFloat32()));

    if (message.getAddressPattern() == "/SDN/ListenerRoll")
        if (message.size() == 1 && message[0].isFloat32())
            listenerRoll->setValue(juce::jlimit(-180.0f, 180.0f, message[0].getFloat32()));


}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GeometryPanel" componentName=""
                 parentClasses="public juce::Component, public juce::OSCReceiver, public juce::OSCReceiver::ListenerWithOSCAddress&lt;juce::OSCReceiver::MessageLoopCallback&gt;"
                 constructorParams="RealtimeSDNAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="processor(p), valueTreeState(vts)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="630" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="44 82 244 30" fill="solid: ffffffff" hasStroke="0" text="Emitter"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="44 314 244 30" fill="solid: ffffffff" hasStroke="0" text="Listener"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="4 124 32 20" fill="solid: ffffffff" hasStroke="0" text="X"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="4 164 32 20" fill="solid: ffffffff" hasStroke="0" text="Y"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="4 204 32 20" fill="solid: ffffffff" hasStroke="0" text="Z"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="308 124 32 20" fill="solid: ffffffff" hasStroke="0" text="X"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="308 164 32 20" fill="solid: ffffffff" hasStroke="0" text="Y"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="308 204 32 20" fill="solid: ffffffff" hasStroke="0" text="Z"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="344 88 248 30" fill="solid: ffffffff" hasStroke="0" text="Room"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="4 356 32 20" fill="solid: ffffffff" hasStroke="0" text="X"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="4 396 32 20" fill="solid: ffffffff" hasStroke="0" text="Y"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="4 436 32 20" fill="solid: ffffffff" hasStroke="0" text="Z"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="324 332 76 20" fill="solid: ffffffff" hasStroke="0" text="Pitch"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="428 332 76 20" fill="solid: ffffffff" hasStroke="0" text="Yaw"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="524 332 76 20" fill="solid: ffffffff" hasStroke="0" text="Roll"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="5eefdf8daf8c33cc" memberName="emitterX"
          virtualName="" explicitFocusOrder="0" pos="33 119 257 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="4e911c7506c2297d" memberName="emitterY"
          virtualName="" explicitFocusOrder="0" pos="33 159 257 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="84fd187cedf47c2a" memberName="emitterZ"
          virtualName="" explicitFocusOrder="0" pos="33 199 257 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="c338155edb0fe879" memberName="listenerX"
          virtualName="" explicitFocusOrder="0" pos="31 354 257 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="6baf213ecebc204c" memberName="listenerY"
          virtualName="" explicitFocusOrder="0" pos="31 394 257 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="76893f504b069909" memberName="listenerZ"
          virtualName="" explicitFocusOrder="0" pos="31 434 257 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="9e818101edc1d3d7" memberName="listenerPitch"
          virtualName="" explicitFocusOrder="0" pos="313 359 95 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="1337db1e7de08" memberName="listenerYaw"
          virtualName="" explicitFocusOrder="0" pos="417 359 95 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="6641584aea36d9b3" memberName="listenerRoll"
          virtualName="" explicitFocusOrder="0" pos="513 359 95 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="7a0b7eca39c454d6" memberName="roomX" virtualName=""
          explicitFocusOrder="0" pos="335 123 257 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="91a47596aec4655a" memberName="roomY" virtualName=""
          explicitFocusOrder="0" pos="335 163 257 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="82aaefc651798196" memberName="roomZ" virtualName=""
          explicitFocusOrder="0" pos="335 203 257 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TEXTBUTTON name="lookAtButton" id="145ae5a1616914e" memberName="lookAtButton"
              virtualName="" explicitFocusOrder="0" pos="384 488 150 24" buttonText="Look at emitter"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

