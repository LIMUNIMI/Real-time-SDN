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

#include "RoomEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RoomEditor::RoomEditor (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    emitterX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterX.get());
    emitterX->setRange (0, 10, 0);
    emitterX->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterX->setBounds (360, 88, 192, 24);

    emitterY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterY.get());
    emitterY->setRange (0, 10, 0);
    emitterY->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterY->setBounds (360, 128, 192, 24);

    emitterZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterZ.get());
    emitterZ->setRange (0, 10, 0);
    emitterZ->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterZ->setBounds (360, 168, 192, 24);

    listenerX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerX.get());
    listenerX->setRange (0, 10, 0);
    listenerX->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerX->setBounds (582, 91, 192, 24);

    listenerY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerY.get());
    listenerY->setRange (0, 10, 0);
    listenerY->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerY->setBounds (582, 131, 192, 24);

    listenerZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerZ.get());
    listenerZ->setRange (0, 10, 0);
    listenerZ->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerZ->setBounds (582, 171, 192, 24);

    listenerYaw.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerYaw.get());
    listenerYaw->setRange (0, 10, 0);
    listenerYaw->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    listenerYaw->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    listenerYaw->setBounds (360, 232, 95, 96);

    listenerPitch.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerPitch.get());
    listenerPitch->setRange (0, 10, 0);
    listenerPitch->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    listenerPitch->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    listenerPitch->setBounds (464, 232, 95, 96);

    listenerRoll.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerRoll.get());
    listenerRoll->setRange (0, 10, 0);
    listenerRoll->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    listenerRoll->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    listenerRoll->setBounds (560, 232, 95, 96);

    gain.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (gain.get());
    gain->setRange (0, 10, 0);
    gain->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    gain->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    gain->setBounds (696, 232, 96, 96);

    microphone.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (microphone.get());
    microphone->setRange (0, 10, 0);
    microphone->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    microphone->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    microphone->setBounds (888, 232, 104, 96);

    los.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (los.get());
    los->setButtonText (TRANS("LOS"));
    los->addListener (this);
    los->setToggleState (true, juce::dontSendNotification);

    los->setBounds (808, 304, 72, 24);

    roomX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomX.get());
    roomX->setRange (0, 10, 0);
    roomX->setSliderStyle (juce::Slider::LinearHorizontal);
    roomX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomX->setBounds (806, 92, 192, 24);

    roomY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomY.get());
    roomY->setRange (0, 10, 0);
    roomY->setSliderStyle (juce::Slider::LinearHorizontal);
    roomY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomY->setBounds (806, 132, 192, 24);

    roomZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomZ.get());
    roomZ->setRange (0, 10, 0);
    roomZ->setSliderStyle (juce::Slider::LinearHorizontal);
    roomZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomZ->setBounds (806, 172, 192, 24);

    wall1.reset (new Absorp (processor, valueTreeState, 2));
    addAndMakeVisible (wall1.get());
    wall1->setName ("new component");

    wall1->setBounds (24, 400, 296, 128);

    wall2.reset (new Absorp (processor, valueTreeState, 4));
    addAndMakeVisible (wall2.get());
    wall2->setName ("new component");

    wall2->setBounds (360, 400, 296, 128);

    wall3.reset (new Absorp (processor, valueTreeState, 0));
    addAndMakeVisible (wall3.get());
    wall3->setName ("new component");

    wall3->setBounds (696, 400, 296, 128);

    wall4.reset (new Absorp (processor, valueTreeState, 3));
    addAndMakeVisible (wall4.get());
    wall4->setName ("new component");

    wall4->setBounds (24, 568, 296, 128);

    wall5.reset (new Absorp (processor, valueTreeState, 5));
    addAndMakeVisible (wall5.get());
    wall5->setName ("new component");

    wall5->setBounds (360, 568, 296, 128);

    wall6.reset (new Absorp (processor, valueTreeState, 1));
    addAndMakeVisible (wall6.get());
    wall6->setName ("new component");

    wall6->setBounds (696, 568, 296, 128);

    load.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (load.get());
    load->setButtonText (TRANS("Load"));
    load->addListener (this);

    load->setBounds (656, 16, 56, 24);

    save.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (save.get());
    save->setButtonText (TRANS("Save"));
    save->addListener (this);

    save->setBounds (720, 16, 56, 24);

    undo.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (undo.get());
    undo->setButtonText (TRANS("Undo"));
    undo->addListener (this);

    undo->setBounds (512, 16, 56, 24);

    redo.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (redo.get());
    redo->setButtonText (TRANS("Redo"));
    redo->addListener (this);

    redo->setBounds (576, 16, 56, 24);

    TopDown.reset (new RoomPlane (processor, valueTreeState,
                                  'Z',
                                  'Y'));
    addAndMakeVisible (TopDown.get());
    TopDown->setName ("new component");

    TopDown->setBounds (24, 232, 296, 128);

    TopDown2.reset (new RoomPlane (processor, valueTreeState,
                                   'X',
                                   'Z'));
    addAndMakeVisible (TopDown2.get());
    TopDown2->setName ("new component");

    TopDown2->setBounds (24, 64, 296, 128);


    //[UserPreSize]

    emitterXAttachment.reset(new SliderAttachment(valueTreeState, "SourceX", *emitterX));
    emitterYAttachment.reset(new SliderAttachment(valueTreeState, "SourceY", *emitterY));
    emitterZAttachment.reset(new SliderAttachment(valueTreeState, "SourceZ", *emitterZ));
    listenerXAttachment.reset(new SliderAttachment(valueTreeState, "ListenerX", *listenerX));
    listenerYAttachment.reset(new SliderAttachment(valueTreeState, "ListenerY", *listenerY));
    listenerZAttachment.reset(new SliderAttachment(valueTreeState, "ListenerZ", *listenerZ));
    listenerYawAttachment.reset(new SliderAttachment(valueTreeState, "ListenerRotx", *listenerYaw));
    listenerPitchAttachment.reset(new SliderAttachment(valueTreeState, "ListenerRoty", *listenerPitch));
    listenerRollAttachment.reset(new SliderAttachment(valueTreeState, "ListenerRotz", *listenerRoll));
    gainAttachment.reset(new SliderAttachment(valueTreeState, "sourceGain", *gain));
    roomXAttachment.reset(new SliderAttachment(valueTreeState, "DimensionsX", *roomX));
    roomYAttachment.reset(new SliderAttachment(valueTreeState, "DimensionsY", *roomY));
    roomZAttachment.reset(new SliderAttachment(valueTreeState, "DimensionsZ", *roomZ));
    microphoneAttachment.reset(new SliderAttachment(valueTreeState, "OutputMode", *microphone));
    losAttachment.reset(new ButtonAttachment(valueTreeState, "LOS", *los));

    //[/UserPreSize]

    setSize (1018, 720);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RoomEditor::~RoomEditor()
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
    gainAttachment.reset();
    roomXAttachment.reset();
    roomYAttachment.reset();
    roomZAttachment.reset();
    microphoneAttachment.reset();
    losAttachment.reset();
    //[/Destructor_pre]

    emitterX = nullptr;
    emitterY = nullptr;
    emitterZ = nullptr;
    listenerX = nullptr;
    listenerY = nullptr;
    listenerZ = nullptr;
    listenerYaw = nullptr;
    listenerPitch = nullptr;
    listenerRoll = nullptr;
    gain = nullptr;
    microphone = nullptr;
    los = nullptr;
    roomX = nullptr;
    roomY = nullptr;
    roomZ = nullptr;
    wall1 = nullptr;
    wall2 = nullptr;
    wall3 = nullptr;
    wall4 = nullptr;
    wall5 = nullptr;
    wall6 = nullptr;
    load = nullptr;
    save = nullptr;
    undo = nullptr;
    redo = nullptr;
    TopDown = nullptr;
    TopDown2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RoomEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 368, y = 56, width = 192, height = 30;
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
        int x = 584, y = 56, width = 192, height = 30;
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
        int x = 556, y = 92, width = 32, height = 20;
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
        int x = 556, y = 132, width = 32, height = 20;
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
        int x = 556, y = 172, width = 32, height = 20;
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
        int x = 372, y = 212, width = 76, height = 20;
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
        int x = 476, y = 212, width = 76, height = 20;
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
        int x = 572, y = 212, width = 76, height = 20;
        juce::String text (TRANS("Roll"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 884, y = 212, width = 108, height = 20;
        juce::String text (TRANS("Output format"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 780, y = 92, width = 32, height = 20;
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
        int x = 780, y = 132, width = 32, height = 20;
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
        int x = 780, y = 172, width = 32, height = 20;
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
        int x = 808, y = 56, width = 192, height = 30;
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
        int x = 700, y = 212, width = 84, height = 20;
        juce::String text (TRANS("Gain"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 20, y = 12, width = 484, height = 30;
        juce::String text (TRANS("SDN Reverb by Laboratorio di Informatica Musicale"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    {
        int x = 788, y = 12, width = 200, height = 30;
        juce::String text (TRANS("Coded by Marco Fontana"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 24, y = 377, width = 296, height = 23;
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
        int x = 24, y = 545, width = 296, height = 23;
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
        int x = 360, y = 377, width = 296, height = 23;
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
        int x = 360, y = 545, width = 296, height = 23;
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
        int x = 696, y = 377, width = 296, height = 23;
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
        int x = 696, y = 545, width = 296, height = 23;
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
        int x = 32, y = 344, width = 960, height = 24;
        juce::String text (TRANS("Walls absorption coefficients:"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (18.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 24, y = 208, width = 296, height = 30;
        juce::String text (TRANS("Side view"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 24, y = 40, width = 296, height = 30;
        juce::String text (TRANS("Top-down view"));
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

void RoomEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RoomEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == los.get())
    {
        //[UserButtonCode_los] -- add your button handler code here..
        //[/UserButtonCode_los]
    }
    else if (buttonThatWasClicked == load.get())
    {
        //[UserButtonCode_load] -- add your button handler code here..
        juce::FileChooser chooser("Select preset to load...", processor.defaultLoc, "*.xml");

        if (chooser.browseForFileToOpen())
        {
            auto fileToLoad = chooser.getResult();
            MemoryBlock sourceData;
            fileToLoad.loadFileAsData(sourceData);
            processor.setStateInformation(sourceData.getData(), sourceData.getSize());
            processor.defaultLoc = fileToLoad.getParentDirectory();
        }
        //[/UserButtonCode_load]
    }
    else if (buttonThatWasClicked == save.get())
    {
        //[UserButtonCode_save] -- add your button handler code here..
        juce::FileChooser chooser("Select save position...", processor.defaultLoc, "*.xml");

        if (chooser.browseForFileToSave(true))
        {
            auto file = chooser.getResult();

            if (file.exists())
                file.deleteFile();

            juce::FileOutputStream outputStream(file);

            if (outputStream.openedOk())
            {
                MemoryBlock destData;
                processor.getStateInformation(destData);
                outputStream.write(destData.getData(), destData.getSize());
                processor.defaultLoc = file.getParentDirectory();
            }
        }
        //[/UserButtonCode_save]
    }
    else if (buttonThatWasClicked == undo.get())
    {
        //[UserButtonCode_undo] -- add your button handler code here..
        valueTreeState.undoManager->undo();
        //[/UserButtonCode_undo]
    }
    else if (buttonThatWasClicked == redo.get())
    {
        //[UserButtonCode_redo] -- add your button handler code here..
        valueTreeState.undoManager->redo();
        //[/UserButtonCode_redo]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RoomEditor" componentName=""
                 parentClasses="public juce::Component" constructorParams="RealtimeSDNAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="processor(p), valueTreeState(vts)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="1018" initialHeight="720">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="368 56 192 30" fill="solid: ffffffff" hasStroke="0" text="Emitter"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="584 56 192 30" fill="solid: ffffffff" hasStroke="0" text="Listener"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="556 92 32 20" fill="solid: ffffffff" hasStroke="0" text="X"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="556 132 32 20" fill="solid: ffffffff" hasStroke="0" text="Y"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="556 172 32 20" fill="solid: ffffffff" hasStroke="0" text="Z"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="372 212 76 20" fill="solid: ffffffff" hasStroke="0" text="Pitch"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="476 212 76 20" fill="solid: ffffffff" hasStroke="0" text="Yaw"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="572 212 76 20" fill="solid: ffffffff" hasStroke="0" text="Roll"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="884 212 108 20" fill="solid: ffffffff" hasStroke="0" text="Output format"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="780 92 32 20" fill="solid: ffffffff" hasStroke="0" text="X"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="780 132 32 20" fill="solid: ffffffff" hasStroke="0" text="Y"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="780 172 32 20" fill="solid: ffffffff" hasStroke="0" text="Z"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="808 56 192 30" fill="solid: ffffffff" hasStroke="0" text="Room"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="700 212 84 20" fill="solid: ffffffff" hasStroke="0" text="Gain"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="20 12 484 30" fill="solid: ffffffff" hasStroke="0" text="SDN Reverb by Laboratorio di Informatica Musicale"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="788 12 200 30" fill="solid: ffffffff" hasStroke="0" text="Coded by Marco Fontana"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="24 377 296 23" fill="solid: ffffffff" hasStroke="0" text="Floor"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="24 545 296 23" fill="solid: ffffffff" hasStroke="0" text="Ceiling"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="360 377 296 23" fill="solid: ffffffff" hasStroke="0" text="Front"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="360 545 296 23" fill="solid: ffffffff" hasStroke="0" text="Back"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="696 377 296 23" fill="solid: ffffffff" hasStroke="0" text="Left"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="696 545 296 23" fill="solid: ffffffff" hasStroke="0" text="Right"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="32 344 960 24" fill="solid: ffffffff" hasStroke="0" text="Walls absorption coefficients:"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="24 208 296 30" fill="solid: ffffffff" hasStroke="0" text="Side view"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="24 40 296 30" fill="solid: ffffffff" hasStroke="0" text="Top-down view"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="5eefdf8daf8c33cc" memberName="emitterX"
          virtualName="" explicitFocusOrder="0" pos="360 88 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="4e911c7506c2297d" memberName="emitterY"
          virtualName="" explicitFocusOrder="0" pos="360 128 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="84fd187cedf47c2a" memberName="emitterZ"
          virtualName="" explicitFocusOrder="0" pos="360 168 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="c338155edb0fe879" memberName="listenerX"
          virtualName="" explicitFocusOrder="0" pos="582 91 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="6baf213ecebc204c" memberName="listenerY"
          virtualName="" explicitFocusOrder="0" pos="582 131 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="76893f504b069909" memberName="listenerZ"
          virtualName="" explicitFocusOrder="0" pos="582 171 192 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="9e818101edc1d3d7" memberName="listenerYaw"
          virtualName="" explicitFocusOrder="0" pos="360 232 95 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="1337db1e7de08" memberName="listenerPitch"
          virtualName="" explicitFocusOrder="0" pos="464 232 95 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="6641584aea36d9b3" memberName="listenerRoll"
          virtualName="" explicitFocusOrder="0" pos="560 232 95 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="3b7355fbb7fbc0bf" memberName="gain" virtualName=""
          explicitFocusOrder="0" pos="696 232 96 96" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="6d6dc1f71cee9106" memberName="microphone"
          virtualName="" explicitFocusOrder="0" pos="888 232 104 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="new toggle button" id="dd7455385ad38f23" memberName="los"
                virtualName="" explicitFocusOrder="0" pos="808 304 72 24" buttonText="LOS"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <SLIDER name="new slider" id="7a0b7eca39c454d6" memberName="roomX" virtualName=""
          explicitFocusOrder="0" pos="806 92 192 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="91a47596aec4655a" memberName="roomY" virtualName=""
          explicitFocusOrder="0" pos="806 132 192 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="82aaefc651798196" memberName="roomZ" virtualName=""
          explicitFocusOrder="0" pos="806 172 192 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <GENERICCOMPONENT name="new component" id="28e5ac1a4cac4c04" memberName="wall1"
                    virtualName="" explicitFocusOrder="0" pos="24 400 296 128" class="Absorp"
                    params="processor, valueTreeState, 2"/>
  <GENERICCOMPONENT name="new component" id="f48b2a76dbd4d152" memberName="wall2"
                    virtualName="" explicitFocusOrder="0" pos="360 400 296 128" class="Absorp"
                    params="processor, valueTreeState, 4"/>
  <GENERICCOMPONENT name="new component" id="f1737d42e43f94ce" memberName="wall3"
                    virtualName="" explicitFocusOrder="0" pos="696 400 296 128" class="Absorp"
                    params="processor, valueTreeState, 0"/>
  <GENERICCOMPONENT name="new component" id="384f4c598c80770d" memberName="wall4"
                    virtualName="" explicitFocusOrder="0" pos="24 568 296 128" class="Absorp"
                    params="processor, valueTreeState, 3"/>
  <GENERICCOMPONENT name="new component" id="eccd39e48289ca7" memberName="wall5"
                    virtualName="" explicitFocusOrder="0" pos="360 568 296 128" class="Absorp"
                    params="processor, valueTreeState, 5"/>
  <GENERICCOMPONENT name="new component" id="11aaf23cd9b2f28d" memberName="wall6"
                    virtualName="" explicitFocusOrder="0" pos="696 568 296 128" class="Absorp"
                    params="processor, valueTreeState, 1"/>
  <TEXTBUTTON name="new button" id="318695e64a9a5be0" memberName="load" virtualName=""
              explicitFocusOrder="0" pos="656 16 56 24" buttonText="Load" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c98d9c075c050f78" memberName="save" virtualName=""
              explicitFocusOrder="0" pos="720 16 56 24" buttonText="Save" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="653a04ca70857f0d" memberName="undo" virtualName=""
              explicitFocusOrder="0" pos="512 16 56 24" buttonText="Undo" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="405ee4fbbda32d65" memberName="redo" virtualName=""
              explicitFocusOrder="0" pos="576 16 56 24" buttonText="Redo" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="new component" id="237d2c8ded89baef" memberName="TopDown"
                    virtualName="" explicitFocusOrder="0" pos="24 232 296 128" class="RoomPlane"
                    params="processor, valueTreeState,&#10;'Z',&#10;'Y'"/>
  <GENERICCOMPONENT name="new component" id="2a2fc017b3736040" memberName="TopDown2"
                    virtualName="" explicitFocusOrder="0" pos="24 64 296 128" class="RoomPlane"
                    params="processor, valueTreeState,&#10;'X',&#10;'Z'"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

