/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

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
    : AudioProcessorEditor(&p), processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    emitterX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterX.get());
    emitterX->setRange (0, 10, 0);
    emitterX->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterX->setBounds (24, 88, 296, 24);

    emitterY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterY.get());
    emitterY->setRange (0, 10, 0);
    emitterY->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterY->setBounds (24, 128, 296, 24);

    emitterZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (emitterZ.get());
    emitterZ->setRange (0, 10, 0);
    emitterZ->setSliderStyle (juce::Slider::LinearHorizontal);
    emitterZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    emitterZ->setBounds (24, 168, 296, 24);

    listenerX.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerX.get());
    listenerX->setRange (0, 10, 0);
    listenerX->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerX->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerX->setBounds (358, 91, 296, 24);

    listenerY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerY.get());
    listenerY->setRange (0, 10, 0);
    listenerY->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerY->setBounds (358, 131, 296, 24);

    listenerZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (listenerZ.get());
    listenerZ->setRange (0, 10, 0);
    listenerZ->setSliderStyle (juce::Slider::LinearHorizontal);
    listenerZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    listenerZ->setBounds (358, 171, 296, 24);

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

    roomX->setBounds (694, 92, 296, 24);

    roomY.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomY.get());
    roomY->setRange (0, 10, 0);
    roomY->setSliderStyle (juce::Slider::LinearHorizontal);
    roomY->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomY->setBounds (694, 132, 296, 24);

    roomZ.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (roomZ.get());
    roomZ->setRange (0, 10, 0);
    roomZ->setSliderStyle (juce::Slider::LinearHorizontal);
    roomZ->setTextBoxStyle (juce::Slider::TextBoxRight, false, 80, 20);

    roomZ->setBounds (694, 172, 296, 24);

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

    cachedImage_axis_png_1 = juce::ImageCache::getFromMemory (axis_png, axis_pngSize);
    cachedImage_roomExample_png_2 = juce::ImageCache::getFromMemory (roomExample_png, roomExample_pngSize);

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
        int x = 24, y = 216, width = 296, height = 112;
        juce::Colour fillColour = juce::Colours::white;
        juce::Colour strokeColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = 28, y = 52, width = 296, height = 30;
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
        int x = 364, y = 52, width = 296, height = 30;
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
        int x = 324, y = 92, width = 32, height = 20;
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
        int x = 324, y = 132, width = 32, height = 20;
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
        int x = 324, y = 172, width = 32, height = 20;
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
        int x = 660, y = 92, width = 32, height = 20;
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
        int x = 660, y = 132, width = 32, height = 20;
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
        int x = 660, y = 172, width = 32, height = 20;
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
        int x = 692, y = 52, width = 296, height = 30;
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
        int x = 32, y = 223, width = 112, height = 99;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_axis_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_axis_png_1.getWidth(), cachedImage_axis_png_1.getHeight());
    }

    {
        int x = 152, y = 200, width = 168, height = 136;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_roomExample_png_2,
                     x, y, width, height,
                     0, 0, cachedImage_roomExample_png_2.getWidth(), cachedImage_roomExample_png_2.getHeight());
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
        //[/UserButtonCode_load]
    }
    else if (buttonThatWasClicked == save.get())
    {
        //[UserButtonCode_save] -- add your button handler code here..
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
                 parentClasses="public juce::AudioProcessorEditor" constructorParams="RealtimeSDNAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor(&amp;p), processor(p), valueTreeState(vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1018" initialHeight="720">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="24 216 296 112" fill="solid: ffffffff" hasStroke="1" stroke="1.5, mitered, butt"
          strokeColour="solid: ff000000"/>
    <TEXT pos="28 52 296 30" fill="solid: ffffffff" hasStroke="0" text="Emitter"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="364 52 296 30" fill="solid: ffffffff" hasStroke="0" text="Listener"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="324 92 32 20" fill="solid: ffffffff" hasStroke="0" text="X"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="324 132 32 20" fill="solid: ffffffff" hasStroke="0" text="Y"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="324 172 32 20" fill="solid: ffffffff" hasStroke="0" text="Z"
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
    <TEXT pos="660 92 32 20" fill="solid: ffffffff" hasStroke="0" text="X"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="660 132 32 20" fill="solid: ffffffff" hasStroke="0" text="Y"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="660 172 32 20" fill="solid: ffffffff" hasStroke="0" text="Z"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="692 52 296 30" fill="solid: ffffffff" hasStroke="0" text="Room"
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
    <IMAGE pos="32 223 112 99" resource="axis_png" opacity="1.0" mode="0"/>
    <IMAGE pos="152 200 168 136" resource="roomExample_png" opacity="1.0"
           mode="0"/>
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
  </BACKGROUND>
  <SLIDER name="new slider" id="5eefdf8daf8c33cc" memberName="emitterX"
          virtualName="" explicitFocusOrder="0" pos="24 88 296 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="4e911c7506c2297d" memberName="emitterY"
          virtualName="" explicitFocusOrder="0" pos="24 128 296 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="84fd187cedf47c2a" memberName="emitterZ"
          virtualName="" explicitFocusOrder="0" pos="24 168 296 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="c338155edb0fe879" memberName="listenerX"
          virtualName="" explicitFocusOrder="0" pos="358 91 296 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="6baf213ecebc204c" memberName="listenerY"
          virtualName="" explicitFocusOrder="0" pos="358 131 296 24" min="0.0"
          max="10.0" int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="76893f504b069909" memberName="listenerZ"
          virtualName="" explicitFocusOrder="0" pos="358 171 296 24" min="0.0"
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
          explicitFocusOrder="0" pos="694 92 296 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="91a47596aec4655a" memberName="roomY" virtualName=""
          explicitFocusOrder="0" pos="694 132 296 24" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="82aaefc651798196" memberName="roomZ" virtualName=""
          explicitFocusOrder="0" pos="694 172 296 24" min="0.0" max="10.0"
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: axis_png, 29220, "../Binary/Axis.png"
static const unsigned char resource_RoomEditor_axis_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,100,0,0,2,15,8,6,0,0,0,221,34,194,37,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,4,103,
65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,18,116,0,0,18,116,1,222,102,31,120,0,0,113,185,73,68,65,84,120,94,237,221,7,152,85,213,213,128,225,109,195,134,138,13,187,40,254,136,61,246,26,
21,123,47,177,215,216,187,198,104,236,45,198,24,141,198,222,59,150,216,208,216,123,239,26,27,42,216,177,43,168,32,162,160,216,231,159,111,121,247,228,114,41,50,48,115,235,247,62,207,125,102,238,204,0,
195,204,185,231,172,179,214,218,107,79,208,212,44,73,146,36,169,98,38,44,188,149,36,73,82,133,24,144,73,146,36,85,152,1,153,36,73,82,133,25,144,73,146,36,85,152,1,153,36,73,82,133,25,144,73,146,36,85,
152,1,153,36,73,82,133,25,144,73,146,36,85,152,1,153,36,73,82,133,25,144,73,146,36,85,152,1,153,36,73,82,133,25,144,73,146,36,85,152,1,153,36,73,82,133,25,144,73,146,36,85,152,1,153,36,73,82,133,25,144,
73,146,36,85,152,1,153,36,73,82,133,25,144,73,146,36,85,216,4,77,205,10,239,75,82,89,13,30,60,56,189,255,254,251,233,203,47,191,76,223,126,251,109,250,249,231,159,211,228,147,79,158,150,89,102,153,212,
169,83,167,194,87,141,236,185,231,158,75,159,124,242,73,250,229,151,95,226,235,22,90,104,161,212,185,115,231,194,103,37,169,246,24,144,73,170,152,23,94,120,33,93,126,249,229,169,119,239,222,233,195,15,
63,76,223,125,247,93,154,117,214,89,211,85,87,93,149,22,94,120,225,194,87,141,108,183,221,118,75,183,222,122,107,250,241,199,31,211,34,139,44,146,142,61,246,216,180,202,42,171,20,62,43,73,181,199,146,
165,164,178,26,52,104,80,58,233,164,147,210,30,123,236,145,142,62,250,232,116,223,125,247,165,55,223,124,51,125,241,197,23,233,235,175,191,78,159,127,254,121,4,90,99,50,100,200,144,248,218,111,190,249,
38,189,254,250,235,233,171,175,190,42,124,70,146,106,147,1,153,164,178,250,254,251,239,35,136,122,234,169,167,210,139,47,190,152,6,14,28,216,82,178,228,115,67,135,14,77,239,188,243,78,4,104,163,67,38,
141,175,37,112,227,207,191,241,198,27,145,97,147,164,90,101,64,38,169,172,166,152,98,138,180,220,114,203,165,21,86,88,33,45,185,228,146,105,222,121,231,77,147,78,58,105,225,179,41,130,172,187,238,186,
43,245,237,219,183,240,145,223,118,207,61,247,164,135,30,122,168,240,76,146,106,143,1,153,164,178,34,32,91,121,229,149,211,246,219,111,159,246,219,111,191,180,239,190,251,166,249,231,159,63,117,236,216,
49,62,79,163,254,71,31,125,20,89,179,209,89,116,209,69,35,144,155,96,130,9,226,57,141,253,211,76,51,77,188,47,73,181,200,128,76,82,89,145,13,155,111,190,249,34,67,182,214,90,107,165,117,214,89,39,45,182,
216,98,105,186,233,166,139,207,19,144,125,250,233,167,209,35,54,58,203,46,187,108,172,196,228,207,76,56,225,132,105,238,185,231,78,115,206,57,103,225,179,146,84,123,12,200,36,85,20,1,218,82,75,45,21,171,
43,193,194,239,207,62,251,44,122,201,70,135,21,149,235,175,191,126,172,196,156,100,146,73,210,239,126,247,187,24,125,33,73,181,202,128,76,82,69,17,144,253,254,247,191,111,201,112,17,144,49,143,140,76,
217,232,80,246,164,169,127,192,128,1,105,170,169,166,74,83,79,61,245,8,125,104,146,84,107,12,200,36,85,20,25,174,5,22,88,32,205,56,227,140,133,143,252,90,182,28,83,64,198,232,12,6,202,178,194,114,137,
37,150,72,51,204,48,67,225,51,146,84,155,12,200,36,85,29,198,90,252,244,211,79,133,103,35,123,248,225,135,211,179,207,62,27,211,249,143,63,254,248,8,202,36,169,150,25,144,73,170,10,172,152,228,49,54,37,
75,130,49,230,142,205,53,215,92,209,208,63,229,148,83,22,62,35,73,181,201,128,76,82,213,33,24,27,213,174,110,100,206,222,123,239,189,24,40,75,6,141,204,88,135,14,29,10,159,149,164,218,101,64,38,169,102,
208,55,118,208,65,7,165,215,94,123,45,198,94,236,190,251,238,209,224,47,73,181,206,128,76,82,85,200,37,75,144,29,43,205,144,177,162,242,249,231,159,79,79,63,253,116,44,2,232,209,163,71,172,204,156,104,
162,137,10,95,33,73,181,203,128,76,82,85,40,13,200,74,245,235,215,47,61,254,248,227,177,161,56,195,100,25,149,33,73,245,194,128,76,82,85,96,142,216,100,147,77,86,120,54,178,62,125,250,164,39,159,124,50,
250,198,216,58,105,150,89,102,41,124,70,146,106,159,1,153,164,170,192,22,72,163,42,63,146,45,99,243,240,71,30,121,36,86,95,110,190,249,230,177,143,229,228,147,79,94,248,10,73,170,125,6,100,146,170,66,
113,201,18,63,254,248,99,26,62,124,120,148,40,207,59,239,188,40,87,118,239,222,61,237,180,211,78,238,91,41,169,238,24,144,73,170,10,19,79,60,113,76,237,207,122,247,238,157,122,246,236,153,206,62,251,236,
244,214,91,111,165,53,214,88,35,29,113,196,17,35,124,141,36,213,11,3,50,73,85,129,61,41,59,117,234,84,120,150,210,7,31,124,16,101,202,91,111,189,53,246,170,92,126,249,229,211,210,75,47,237,170,74,73,117,
201,128,76,82,85,96,47,203,153,102,154,169,240,44,165,47,191,252,50,50,99,140,186,88,118,217,101,163,145,95,146,234,149,1,153,164,170,244,249,231,159,167,175,190,250,42,130,49,202,149,221,186,117,43,124,
70,146,234,143,1,153,164,170,64,111,88,241,54,72,108,141,52,237,180,211,166,77,54,217,36,178,99,211,79,63,125,225,51,146,84,127,12,200,36,85,5,198,88,116,236,216,177,240,44,69,63,25,51,199,246,219,111,
191,52,251,236,179,23,62,42,73,245,201,128,76,82,85,88,114,201,37,91,166,239,211,184,191,246,218,107,199,136,11,50,103,197,227,48,36,169,30,25,144,73,170,10,100,200,166,156,114,202,40,91,210,55,182,222,
122,235,197,202,74,73,106,4,6,100,146,170,194,179,207,62,27,195,95,25,127,113,220,113,199,69,64,38,73,141,194,128,76,82,69,125,247,221,119,233,129,7,30,72,183,223,126,123,76,231,255,231,63,255,153,22,
90,104,33,183,70,146,212,80,12,200,36,85,12,179,198,94,120,225,133,116,203,45,183,164,55,223,124,51,205,49,199,28,105,215,93,119,77,157,59,119,46,124,133,36,53,6,3,50,73,21,243,226,139,47,166,99,142,57,
38,221,116,211,77,177,79,37,35,46,36,169,17,77,208,212,172,240,190,36,181,185,65,131,6,165,187,238,186,43,125,244,209,71,177,122,146,44,24,115,197,8,198,238,190,251,238,244,228,147,79,166,229,150,91,46,
109,182,217,102,105,165,149,86,50,59,38,169,33,25,144,73,106,87,111,188,241,70,218,119,223,125,211,75,47,189,20,27,136,47,188,240,194,105,221,117,215,77,183,221,118,91,234,211,167,79,154,107,174,185,98,
211,240,21,86,88,97,132,173,147,36,169,145,24,144,73,106,87,4,98,235,175,191,126,250,236,179,207,98,158,24,205,250,12,125,101,91,36,130,179,61,247,220,51,173,178,202,42,177,151,37,51,199,36,169,17,217,
67,38,169,93,253,242,203,47,233,219,111,191,141,173,144,88,69,57,108,216,176,52,112,224,192,180,218,106,171,165,93,118,217,37,50,99,51,204,48,131,193,152,164,134,102,64,38,169,93,17,104,81,138,36,43,70,
22,172,107,215,174,105,254,249,231,143,41,252,59,238,184,99,148,44,139,247,176,148,164,70,100,201,82,82,187,34,27,198,88,139,39,158,120,34,246,164,220,112,195,13,163,151,140,64,204,13,195,37,233,87,6,
100,146,218,213,247,223,127,31,43,44,105,238,167,52,201,182,72,146,164,17,25,144,73,146,36,85,152,61,100,146,36,73,21,102,64,38,73,146,84,97,6,100,146,36,73,21,102,64,38,73,146,84,97,6,100,146,36,73,21,
102,64,38,73,146,84,97,6,100,146,36,73,21,102,64,38,73,146,84,97,6,100,146,36,73,21,102,64,38,73,146,84,97,6,100,146,36,73,21,102,64,38,73,146,84,97,6,100,146,36,73,21,102,64,38,73,146,84,97,6,100,146,
36,73,21,102,64,38,73,146,84,97,6,100,146,36,73,21,102,64,38,73,146,84,97,19,52,53,43,188,47,73,21,199,41,105,208,160,65,233,197,23,95,76,195,135,15,79,27,111,188,113,225,51,146,84,191,204,144,73,170,
42,63,255,252,115,122,253,245,215,211,85,87,93,149,46,187,236,178,244,205,55,223,196,199,36,169,158,25,144,73,170,42,223,127,255,125,186,242,202,43,211,227,143,63,158,250,247,239,159,30,120,224,129,244,
229,151,95,22,62,43,73,245,201,128,76,82,213,248,238,187,239,210,128,1,3,82,223,190,125,35,24,227,113,195,13,55,164,207,63,255,188,240,21,146,84,159,12,200,36,85,141,175,191,254,58,130,49,50,98,63,253,
244,83,250,244,211,79,35,32,27,56,112,96,225,43,36,169,62,25,144,73,170,26,111,190,249,102,58,245,212,83,35,75,6,26,252,127,249,229,151,120,43,73,245,204,128,76,82,85,120,251,237,183,211,99,143,61,150,
158,125,246,217,52,108,216,176,194,71,83,4,100,31,125,244,81,172,188,148,164,122,101,64,38,169,42,60,252,240,195,233,182,219,110,75,63,252,240,195,8,25,49,222,127,225,133,23,210,59,239,188,83,248,136,
36,213,31,3,50,73,85,225,195,15,63,28,109,208,197,138,203,215,94,123,173,240,76,146,234,143,1,153,164,138,98,204,5,101,74,2,174,193,131,7,23,62,250,63,100,200,40,103,230,190,50,73,170,71,6,100,146,42,
106,232,208,161,233,236,179,207,78,255,253,239,127,71,219,188,79,79,25,35,49,36,169,94,25,144,73,170,24,130,177,126,253,250,197,234,202,49,13,127,37,80,123,239,189,247,162,151,140,38,127,73,170,55,6,100,
146,42,134,193,175,15,62,248,96,244,143,177,111,229,152,16,184,61,253,244,211,110,163,36,169,46,25,144,73,170,24,134,192,158,119,222,121,163,236,29,43,69,22,237,209,71,31,53,32,147,84,151,12,200,36,85,
4,211,247,243,124,49,166,242,255,22,250,200,8,220,70,215,103,38,73,181,204,128,76,82,69,176,170,178,79,159,62,35,205,29,27,157,31,127,252,49,182,86,98,59,37,86,102,74,82,61,49,32,147,84,17,119,220,113,
71,186,253,246,219,11,207,198,206,87,95,125,21,3,100,221,219,82,82,189,49,32,147,84,86,100,185,110,186,233,166,244,252,243,207,143,85,239,88,49,190,158,64,238,179,207,62,43,124,68,146,234,131,1,153,164,
178,34,32,235,213,171,87,52,233,183,182,65,159,63,203,212,254,47,190,248,162,240,17,73,170,15,6,100,146,202,138,1,175,175,188,242,202,56,109,22,78,243,63,101,75,250,201,36,169,158,24,144,73,42,155,55,
222,120,35,221,120,227,141,81,114,28,151,160,138,230,127,130,50,182,82,250,248,227,143,11,31,149,164,218,103,64,38,169,44,8,192,122,247,238,157,174,188,242,202,24,97,49,174,8,202,94,124,241,197,8,238,
36,169,94,24,144,73,42,11,166,242,191,245,214,91,233,131,15,62,24,239,146,35,19,251,41,123,74,82,189,48,32,147,84,22,143,61,246,88,122,242,201,39,211,183,223,126,59,210,220,177,137,39,158,56,77,59,237,
180,105,186,233,166,43,124,228,87,19,76,48,65,225,189,17,17,220,57,250,66,82,61,49,32,147,212,174,8,190,200,136,221,123,239,189,177,66,18,4,90,147,78,58,105,154,122,234,169,211,204,51,207,156,102,157,
117,214,212,181,107,215,52,219,108,179,197,231,49,209,68,19,165,201,39,159,60,117,238,220,57,190,182,56,56,99,223,75,202,158,44,16,24,155,161,178,146,84,237,12,200,36,181,43,166,234,191,243,206,59,49,
170,130,192,108,194,9,39,140,64,107,209,69,23,77,251,236,179,79,186,250,234,171,211,21,87,92,145,182,217,102,155,17,2,178,78,157,58,165,85,87,93,53,62,191,204,50,203,196,159,201,8,194,216,144,252,153,
103,158,25,239,242,167,36,85,131,137,142,109,86,120,95,146,218,28,1,25,43,34,25,115,49,251,236,179,167,229,151,95,62,45,185,228,146,169,71,143,30,17,112,173,184,226,138,105,174,185,230,138,222,50,154,
254,9,222,48,211,76,51,165,21,86,88,33,237,185,231,158,145,9,227,207,146,73,251,228,147,79,98,126,25,101,206,142,29,59,166,165,150,90,42,50,104,146,84,203,38,104,190,211,52,223,47,169,221,124,243,205,
55,233,245,215,95,143,113,21,4,89,115,207,61,119,225,51,35,58,239,188,243,210,37,151,92,18,65,25,22,94,120,225,180,197,22,91,164,163,142,58,42,158,131,207,109,191,253,246,105,192,128,1,241,124,241,197,
23,79,215,93,119,93,154,126,250,233,227,185,36,213,42,75,150,146,218,213,100,147,77,150,230,153,103,158,52,239,188,243,70,64,54,58,67,135,14,141,161,175,25,13,254,244,151,21,35,152,59,227,140,51,162,196,
185,223,126,251,165,57,230,152,35,122,205,36,169,214,25,144,73,106,87,4,76,121,5,229,20,83,76,81,248,232,200,104,212,39,155,150,17,188,117,233,210,165,240,236,87,244,149,173,190,250,234,105,253,245,215,
79,27,110,184,97,148,61,59,116,232,80,248,172,36,213,46,3,50,73,85,129,94,51,130,178,140,126,177,110,221,186,21,158,141,140,114,37,229,203,49,5,121,146,84,43,12,200,36,85,5,86,75,22,175,152,36,27,54,227,
140,51,22,158,141,218,232,230,148,73,82,173,49,32,147,84,21,104,250,231,145,209,123,54,229,148,83,22,158,73,82,125,51,32,147,84,21,126,249,229,151,24,103,33,73,141,200,128,76,82,85,96,2,79,158,194,99,
41,82,82,163,49,32,147,84,149,12,202,36,53,18,3,50,73,85,161,56,67,198,246,74,6,100,146,26,137,1,153,164,170,195,236,50,3,50,73,141,196,128,76,82,69,145,21,251,246,219,111,91,70,94,16,136,177,79,165,19,
248,37,53,18,3,50,73,21,197,168,139,247,223,127,63,13,25,50,164,240,145,20,155,133,19,148,73,82,163,48,32,147,84,81,100,198,222,126,251,237,52,120,240,224,120,78,134,140,233,251,110,137,36,169,145,24,
144,73,170,40,50,100,239,188,243,206,8,1,217,84,83,77,21,89,50,73,106,20,6,100,146,42,138,97,176,31,127,252,113,250,250,235,175,227,57,1,25,27,145,59,165,95,82,35,49,32,147,84,81,4,100,3,7,14,140,198,
126,48,242,98,166,153,102,74,83,79,61,117,60,151,164,70,96,64,38,169,162,216,50,233,203,47,191,76,195,135,15,143,231,4,100,179,207,62,123,108,46,46,73,141,194,128,76,82,69,49,246,98,216,176,97,233,135,
31,126,136,231,4,100,221,186,117,75,157,59,119,142,231,146,212,8,12,200,36,85,20,1,217,119,223,125,23,205,253,96,254,88,151,46,93,162,143,76,146,26,133,1,153,164,138,34,32,35,59,70,47,25,104,234,159,117,
214,89,211,52,211,76,19,207,37,169,17,24,144,73,170,40,2,50,178,99,244,146,73,82,163,50,32,147,84,113,100,199,8,204,64,134,76,146,26,141,1,153,164,138,35,24,203,1,153,36,53,34,3,50,73,85,131,236,24,171,
44,37,169,209,120,230,147,84,113,197,229,74,2,50,203,150,146,26,141,1,153,164,170,65,32,54,201,36,147,24,144,73,106,56,6,100,146,42,230,155,111,190,73,159,124,242,73,203,12,50,178,99,29,58,116,48,32,147,
212,112,12,200,36,85,12,27,138,191,243,206,59,45,83,250,39,158,120,226,52,197,20,83,216,71,38,169,225,120,214,147,84,49,131,7,15,78,125,251,246,141,73,253,32,32,155,106,170,169,98,90,191,36,53,18,3,50,
73,21,51,116,232,208,244,254,251,239,183,100,200,40,87,78,63,253,244,17,152,73,82,35,49,32,147,84,49,244,144,245,239,223,191,165,135,108,178,201,38,75,51,207,60,115,52,246,75,82,35,49,32,147,84,49,148,
42,7,13,26,212,18,144,77,57,229,148,105,206,57,231,76,147,78,58,105,60,151,164,70,97,64,38,169,98,126,252,241,199,104,236,207,251,88,210,63,54,223,124,243,165,201,39,159,60,158,75,82,163,48,32,147,84,
49,4,100,195,134,13,139,189,44,49,245,212,83,167,249,231,159,223,128,76,82,195,49,32,147,84,49,4,98,223,127,255,125,203,164,126,50,100,243,206,59,111,244,146,73,82,35,49,32,147,84,49,148,42,201,146,229,
128,140,113,23,206,33,147,212,136,60,235,73,170,24,2,178,220,208,47,73,141,204,128,76,82,69,145,29,43,222,92,92,146,26,145,1,153,164,138,49,24,147,164,95,25,144,73,170,168,226,128,204,222,49,73,141,202,
179,159,164,170,64,48,102,64,38,169,81,121,246,147,84,17,223,126,251,109,60,50,246,175,116,15,75,73,141,202,128,76,82,69,12,30,60,56,125,241,197,23,133,103,191,6,100,238,97,41,169,81,25,144,73,170,136,
15,62,248,32,30,25,195,96,157,208,47,169,81,25,144,73,170,136,254,253,251,199,35,35,24,235,216,177,99,225,153,36,53,22,3,50,73,21,49,112,224,192,120,100,4,99,108,157,36,73,141,200,128,76,82,69,124,245,
213,87,105,200,144,33,133,103,41,77,55,221,116,169,115,231,206,133,103,146,212,88,12,200,36,85,196,208,161,67,227,145,17,140,205,58,235,172,133,103,146,212,88,12,200,36,85,196,240,225,195,227,145,17,140,
205,49,199,28,133,103,146,212,88,12,200,36,85,196,15,63,252,16,143,108,150,89,102,73,93,186,116,41,60,147,164,198,98,64,38,169,34,126,250,233,167,244,227,143,63,22,158,165,212,169,83,167,232,35,147,164,
70,100,64,38,169,34,8,200,126,254,249,231,194,51,73,106,108,6,100,146,42,130,77,197,243,198,226,146,212,232,12,200,36,85,68,113,64,54,193,4,19,196,91,73,106,84,6,100,146,42,162,52,32,51,40,147,212,200,
12,200,36,85,20,129,216,68,19,77,100,64,38,169,161,25,144,73,42,43,178,98,172,174,252,229,151,95,10,31,73,17,144,77,56,161,167,35,73,141,203,51,160,164,178,98,101,229,160,65,131,210,119,223,125,23,207,
201,140,117,232,208,33,130,50,73,106,84,6,100,146,202,138,97,176,111,191,253,118,203,62,150,4,100,147,79,62,121,154,100,146,73,226,185,36,53,34,3,50,73,101,245,253,247,223,167,215,94,123,45,13,30,60,56,
158,19,144,117,236,216,209,128,76,82,67,51,32,147,84,86,100,200,222,127,255,253,150,141,197,233,29,99,74,255,100,147,77,22,207,37,169,17,25,144,73,42,43,38,244,15,24,48,32,125,243,205,55,241,156,222,177,
206,157,59,167,41,167,156,50,158,75,82,35,50,32,147,84,86,4,100,3,7,14,108,105,234,39,32,155,117,214,89,211,84,83,77,21,207,37,169,17,25,144,73,42,43,198,93,124,253,245,215,81,186,4,189,99,221,186,117,
75,211,79,63,125,60,151,164,70,100,64,38,169,172,8,200,40,87,50,139,12,4,100,243,205,55,95,154,97,134,25,226,185,36,53,34,3,50,73,101,197,96,216,225,195,135,71,233,18,19,79,60,113,234,222,189,187,25,50,
73,13,205,128,76,82,89,17,144,17,140,229,125,44,37,73,6,100,146,42,128,105,253,121,235,36,247,176,148,36,3,50,73,101,70,102,140,96,204,12,153,36,253,143,1,153,164,178,203,193,24,217,49,51,100,146,100,
64,38,169,130,8,198,152,212,47,73,141,206,51,161,164,138,201,1,153,89,50,73,141,206,128,76,82,217,48,12,118,216,176,97,45,13,253,4,99,29,58,116,48,32,147,212,240,12,200,36,149,13,193,24,251,88,178,202,
18,108,155,52,233,164,147,26,144,73,106,120,6,100,146,202,134,61,44,251,246,237,219,178,109,18,67,97,217,84,220,62,50,73,141,206,179,160,164,178,249,242,203,47,211,187,239,190,219,178,109,18,217,177,78,
157,58,69,166,76,146,26,153,1,153,164,178,97,83,241,143,62,250,168,165,100,57,217,100,147,197,30,150,6,100,146,26,157,1,153,164,178,249,246,219,111,211,231,159,127,222,18,144,77,49,197,20,105,150,89,102,
137,13,198,37,169,145,25,144,73,42,155,239,190,251,46,125,245,213,87,45,171,44,167,158,122,234,212,181,107,215,88,105,41,73,141,204,128,76,82,217,208,204,63,116,232,208,150,128,140,254,177,238,221,187,
71,47,153,36,53,50,3,50,73,101,243,211,79,63,165,225,195,135,183,108,157,68,255,216,98,139,45,22,189,100,146,212,200,12,200,36,149,13,189,99,100,201,114,64,70,169,210,85,150,146,100,64,38,169,140,40,85,
146,37,147,36,141,200,128,76,82,217,144,25,35,40,203,25,50,73,210,175,12,200,36,149,85,14,198,216,46,201,45,147,36,233,87,6,100,146,202,134,96,204,128,76,146,70,102,64,38,169,34,216,191,210,61,44,37,233,
87,158,13,37,149,5,205,252,121,66,63,8,198,92,93,41,73,191,50,32,147,84,22,223,127,255,125,140,188,200,38,158,120,98,3,50,73,42,48,32,147,84,22,253,250,245,75,239,191,255,126,225,89,138,233,252,78,232,
151,164,95,25,144,73,42,139,15,62,248,32,125,242,201,39,133,103,41,77,62,249,228,177,185,184,36,201,128,76,82,153,16,140,125,250,233,167,133,103,41,117,236,216,49,30,146,36,3,50,73,101,50,120,240,224,
52,100,200,144,194,179,148,166,157,118,218,120,72,146,12,200,36,149,201,87,95,125,149,134,14,29,90,120,246,235,198,226,60,36,73,6,100,146,202,228,155,111,190,73,195,135,15,47,60,75,105,150,89,102,73,179,
206,58,107,225,153,36,53,54,3,50,73,101,241,221,119,223,197,232,139,172,107,215,174,241,144,36,25,144,73,42,19,102,144,253,248,227,143,133,103,41,205,60,243,204,241,144,36,25,144,73,42,19,38,245,243,200,
216,199,210,173,147,36,233,87,158,13,37,149,197,47,191,252,18,143,204,141,197,37,233,127,12,200,154,177,250,139,134,99,73,237,167,169,169,41,30,146,164,145,25,144,53,123,234,169,167,82,223,190,125,11,
207,36,181,135,226,128,204,82,165,36,141,168,161,207,138,31,125,244,81,58,245,212,83,211,85,87,93,149,46,185,228,146,116,202,41,167,164,115,207,61,55,61,249,228,147,105,224,192,129,133,175,146,212,22,
114,48,150,123,199,44,89,74,210,255,76,208,124,146,108,216,26,194,227,143,63,158,214,92,115,205,88,138,207,143,161,67,135,14,49,57,124,219,109,183,77,107,173,181,86,154,127,254,249,211,68,19,77,148,166,
153,102,154,216,119,207,187,122,105,220,240,250,218,124,243,205,211,127,254,243,159,8,196,38,153,100,146,184,9,218,126,251,237,11,95,33,73,141,173,161,35,12,46,18,63,255,252,115,203,157,59,75,242,191,
252,242,203,116,227,141,55,166,195,14,59,44,237,176,195,14,233,224,131,15,142,140,25,51,148,36,181,30,175,47,94,91,185,161,159,128,140,155,31,110,118,36,73,191,106,232,128,108,202,41,167,76,139,44,178,
72,100,197,184,56,112,225,96,86,210,135,31,126,152,94,122,233,165,244,196,19,79,164,7,31,124,48,93,115,205,53,233,130,11,46,72,23,94,120,97,4,107,239,189,247,94,225,111,144,244,91,200,64,191,251,238,187,
105,216,176,97,241,156,128,108,210,73,39,53,32,147,164,34,19,29,219,172,240,126,195,33,248,98,117,229,215,95,127,29,119,240,19,79,60,113,4,101,249,193,29,61,159,127,249,229,151,211,3,15,60,144,30,122,
232,161,244,230,155,111,198,118,47,179,207,62,123,108,3,195,92,37,74,153,94,92,164,81,99,21,51,55,55,15,63,252,112,234,223,191,127,188,206,184,9,90,119,221,117,211,2,11,44,80,248,42,73,106,108,13,221,
67,246,237,183,223,166,143,63,254,56,26,248,9,174,62,249,228,147,116,197,21,87,164,87,95,125,53,125,241,197,23,81,206,204,114,35,242,84,83,77,149,230,154,107,174,216,135,111,178,201,38,75,11,47,188,112,
90,111,189,245,210,210,75,47,93,248,74,73,197,120,93,209,47,118,237,181,215,198,13,13,175,155,110,221,186,165,19,78,56,33,173,191,254,250,133,175,146,164,198,214,208,25,50,26,139,167,159,126,250,52,231,
156,115,198,158,122,100,190,200,116,145,253,234,222,189,123,154,103,158,121,210,208,161,67,35,147,70,112,70,198,140,94,178,79,63,253,52,74,48,239,191,255,126,4,110,148,98,62,255,252,243,244,218,107,175,
197,251,252,189,29,59,118,44,252,43,82,99,227,53,114,251,237,183,167,55,222,120,35,178,209,148,43,231,157,119,222,180,234,170,171,186,151,165,36,21,52,116,134,236,183,48,22,99,255,253,247,79,207,61,247,
92,26,52,104,80,4,101,57,48,43,69,16,70,246,108,147,77,54,73,91,108,177,69,90,105,165,149,34,171,70,128,231,18,127,53,50,178,98,188,142,158,127,254,249,8,206,88,181,76,102,108,159,125,246,73,203,45,183,
92,225,171,36,169,177,25,144,141,1,37,77,250,199,6,15,30,28,15,178,98,189,122,245,138,204,24,37,206,226,31,29,65,23,189,49,179,205,54,91,154,99,142,57,162,164,73,128,182,206,58,235,164,165,150,90,42,62,
38,53,34,50,199,59,239,188,115,188,37,227,60,227,140,51,166,61,247,220,51,109,181,213,86,246,144,73,82,129,1,217,88,162,20,73,32,118,195,13,55,196,91,50,102,3,6,12,136,21,151,92,100,138,251,205,144,51,
102,204,51,163,191,172,75,151,46,177,170,147,11,208,204,51,207,28,193,155,212,8,250,244,233,147,182,220,114,203,150,27,25,90,2,78,62,249,228,212,163,71,143,184,113,81,125,99,23,20,122,117,89,32,197,121,
111,201,37,151,140,27,87,73,35,50,32,107,5,126,84,4,94,188,253,224,131,15,210,157,119,222,153,46,191,252,242,244,214,91,111,69,54,173,84,94,8,192,99,138,41,166,136,160,236,232,163,143,78,107,175,189,182,
61,102,106,24,100,153,55,218,104,163,88,97,201,106,230,255,251,191,255,75,183,221,118,91,188,229,198,69,245,141,115,30,3,129,185,121,229,166,244,162,139,46,138,214,14,73,35,50,32,27,71,100,204,184,235,
235,215,175,95,52,42,243,62,99,49,184,248,144,61,99,28,70,49,238,12,57,25,253,238,119,191,139,242,37,239,243,118,131,13,54,136,143,73,245,138,153,126,140,184,96,225,11,55,52,172,176,188,247,222,123,227,
6,133,155,21,213,31,246,7,230,119,204,76,199,23,94,120,33,178,163,156,51,57,15,94,122,233,165,145,49,101,56,176,164,255,49,32,107,35,4,100,100,204,104,92,254,236,179,207,210,144,33,67,210,219,111,191,
29,111,243,214,76,25,153,51,150,254,207,61,247,220,209,71,67,73,147,19,21,179,153,88,241,57,195,12,51,20,190,82,170,125,189,123,247,142,210,61,13,253,44,136,97,133,37,115,253,236,171,172,47,204,155,99,
1,7,45,28,4,99,55,223,124,115,100,197,114,59,71,174,24,16,144,113,222,99,181,173,164,255,49,32,107,35,156,116,24,143,145,183,136,161,140,121,226,137,39,198,10,77,2,180,210,140,89,94,129,73,96,198,131,
126,179,229,151,95,62,154,159,25,7,32,213,139,23,95,124,49,246,140,101,97,12,167,27,3,178,250,68,38,148,242,36,115,28,201,134,50,34,168,184,183,150,96,140,61,129,123,246,236,153,54,219,108,179,56,7,74,
250,31,3,178,118,66,102,236,217,103,159,141,153,101,244,151,17,148,93,127,253,245,49,74,131,230,214,226,31,59,39,38,210,247,204,65,91,112,193,5,35,115,198,137,107,241,197,23,143,6,88,230,161,73,181,138,
128,108,141,53,214,136,128,140,99,61,7,100,52,247,171,182,113,19,74,127,24,43,104,201,142,177,239,47,153,80,170,2,25,125,130,180,101,172,178,202,42,49,119,142,99,193,115,154,52,50,3,178,50,97,90,249,105,
167,157,22,153,51,78,88,164,245,233,175,32,56,43,190,139,4,229,75,154,254,57,129,173,190,250,234,113,50,227,164,70,192,54,221,116,211,197,2,1,169,86,16,144,113,28,179,113,63,1,217,124,243,205,151,238,
187,239,62,3,178,26,198,2,13,110,54,9,178,207,57,231,156,244,204,51,207,68,86,44,95,78,138,23,50,209,130,193,185,140,172,24,3,183,57,191,73,26,153,1,89,153,80,178,228,130,68,73,147,128,236,149,87,94,73,
167,159,126,122,4,104,52,187,22,255,26,184,104,241,224,132,198,99,234,169,167,142,254,50,202,153,92,216,88,157,38,213,138,226,128,140,11,245,252,243,207,159,238,185,231,30,3,178,26,118,217,101,151,197,
86,88,236,190,64,53,128,113,38,197,55,150,100,252,9,188,15,60,240,192,180,216,98,139,197,152,11,218,50,184,177,228,220,38,105,100,6,100,21,192,201,139,187,75,86,34,229,121,102,164,252,89,16,192,115,130,
182,98,220,81,230,18,38,193,24,115,204,200,148,209,40,205,138,53,87,43,169,154,21,7,100,28,203,148,229,89,0,227,44,170,218,194,34,165,251,239,191,63,206,87,79,63,253,116,203,138,242,140,96,155,115,17,
37,73,246,248,37,27,182,194,10,43,68,102,159,243,151,164,49,51,32,171,2,172,208,124,236,177,199,210,45,183,220,18,61,102,220,113,146,69,99,156,6,61,26,165,217,51,22,1,112,146,99,235,153,101,151,93,54,
70,104,112,194,35,80,227,46,84,170,22,244,18,81,206,218,120,227,141,227,184,102,101,221,34,139,44,18,43,240,12,200,170,31,55,135,180,91,144,197,127,226,137,39,210,5,23,92,16,89,125,110,42,51,2,49,110,
16,59,119,238,28,111,217,133,97,229,149,87,54,3,42,181,146,1,89,21,224,164,71,79,25,203,198,9,192,184,19,101,1,0,65,26,119,163,165,25,51,78,128,164,254,217,130,134,94,51,130,48,26,165,247,222,123,239,
88,169,41,85,11,198,30,144,13,59,252,240,195,227,162,206,205,3,153,222,235,174,187,46,110,42,84,221,200,228,179,171,2,217,123,134,97,15,28,56,48,130,236,188,159,111,190,65,36,224,166,71,108,161,133,22,
138,158,49,206,75,102,238,165,214,49,32,171,66,52,199,114,2,36,48,35,72,35,40,123,228,145,71,226,78,149,69,0,197,155,155,115,66,36,235,192,221,41,141,179,148,52,57,65,210,76,203,10,77,86,108,74,149,194,
216,151,171,175,190,58,166,179,147,85,161,23,146,13,197,153,69,69,70,87,213,233,209,71,31,141,45,143,8,168,153,41,70,48,198,77,99,70,233,153,153,137,191,255,253,239,227,237,50,203,44,147,150,88,98,9,183,
194,146,198,131,1,89,13,160,68,112,230,153,103,70,207,6,165,76,46,108,4,109,100,211,74,87,104,50,219,140,69,0,108,104,190,221,118,219,197,197,143,143,229,76,26,193,154,84,46,92,204,47,188,240,194,116,
215,93,119,69,102,133,11,54,55,14,44,104,225,38,66,213,131,128,43,15,178,62,235,172,179,210,29,119,220,17,19,246,243,37,130,155,63,206,37,211,79,63,125,234,212,169,83,180,75,236,181,215,94,209,19,232,
86,112,210,248,51,32,171,1,4,96,57,59,198,106,205,119,223,125,55,202,8,100,208,232,51,43,254,21,230,147,38,193,87,238,233,152,102,154,105,210,106,171,173,22,139,0,104,182,149,202,133,25,85,4,95,204,228,
163,244,206,252,169,245,215,95,63,6,136,114,97,87,245,160,97,255,170,171,174,138,243,10,35,121,24,105,193,112,215,140,172,24,229,200,61,246,216,35,50,98,252,46,9,176,89,9,206,57,71,210,248,49,32,171,65,
12,153,189,233,166,155,162,148,73,198,140,153,64,172,122,98,21,27,89,179,98,156,40,233,219,161,145,154,222,29,78,162,156,64,89,138,206,144,70,74,72,82,123,225,2,207,142,21,100,121,201,230,114,220,109,
187,237,182,105,215,93,119,141,27,5,85,22,61,97,148,39,201,184,179,248,130,214,8,206,39,57,243,206,13,30,129,24,191,55,50,97,156,51,242,234,110,178,100,146,218,142,1,89,141,227,46,150,177,2,167,158,122,
106,122,231,157,119,162,231,140,187,90,118,7,224,164,90,154,61,163,223,140,187,92,46,136,100,205,232,57,35,104,163,204,73,19,46,95,35,181,21,122,199,142,59,238,184,184,121,160,247,145,109,193,246,221,
119,223,216,74,137,27,5,149,31,231,4,202,147,156,39,232,19,59,246,216,99,227,45,229,202,124,190,200,231,10,50,237,156,27,56,95,252,225,15,127,136,81,22,146,218,135,1,89,141,163,12,68,217,146,94,15,130,
48,154,111,153,111,70,207,14,43,164,138,183,48,65,158,21,196,146,116,74,70,148,52,105,174,222,125,247,221,211,162,139,46,106,143,153,218,212,185,231,158,27,229,201,124,177,103,83,233,227,143,63,62,22,
157,144,121,81,249,209,246,112,254,249,231,199,121,130,155,184,126,253,250,197,10,216,226,213,220,4,99,244,136,109,190,249,230,49,224,149,204,24,45,16,6,209,82,251,49,32,171,51,148,30,104,254,207,123,
202,145,153,96,154,118,222,166,169,116,133,38,193,25,129,217,38,155,108,18,119,191,220,17,19,164,177,66,211,21,83,26,95,44,70,57,242,200,35,227,102,129,83,13,153,22,62,198,220,60,179,177,229,197,240,105,
30,148,41,111,184,225,134,216,45,36,111,248,14,110,214,104,97,96,181,36,55,108,244,137,145,69,103,21,37,99,118,36,181,47,3,178,58,71,41,162,103,207,158,177,119,32,193,25,101,10,178,102,165,229,76,112,
66,166,60,177,192,2,11,164,163,142,58,42,150,180,115,209,164,164,73,224,102,227,174,90,139,253,91,153,65,150,123,27,89,149,119,222,121,231,197,251,106,127,188,206,243,235,253,146,75,46,137,45,143,94,125,
245,213,17,94,251,249,198,140,222,82,182,181,226,247,69,48,198,156,67,73,229,99,64,86,231,40,103,146,29,35,115,70,48,198,10,42,246,160,163,201,154,207,229,230,93,112,98,166,140,68,150,140,108,25,37,10,
150,179,51,236,113,131,13,54,136,166,94,169,53,232,109,60,244,208,67,91,142,51,3,178,242,234,211,167,79,250,247,191,255,29,243,196,200,148,211,210,192,235,62,227,38,140,242,36,165,100,134,74,51,96,154,
7,153,50,62,46,169,124,12,200,26,12,189,102,140,34,96,116,6,141,189,148,53,25,222,201,98,0,122,72,138,15,135,188,66,147,30,18,86,86,145,57,163,199,108,142,57,230,72,115,205,53,151,99,11,244,155,78,57,
229,148,116,200,33,135,180,28,87,6,100,237,143,27,47,22,250,176,26,155,183,189,122,245,138,155,50,62,158,113,227,197,107,152,224,139,30,82,26,246,105,83,112,88,175,84,57,6,100,13,142,126,179,253,246,219,
47,122,75,104,188,166,199,108,116,135,4,101,13,178,102,155,110,186,105,218,102,155,109,98,248,108,102,63,144,70,229,95,255,250,87,4,100,224,24,33,32,163,209,95,109,47,191,110,9,196,14,58,232,160,244,240,
195,15,71,155,66,233,235,153,223,3,229,73,94,195,204,20,99,28,142,175,95,169,242,12,200,26,28,65,216,11,47,188,16,25,50,178,101,111,190,249,102,186,241,198,27,227,164,94,124,71,13,202,27,100,200,104,248,
229,238,154,187,105,74,27,107,175,189,118,172,208,244,238,90,165,138,3,50,50,174,108,60,125,206,57,231,196,115,181,45,54,108,103,3,112,178,223,189,123,247,142,54,133,226,77,192,105,204,103,126,24,11,120,
24,119,67,198,155,185,132,44,226,145,84,121,6,100,106,65,80,246,250,235,175,199,198,230,220,89,179,26,139,209,25,148,59,56,177,23,247,155,129,140,25,39,115,250,203,88,153,69,41,147,213,115,244,156,241,
113,23,1,168,56,32,35,32,32,32,99,91,30,181,13,94,167,121,199,14,94,183,121,207,219,124,90,39,243,69,47,24,109,7,108,230,206,141,211,150,91,110,25,129,152,35,44,164,234,98,64,166,22,28,10,148,44,89,17,
199,251,100,203,238,188,243,206,116,229,149,87,166,143,62,250,104,164,140,25,56,225,115,161,205,139,1,152,47,117,194,9,39,196,30,154,148,69,212,216,138,3,50,130,117,74,100,108,165,164,182,113,235,173,
183,198,74,86,154,247,243,214,106,197,163,109,120,109,178,90,242,136,35,142,72,171,175,190,122,188,62,249,24,217,110,203,148,82,117,49,32,211,104,81,206,36,59,70,96,198,201,158,82,200,99,143,61,22,39,
127,178,105,165,25,51,78,244,4,101,75,47,189,116,204,48,227,125,202,155,148,72,184,35,87,99,97,232,40,229,201,51,206,56,35,158,179,85,18,1,217,73,39,157,20,207,53,110,200,138,209,168,207,2,29,198,218,
208,7,202,60,177,252,122,36,208,34,123,205,38,238,172,156,164,60,73,159,216,108,179,205,230,38,224,82,21,51,32,211,88,163,52,66,198,140,141,162,185,0,208,115,198,69,129,114,73,233,10,77,238,192,41,137,
48,225,123,231,157,119,142,77,205,9,216,216,255,142,210,166,251,24,214,63,102,223,93,122,233,165,17,60,96,166,153,102,138,29,33,216,74,73,173,199,235,143,54,2,110,144,46,184,224,130,120,203,141,81,198,
107,142,149,207,100,193,200,138,109,188,241,198,105,141,53,214,72,115,207,61,119,225,43,36,85,51,3,50,141,53,202,33,244,146,49,104,146,178,8,75,234,41,151,188,244,210,75,35,220,161,103,92,32,40,101,18,
152,81,174,162,175,140,82,38,23,101,150,216,171,190,49,136,148,25,88,108,94,13,130,243,221,118,219,45,29,118,216,97,241,92,173,243,215,191,254,53,221,125,247,221,49,83,140,145,53,220,4,21,151,39,89,112,
67,86,140,149,172,191,251,221,239,226,245,198,199,220,162,74,170,13,6,100,26,103,52,252,147,45,99,69,38,129,26,67,39,89,161,201,93,60,253,102,165,25,51,130,50,202,38,52,22,147,37,99,87,0,46,28,121,171,
22,213,23,122,9,105,52,103,139,30,80,54,35,91,186,207,62,251,196,115,253,182,103,158,121,38,61,254,248,227,169,127,255,254,209,46,64,25,184,56,43,198,194,25,178,97,172,116,102,166,24,153,104,126,206,140,
167,49,16,147,106,139,1,153,218,12,43,52,105,226,102,1,192,151,95,126,25,165,204,143,63,254,184,37,163,86,140,242,37,229,149,85,87,93,53,134,206,178,101,11,171,193,40,107,81,214,116,74,120,237,99,22,22,
67,136,41,107,131,242,217,142,59,238,24,243,175,52,122,100,191,120,13,177,255,39,163,44,216,119,146,13,192,243,169,154,30,49,110,112,88,53,73,224,69,32,198,30,161,220,220,56,172,89,170,93,6,100,106,51,
4,94,131,6,13,138,82,10,51,144,200,158,49,226,128,101,248,100,208,138,15,53,46,42,121,39,0,154,255,233,41,99,33,0,23,236,21,87,92,49,54,52,86,109,163,52,205,42,64,142,5,108,191,253,246,241,32,48,211,232,
49,23,144,27,27,182,58,34,51,70,70,44,239,5,10,94,55,100,155,25,33,66,102,140,109,206,152,7,72,121,210,81,51,82,237,50,32,83,187,96,85,38,43,52,41,183,112,65,33,83,70,6,141,139,13,153,51,250,209,138,145,
49,163,132,201,244,127,86,100,50,100,150,30,152,117,214,89,39,202,153,124,94,181,101,187,237,182,75,119,220,113,71,75,137,237,152,99,142,73,91,111,189,117,204,196,210,136,184,97,161,63,140,146,36,155,
127,63,244,208,67,17,200,114,147,147,241,26,160,36,185,236,178,203,70,227,254,10,43,172,16,63,75,179,98,82,125,48,32,83,89,80,114,225,34,67,9,134,11,13,35,53,40,107,14,27,54,44,130,179,210,236,25,153,
51,178,100,7,31,124,112,92,132,120,78,6,128,146,38,217,1,85,191,205,54,219,44,221,117,215,93,17,108,224,226,139,47,78,155,111,190,185,43,108,139,144,81,230,181,192,107,130,172,216,211,79,63,29,239,231,
215,3,175,5,142,119,74,147,100,193,214,93,119,221,216,8,156,18,191,217,48,169,190,24,144,169,44,104,242,39,51,198,106,76,74,154,52,122,19,156,145,65,227,99,165,25,51,46,54,204,82,162,140,201,236,36,250,
202,216,246,229,128,3,14,72,11,46,184,96,225,171,84,205,24,187,64,64,198,239,27,215,93,119,93,4,105,6,18,255,211,179,103,207,116,219,109,183,197,13,11,229,201,188,122,50,227,53,192,241,78,121,146,183,
220,164,144,17,35,72,35,88,147,84,63,12,200,84,17,52,45,63,247,220,115,45,67,103,89,161,73,118,128,161,151,4,111,197,139,0,184,240,48,245,159,236,24,37,76,46,74,60,231,45,37,78,130,54,85,31,182,212,162,
12,151,199,161,176,2,151,141,233,27,29,193,215,83,79,61,21,153,48,178,198,148,241,89,153,156,79,197,52,236,147,13,166,151,146,134,125,246,156,100,202,62,43,148,205,14,75,245,203,128,76,85,225,249,231,
159,79,231,158,123,110,76,29,167,231,136,21,102,57,115,86,186,66,147,229,252,100,9,150,89,102,153,150,213,101,100,93,8,210,40,109,146,85,80,229,173,183,222,122,233,158,123,238,105,249,253,53,114,64,198,
113,204,241,76,79,216,253,247,223,159,206,62,251,236,104,218,47,222,142,140,27,143,188,192,133,18,229,159,255,252,231,212,163,71,15,71,194,72,13,194,128,76,85,129,82,13,141,255,185,167,140,146,230,153,
103,158,25,153,52,50,104,197,135,41,23,174,188,8,128,165,255,244,214,48,139,137,161,152,107,174,185,102,108,21,163,202,163,223,137,128,140,223,29,191,51,198,55,52,106,64,198,177,77,16,70,195,62,91,144,
229,177,22,57,88,229,231,67,86,108,195,13,55,140,64,150,102,125,102,245,113,108,59,2,70,106,12,6,100,170,74,92,180,110,186,233,166,40,235,144,89,224,2,198,24,13,130,179,226,30,27,144,49,163,199,140,129,
179,236,0,192,10,180,60,116,54,15,160,85,249,81,94,38,32,35,216,160,12,199,22,74,236,107,218,72,40,77,178,114,146,7,199,51,51,217,184,249,200,56,118,201,128,113,220,114,115,177,242,202,43,71,230,151,242,
164,164,198,98,64,166,170,71,80,70,243,63,171,208,104,124,38,139,70,233,39,239,6,80,124,8,115,241,167,207,134,254,50,54,178,230,2,71,128,70,73,147,114,38,111,249,26,181,63,102,100,221,123,239,189,241,
243,38,240,160,169,191,17,2,50,142,77,86,150,210,59,199,190,157,183,223,126,123,4,98,197,199,105,46,177,83,162,164,44,185,255,254,251,167,133,22,90,40,62,38,169,49,25,144,169,234,113,129,99,68,6,89,6,
130,176,220,20,77,246,133,143,151,102,204,184,216,229,160,108,134,25,102,136,126,51,50,101,12,42,165,156,105,9,168,60,114,64,70,118,140,159,249,53,215,92,19,43,47,235,29,61,98,172,32,102,207,73,22,173,
176,181,24,229,201,140,224,148,57,123,59,236,176,67,100,113,57,38,217,0,156,224,140,99,87,82,99,50,32,83,205,161,31,135,141,205,243,208,89,118,2,120,251,237,183,71,185,77,83,206,152,177,18,115,203,45,
183,76,115,205,53,87,92,248,232,205,97,133,38,195,103,213,182,248,29,124,241,197,23,105,219,109,183,77,143,60,242,72,4,25,252,204,175,184,226,138,232,145,170,71,204,19,99,213,48,55,8,15,63,252,112,4,101,
148,217,139,123,196,8,196,200,130,17,128,241,32,56,101,202,190,115,217,36,193,128,76,53,143,113,25,92,236,201,152,17,8,176,205,76,30,54,91,122,120,19,28,16,132,49,108,246,196,19,79,140,12,5,200,226,112,
193,180,156,57,254,232,249,163,223,239,168,163,142,138,145,14,44,192,32,83,201,96,88,26,214,235,9,217,89,130,46,86,9,31,126,248,225,169,79,159,62,113,147,80,124,220,113,204,177,242,151,146,249,129,7,30,
24,11,27,24,103,33,73,197,12,200,84,243,8,194,152,99,246,233,167,159,70,48,198,69,145,146,17,165,77,22,1,148,102,204,184,56,146,149,32,91,65,57,147,5,1,204,122,218,104,163,141,162,116,164,241,67,102,232,
250,235,175,143,0,236,173,183,222,138,213,131,244,241,177,175,41,171,96,235,5,229,115,6,187,190,244,210,75,145,161,205,193,88,113,9,157,82,45,91,29,173,191,254,250,145,21,99,245,36,77,252,12,59,150,164,
98,6,100,170,59,140,22,96,83,107,2,50,122,119,232,225,97,190,25,171,219,70,181,35,64,14,200,24,100,202,62,154,52,86,115,209,164,7,205,21,154,173,71,16,118,218,105,167,165,59,239,188,51,202,200,4,31,139,
44,178,72,58,225,132,19,98,145,69,173,35,248,162,63,140,227,234,202,43,175,140,128,140,155,130,124,42,37,219,202,49,69,192,207,48,227,149,86,90,41,86,156,82,46,183,71,76,210,232,24,144,169,238,112,72,
147,21,203,135,246,163,143,62,154,14,57,228,144,184,144,178,66,115,84,135,60,23,209,220,111,198,2,0,202,74,108,132,77,160,166,214,33,83,116,232,161,135,70,79,21,189,85,244,235,177,146,144,143,49,210,161,
214,49,31,143,204,216,107,175,189,22,43,41,139,51,176,32,43,70,41,252,216,99,143,77,139,47,190,120,148,107,243,241,37,73,163,99,64,166,186,71,38,131,94,38,246,210,100,139,154,190,125,251,166,91,110,185,
37,54,117,166,196,89,140,12,70,222,216,188,107,215,174,145,225,96,106,250,90,107,173,21,193,25,37,78,141,25,11,46,246,218,107,175,152,68,207,207,156,21,133,4,183,59,239,188,115,100,141,106,81,46,131,83,
142,37,35,70,246,149,227,39,227,184,161,52,203,88,143,37,150,88,34,122,196,8,202,56,94,92,213,43,105,108,24,144,169,161,208,112,78,192,112,237,181,215,198,251,4,104,4,108,148,214,8,206,74,251,205,184,
152,50,176,147,254,50,6,207,242,62,43,6,233,5,162,20,103,9,106,100,52,244,111,191,253,246,17,188,48,143,139,82,221,97,135,29,214,178,15,105,173,224,123,39,168,100,229,36,99,86,24,219,193,192,98,86,145,
102,252,254,41,111,211,35,71,240,206,255,123,233,165,151,142,247,37,169,53,12,200,212,80,8,184,232,35,203,67,101,217,162,137,193,157,255,254,247,191,91,86,104,22,35,40,203,115,180,88,45,72,249,109,254,
249,231,79,199,31,127,124,100,204,200,138,104,68,172,122,165,228,155,127,158,252,156,46,185,228,146,180,224,130,11,214,84,79,30,65,250,145,71,30,153,158,121,230,153,24,72,204,49,67,137,50,159,50,57,54,
232,55,220,110,187,237,226,193,202,93,142,7,142,19,142,25,73,106,13,3,50,53,52,122,156,104,208,126,253,245,215,227,130,75,70,132,108,8,11,3,242,180,245,140,11,48,43,52,25,155,177,252,242,203,71,111,16,
205,219,244,156,81,170,98,214,153,82,122,242,201,39,99,222,24,229,74,130,95,74,119,44,178,32,187,72,176,82,237,8,208,41,113,147,13,227,88,24,48,96,192,8,131,93,249,63,116,235,214,173,165,81,159,204,41,
65,186,229,108,73,227,195,128,76,42,66,127,16,171,3,255,251,223,255,198,2,0,2,54,50,37,172,208,44,206,142,32,175,166,163,95,104,239,189,247,142,145,25,121,164,6,65,90,163,110,131,243,196,19,79,68,176,
146,55,207,166,177,253,129,7,30,136,236,98,181,98,123,46,6,12,51,38,133,108,222,67,15,61,20,191,247,252,251,206,229,107,74,147,244,20,82,150,252,227,31,255,24,163,44,220,238,72,82,91,48,32,147,138,208,
31,196,69,57,79,252,127,236,177,199,210,5,23,92,208,50,54,163,116,69,29,61,68,100,76,8,194,88,161,73,3,59,43,9,105,106,103,10,123,35,98,7,5,230,141,241,51,228,244,82,11,1,25,139,60,46,188,240,194,200,
144,210,91,72,48,89,60,34,133,223,49,25,208,131,14,58,40,178,163,4,102,244,18,18,128,19,172,73,210,248,50,32,147,198,128,77,161,25,223,192,208,89,2,12,102,108,221,117,215,93,145,57,163,63,170,248,229,
67,198,140,70,127,178,99,100,80,8,206,242,174,0,4,37,51,206,56,99,225,43,235,27,65,44,1,89,254,249,176,234,144,173,132,170,45,32,163,47,236,182,219,110,139,146,36,11,61,248,61,179,200,35,7,221,185,68,
189,226,138,43,198,255,129,25,117,43,172,176,66,44,76,112,176,171,164,182,102,64,38,181,2,13,222,76,156,255,240,195,15,163,71,138,201,236,172,210,204,91,232,20,227,98,62,219,108,179,165,213,87,95,61,74,
120,140,209,160,233,155,192,140,236,74,45,244,83,141,11,2,178,53,214,88,35,2,50,130,154,156,33,163,188,91,105,156,238,40,69,242,187,99,148,197,169,167,158,26,65,54,217,207,124,42,36,176,38,227,73,64,77,
16,201,202,73,198,158,184,139,131,164,246,100,64,38,181,2,229,76,178,40,4,27,100,205,8,62,46,186,232,162,232,65,42,30,135,0,130,17,130,46,130,47,46,240,4,36,4,101,121,52,2,23,252,122,196,207,132,32,148,
32,149,224,134,236,210,125,247,221,87,21,1,25,191,183,127,254,243,159,49,44,56,79,219,231,247,86,188,120,131,160,121,213,85,87,77,59,238,184,99,172,16,101,132,5,171,67,9,176,37,169,189,24,144,73,227,136,
44,11,3,66,233,153,34,195,66,214,140,213,154,44,12,40,93,161,9,46,232,172,204,100,111,67,178,45,52,135,19,148,81,222,227,227,108,110,94,15,138,3,50,122,236,150,90,106,169,116,247,221,119,87,52,32,99,54,
26,43,39,41,79,178,9,61,89,49,178,155,25,223,39,191,15,118,20,96,229,36,89,61,126,79,244,141,57,107,78,82,57,24,144,73,109,132,29,0,200,4,221,120,227,141,45,229,76,30,121,181,97,241,75,141,236,25,89,23,
50,48,108,41,148,247,208,204,37,205,90,45,103,18,132,61,242,200,35,105,189,245,214,139,247,9,66,89,228,64,175,86,185,3,50,126,238,204,66,35,3,118,229,149,87,166,235,174,187,46,2,232,252,123,224,119,192,
131,113,21,148,38,249,93,236,191,255,254,177,239,38,189,127,146,84,78,6,100,82,27,33,0,96,170,59,13,255,100,199,232,55,99,166,21,131,82,25,161,81,154,49,35,35,150,247,206,36,24,35,48,96,120,42,65,65,45,
77,180,47,70,163,60,99,67,24,3,194,42,69,254,95,172,74,36,72,165,108,91,78,52,233,159,127,254,249,17,132,125,240,193,7,81,106,38,115,153,145,249,34,0,222,99,143,61,98,211,115,102,139,49,43,141,173,179,
234,37,91,41,169,118,24,144,73,237,132,205,204,41,149,189,249,230,155,49,116,150,192,128,178,25,125,75,99,90,161,185,193,6,27,68,223,82,126,78,201,175,86,50,54,148,107,175,191,254,250,244,175,127,253,
43,2,80,178,98,43,173,180,82,186,234,170,171,202,50,165,159,30,63,50,116,52,238,243,189,80,42,205,43,100,51,178,143,100,195,24,232,202,162,11,26,246,9,132,29,236,42,169,146,12,200,164,50,121,240,193,7,
211,197,23,95,28,129,2,129,3,25,53,122,207,200,36,149,190,12,243,220,171,229,150,91,46,237,179,207,62,49,128,148,172,13,25,29,178,106,213,154,193,161,100,219,179,103,207,212,171,87,175,40,211,18,88,174,
182,218,106,49,203,141,197,13,237,133,159,35,217,47,50,116,199,30,123,108,100,37,201,136,229,159,43,165,73,202,167,124,15,4,134,91,108,177,69,218,118,219,109,107,118,179,115,73,245,199,128,76,42,19,6,
142,230,145,11,100,143,8,26,46,189,244,210,248,24,25,156,226,151,34,1,4,147,225,201,48,81,190,228,45,229,52,74,107,140,148,32,179,83,141,8,196,40,19,210,216,79,64,198,170,82,250,201,78,56,225,132,118,
157,221,117,197,21,87,196,104,13,182,59,34,19,57,100,200,144,200,66,102,4,99,4,95,59,236,176,67,12,236,229,251,34,224,117,158,152,164,106,97,64,38,85,8,115,176,104,118,167,132,73,239,25,125,78,100,207,
200,156,149,246,155,145,49,163,217,159,213,127,52,201,19,156,81,198,36,200,224,253,106,217,190,231,178,203,46,75,103,158,121,102,252,223,56,181,80,22,220,124,243,205,211,159,255,252,231,54,255,30,9,190,
248,121,17,232,242,115,164,60,204,248,145,124,74,163,12,204,191,185,228,146,75,198,202,73,246,212,36,56,156,125,246,217,35,203,40,73,213,196,128,76,170,2,236,163,200,56,6,130,25,122,158,8,202,88,165,200,
163,244,37,74,246,140,198,115,54,180,102,139,38,166,199,231,241,12,148,52,9,68,42,229,236,179,207,78,167,156,114,74,250,232,163,143,226,251,102,140,196,46,187,236,18,65,25,25,191,241,69,214,141,126,60,
2,214,155,111,190,57,157,126,250,233,233,181,215,94,27,33,27,150,203,147,4,93,252,92,142,60,242,200,248,62,170,53,171,40,73,48,32,147,170,0,65,6,153,50,178,62,188,207,158,138,79,62,249,100,148,225,232,
55,43,222,87,17,244,144,209,15,69,230,135,102,116,178,103,172,18,36,248,33,8,169,212,216,12,38,223,51,120,149,113,19,156,90,182,220,114,203,244,151,191,252,37,45,182,216,98,109,210,247,70,22,145,205,191,
223,121,231,157,152,37,70,121,178,120,143,81,130,49,130,210,245,215,95,63,134,187,242,51,161,68,201,156,55,62,46,73,213,202,128,76,170,66,4,28,140,109,160,23,139,128,140,140,19,193,26,131,77,75,179,102,
57,99,70,95,212,54,219,108,19,195,102,105,92,39,8,161,196,201,231,202,133,96,140,126,49,130,36,236,185,231,158,209,100,79,192,56,174,153,59,254,175,236,53,73,175,29,129,234,213,87,95,29,83,246,25,37,146,
145,29,36,3,198,234,73,254,255,108,85,69,230,208,172,152,164,90,97,64,38,213,128,123,239,189,55,26,215,121,75,32,66,80,134,81,189,124,9,78,8,74,152,52,207,248,137,46,93,186,196,199,9,220,120,180,167,227,
143,63,62,30,121,204,196,193,7,31,156,78,62,249,228,120,191,181,248,191,241,32,251,69,150,141,62,49,50,100,165,255,103,254,79,244,138,173,187,238,186,233,192,3,15,140,190,53,179,97,146,106,141,1,153,84,
3,232,43,35,43,196,91,202,151,52,176,51,99,139,76,26,253,83,185,100,135,92,182,35,67,70,35,59,3,89,121,159,89,91,27,110,184,97,140,162,104,47,199,29,119,92,250,251,223,255,222,82,98,29,159,128,140,114,
45,99,52,216,146,170,119,239,222,209,103,71,182,48,163,4,202,130,6,70,88,208,79,55,223,124,243,69,121,146,21,169,110,119,36,169,214,24,144,73,53,136,128,140,93,0,232,161,34,27,69,176,194,0,218,209,237,
8,64,201,112,225,133,23,78,155,108,178,73,148,241,40,99,242,150,21,135,109,185,250,241,111,127,251,91,4,101,57,64,108,109,64,70,239,25,77,250,140,6,97,226,255,93,119,221,21,1,89,62,77,17,108,18,108,17,
120,49,52,119,222,121,231,141,50,45,193,88,185,119,2,144,164,182,100,64,38,213,32,130,46,178,80,4,62,188,132,9,206,254,241,143,127,68,128,198,162,128,210,151,117,14,100,8,206,8,192,104,118,255,195,31,
254,144,182,218,106,171,150,146,102,91,160,95,140,128,140,127,159,127,243,160,131,14,106,85,64,198,66,134,99,142,57,38,189,250,234,171,49,10,36,255,31,51,254,15,124,255,236,255,185,209,70,27,197,192,92,
22,48,208,159,198,191,39,73,181,202,128,76,170,3,244,86,81,214,99,51,115,38,212,211,4,127,255,253,247,199,128,212,210,21,154,4,53,100,147,230,158,123,238,8,104,40,103,146,109,90,125,245,213,35,80,27,159,
45,142,8,200,200,146,129,32,137,128,236,164,147,78,138,231,163,67,86,143,141,191,105,216,231,241,252,243,207,199,108,177,220,39,135,188,73,57,43,39,249,190,89,172,64,32,89,142,237,152,36,169,28,12,200,
164,58,195,112,212,167,158,122,42,54,244,166,4,200,131,145,26,244,159,141,106,133,38,243,186,88,161,73,57,147,178,102,231,206,157,35,96,35,56,107,237,92,179,191,254,245,175,145,33,3,217,56,2,178,19,79,
60,49,158,151,122,255,253,247,99,213,40,15,166,251,51,228,53,143,203,0,255,46,1,215,60,243,204,19,65,227,154,107,174,25,251,124,242,124,92,87,108,74,82,181,50,32,147,234,12,229,76,26,253,25,46,75,185,
143,241,25,148,52,111,184,225,134,200,160,149,102,204,8,202,8,158,8,204,24,222,202,92,51,166,219,147,233,162,199,140,236,212,216,42,14,200,248,187,88,29,73,41,117,84,24,130,219,171,87,175,216,132,157,
49,25,165,139,19,248,243,100,194,14,57,228,144,216,145,128,197,8,213,188,143,167,36,141,15,3,50,169,206,145,129,162,183,140,114,32,11,0,216,214,136,69,1,175,191,254,122,100,204,138,131,32,130,51,178,98,
140,205,88,113,197,21,35,83,198,22,77,100,208,232,217,26,93,227,60,167,17,50,112,204,33,59,235,172,179,226,99,12,174,61,224,128,3,90,74,152,224,223,102,229,36,223,19,123,121,242,61,208,43,150,81,78,101,
193,1,115,196,8,194,104,214,103,124,7,139,18,218,98,210,191,36,85,43,3,50,169,193,208,56,207,234,197,103,158,121,38,22,0,208,115,70,73,147,94,174,226,224,12,4,72,100,204,152,237,181,223,126,251,69,57,
147,192,136,192,140,29,1,114,144,196,159,35,200,99,235,164,107,174,185,38,62,70,153,145,61,44,201,146,209,227,198,223,255,208,67,15,165,158,61,123,182,140,235,200,248,119,248,187,249,59,9,6,119,223,125,
247,232,25,227,125,73,106,4,6,100,82,131,161,148,73,112,196,91,94,254,204,51,187,242,202,43,211,43,175,188,18,25,180,210,160,140,18,33,89,51,50,101,148,12,41,99,50,5,127,143,61,246,136,57,96,160,76,74,
99,254,229,151,95,30,243,195,48,231,156,115,166,63,253,233,79,209,155,198,176,88,254,126,166,237,147,17,35,24,203,167,158,220,199,182,237,182,219,166,77,55,221,52,102,138,77,59,237,180,150,39,37,53,20,
3,50,169,193,229,149,141,148,17,233,47,35,112,122,228,145,71,210,160,65,131,34,208,42,62,69,20,175,208,92,110,185,229,90,246,209,164,180,72,246,139,13,210,89,225,9,122,190,232,1,99,191,77,86,124,246,239,
223,63,130,192,140,113,21,172,242,92,105,165,149,34,120,35,35,182,200,34,139,196,223,39,73,141,198,128,76,210,8,8,170,46,190,248,226,88,5,201,100,124,22,2,176,250,145,96,173,244,116,65,230,140,254,178,
85,86,89,37,118,18,96,168,43,127,14,244,130,145,109,43,158,139,70,54,140,69,2,148,39,201,184,17,140,237,188,243,206,17,208,241,119,73,82,163,50,32,147,52,2,2,48,70,103,80,190,36,171,69,118,139,13,189,
201,152,21,207,6,3,227,39,232,35,99,60,69,94,217,153,247,177,204,163,41,138,75,160,100,197,40,121,238,179,207,62,177,146,147,236,25,25,177,214,142,215,144,164,122,99,64,38,105,180,24,44,219,183,111,223,
152,107,198,104,10,154,243,89,25,73,38,140,204,87,105,191,217,168,144,21,35,16,163,196,201,126,154,148,41,25,66,75,48,198,74,76,73,146,1,153,164,86,160,215,140,21,154,55,223,124,115,148,40,71,181,119,
102,41,50,95,52,232,239,181,215,94,177,185,121,110,218,167,31,77,146,244,171,137,142,101,175,19,73,26,11,100,180,216,208,155,217,96,244,138,177,197,209,240,225,195,11,159,29,61,130,54,202,159,108,128,
78,233,147,230,125,123,198,36,233,127,204,144,73,26,107,76,253,167,92,73,143,25,83,246,223,122,235,173,244,245,215,95,23,62,59,102,100,202,200,140,17,208,177,5,18,171,53,121,206,138,77,2,52,54,13,151,
164,70,101,64,38,105,140,104,214,103,181,37,89,174,211,78,59,45,26,252,63,250,232,163,17,86,92,210,39,86,122,42,33,224,162,199,140,70,255,81,149,53,89,12,64,63,217,90,107,173,149,118,217,101,151,24,147,
145,103,158,209,115,102,147,191,164,70,98,64,38,105,140,152,236,127,233,165,151,198,214,72,100,196,40,61,22,151,41,233,5,35,136,162,201,63,7,94,4,104,236,97,201,162,0,6,198,242,103,248,92,241,233,134,
128,139,209,24,76,244,159,99,142,57,82,167,78,157,34,123,182,246,218,107,199,10,204,209,109,211,36,73,245,200,128,76,210,72,40,67,62,241,196,19,209,35,246,223,255,254,55,221,120,227,141,209,251,149,55,
38,39,224,34,155,197,170,73,154,244,9,158,110,189,245,214,24,46,203,231,8,182,238,188,243,206,232,57,99,17,0,37,78,254,60,11,1,8,234,70,181,66,147,160,142,149,151,236,161,185,240,194,11,71,160,198,86,
74,75,44,177,68,148,51,93,4,32,169,158,25,144,73,106,193,156,49,50,89,236,53,201,126,146,140,188,40,237,17,35,48,98,184,43,193,22,243,196,118,218,105,167,152,37,182,198,26,107,68,16,71,48,70,176,118,251,
237,183,167,53,215,92,179,240,167,82,244,158,17,216,93,113,197,21,177,127,38,243,202,248,183,70,85,206,228,239,96,23,128,30,61,122,196,230,228,4,102,172,212,228,227,148,51,37,169,222,24,144,73,106,113,
193,5,23,164,167,159,126,58,50,93,108,129,68,48,86,60,12,150,44,214,82,75,45,149,118,216,97,135,8,152,186,119,239,30,131,94,249,154,245,215,95,63,254,44,1,27,193,19,163,49,152,55,150,241,119,125,242,201,
39,49,203,140,96,140,5,2,4,112,188,45,205,152,145,101,35,232,35,208,91,96,129,5,34,67,150,183,98,34,0,52,40,147,84,111,12,200,164,6,215,175,95,191,24,246,74,80,116,209,69,23,69,137,146,33,176,25,1,22,
217,176,165,151,94,58,2,36,222,110,183,221,118,49,157,159,76,24,95,203,56,11,50,106,189,123,247,142,96,137,126,176,235,175,191,62,182,84,26,29,2,62,250,211,120,75,79,26,229,76,70,105,176,77,19,193,89,
241,169,41,103,204,22,91,108,177,8,6,89,16,192,247,196,230,230,4,133,6,104,146,106,157,1,153,212,224,200,138,157,112,194,9,209,180,63,186,253,42,217,107,242,178,203,46,139,183,4,67,4,72,217,135,31,126,
152,110,187,237,182,116,198,25,103,68,169,147,236,24,37,198,158,61,123,198,94,149,163,195,191,147,31,184,234,170,171,210,149,87,94,25,89,54,86,118,142,106,23,128,220,159,198,247,192,247,178,238,186,235,
166,67,14,57,36,130,51,73,170,101,6,100,82,3,162,177,254,252,243,207,143,125,43,95,125,245,213,212,167,79,159,200,144,229,211,1,89,177,142,29,59,166,29,119,220,49,45,179,204,50,145,13,91,126,249,229,163,
121,191,56,24,3,189,97,231,158,123,110,186,229,150,91,98,53,37,95,75,153,241,244,211,79,143,1,178,99,235,221,119,223,141,7,253,101,244,149,61,244,208,67,233,129,7,30,136,191,179,52,99,198,247,199,191,
51,219,108,179,197,194,2,2,50,230,153,241,239,241,112,166,153,164,90,99,64,38,53,8,130,28,74,138,172,156,124,229,149,87,210,201,39,159,28,1,25,217,168,140,190,173,57,231,156,51,86,78,230,166,125,2,177,
49,97,59,165,163,143,62,58,74,157,95,126,249,101,148,53,201,140,29,117,212,81,105,209,69,23,45,124,85,235,221,125,247,221,233,142,59,238,136,12,28,179,204,62,254,248,227,152,127,86,28,56,102,100,241,24,
153,193,191,187,242,202,43,71,201,148,85,154,121,191,76,2,56,73,170,102,6,100,82,131,32,168,217,121,231,157,163,145,158,64,140,231,165,101,193,233,166,155,46,237,186,235,174,233,136,35,142,136,242,32,
229,199,223,234,207,226,239,219,119,223,125,163,23,141,1,178,204,20,219,114,203,45,211,110,187,237,22,65,210,184,34,80,228,65,32,201,98,0,6,210,82,210,100,193,65,105,198,140,239,149,160,139,239,149,160,
50,175,208,220,115,207,61,35,131,102,198,76,82,181,51,32,147,234,24,61,97,100,153,30,127,252,241,88,229,120,255,253,247,71,9,176,120,229,36,65,23,129,19,193,26,101,64,2,24,86,82,142,173,135,31,126,56,
74,155,159,125,246,89,172,158,36,187,70,198,140,134,254,153,103,158,185,240,85,227,135,77,204,89,56,192,226,3,130,62,202,164,172,206,36,211,71,96,89,122,26,35,99,198,234,207,60,207,140,172,29,11,2,54,
219,108,179,194,87,72,82,117,49,32,147,234,12,65,24,67,88,233,199,162,188,71,51,62,77,247,197,43,39,233,3,35,147,68,99,60,13,248,4,43,4,81,4,50,173,69,144,183,213,86,91,69,192,199,191,205,148,253,203,
47,191,60,202,133,76,226,111,15,4,99,15,62,248,96,172,210,228,255,69,214,140,222,51,190,135,210,185,102,252,95,115,25,149,76,30,217,52,50,102,100,209,248,30,37,169,26,24,144,73,117,134,0,133,41,249,108,
93,68,128,66,95,23,89,165,226,242,36,129,23,115,189,206,60,243,204,24,99,65,112,70,185,146,96,165,181,238,189,247,222,180,201,38,155,180,204,18,99,210,254,61,247,220,19,255,70,233,2,128,182,66,38,142,
204,88,254,55,25,177,193,78,1,121,166,89,233,105,141,114,38,153,64,22,37,80,214,156,103,158,121,98,15,205,131,14,58,104,156,254,207,146,212,214,12,200,164,58,64,128,66,159,21,195,88,121,75,73,239,177,
199,30,139,143,231,64,140,192,131,128,100,181,213,86,75,191,255,253,239,99,21,37,99,35,152,229,53,62,8,190,54,218,104,163,40,131,114,58,33,19,197,234,200,114,206,6,99,71,129,55,222,120,35,254,239,100,
233,248,191,179,216,128,50,106,105,191,25,193,217,180,211,78,27,27,155,175,176,194,10,49,66,131,190,183,69,22,89,36,130,83,102,171,73,82,185,25,144,73,53,138,64,131,128,139,114,29,15,250,171,254,249,207,
127,198,74,196,226,149,147,4,70,172,58,236,210,165,75,234,220,185,115,244,138,109,186,233,166,133,207,142,63,86,67,50,165,159,83,73,165,2,178,82,215,92,115,77,244,206,49,23,141,64,145,192,140,50,110,241,
207,37,35,147,71,223,28,187,10,108,188,241,198,81,206,100,101,38,37,77,130,214,246,202,242,73,82,49,3,50,169,70,81,154,99,36,196,89,103,157,21,25,161,33,67,134,196,38,222,4,29,197,47,107,154,218,41,207,
209,35,70,144,68,105,146,0,173,173,176,121,248,122,235,173,23,239,147,133,35,32,163,175,172,146,1,25,101,90,86,146,18,176,242,115,162,167,141,125,52,243,76,179,98,4,92,4,101,4,97,252,92,200,34,50,234,
131,50,44,25,51,50,104,146,212,222,12,200,164,26,67,208,197,60,49,230,126,145,249,97,149,35,35,39,74,247,156,164,89,127,131,13,54,136,114,28,131,90,41,79,182,135,226,128,140,224,134,57,96,244,149,85,50,
32,203,56,189,81,194,124,230,153,103,98,139,38,2,53,50,136,47,189,244,82,148,56,217,178,169,248,20,72,64,201,207,174,107,215,174,177,208,129,166,127,2,88,50,104,244,198,241,57,123,206,36,181,7,3,50,169,
6,144,245,162,49,159,125,30,25,255,64,182,167,87,175,94,35,4,20,4,10,52,231,147,17,35,24,35,8,251,251,223,255,30,131,94,219,11,217,38,2,50,2,63,208,127,197,252,47,202,152,213,216,139,197,247,75,48,203,
174,2,148,85,115,38,141,133,16,252,44,71,149,61,163,204,75,48,203,76,51,178,104,57,155,70,73,83,146,218,138,1,153,84,3,200,234,80,150,188,244,210,75,163,23,138,44,25,99,30,138,3,8,130,49,178,97,76,215,
95,117,213,85,99,85,33,125,99,237,89,114,35,72,164,87,139,177,23,32,88,97,254,24,99,54,170,49,32,227,116,151,3,91,74,188,140,200,184,253,246,219,163,196,74,160,86,154,49,3,63,87,22,1,16,228,242,62,1,238,
154,107,174,25,131,111,37,169,173,24,144,73,85,138,192,129,64,140,81,14,148,215,88,73,72,86,39,143,122,200,8,22,24,128,74,223,19,217,177,181,215,94,59,74,108,229,64,169,148,108,221,225,135,31,30,207,201,
28,173,177,198,26,49,134,162,86,86,43,178,26,147,18,230,123,239,189,23,153,72,126,222,100,33,243,158,154,197,200,152,49,211,236,119,191,251,93,4,101,252,31,25,31,194,96,221,197,23,95,188,240,85,146,212,
122,6,100,82,21,225,229,152,103,108,17,140,49,248,244,130,11,46,136,128,172,184,71,140,209,13,100,190,104,66,167,223,137,12,21,153,177,114,99,3,240,171,174,186,42,154,230,65,176,178,206,58,235,68,38,175,
86,2,178,82,252,188,201,240,241,51,39,64,99,150,27,153,51,122,209,138,81,34,230,119,64,112,70,15,221,46,187,236,210,242,49,86,106,146,45,148,164,177,101,64,38,85,17,130,174,103,159,125,54,6,187,18,140,
145,165,33,48,43,222,119,146,139,62,153,48,182,55,98,242,60,239,179,69,17,229,202,114,35,19,70,240,69,201,15,52,193,111,184,225,134,233,212,83,79,173,217,128,140,159,55,63,119,50,148,156,30,123,246,236,
153,238,187,239,190,244,233,167,159,142,178,199,140,172,32,129,232,108,179,205,22,99,50,216,169,128,89,111,204,56,227,243,146,52,54,12,200,164,42,192,56,134,183,223,126,59,102,137,177,63,35,193,24,195,
93,139,179,50,100,94,104,36,95,118,217,101,163,68,198,158,145,155,111,190,121,244,138,85,10,217,36,30,47,191,252,114,60,95,116,209,69,211,22,91,108,145,14,57,228,144,200,226,213,3,122,228,88,209,74,144,
54,120,240,224,244,234,171,175,70,121,147,172,89,41,126,23,252,94,24,151,193,160,89,2,52,6,208,178,192,130,125,66,93,161,41,105,116,12,200,164,10,161,63,137,140,24,15,26,246,111,184,225,134,200,56,81,
38,43,206,196,228,242,36,153,48,122,197,254,246,183,191,165,37,150,88,162,240,217,202,58,249,228,147,211,57,231,156,19,89,37,48,92,117,135,29,118,72,219,108,179,77,221,101,135,248,189,188,245,214,91,233,
146,75,46,137,149,165,44,172,224,119,199,199,249,93,150,158,74,9,190,232,47,99,8,239,174,187,238,26,139,1,88,20,192,56,16,126,159,146,84,204,128,76,170,144,247,223,127,63,61,250,232,163,177,73,54,19,229,
9,106,216,250,135,151,100,126,89,18,212,144,97,97,172,4,195,93,41,143,177,33,120,91,14,118,29,31,199,29,119,92,12,166,101,213,34,8,198,246,219,111,191,104,112,175,183,108,16,65,242,176,97,195,98,24,47,
243,223,120,255,137,39,158,136,223,33,89,51,202,202,165,8,188,216,154,138,213,174,100,203,120,159,69,15,155,109,182,89,225,43,36,233,87,6,100,82,25,209,176,255,238,187,239,70,48,70,105,242,169,167,158,
74,143,63,254,120,204,194,42,238,17,163,188,197,69,156,18,32,125,89,92,196,217,127,178,218,28,117,212,81,233,140,51,206,136,126,43,252,229,47,127,73,135,30,122,104,244,84,213,187,220,239,199,208,89,86,
101,18,144,81,102,38,176,102,190,217,168,86,104,210,235,199,78,6,108,53,197,115,134,206,242,251,237,222,189,123,225,171,36,53,42,3,50,169,12,120,153,241,160,15,233,223,255,254,119,236,181,72,64,54,170,
149,123,148,40,233,67,162,212,245,215,191,254,181,240,153,234,68,240,117,250,233,167,71,112,2,202,169,199,28,115,76,188,223,104,8,192,78,59,237,180,216,224,157,223,109,30,79,50,170,83,44,191,103,178,103,
100,18,89,33,187,247,222,123,183,124,60,63,36,53,22,3,50,169,12,200,130,81,222,122,225,133,23,162,60,249,193,7,31,196,96,210,252,242,227,2,76,195,62,243,195,40,103,81,166,100,213,100,185,230,137,141,171,
131,15,62,56,2,178,156,13,106,228,128,140,223,37,153,50,202,206,121,232,236,181,215,94,27,11,2,232,55,43,205,152,17,120,51,67,142,222,178,110,221,186,197,152,12,122,4,151,91,110,185,152,41,39,169,177,
24,144,73,237,132,108,24,129,215,128,1,3,98,94,23,189,70,125,250,244,25,33,43,198,104,8,154,245,9,192,232,13,227,130,188,229,150,91,70,51,120,45,56,232,160,131,34,43,196,105,132,160,242,216,99,143,109,
216,128,108,84,152,209,70,73,147,99,128,140,25,171,104,25,159,65,233,186,248,212,203,207,142,21,154,252,254,41,77,179,111,38,11,0,102,159,125,246,8,204,171,165,103,80,82,251,49,32,147,218,9,155,126,51,
48,149,153,98,52,128,19,136,21,103,73,184,8,79,57,229,148,209,83,148,183,59,162,175,136,85,120,181,82,178,162,103,140,128,12,124,239,4,100,71,31,125,116,60,215,175,125,102,252,206,89,137,201,194,135,19,
78,56,33,198,104,144,49,43,157,105,198,239,156,159,33,153,51,142,1,2,117,178,165,91,111,189,117,213,172,170,149,212,126,12,200,164,54,68,246,131,33,169,100,194,216,234,136,18,22,171,242,184,40,231,151,
26,23,93,230,136,81,154,98,223,199,188,17,56,43,240,106,77,113,64,70,182,143,158,55,26,253,53,34,130,47,50,100,108,209,196,241,64,211,63,43,51,153,55,199,40,141,210,61,52,9,206,40,97,206,61,247,220,145,
61,101,131,115,2,52,198,138,48,116,86,82,253,49,32,147,198,19,23,91,74,147,140,66,96,187,157,255,252,231,63,177,31,34,37,203,226,149,147,140,61,160,20,153,87,79,178,114,146,81,22,181,136,211,6,89,31,6,
192,50,246,2,4,16,148,43,243,190,150,26,61,2,176,23,95,124,49,221,123,239,189,17,188,179,202,246,227,143,63,142,204,217,208,161,67,71,200,158,113,236,240,32,112,223,120,227,141,227,193,115,70,160,176,
59,0,15,73,181,207,128,76,26,79,4,38,103,159,125,118,148,162,200,138,49,2,34,15,11,205,242,202,73,198,29,236,182,219,110,49,238,128,0,166,86,247,59,36,96,32,0,37,0,99,80,106,14,56,201,142,17,164,105,204,
114,64,75,47,25,101,77,246,203,164,188,205,192,89,142,33,178,105,165,56,134,232,51,99,159,76,178,145,11,45,180,80,218,118,219,109,211,31,255,248,199,194,87,72,170,101,6,100,210,56,202,51,168,250,245,235,
23,25,49,222,210,39,148,95,82,4,41,211,76,51,77,108,161,195,190,134,52,108,207,51,207,60,177,25,117,173,79,106,39,152,96,229,232,153,103,158,153,110,191,253,246,248,191,82,86,35,59,182,255,254,251,23,
190,74,99,139,159,39,153,50,86,224,14,26,52,40,2,50,122,15,41,107,242,188,180,247,144,7,179,222,88,133,203,113,69,207,25,101,112,122,205,24,165,33,169,246,24,144,73,173,64,57,137,177,6,188,37,16,225,193,
204,41,94,70,197,129,24,35,44,40,79,18,128,173,188,242,202,105,163,141,54,138,247,235,5,67,80,217,116,155,85,132,140,117,224,255,76,175,19,171,46,119,223,125,247,194,87,105,92,17,160,93,120,225,133,209,
99,198,241,70,64,198,64,97,122,207,200,168,21,159,182,233,73,36,192,39,24,91,115,205,53,163,20,78,6,141,99,144,7,67,134,37,85,63,3,50,169,21,200,132,157,127,254,249,49,79,140,81,6,4,102,197,229,37,2,19,
46,134,235,173,183,94,218,100,147,77,82,143,30,61,162,196,68,191,15,99,12,234,5,255,111,182,77,186,237,182,219,162,41,157,160,128,13,181,217,54,137,125,44,53,126,56,45,19,124,209,107,150,135,238,30,121,
228,145,49,62,101,84,43,52,249,249,83,254,102,213,46,1,24,153,217,117,215,93,55,74,228,203,44,179,76,225,171,36,85,51,3,50,233,55,48,178,130,230,107,202,73,244,247,176,221,17,89,139,226,64,140,254,30,
50,96,139,45,182,88,60,232,23,163,148,196,42,185,122,68,19,250,159,254,244,167,244,192,3,15,164,254,253,251,199,255,159,44,32,155,104,175,179,206,58,133,175,82,91,186,231,158,123,210,219,111,191,29,101,
113,142,63,178,103,108,193,69,208,86,140,155,2,122,205,152,107,199,234,93,182,102,34,64,99,85,47,139,73,8,218,36,85,31,3,50,105,52,88,37,201,196,117,46,126,244,74,81,154,99,172,69,126,201,112,225,163,
84,68,131,62,165,33,250,196,200,72,144,153,224,115,245,140,159,11,205,228,244,145,241,62,89,65,2,52,102,102,45,185,228,146,133,175,82,123,224,6,129,1,179,148,139,89,169,73,38,141,7,65,50,55,9,165,43,52,
9,150,41,159,147,185,228,248,228,88,229,184,229,45,59,5,72,170,14,6,100,210,104,92,124,241,197,177,234,141,146,28,229,73,46,132,185,124,4,130,16,250,166,24,67,192,248,10,50,17,76,84,111,132,169,234,4,
0,236,181,73,144,74,63,25,229,216,11,46,184,32,178,99,108,160,173,246,67,63,25,129,23,205,254,252,236,121,203,10,223,251,238,187,47,230,222,141,42,99,70,211,127,14,192,40,109,114,220,178,66,115,195,13,
55,44,124,149,164,74,51,32,147,138,48,71,140,149,147,140,116,160,95,135,65,158,100,202,242,203,36,247,234,208,64,157,203,146,188,207,8,2,250,196,26,197,224,193,131,211,6,27,108,144,158,127,254,249,104,
64,39,227,194,166,218,244,204,81,46,83,249,48,102,133,227,148,114,58,55,14,100,202,40,171,231,69,0,165,43,52,57,134,201,152,177,95,38,199,46,25,52,246,211,100,53,48,199,180,164,202,48,32,83,195,35,160,
32,192,224,45,153,6,86,183,17,152,241,60,227,66,198,156,45,122,113,200,0,145,93,32,27,212,189,123,247,194,87,52,22,250,152,248,255,83,50,227,130,79,64,70,63,25,251,48,170,178,8,194,206,61,247,220,244,
216,99,143,197,192,98,102,157,241,251,34,171,86,188,143,42,242,10,77,22,100,176,77,19,37,77,62,198,66,20,122,205,12,174,165,242,49,32,83,195,163,89,255,244,211,79,143,134,105,154,164,105,82,39,235,144,
95,26,4,99,92,180,8,64,214,94,123,237,200,42,144,97,160,119,140,11,87,35,226,2,207,136,133,222,189,123,199,207,201,128,172,122,16,116,209,247,72,111,31,65,24,165,118,182,183,34,155,73,121,115,84,187,0,
176,50,147,185,102,204,146,35,16,99,75,47,182,105,178,31,80,42,31,3,50,53,36,14,251,71,30,121,36,189,247,222,123,17,136,177,221,17,23,49,122,114,178,92,202,97,101,26,111,41,241,112,129,234,218,181,107,
225,43,26,23,1,25,243,174,40,149,241,179,164,140,75,64,198,194,6,85,23,130,50,142,111,122,33,9,200,200,160,209,251,199,141,7,159,43,150,75,242,12,47,102,192,44,37,76,110,58,40,205,211,119,214,8,253,145,
82,165,24,144,169,161,208,240,156,103,59,29,122,232,161,209,8,93,186,114,146,64,140,139,16,37,74,50,5,140,114,160,164,211,168,217,176,81,33,32,35,131,66,64,198,207,140,210,22,63,75,3,178,234,70,182,140,
155,144,147,79,62,57,118,154,160,84,79,73,51,151,51,75,47,7,44,6,32,107,182,211,78,59,69,57,147,209,46,249,245,65,86,84,82,219,49,32,83,67,161,241,252,150,91,110,137,236,0,125,98,52,236,115,65,202,184,
0,205,62,251,236,49,210,33,111,117,68,118,140,222,49,46,68,250,85,113,64,70,86,133,50,23,115,178,200,34,170,122,209,239,71,22,152,134,127,74,154,44,94,97,17,11,193,52,165,251,81,101,204,88,65,203,107,
130,50,61,175,3,222,167,135,114,165,149,86,42,124,149,164,182,96,64,166,186,71,240,197,69,135,233,242,12,120,125,240,193,7,71,88,57,73,134,135,64,140,18,13,229,72,74,51,140,3,232,214,173,155,219,206,140,
2,139,29,62,250,232,163,24,247,193,202,62,2,85,74,89,108,35,197,240,81,213,14,86,100,190,252,242,203,49,100,150,223,41,25,51,246,207,252,248,227,143,227,245,82,186,66,147,81,47,4,102,172,176,93,106,169,
165,226,119,79,239,25,3,104,187,116,233,82,248,74,73,227,194,128,76,117,137,195,154,192,129,6,230,135,31,126,56,253,229,47,127,137,21,103,165,51,154,184,192,80,122,161,60,121,204,49,199,68,89,134,140,
152,70,143,204,10,251,119,178,103,37,115,175,200,160,112,81,166,79,201,109,122,106,27,129,216,57,231,156,19,25,51,178,104,100,143,41,239,243,58,42,189,84,144,61,163,84,77,96,182,231,158,123,182,204,52,
35,72,227,117,197,231,37,141,61,3,50,213,37,238,252,207,62,251,236,40,75,178,114,146,0,130,82,77,241,29,63,23,19,202,110,220,237,207,50,203,44,113,151,207,72,11,123,197,198,140,11,53,123,88,178,114,143,
172,10,63,47,178,35,76,142,103,5,170,106,23,55,44,148,46,41,101,178,210,152,76,242,149,87,94,153,94,123,237,181,209,206,52,99,181,49,91,132,205,49,199,28,177,32,128,0,141,121,116,44,12,144,52,246,12,200,
84,87,40,191,16,128,177,1,51,155,128,179,178,140,11,75,198,157,59,77,202,4,14,244,195,176,82,144,81,22,100,120,184,192,232,183,49,234,130,169,252,244,227,113,193,166,92,73,191,29,1,176,23,225,250,66,9,
243,234,171,175,142,27,27,250,6,41,99,210,55,200,251,197,189,151,32,51,150,135,38,175,184,226,138,177,58,153,236,51,125,152,179,205,54,91,188,222,36,141,158,1,153,234,202,97,135,29,22,119,244,220,225,
115,104,151,30,222,121,198,210,121,231,157,151,102,152,97,134,184,128,24,136,181,14,251,87,254,237,111,127,75,207,61,247,92,250,250,235,175,163,167,136,6,111,62,230,164,247,250,147,231,150,209,2,240,225,
135,31,166,3,15,60,48,198,102,16,148,141,234,242,193,235,137,7,193,24,219,53,229,114,38,65,187,164,209,51,32,83,205,163,33,185,87,175,94,209,219,196,240,75,74,106,197,171,197,104,216,103,15,191,189,246,
218,43,26,245,185,91,103,140,5,193,152,125,46,173,119,255,253,247,167,131,15,62,56,178,143,148,184,200,128,108,181,213,86,49,30,132,253,60,85,159,8,204,200,54,231,1,179,220,244,80,202,100,254,28,165,235,
81,173,208,36,40,155,119,222,121,163,156,73,102,154,155,160,205,55,223,60,50,169,188,46,37,253,143,1,153,106,82,46,157,112,129,96,213,228,229,151,95,62,66,143,11,119,232,156,240,231,155,111,190,88,57,
201,157,58,141,253,4,100,148,45,53,238,238,188,243,206,180,247,222,123,199,252,54,178,38,148,166,14,63,252,240,200,60,82,250,85,99,32,67,70,111,38,199,3,11,102,8,210,8,204,8,212,232,215,44,221,17,128,
197,31,4,101,140,148,161,207,140,30,78,246,127,101,85,179,199,141,100,64,166,26,197,157,57,25,25,134,92,210,192,79,63,75,241,5,32,55,27,31,119,220,113,49,51,137,231,92,0,156,37,54,254,152,227,182,243,
206,59,71,185,146,0,152,64,172,103,207,158,177,32,194,97,161,141,131,215,27,191,127,130,114,222,178,24,128,118,129,187,239,190,59,250,56,75,123,204,114,41,147,204,52,193,25,43,155,217,148,159,18,40,189,
156,82,163,51,32,83,77,185,236,178,203,82,159,62,125,98,155,35,50,99,4,5,197,27,38,179,226,111,217,101,151,77,91,110,185,101,4,7,188,223,168,27,128,183,151,155,110,186,41,109,191,253,246,81,162,226,162,
188,214,90,107,197,200,11,46,180,6,188,141,139,27,35,154,255,201,150,241,186,100,254,31,155,245,19,168,209,78,80,154,49,35,131,77,230,122,177,197,22,139,82,55,55,76,172,116,102,183,7,95,179,106,68,6,100,
170,106,156,196,153,141,196,131,121,72,255,248,199,63,210,83,79,61,53,194,202,73,130,0,74,31,52,148,115,130,103,211,235,253,246,219,175,240,89,181,181,27,111,188,49,109,179,205,54,45,91,237,172,187,238,
186,81,182,146,138,81,190,164,149,128,27,40,202,155,108,219,196,190,177,188,229,181,92,140,215,48,25,51,74,153,235,173,183,94,172,212,36,96,99,193,8,229,76,62,39,213,59,3,50,85,53,78,220,23,94,120,97,
140,89,224,46,59,239,189,87,124,183,205,201,122,145,69,22,137,129,150,204,19,227,78,219,37,246,237,231,134,27,110,136,38,254,252,59,48,32,211,168,16,176,211,235,153,75,154,148,49,143,56,226,136,8,208,
74,51,102,200,139,0,88,9,205,107,154,150,131,45,182,216,34,142,47,87,104,170,17,24,144,169,234,16,112,81,250,160,52,70,38,140,77,144,25,177,80,188,138,139,198,124,182,53,218,100,147,77,34,24,227,78,154,
59,107,78,230,106,95,4,100,148,132,57,117,80,122,226,130,73,105,74,26,19,130,48,218,12,104,250,103,126,29,1,218,67,15,61,20,207,71,53,211,140,27,171,5,23,92,48,86,105,178,127,38,55,89,100,191,89,152,99,
198,76,245,200,128,76,85,129,187,101,2,46,230,28,177,90,139,81,22,255,252,231,63,163,188,81,220,35,70,25,131,149,90,108,111,196,18,122,86,247,185,127,98,121,49,98,132,128,12,100,53,8,132,153,220,47,141,
45,50,221,100,202,232,9,37,48,227,121,126,228,45,207,178,188,16,128,210,37,219,117,177,61,87,158,33,200,8,27,218,21,164,122,96,64,166,170,192,50,121,78,204,12,23,101,115,99,78,204,76,219,231,196,92,124,
136,146,9,99,217,252,110,187,237,214,50,117,223,172,88,121,21,7,100,4,200,4,100,76,237,151,198,22,37,76,102,216,229,0,172,95,191,126,233,174,187,238,138,210,55,11,118,74,51,102,4,254,188,222,233,17,229,
245,78,182,140,249,119,7,29,116,80,244,157,73,245,192,128,76,21,195,73,153,19,242,19,79,60,17,91,30,13,24,48,32,78,202,204,183,42,93,57,73,153,98,163,141,54,138,109,122,24,234,202,74,44,149,31,101,167,
235,175,191,62,166,175,131,44,5,123,129,18,164,73,227,138,172,56,55,98,125,251,246,141,99,140,69,60,44,222,97,197,38,89,114,206,21,25,25,51,122,205,200,146,177,23,45,251,104,82,222,36,107,78,182,156,183,
82,45,50,32,83,217,113,71,204,178,120,50,96,100,197,46,186,232,162,152,254,78,150,44,227,142,152,89,69,204,182,162,81,159,189,241,78,56,225,4,199,42,84,216,155,111,190,153,174,185,230,154,152,239,6,250,
248,216,22,135,141,197,165,182,66,15,233,165,151,94,26,187,2,208,111,70,47,41,231,11,50,103,197,193,25,56,39,144,49,99,101,230,142,59,238,152,150,92,114,201,248,24,199,38,229,76,110,26,164,90,96,64,166,
178,35,8,99,120,36,155,22,51,187,136,121,69,165,171,174,40,75,116,233,210,37,29,117,212,81,209,216,203,201,149,231,220,29,171,114,238,189,247,222,8,190,248,221,129,18,242,198,27,111,28,171,96,165,182,
66,57,147,102,255,60,34,131,27,129,211,78,59,45,198,102,112,51,87,218,99,150,199,102,208,194,192,54,105,148,54,25,54,187,246,218,107,199,110,29,82,45,48,32,83,89,112,18,101,170,254,51,207,60,19,111,95,
120,225,133,216,164,154,108,89,62,4,201,138,113,50,165,105,151,97,145,156,92,55,219,108,179,52,235,172,179,198,231,85,121,87,94,121,101,204,150,122,248,225,135,227,57,219,222,240,59,58,241,196,19,227,
185,212,30,184,105,187,253,246,219,163,173,129,45,210,120,206,249,131,247,9,216,138,47,99,4,103,100,198,216,47,51,15,157,229,57,189,102,220,212,113,115,39,85,35,3,50,181,27,238,98,41,49,112,151,203,134,
223,143,60,242,72,58,235,172,179,162,244,80,220,35,70,179,46,61,32,220,213,114,242,100,168,43,227,44,84,125,78,63,253,244,40,37,209,239,3,202,68,91,111,189,117,236,19,42,149,3,55,119,189,123,247,78,39,
157,116,82,220,220,145,93,39,163,70,89,147,114,102,241,37,141,236,25,231,22,110,234,246,216,99,143,104,125,96,163,115,206,57,220,252,177,40,69,170,22,6,100,106,55,156,56,217,0,156,134,111,222,18,136,49,
214,162,56,43,198,9,147,62,49,154,115,89,210,78,191,7,77,185,100,199,84,125,88,5,75,64,198,20,118,48,131,140,190,157,205,55,223,60,158,75,237,45,15,156,165,245,129,64,140,160,140,49,57,204,194,163,204,
201,249,165,24,25,51,22,1,48,203,44,151,51,121,159,155,8,102,156,73,213,194,128,76,109,142,160,139,158,15,178,40,175,191,254,122,12,127,228,228,89,186,114,146,102,125,86,75,18,128,81,78,160,57,92,213,
237,176,195,14,75,23,95,124,113,172,142,5,89,7,30,148,134,164,74,32,8,123,229,149,87,34,40,227,184,100,108,6,231,29,206,67,4,108,165,253,102,100,204,152,105,198,246,95,148,48,243,140,51,206,65,188,149,
42,197,128,76,109,130,82,1,119,166,60,30,120,224,129,88,137,199,76,161,226,121,66,185,249,150,19,32,37,4,150,168,211,123,68,96,166,218,240,231,63,255,57,2,178,188,34,246,248,227,143,143,143,57,11,78,213,
226,197,23,95,140,62,71,206,67,172,208,100,224,52,143,210,114,38,56,31,145,49,91,116,209,69,99,200,52,55,22,121,230,25,171,188,249,188,84,46,6,100,106,19,220,145,62,246,216,99,233,158,123,238,137,134,
91,74,90,220,185,22,223,157,114,103,218,181,107,215,180,237,182,219,198,44,49,246,170,99,67,112,151,165,215,14,250,251,24,83,146,203,66,39,159,124,114,58,240,192,3,189,112,169,106,176,114,155,236,24,193,
24,199,41,153,122,86,5,191,243,206,59,209,207,90,154,49,35,240,98,108,6,11,84,152,109,70,128,70,182,108,173,181,214,138,243,149,84,46,6,100,26,103,185,143,131,19,29,61,98,79,63,253,116,52,238,83,154,204,
39,61,78,120,244,109,48,216,149,13,130,41,17,252,225,15,127,136,81,22,170,61,123,239,189,119,4,100,121,22,212,169,167,158,26,1,153,84,173,24,149,193,190,184,12,153,165,241,159,27,197,255,254,247,191,241,
62,231,170,226,75,96,110,246,103,133,102,143,30,61,34,32,99,156,6,189,102,108,211,228,30,154,106,79,6,100,106,53,14,25,2,46,78,116,76,109,103,20,2,39,187,226,129,141,4,98,185,68,73,57,96,151,93,118,137,
94,35,213,54,38,244,19,144,229,211,134,1,153,106,9,231,45,118,0,32,211,91,188,11,64,113,214,44,227,252,149,179,250,44,56,98,166,89,206,152,81,214,228,243,82,91,50,32,83,171,208,139,65,105,146,25,64,100,
197,88,225,148,239,60,243,161,196,137,138,190,48,38,102,179,231,33,43,38,217,222,132,189,231,84,219,8,200,46,188,240,194,120,159,139,210,41,167,156,146,14,56,224,128,120,46,85,59,206,81,95,124,241,69,
244,153,113,206,98,139,38,70,104,176,101,27,51,205,74,87,104,146,49,163,63,146,115,23,231,52,154,254,89,161,185,221,118,219,181,44,8,144,218,138,1,153,198,10,125,97,244,101,16,124,49,20,244,209,71,31,
141,12,89,206,138,17,132,177,180,156,254,11,250,194,186,119,239,30,125,98,204,168,114,214,79,253,32,203,73,134,12,92,172,254,245,175,127,69,83,191,84,139,24,52,75,64,198,208,89,2,50,246,209,165,255,149,
243,29,193,89,105,191,25,171,195,9,200,118,216,97,135,184,201,164,247,140,253,117,23,90,104,161,24,62,43,141,15,3,50,141,149,155,111,190,57,93,123,237,181,209,180,207,202,201,226,62,49,144,45,33,19,182,
252,242,203,167,35,142,56,34,78,80,148,43,185,104,171,126,228,128,140,139,19,205,208,52,245,255,233,79,127,42,124,86,170,45,92,254,184,169,228,193,251,207,62,251,108,186,238,186,235,226,124,71,38,141,
93,0,138,113,220,243,224,188,198,141,38,139,0,88,153,201,106,113,183,104,210,248,50,32,211,104,245,235,215,47,50,97,148,38,89,69,73,70,140,20,127,14,196,56,49,17,116,113,34,90,117,213,85,99,140,5,123,
27,210,51,70,99,172,234,7,23,38,126,247,140,6,160,111,144,223,61,25,1,46,68,52,250,75,245,128,149,153,44,82,98,177,18,55,158,172,208,188,239,190,251,226,92,56,170,153,102,148,44,243,170,76,222,178,114,
156,243,33,43,52,221,242,77,173,101,64,166,17,208,35,150,151,140,63,255,252,243,49,75,140,253,39,105,126,205,135,10,39,34,82,245,244,84,144,182,103,69,210,6,27,108,16,1,153,234,19,115,199,232,27,164,137,
255,254,251,239,111,201,136,30,119,220,113,105,183,221,118,43,124,149,84,95,40,103,146,45,35,48,163,231,140,243,34,193,25,175,135,226,65,215,32,107,70,198,140,27,82,246,119,229,220,200,162,0,206,147,220,
168,242,190,52,38,6,100,26,1,189,19,23,92,112,65,186,247,222,123,227,196,195,73,136,94,138,226,195,132,172,24,123,24,178,223,228,174,187,238,26,169,123,238,20,41,97,169,62,177,95,224,101,151,93,22,243,
156,104,136,230,24,160,209,249,200,35,143,76,127,252,227,31,11,95,37,213,23,50,195,100,198,242,6,230,140,245,97,24,50,89,52,130,178,210,213,153,188,46,56,31,18,124,49,34,131,160,140,109,197,214,95,127,
253,216,167,87,26,19,3,50,5,182,55,226,66,75,105,146,187,66,86,79,50,96,49,31,30,100,197,200,136,144,13,91,121,229,149,99,46,15,143,69,22,89,36,62,175,250,54,104,208,160,184,16,177,95,32,23,35,46,58,44,
218,96,228,133,27,193,171,81,80,61,96,222,34,55,40,100,203,94,123,237,181,40,105,178,111,111,105,191,25,25,51,26,254,89,224,196,208,89,178,100,148,49,25,159,193,194,0,119,183,80,41,3,178,6,70,211,42,67,
18,57,153,176,213,17,91,141,176,7,101,241,93,31,23,94,250,34,216,0,124,129,5,22,72,43,173,180,82,220,241,209,47,161,198,193,234,179,253,247,223,63,122,10,57,102,200,136,82,166,166,201,127,181,213,86,43,
124,149,212,56,8,200,8,206,152,195,200,185,52,63,248,120,233,192,89,110,104,9,192,8,204,118,218,105,167,8,210,56,135,146,69,99,182,153,213,5,193,128,172,129,221,125,247,221,81,130,98,106,53,155,242,82,
158,44,222,123,146,62,33,238,240,104,80,221,106,171,173,162,76,201,178,239,169,167,158,58,82,243,106,28,148,178,89,234,255,220,115,207,69,230,148,139,11,195,53,153,51,71,207,140,212,104,88,153,73,57,147,
108,25,239,83,97,96,158,25,61,103,163,202,152,113,62,205,219,52,113,67,195,76,51,94,59,244,97,186,159,175,96,64,214,96,184,176,62,248,224,131,145,122,231,4,194,131,185,59,197,243,196,56,113,48,75,108,
241,197,23,143,7,165,73,78,28,158,52,26,23,43,44,201,140,190,252,242,203,113,17,226,162,66,175,33,171,107,41,101,75,141,238,147,79,62,73,111,188,241,70,234,219,183,111,220,216,210,254,193,13,12,37,254,
209,205,52,163,132,185,230,154,107,198,141,47,15,122,206,120,77,185,74,189,49,25,144,53,0,78,4,148,156,216,123,242,149,87,94,73,231,159,127,126,140,178,224,206,46,255,250,243,9,130,242,36,169,116,202,
80,52,162,178,159,155,68,208,206,241,192,69,134,59,127,142,17,122,103,152,193,196,177,35,105,68,79,60,241,68,236,161,73,5,130,5,0,12,158,165,156,201,74,246,210,197,0,244,155,209,22,194,238,38,180,1,208,
99,198,160,109,110,124,8,206,104,29,81,253,51,32,107,0,156,12,206,60,243,204,216,242,136,149,147,244,0,145,229,40,94,182,205,9,129,139,43,125,65,235,173,183,94,164,211,185,99,115,250,180,64,70,149,102,
228,183,222,122,43,178,169,4,100,244,28,90,174,148,70,141,81,65,185,21,132,0,140,202,4,43,149,121,13,145,65,43,205,152,17,116,209,10,192,185,55,175,208,92,125,245,213,211,70,27,109,100,117,162,65,24,144,
213,49,210,229,148,152,40,55,145,205,160,97,159,187,180,252,43,167,52,201,221,23,23,213,5,23,92,48,86,76,242,62,111,189,35,83,49,182,204,162,180,194,112,96,142,31,230,45,17,144,177,234,86,210,111,35,187,
204,77,49,213,10,130,53,206,199,79,62,249,100,244,155,141,110,166,25,59,158,112,163,76,91,0,25,52,6,208,186,66,179,126,25,144,213,25,50,95,121,147,220,158,61,123,166,27,110,184,97,164,149,147,4,98,100,
190,72,135,211,31,70,99,118,94,138,45,141,10,1,217,26,107,172,17,1,25,12,200,164,113,71,251,8,55,201,231,157,119,94,244,245,18,160,241,224,227,156,171,139,47,203,100,207,200,152,177,202,157,21,154,44,
174,34,139,198,172,51,50,213,46,176,170,31,6,100,117,134,169,250,151,94,122,105,148,38,217,254,227,243,207,63,143,146,101,70,48,198,10,31,102,71,145,14,39,35,198,221,23,189,99,244,44,72,163,66,64,198,
241,194,113,197,5,130,128,140,137,253,6,100,82,235,81,246,167,156,73,48,150,23,0,60,252,240,195,177,201,249,168,50,102,4,93,100,197,200,146,177,202,61,175,208,60,248,224,131,227,198,154,243,186,106,159,
1,89,29,224,5,204,124,40,82,225,172,154,100,3,112,94,232,100,201,50,82,224,221,186,117,139,210,36,115,111,86,88,97,133,72,133,207,49,199,28,133,175,144,70,175,56,32,227,228,207,144,75,142,51,7,3,75,227,
143,69,51,180,151,228,5,0,188,206,88,177,201,77,117,222,37,32,203,25,51,118,202,96,139,38,170,29,4,105,84,56,56,175,55,210,22,77,244,231,177,80,141,159,23,149,161,214,160,45,135,159,27,11,216,8,116,171,
129,1,89,13,35,197,205,221,21,47,90,182,176,121,225,133,23,98,48,97,254,149,230,70,81,86,79,242,162,221,112,195,13,99,158,216,239,127,255,251,248,188,52,54,40,161,188,251,238,187,81,214,102,9,63,193,61,
203,245,153,218,191,240,194,11,23,190,74,82,91,33,251,124,227,141,55,70,91,0,109,40,4,30,121,33,86,233,37,59,191,30,57,175,31,117,212,81,145,189,38,163,70,197,131,224,172,189,178,103,124,47,252,221,149,
204,206,49,106,228,172,179,206,138,217,111,156,155,90,35,47,156,96,124,207,178,203,46,91,248,104,101,25,144,213,176,139,46,186,40,50,99,172,128,163,79,140,129,157,197,89,49,130,49,50,98,204,143,34,147,
193,193,199,11,215,25,55,106,13,130,124,74,225,123,237,181,87,220,201,115,162,103,95,62,46,24,52,29,75,106,91,108,85,70,197,131,183,220,16,177,181,29,229,76,178,102,163,202,152,209,134,194,121,157,157,
0,40,109,146,45,35,200,216,120,227,141,163,29,165,173,81,114,37,17,192,74,124,250,216,42,133,21,171,187,239,190,123,100,23,185,254,181,6,165,94,206,95,167,157,118,90,44,150,168,6,117,19,144,229,82,10,
229,184,49,225,224,102,6,87,190,171,224,110,162,189,209,8,205,176,64,34,114,2,35,202,61,227,138,3,144,20,45,205,159,189,122,245,138,149,148,244,34,228,95,35,63,3,94,144,12,116,165,28,73,143,15,171,227,
120,161,146,41,147,90,139,227,247,150,91,110,73,167,156,114,74,244,36,114,28,207,55,223,124,177,101,12,3,132,37,181,175,103,159,125,54,54,54,103,143,97,50,83,188,38,185,14,208,174,146,135,122,103,220,
136,115,141,225,220,207,144,89,174,113,60,88,192,69,160,70,240,54,190,8,10,217,199,147,100,0,215,27,254,157,74,120,245,213,87,99,84,19,55,138,165,125,119,99,66,230,144,237,171,182,217,102,155,180,197,
22,91,164,46,93,186,20,62,83,89,53,23,144,241,237,242,131,231,32,228,253,252,237,95,119,221,117,113,32,242,195,101,123,10,238,26,138,241,245,252,57,134,242,157,116,210,73,45,7,17,145,49,233,221,210,175,
111,43,252,155,87,92,113,69,204,1,227,151,126,232,161,135,182,186,100,72,16,73,230,139,255,43,23,193,83,79,61,53,74,72,197,47,68,190,127,130,76,14,52,94,116,148,48,217,4,124,182,217,102,43,124,133,52,
110,200,142,145,214,39,40,227,46,148,59,110,86,122,157,123,238,185,209,151,40,169,188,184,222,113,131,68,153,142,182,21,174,51,60,70,117,57,231,6,138,27,244,63,254,241,143,177,82,154,5,1,220,184,143,234,
58,57,182,248,183,88,136,112,250,233,167,199,57,225,170,171,174,138,64,175,156,229,75,254,175,100,198,72,56,144,73,228,255,50,166,255,15,95,207,181,148,175,225,26,201,160,235,115,206,57,167,162,37,215,
82,53,23,144,49,233,152,102,226,222,189,123,167,1,3,6,68,128,197,127,129,89,91,244,73,173,178,202,42,105,239,189,247,30,41,243,197,29,6,131,249,184,184,80,222,35,120,97,42,50,27,38,147,61,106,175,1,168,
44,109,230,96,165,23,128,23,197,225,135,31,222,234,128,140,187,33,46,126,164,176,201,144,241,156,158,130,252,171,227,128,162,140,180,233,166,155,198,230,223,148,147,200,96,240,51,104,164,6,79,181,15,142,
93,110,98,216,72,153,227,142,32,159,70,216,191,253,237,111,113,172,73,42,47,174,119,92,11,120,61,82,58,100,158,25,125,103,4,71,165,25,51,174,117,148,22,231,156,115,206,104,94,231,186,64,239,39,217,33,
202,141,227,178,186,158,107,15,217,57,122,214,232,223,226,154,118,236,177,199,198,117,167,92,136,5,104,217,161,100,73,80,74,86,112,76,9,8,42,73,4,145,252,12,232,165,38,64,37,139,56,174,65,105,123,152,
168,249,135,120,108,225,253,154,64,19,31,189,83,212,212,159,127,254,249,72,89,82,87,39,56,35,74,166,209,157,230,117,14,64,112,112,146,206,100,211,215,255,252,231,63,177,180,56,239,200,207,106,22,202,122,
100,174,88,109,209,150,8,20,89,153,70,89,145,131,134,131,129,127,107,197,21,87,140,23,198,111,225,251,102,197,13,141,250,252,249,127,255,251,223,177,130,146,23,98,238,19,227,133,198,5,145,149,53,100,44,
242,40,11,202,162,212,199,201,24,74,227,139,114,59,253,43,188,102,56,46,57,233,113,28,47,189,244,210,237,118,35,35,105,244,184,94,209,19,76,217,141,214,27,158,83,245,33,185,64,47,25,65,70,190,105,39,43,
196,181,142,107,36,173,61,148,61,185,6,130,96,142,178,35,45,48,4,52,99,155,45,226,239,39,35,70,146,131,64,144,36,1,193,29,193,94,185,246,182,229,186,79,114,134,22,164,101,150,89,38,110,18,121,203,188,
182,210,7,37,86,118,168,225,252,181,206,58,235,196,234,212,229,151,95,190,170,130,177,208,252,11,171,41,207,61,247,92,211,44,179,204,210,212,161,67,135,166,230,31,38,41,162,17,30,205,1,74,83,243,65,87,
248,234,166,166,225,195,135,55,93,125,245,213,77,171,172,178,202,72,95,223,124,224,52,109,177,197,22,77,205,191,208,194,87,183,157,79,63,253,180,233,226,139,47,110,106,14,142,226,223,106,126,193,52,53,
31,8,77,143,63,254,120,225,43,198,140,239,123,235,173,183,110,154,113,198,25,71,249,255,228,209,177,99,199,166,93,118,217,165,169,249,78,169,169,249,14,161,169,249,133,87,248,211,82,219,185,254,250,235,
155,154,131,176,166,230,27,128,56,238,154,79,122,241,177,230,155,140,194,87,72,170,36,206,253,205,193,70,60,238,184,227,142,166,237,183,223,190,169,249,166,188,105,162,137,38,26,233,186,193,131,107,74,
115,240,213,212,124,211,222,212,181,107,215,166,189,246,218,43,174,57,173,117,224,129,7,182,252,157,252,125,127,255,251,223,11,159,105,127,87,93,117,85,83,115,176,213,212,28,72,54,253,231,63,255,137,255,
59,63,135,81,61,254,242,151,191,52,53,7,140,77,205,55,145,77,189,123,247,142,143,85,163,154,203,144,145,94,101,229,32,141,124,100,132,136,136,201,34,145,178,204,168,111,19,165,179,255,23,119,9,212,185,
41,89,146,61,43,70,147,59,119,25,220,237,183,229,28,18,178,97,52,219,83,159,230,206,129,108,25,223,55,153,177,223,202,144,209,167,195,159,187,246,218,107,163,68,196,157,12,255,159,140,186,63,205,153,135,
29,118,88,76,216,167,39,128,255,67,185,235,247,106,28,244,105,220,122,235,173,241,26,107,62,103,196,64,74,54,64,166,151,204,41,225,82,229,145,233,201,15,122,198,200,148,245,232,209,35,246,193,228,90,200,
200,12,202,153,205,129,72,225,79,52,71,80,205,175,101,30,84,92,200,126,115,141,100,148,13,149,25,174,97,44,144,251,173,42,11,45,57,92,167,192,223,197,245,138,7,85,155,246,190,30,241,61,146,241,34,211,
69,171,14,25,190,226,159,3,15,50,127,199,31,127,124,148,116,185,110,30,114,200,33,17,63,84,107,43,79,205,5,100,4,81,172,236,162,6,206,131,160,139,178,37,191,28,210,178,28,112,28,16,12,61,37,133,202,202,
20,154,234,249,229,80,223,166,220,66,144,70,144,67,16,70,250,146,114,95,91,142,130,224,2,70,93,253,182,219,110,139,127,11,99,10,200,72,165,242,98,32,5,203,86,71,148,86,41,199,230,126,0,14,108,94,24,124,
159,244,161,81,175,223,121,231,157,163,100,68,185,149,191,155,255,159,212,30,232,215,228,70,33,55,13,243,218,218,117,215,93,13,198,164,42,68,27,1,237,49,4,30,92,35,41,101,114,35,159,199,98,112,189,32,
73,144,23,138,81,206,227,250,73,107,66,94,57,201,181,135,150,24,218,125,104,5,226,58,196,223,83,250,154,167,191,148,0,142,191,7,92,203,8,238,248,247,249,55,73,20,180,87,235,12,215,122,90,115,184,46,114,
29,44,93,61,74,137,54,111,232,78,11,19,193,41,189,99,85,221,87,221,252,131,172,105,95,127,253,117,211,61,247,220,211,180,242,202,43,183,164,98,155,127,224,77,151,94,122,105,164,110,155,127,81,81,222,108,
14,96,154,154,239,242,155,110,188,241,198,166,230,95,96,148,251,214,92,115,205,248,243,205,23,154,194,223,214,54,78,62,249,228,248,251,249,94,248,158,120,140,169,100,121,215,93,119,69,234,149,148,106,
243,139,101,164,18,37,105,101,74,151,55,221,116,83,83,243,139,163,169,57,200,139,244,172,84,14,61,123,246,140,114,101,62,46,41,243,75,170,13,205,129,87,92,51,184,214,53,7,90,77,103,158,121,102,211,66,
11,45,52,194,107,186,248,65,233,145,107,102,115,96,23,237,65,235,174,187,110,211,37,151,92,210,52,100,200,144,194,223,248,63,135,30,122,104,92,179,138,255,60,101,82,254,236,57,231,156,211,244,193,7,31,
20,190,178,237,113,221,166,85,167,57,160,28,101,9,146,235,37,109,73,243,205,55,95,124,255,227,82,146,45,183,154,203,144,149,34,123,196,29,1,205,250,172,158,108,254,63,69,228,76,212,76,198,140,166,63,74,
155,127,248,195,31,98,85,37,13,144,220,37,176,26,147,38,64,26,254,218,234,78,159,127,155,5,7,12,204,100,44,5,207,179,210,12,25,119,36,148,38,123,245,234,21,11,14,250,244,233,19,233,213,92,158,108,126,
161,68,234,153,193,126,127,250,211,159,34,147,71,26,152,37,203,102,196,84,78,100,200,40,89,230,227,57,15,27,150,84,253,184,190,145,165,226,186,193,131,5,0,92,247,184,254,113,77,161,234,68,86,43,183,36,
240,32,35,70,6,141,143,113,93,34,107,70,27,206,99,143,61,22,239,147,109,227,207,81,217,225,252,64,73,52,227,207,243,103,217,202,136,191,151,231,92,243,218,58,163,206,181,159,191,147,183,165,215,195,107,
174,185,38,218,126,248,190,24,104,205,255,149,146,102,181,171,249,128,140,95,8,1,25,129,23,233,86,14,36,14,0,86,123,52,71,244,177,42,115,223,125,247,141,50,31,229,77,82,156,148,60,41,187,48,67,169,173,
2,27,82,188,172,246,96,27,7,14,92,14,200,98,57,32,163,76,74,160,72,89,243,236,179,207,142,148,47,165,202,156,62,38,77,76,205,159,224,145,18,235,214,91,111,157,182,219,110,187,88,158,203,247,206,193,39,
149,19,199,53,1,25,120,189,48,221,154,85,74,146,106,15,55,245,4,100,36,45,88,165,73,105,145,68,0,215,29,130,53,94,227,4,98,36,54,120,228,128,140,107,22,237,65,180,4,241,103,24,123,65,107,77,30,191,81,
138,137,0,12,146,230,239,224,218,151,75,167,237,137,82,44,211,8,122,246,236,25,223,23,83,7,118,217,101,151,232,179,174,5,117,51,169,159,44,210,213,87,95,29,153,39,144,93,226,192,35,168,97,128,30,7,94,
91,71,232,197,8,194,14,60,240,192,56,96,9,4,75,127,172,28,232,220,141,112,112,83,147,231,238,129,71,233,54,24,124,29,217,48,22,34,240,194,32,216,228,64,150,42,133,30,12,78,106,224,134,128,225,203,220,
125,74,170,109,36,48,200,34,145,36,224,125,70,44,113,243,69,130,131,128,139,96,170,24,175,127,146,11,92,147,120,75,34,129,96,140,63,63,42,100,230,232,39,99,70,230,142,59,238,24,129,96,123,162,231,109,
219,109,183,141,94,182,181,214,90,43,253,245,175,127,141,68,6,137,142,90,80,243,25,178,140,236,24,51,85,248,69,128,64,135,95,62,129,26,141,141,164,87,219,11,65,216,157,119,222,25,7,50,1,87,233,65,12,130,
46,14,222,254,253,251,199,247,152,27,246,193,93,3,217,59,82,171,148,87,73,175,178,146,141,160,178,189,239,40,164,223,66,73,130,5,42,224,166,134,215,19,199,169,164,218,70,128,197,53,134,0,139,155,127,30,
76,177,167,130,196,78,54,172,164,230,90,154,175,107,92,199,200,166,17,128,49,181,128,76,26,215,177,81,93,243,192,199,249,26,146,15,92,255,104,168,39,64,107,15,148,79,25,160,206,245,152,233,253,180,85,
144,144,169,165,170,82,221,4,100,4,56,148,39,249,101,128,236,210,114,203,45,23,147,132,75,87,95,180,21,14,78,178,97,12,198,99,21,26,165,199,209,29,152,28,180,124,109,190,19,225,251,227,133,192,234,16,
14,26,2,48,182,85,98,140,5,61,110,82,53,224,120,37,251,75,159,35,184,43,38,32,163,183,81,82,125,97,53,34,215,31,182,20,228,250,201,181,147,235,28,55,98,244,96,241,150,128,140,7,31,231,122,55,186,107,94,
70,64,71,18,130,234,85,190,230,17,248,181,101,160,196,16,118,38,27,92,126,249,229,113,45,37,27,199,214,129,181,166,110,26,146,232,17,227,0,42,39,14,74,162,114,102,177,80,75,111,13,14,108,250,220,200,224,
81,239,254,199,63,254,17,89,50,169,154,144,117,230,100,151,113,66,37,40,147,84,255,152,239,197,204,75,174,81,180,4,237,176,195,14,177,59,12,37,64,146,10,173,193,190,155,44,120,163,207,154,4,74,91,186,
228,146,75,98,129,28,223,27,223,47,1,101,45,170,155,12,25,23,9,202,150,185,180,194,193,194,106,176,246,106,62,166,238,206,133,138,205,190,31,127,252,241,150,82,233,216,160,153,114,207,61,247,140,148,48,
77,135,100,200,168,115,183,103,143,155,52,46,242,202,170,156,121,102,117,21,179,240,232,207,144,84,223,184,174,210,215,76,233,146,185,158,180,209,16,244,144,133,34,161,64,6,157,202,207,216,32,129,193,
117,147,96,140,230,123,254,60,125,222,227,131,5,6,215,95,127,125,84,168,248,222,152,143,72,16,73,6,174,20,253,101,124,29,111,9,40,249,63,85,155,186,201,144,241,139,201,13,253,32,157,202,193,194,134,220,
164,76,219,26,255,222,19,79,60,145,238,189,247,222,136,252,199,22,129,34,19,144,169,111,179,219,60,171,79,164,106,197,74,41,90,1,50,78,116,156,160,37,53,30,134,145,83,14,100,167,14,22,169,177,50,179,53,
232,59,99,131,239,11,46,184,32,246,163,102,120,235,184,98,209,193,43,175,188,146,46,188,240,194,232,81,163,68,201,247,54,170,243,19,177,0,55,149,140,165,106,109,2,165,156,234,38,32,35,242,101,219,135,
98,108,91,116,241,197,23,199,170,198,182,70,191,216,191,254,245,175,104,210,111,13,2,69,14,196,237,183,223,62,29,112,192,1,49,229,88,170,86,220,120,240,200,184,171,228,206,86,82,99,34,152,33,17,193,74,
107,170,82,173,69,166,140,113,24,103,156,113,70,4,83,227,138,132,8,215,96,18,34,59,237,180,83,236,94,51,58,92,175,89,65,74,76,64,224,70,31,108,53,170,249,146,37,217,47,162,108,14,14,126,232,204,249,202,
43,24,115,211,33,171,22,73,183,182,21,126,177,215,93,119,93,108,203,48,46,217,55,210,182,28,212,28,148,164,110,233,203,97,159,45,169,218,176,122,152,254,72,238,70,193,124,60,134,27,51,203,79,82,99,161,
220,71,11,67,175,94,189,98,245,53,171,47,199,5,215,103,178,90,100,204,184,70,83,53,106,205,150,70,92,123,233,71,99,32,60,231,38,110,18,73,188,60,245,212,83,163,124,240,245,236,185,73,182,159,236,222,60,
243,204,83,248,155,170,76,115,208,82,211,134,12,25,210,116,243,205,55,55,245,232,209,35,118,114,63,224,128,3,154,154,239,226,25,236,21,219,63,116,235,214,173,169,79,159,62,133,175,254,213,247,133,237,
22,90,171,249,32,106,26,56,112,96,211,62,251,236,19,91,35,241,111,140,239,99,162,137,38,106,218,100,147,77,154,154,15,244,166,230,192,50,182,184,144,170,197,190,251,238,219,52,237,180,211,182,28,175,28,
251,205,1,90,225,179,146,26,65,115,208,20,215,38,182,31,220,106,171,173,70,184,134,141,239,131,237,153,30,121,228,145,166,230,224,174,240,175,141,222,15,63,252,208,244,217,103,159,197,86,136,51,205,52,
83,252,249,9,39,156,240,55,31,19,76,48,65,188,237,212,169,83,211,51,207,60,83,248,219,170,79,205,151,44,137,138,153,120,79,86,140,102,62,182,72,202,13,125,164,70,25,90,87,188,44,183,249,255,28,219,26,
145,157,106,45,254,141,147,79,62,57,74,142,100,185,218,2,223,27,169,87,166,241,179,226,146,187,15,169,90,48,67,136,71,198,196,107,118,184,144,212,56,184,222,61,249,228,147,145,25,107,14,158,10,31,109,
27,244,126,31,124,240,193,177,107,205,111,97,33,221,209,71,31,29,215,73,50,108,224,26,250,91,15,174,251,84,162,104,185,168,230,33,177,53,19,144,177,39,22,77,121,52,241,145,238,4,245,107,74,135,108,233,
64,77,152,97,112,52,201,179,50,132,230,121,126,17,148,20,249,101,128,242,32,91,64,220,126,251,237,177,119,100,107,16,192,209,12,72,234,147,131,34,127,15,109,129,255,27,65,25,7,58,7,218,184,212,229,165,
246,192,235,167,184,44,111,83,191,212,88,8,124,40,79,50,231,235,153,103,158,137,133,114,109,129,107,52,15,206,47,252,253,244,165,177,170,123,116,40,151,114,13,102,238,39,139,141,24,52,219,26,76,50,96,
194,1,171,49,171,85,205,4,100,236,75,197,188,47,6,84,18,81,147,173,34,162,102,139,33,108,176,193,6,49,84,149,95,48,1,89,30,33,65,224,68,157,154,76,25,65,21,115,195,232,55,99,191,171,177,69,96,151,103,
168,188,247,222,123,177,98,163,24,255,230,132,19,254,186,209,41,209,55,219,69,228,121,77,212,197,243,20,100,134,238,149,62,24,35,64,212,206,251,32,80,28,211,65,41,149,19,175,159,182,188,249,144,84,59,
184,246,17,8,177,149,210,13,55,220,208,50,81,32,7,83,92,247,198,245,218,199,131,235,95,126,112,77,30,83,150,140,24,128,234,20,253,215,124,95,252,59,173,121,204,58,235,172,145,180,225,223,173,86,53,179,
151,229,62,251,236,19,205,244,28,4,52,20,115,0,244,235,215,47,162,117,150,186,178,9,55,91,37,209,224,79,211,30,141,124,172,14,227,192,96,102,18,179,147,184,176,16,93,51,137,120,171,173,182,74,235,173,
183,94,225,111,31,51,86,82,50,223,140,85,33,100,216,114,100,206,143,142,239,35,31,124,188,101,25,48,111,57,48,249,197,51,103,133,9,199,28,12,76,40,206,129,98,198,255,39,227,125,14,76,6,196,182,215,246,
18,82,107,176,26,152,129,144,28,235,28,159,44,87,223,125,247,221,11,159,149,84,207,104,130,231,218,119,222,121,231,69,48,198,181,47,7,96,76,241,47,126,159,107,93,233,181,143,69,118,249,218,199,215,22,
43,189,246,177,189,33,95,63,186,150,8,42,100,92,191,169,112,209,142,212,90,108,7,197,126,211,92,143,249,62,171,81,205,4,100,172,148,36,58,230,151,159,247,165,228,151,183,236,178,203,166,189,247,222,59,
130,52,82,146,100,207,216,207,138,90,119,223,190,125,227,32,224,227,12,179,163,212,194,16,59,246,140,100,32,235,216,174,180,32,34,103,60,5,217,57,14,200,252,35,203,1,25,209,55,7,36,111,89,237,193,91,238,
22,248,247,88,221,153,131,178,217,102,155,109,164,128,76,170,102,244,54,18,144,129,215,210,249,231,159,111,64,38,53,8,18,30,36,55,184,246,229,76,121,14,194,184,206,229,247,9,112,184,214,241,49,2,50,174,
125,84,126,114,80,198,181,175,52,32,107,45,90,123,72,194,208,162,68,134,172,181,136,1,214,93,119,221,194,179,234,84,51,1,25,1,20,1,89,254,118,249,229,210,192,79,51,32,145,47,7,2,232,19,35,245,121,226,
137,39,198,146,253,226,175,103,105,45,147,251,201,160,241,203,145,52,102,57,32,227,14,150,19,47,119,202,187,237,182,91,225,179,146,164,182,82,51,61,100,4,80,148,3,115,230,137,18,37,101,71,202,143,197,
171,38,136,206,187,119,239,30,219,38,177,107,61,129,24,77,124,235,172,179,78,12,98,229,207,17,181,75,106,29,94,103,227,123,151,43,73,26,181,154,25,12,75,41,146,64,140,192,140,21,149,100,199,216,76,156,
82,96,113,45,154,11,6,37,77,150,233,82,70,36,40,227,235,73,85,210,244,207,190,145,57,155,38,105,212,88,249,196,34,152,91,111,189,53,6,46,231,215,21,125,151,236,99,39,73,106,91,53,83,178,164,137,143,186,
113,254,118,243,221,122,113,48,86,44,175,14,203,95,79,185,133,199,232,190,94,210,255,48,253,154,17,44,204,221,99,169,57,175,55,50,203,108,85,178,237,182,219,22,190,74,146,212,86,106,166,254,192,5,129,
204,22,205,131,60,126,43,184,226,243,197,95,207,159,55,24,147,198,14,189,152,100,198,88,4,3,110,126,88,28,195,107,73,146,212,246,108,8,145,52,18,86,19,179,204,61,239,97,201,13,14,25,178,188,194,89,146,
212,182,12,200,36,141,132,30,50,166,97,231,33,200,100,152,233,199,204,219,146,73,146,218,150,1,153,164,145,208,127,201,150,41,121,31,75,86,47,207,59,239,188,49,91,72,146,212,246,12,200,36,141,132,128,
140,114,101,222,149,130,126,76,134,47,51,252,81,146,212,246,12,200,36,141,132,21,205,140,142,201,211,185,9,200,152,237,199,78,20,146,164,182,103,64,38,105,36,140,139,33,59,150,3,50,86,40,51,215,143,94,
50,73,82,219,51,32,147,52,74,204,254,171,145,49,133,146,84,243,12,200,36,141,132,64,172,56,24,115,134,159,36,181,47,3,50,73,163,148,131,50,130,177,252,144,36,181,15,3,50,73,99,68,32,198,96,88,73,82,251,
49,32,147,52,70,108,155,196,28,50,51,100,146,212,126,12,200,36,141,128,129,176,239,189,247,94,52,245,131,149,149,172,176,52,32,147,164,246,99,64,38,105,4,3,6,12,72,47,189,244,82,108,159,4,178,99,29,59,
118,140,76,153,36,169,125,120,134,149,52,130,47,190,248,34,189,245,214,91,45,25,50,178,99,211,78,59,173,125,100,146,212,142,12,200,36,141,224,171,175,190,138,141,197,115,64,54,197,20,83,164,153,103,158,
217,161,176,146,212,142,12,200,36,141,96,216,176,97,233,179,207,62,139,237,147,64,185,114,142,57,230,48,32,147,164,118,100,64,38,105,4,223,127,255,125,108,44,158,3,50,246,175,92,104,161,133,210,164,147,
78,26,207,37,73,109,207,128,76,210,8,216,195,242,155,111,190,105,153,212,63,221,116,211,165,249,231,159,223,128,76,146,218,145,1,153,164,17,208,59,54,124,248,240,150,128,140,134,254,238,221,187,167,14,
29,58,196,115,73,82,219,51,32,147,52,2,74,149,63,255,252,115,225,153,36,169,28,12,200,36,141,32,7,100,197,155,139,75,146,218,151,1,153,164,145,228,96,204,233,252,146,84,30,6,100,146,70,82,28,144,57,161,
95,146,218,159,103,90,73,45,8,196,138,75,149,76,231,55,32,147,164,246,231,153,86,82,11,130,177,60,127,12,12,131,117,32,172,36,181,63,3,50,73,45,216,195,242,195,15,63,44,60,75,49,123,204,249,99,146,212,
254,12,200,36,181,32,32,123,255,253,247,11,207,126,221,199,114,242,201,39,47,60,147,36,181,23,3,50,73,45,200,142,125,250,233,167,133,103,41,77,53,213,84,241,144,36,181,47,3,50,73,45,6,14,28,152,6,15,30,
92,120,246,235,62,150,211,79,63,125,225,153,36,169,189,24,144,73,106,241,229,151,95,198,198,226,217,204,51,207,156,102,154,105,166,194,51,73,82,123,49,32,147,212,130,77,197,217,199,50,155,107,174,185,
82,151,46,93,10,207,36,73,237,197,128,76,82,139,239,190,251,46,125,255,253,247,133,103,41,205,62,251,236,105,214,89,103,45,60,147,36,181,23,3,50,73,45,126,248,225,135,244,211,79,63,21,158,165,52,227,140,
51,198,67,146,212,190,12,200,36,181,96,40,108,241,96,88,73,82,121,24,144,73,106,81,26,144,185,185,184,36,149,135,1,153,164,22,197,123,89,26,140,73,82,249,24,144,73,26,9,193,24,27,139,27,148,73,82,121,
24,144,73,138,172,24,13,253,185,92,73,32,198,166,226,19,78,232,41,66,146,202,193,179,173,164,244,243,207,63,199,12,178,188,194,146,128,172,67,135,14,6,100,146,84,38,158,109,37,165,161,67,135,166,167,158,
122,42,125,241,197,23,241,156,64,172,99,199,142,105,146,73,38,137,231,146,164,246,101,64,38,41,178,99,47,191,252,114,250,234,171,175,226,57,253,99,157,58,117,138,44,153,36,169,253,25,144,73,138,9,253,
111,189,245,86,26,54,108,88,60,39,32,99,99,241,201,38,155,44,158,75,146,218,151,1,153,164,104,232,239,223,191,127,4,102,32,51,54,231,156,115,70,217,82,146,212,254,12,200,36,165,31,127,252,49,13,28,56,
176,101,31,203,73,39,157,52,205,59,239,188,105,154,105,166,137,231,146,164,246,101,64,38,41,86,89,126,253,245,215,17,152,97,242,201,39,79,139,45,182,88,154,126,250,233,227,185,36,169,125,25,144,73,138,
249,99,195,135,15,143,192,12,148,44,231,154,107,46,75,150,146,84,38,6,100,146,98,48,44,229,202,60,24,150,161,176,54,245,75,82,249,24,144,73,138,128,140,236,88,222,199,82,146,84,94,6,100,146,34,16,35,59,
150,3,50,247,176,148,164,242,50,32,147,20,138,131,177,252,144,36,149,135,1,153,164,17,16,136,185,135,165,36,149,151,103,93,169,193,49,20,246,219,111,191,109,201,144,49,165,223,61,44,37,169,188,12,200,
164,6,199,198,226,131,6,13,106,9,200,88,97,201,234,74,75,150,146,84,62,6,100,82,131,251,228,147,79,82,159,62,125,90,102,144,145,29,155,114,202,41,13,200,36,169,140,12,200,164,6,199,150,73,239,188,243,
78,203,12,50,166,244,119,234,212,201,62,50,73,42,35,207,184,82,131,27,60,120,112,250,240,195,15,91,74,150,100,199,102,156,113,198,232,37,147,36,149,135,1,153,212,224,134,13,27,150,190,248,226,139,150,
12,25,27,138,207,57,231,156,6,100,146,84,70,6,100,82,131,99,15,203,175,190,250,170,240,44,69,118,108,190,249,230,139,230,126,73,82,121,24,144,73,13,142,61,44,191,249,230,155,150,146,229,76,51,205,148,
22,90,104,33,71,95,72,82,25,25,144,73,13,238,167,159,126,138,160,44,163,135,172,115,231,206,150,44,37,169,140,12,200,164,6,71,239,24,65,89,206,144,117,232,208,193,177,23,146,84,102,6,100,82,131,35,32,
203,13,253,146,164,202,48,32,147,212,146,29,51,43,38,73,149,97,64,38,53,56,130,177,28,144,49,12,214,129,176,146,84,126,158,121,37,181,48,32,147,164,202,240,204,43,53,48,230,143,125,251,237,183,133,103,
191,110,44,238,252,49,73,42,63,3,50,169,129,245,239,223,63,166,244,103,147,78,58,169,243,199,36,169,2,12,200,164,6,246,218,107,175,197,62,150,217,20,83,76,145,38,155,108,178,194,51,73,82,185,24,144,73,
13,108,193,5,23,76,243,206,59,111,234,216,177,99,204,31,219,98,139,45,210,154,107,174,89,248,172,36,169,92,12,200,164,6,198,158,149,203,46,187,108,90,126,249,229,227,237,166,155,110,154,150,94,122,233,
194,103,37,73,229,50,65,83,94,239,46,169,33,209,216,63,120,240,224,24,125,193,62,150,76,233,151,36,149,151,1,153,36,73,82,133,89,178,148,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,
146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,
3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,
73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,
32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,164,10,51,32,147,36,73,170,48,3,50,73,146,
164,10,51,32,147,36,73,170,168,148,254,31,65,94,224,203,37,161,187,51,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* RoomEditor::axis_png = (const char*) resource_RoomEditor_axis_png;
const int RoomEditor::axis_pngSize = 29220;

// JUCER_RESOURCE: roomExample_png, 5868, "../Binary/Room example.png"
static const unsigned char resource_RoomEditor_roomExample_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,111,0,0,1,28,8,6,0,0,0,8,138,53,123,0,0,0,1,115,82,71,66,0,174,206,28,233,0,0,0,
4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,195,0,0,14,195,1,199,111,168,100,0,0,22,129,73,68,65,84,120,94,237,221,13,112,28,245,121,199,241,179,49,182,37,219,146,141,109,249,13,
219,194,54,111,33,133,115,8,13,201,208,88,9,37,164,180,77,104,211,76,73,91,26,250,222,164,211,150,54,45,67,103,232,148,116,152,118,76,95,38,33,29,210,151,161,165,211,240,210,76,97,156,52,161,188,76,169,
73,12,109,112,8,226,253,197,111,178,176,108,201,198,146,44,191,157,108,73,238,243,187,187,141,215,235,59,221,238,105,239,246,237,251,153,121,70,187,119,186,221,67,200,191,253,223,179,255,93,229,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,42,56,167,252,21,72,173,217,179,103,181,175,93,181,242,234,137,83,185,92,161,80,56,84,126,24,72,180,105,229,175,64,106,172,88,182,244,138,43,47,190,160,235,218,203,215,117,93,180,108,65,
231,71,47,93,153,119,255,162,191,178,231,96,207,150,183,251,186,95,216,209,215,221,123,96,168,103,251,59,251,186,247,236,235,127,169,252,52,144,8,132,55,18,77,163,234,69,11,44,160,223,247,158,27,175,92,
187,34,255,179,235,215,116,117,44,152,59,191,158,95,108,133,250,235,125,131,61,79,189,188,125,179,66,125,223,187,67,61,111,237,236,121,166,252,52,16,43,132,55,18,69,97,189,122,249,178,252,245,239,191,
236,198,171,44,172,109,104,157,95,98,97,93,126,58,116,167,172,94,245,132,250,225,99,199,135,95,120,245,205,111,148,190,3,136,6,225,141,88,83,11,228,194,149,203,242,27,222,187,182,235,234,11,151,231,189,
45,144,70,83,120,87,163,145,250,27,132,58,34,66,120,35,54,194,108,129,132,101,178,240,174,134,80,71,51,16,222,136,76,179,91,32,142,122,2,57,12,3,67,71,134,159,121,187,175,251,249,29,251,186,95,233,217,
219,77,168,99,42,8,111,52,77,88,45,144,168,194,183,36,252,189,15,12,29,253,97,168,239,222,63,216,211,247,238,80,207,107,219,119,109,46,20,70,153,214,136,170,8,111,52,68,35,91,32,105,11,239,201,124,253,
123,111,111,118,135,250,206,61,253,221,67,195,195,187,203,79,35,195,8,111,132,162,145,45,144,104,195,218,43,30,239,70,161,190,125,96,168,103,151,213,107,187,247,118,19,234,217,67,120,163,46,78,11,228,
242,206,229,249,159,88,191,182,43,104,11,36,94,129,60,153,228,188,83,33,212,179,131,240,70,77,141,104,129,16,222,205,69,168,167,15,225,141,179,248,105,129,164,35,210,252,72,247,127,233,211,111,236,233,
254,191,109,125,221,132,122,242,16,222,168,216,2,209,227,222,95,142,244,196,88,118,14,61,245,82,168,191,185,111,176,231,197,29,123,187,9,245,120,34,188,51,70,163,234,133,11,22,116,94,91,71,11,132,240,
70,233,2,164,131,61,79,189,188,179,120,1,210,182,119,246,117,247,113,83,175,72,16,222,41,231,180,64,62,112,233,154,174,235,46,95,215,165,22,136,19,214,217,141,48,194,59,108,222,80,231,166,94,141,71,120,
167,140,211,2,249,145,206,229,249,27,92,45,144,116,33,124,147,194,27,234,92,85,26,158,40,194,123,187,213,186,210,98,238,94,171,207,89,237,176,114,30,243,227,113,171,157,86,159,47,174,157,86,207,246,110,
178,122,168,180,152,91,107,165,237,234,177,85,86,119,91,197,150,187,5,178,126,237,138,252,167,214,175,233,106,198,229,229,209,35,188,147,206,29,234,219,246,30,232,121,241,245,183,55,21,70,185,162,52,136,
102,134,247,26,43,133,170,19,144,183,89,117,90,41,128,21,150,31,46,47,215,162,224,190,222,234,171,86,238,239,175,103,123,215,88,221,111,165,160,215,251,123,178,188,44,58,16,136,159,247,212,20,222,22,200,
134,38,221,11,36,126,8,239,164,26,61,57,150,59,114,124,52,215,123,96,48,55,56,114,52,215,63,52,146,59,49,54,158,187,245,190,199,230,19,222,193,52,51,188,21,186,119,89,109,41,174,149,70,224,183,88,57,235,
250,23,233,4,123,45,149,130,181,158,237,105,59,61,86,206,8,91,239,81,97,254,112,113,237,236,247,220,84,217,104,129,212,131,240,78,10,119,88,247,15,142,228,6,15,31,45,134,181,23,225,29,92,179,194,219,61,
194,21,239,40,92,188,225,59,25,111,120,215,187,61,125,207,29,86,78,88,123,195,92,239,91,207,127,188,184,214,64,217,109,129,248,65,88,39,133,194,90,1,221,187,223,70,214,135,143,85,13,107,47,194,59,184,
102,133,183,187,165,33,78,216,186,247,31,70,120,7,221,158,247,123,188,225,45,74,142,208,127,78,180,64,130,34,192,227,232,224,200,209,98,64,171,212,2,81,96,215,227,246,7,159,238,28,30,62,196,60,242,0,154,
21,222,222,80,76,90,120,251,109,231,84,69,11,196,139,48,78,154,106,253,234,48,220,254,128,133,247,33,194,59,136,168,194,91,188,193,25,100,132,235,13,111,169,103,123,222,247,85,169,199,29,56,188,105,129,
248,65,120,199,157,223,126,117,24,8,239,224,154,21,222,222,182,137,184,31,171,244,252,100,42,133,119,61,219,115,247,226,189,125,121,71,205,131,0,45,144,122,16,222,113,83,111,191,58,12,132,119,112,205,
10,111,181,53,220,211,240,28,206,180,63,181,60,156,231,156,121,215,159,177,114,78,36,186,41,184,53,151,91,188,211,5,235,217,158,130,126,99,105,241,172,17,118,197,19,150,222,22,200,101,75,23,116,50,101,
15,73,19,86,191,58,12,132,119,112,205,10,111,9,58,237,78,161,234,110,179,76,85,61,219,211,129,226,65,171,226,123,190,236,162,181,159,252,210,205,215,222,223,217,177,96,254,185,51,206,201,45,91,184,64,
15,103,24,225,157,20,78,11,68,33,221,63,120,40,212,126,117,24,8,239,224,154,25,222,162,127,237,181,250,199,26,237,126,215,42,172,247,86,239,246,206,106,189,40,188,239,252,196,149,155,202,171,69,45,179,
102,230,90,103,207,202,45,106,159,103,203,179,114,217,10,117,194,59,174,154,217,175,14,3,225,29,92,179,195,91,116,98,209,219,62,137,155,138,151,199,87,10,239,106,188,161,222,58,123,166,45,183,149,159,
77,42,194,58,174,156,126,117,105,100,29,255,176,246,34,188,131,139,34,188,19,43,72,120,87,227,13,245,246,57,173,185,246,185,173,229,103,155,141,48,78,42,111,191,90,163,236,36,133,181,23,225,29,28,225,
29,64,24,225,93,141,66,221,9,242,54,125,181,82,200,55,22,225,157,20,10,107,167,95,125,164,48,106,161,29,221,201,197,70,32,188,131,35,188,3,104,100,120,87,211,54,167,37,215,170,17,122,67,66,157,240,142,
35,119,191,58,236,139,97,226,234,139,143,62,151,223,215,63,192,31,117,8,128,240,14,96,205,234,149,27,54,126,250,131,155,203,171,145,82,168,59,65,94,127,168,19,222,113,144,180,147,139,141,112,231,35,207,
230,251,7,246,19,222,1,16,222,1,196,41,188,171,89,216,62,207,70,234,165,190,122,237,80,39,188,163,224,156,92,140,226,98,152,184,34,188,131,35,188,3,72,66,120,87,83,57,212,103,150,159,69,35,197,233,98,
152,184,34,188,131,35,188,3,72,114,120,87,227,132,186,2,93,97,30,110,79,61,123,178,216,175,14,3,225,29,28,225,29,64,26,195,187,26,133,122,251,156,22,215,28,245,121,185,115,103,204,40,63,11,7,253,234,112,
16,222,193,17,222,1,100,41,188,171,113,66,93,35,245,44,222,34,128,126,117,99,16,222,193,17,222,1,44,91,210,113,197,61,55,119,117,151,87,81,54,227,156,115,138,83,25,75,23,30,205,76,85,168,211,175,110,14,
194,59,56,194,59,0,194,59,152,51,175,38,141,127,168,59,45,16,231,98,24,250,213,205,67,120,7,71,120,7,64,120,135,35,46,161,78,191,58,62,8,239,224,8,239,0,8,239,198,242,134,186,179,28,22,167,95,93,26,89,
19,214,113,114,247,183,95,232,218,185,187,247,153,242,42,124,32,188,3,32,188,163,225,14,114,247,149,165,181,164,237,230,77,105,182,241,91,91,187,118,245,238,33,188,3,32,188,3,32,188,227,69,161,174,32,
47,221,247,165,37,55,123,230,204,220,94,27,81,167,245,230,77,105,70,120,7,55,189,252,21,62,28,47,140,14,151,23,17,3,199,71,79,88,80,15,231,222,234,221,155,219,250,198,142,220,19,223,127,53,247,252,91,
61,185,222,3,67,4,55,82,143,240,6,128,4,34,188,145,26,244,0,145,37,132,55,0,36,16,225,29,64,161,80,160,231,13,32,22,8,111,0,72,32,194,27,0,18,136,240,6,16,185,214,150,150,249,229,69,248,68,120,3,136,220,
169,137,137,242,18,252,34,188,145,26,211,166,49,89,16,217,65,120,7,80,24,29,61,84,94,4,128,72,17,222,0,144,64,132,55,0,36,16,225,13,0,9,68,120,3,64,2,17,222,0,144,64,132,119,64,35,163,99,220,223,36,166,
248,101,70,150,240,251,14,0,9,68,120,3,136,92,107,203,108,46,143,15,136,240,6,16,57,46,143,15,142,240,6,128,4,34,188,1,32,129,8,239,128,70,10,19,204,54,1,16,57,194,27,169,193,77,5,145,37,132,55,0,36,16,
225,13,0,9,68,120,3,64,2,17,222,1,29,61,121,146,19,150,64,200,90,91,185,72,39,40,194,27,64,228,78,141,143,151,151,224,23,225,13,0,9,68,120,35,53,248,3,196,200,18,194,27,0,18,136,240,14,232,72,97,156,19,
150,0,34,71,120,3,64,2,17,222,0,144,64,132,55,210,227,84,249,43,144,1,132,55,146,75,97,237,46,32,67,8,239,128,142,156,224,10,203,72,120,131,186,66,88,51,81,48,185,230,180,180,112,133,101,64,132,55,226,
169,70,80,3,89,71,120,35,30,8,235,76,155,152,224,242,248,160,8,111,68,131,176,6,166,132,240,70,115,16,214,64,168,8,111,52,6,97,13,52,20,225,29,208,225,209,49,102,155,84,66,88,3,77,69,120,163,62,49,12,
107,110,42,136,44,33,188,225,79,12,195,250,44,132,55,50,132,240,198,217,188,65,29,215,176,6,50,140,240,6,65,141,200,205,109,153,197,21,150,1,17,222,89,68,88,35,102,38,198,39,202,75,240,139,240,14,232,
88,33,129,247,54,33,172,129,212,33,188,211,40,171,97,205,129,9,25,66,120,167,65,86,195,218,99,58,115,5,145,33,132,119,18,17,214,64,230,17,222,73,64,88,3,240,32,188,3,58,58,218,132,19,150,132,53,128,26,
8,239,56,162,117,11,160,6,194,59,174,8,112,0,147,32,188,227,140,0,71,70,204,105,157,205,21,150,1,17,222,113,167,0,39,196,125,227,71,149,76,167,198,78,150,151,224,23,225,29,208,177,209,19,209,92,97,73,
42,1,112,33,188,147,132,81,56,128,50,194,59,137,8,112,32,243,8,239,164,34,192,129,76,35,188,147,140,54,10,144,89,132,119,26,16,224,64,230,16,222,1,29,45,68,52,219,164,22,70,225,64,166,16,222,105,147,241,
0,231,174,176,200,10,194,59,141,24,133,35,97,230,182,182,112,133,101,64,132,119,154,17,224,72,136,137,241,177,242,18,252,34,188,211,142,0,7,82,137,240,14,40,178,203,227,167,130,54,10,144,58,132,119,150,
16,224,64,106,16,222,89,147,242,81,56,199,39,100,5,225,157,85,164,28,144,104,132,119,150,165,124,20,14,164,25,225,13,2,28,72,32,194,59,160,227,73,156,109,226,7,1,14,36,10,225,141,211,104,163,32,34,173,
231,206,224,10,203,128,8,111,156,141,0,7,98,143,240,198,105,167,92,149,80,211,184,51,21,50,130,240,206,50,119,88,39,56,176,129,44,34,188,3,58,94,24,77,238,9,75,194,26,72,13,194,59,205,8,107,32,181,8,239,
52,33,172,129,204,32,188,147,140,176,6,50,139,240,78,18,194,26,64,25,225,29,103,132,117,96,76,20,68,86,16,222,1,53,116,182,9,97,141,140,154,55,103,38,87,88,6,68,120,71,197,27,212,132,53,50,108,252,36,
127,195,50,40,194,187,217,8,106,0,33,32,188,1,32,129,8,111,0,72,32,194,59,160,66,161,144,206,251,121,3,72,20,194,187,30,244,172,1,68,140,240,174,199,84,38,19,51,17,185,161,166,243,243,69,70,16,222,0,144,
64,132,55,0,36,16,225,29,5,62,218,3,103,104,155,211,194,21,150,1,17,222,1,21,70,71,15,149,23,167,134,0,7,126,104,236,228,104,121,9,126,17,222,81,82,128,19,226,0,234,64,120,199,1,1,14,32,32,194,59,46,8,
240,80,76,227,7,137,140,32,188,227,132,54,10,0,159,8,239,58,140,140,142,53,246,158,222,0,80,3,225,29,37,231,246,176,238,2,0,31,8,239,102,34,168,129,32,90,172,110,176,186,171,184,150,203,157,103,117,187,
213,19,86,75,244,64,217,98,43,125,143,254,85,125,203,106,157,149,31,191,99,117,208,234,121,171,143,235,1,159,54,90,253,147,213,123,138,107,167,221,107,117,196,234,49,171,203,244,128,185,223,234,67,165,
197,112,17,222,141,68,88,3,245,106,183,250,77,171,91,173,238,176,90,96,245,235,86,127,105,229,54,215,234,151,172,86,90,233,140,209,163,86,183,89,213,114,147,213,42,171,13,86,127,110,117,185,149,55,140,
43,209,254,63,103,53,175,184,118,154,222,227,110,171,139,173,254,211,74,219,93,102,245,215,86,247,88,125,196,42,84,132,119,163,16,214,145,152,198,9,223,68,154,119,246,21,150,151,88,93,99,245,217,226,90,
46,55,100,245,119,86,191,85,92,59,77,161,173,215,62,93,92,203,229,222,176,210,247,94,95,92,171,76,223,255,126,43,93,25,244,170,213,203,86,10,218,15,91,213,242,39,86,119,90,237,45,174,149,116,88,105,116,
189,205,170,207,234,25,171,31,183,186,208,74,219,255,99,171,235,172,252,126,34,240,133,240,110,20,66,4,240,101,215,224,177,238,239,188,53,160,246,130,67,109,144,15,90,237,176,218,167,7,38,161,246,73,167,
213,187,197,181,82,219,226,132,213,194,226,90,101,10,234,57,86,10,121,57,108,53,211,74,163,251,122,40,148,79,90,105,223,50,104,165,109,181,22,215,114,185,255,177,210,40,95,173,148,217,122,32,12,132,119,
29,70,10,19,254,102,155,48,245,15,56,139,194,250,153,237,7,238,191,231,169,151,111,188,245,190,199,230,111,124,248,137,245,155,158,126,246,15,202,79,139,90,38,10,187,23,139,107,181,29,181,82,239,58,8,
5,119,208,215,76,70,7,25,189,143,106,190,111,181,212,202,219,110,169,27,225,221,12,4,56,50,204,9,235,7,182,238,186,245,206,71,158,205,43,172,31,122,114,203,175,188,190,109,199,55,170,220,43,72,39,42,117,
114,114,127,113,45,61,244,41,97,86,105,113,234,8,239,102,33,192,145,17,71,11,227,195,10,235,175,125,111,199,25,97,253,221,173,221,95,238,31,216,255,82,249,219,194,50,96,117,192,74,39,10,69,39,48,213,194,
80,255,185,26,141,146,213,38,113,122,208,26,13,235,177,157,197,181,224,182,91,233,147,130,51,3,70,7,158,215,172,156,86,78,67,196,41,188,245,3,60,183,180,88,236,11,233,7,161,58,71,15,248,228,188,70,253,
44,191,180,95,189,102,81,113,173,68,253,170,32,251,245,135,54,10,82,72,97,253,90,255,145,205,78,88,127,225,159,191,185,64,97,189,229,133,151,235,13,235,227,86,234,27,235,68,96,45,239,88,169,141,249,81,
43,253,91,214,73,199,243,173,182,90,85,163,239,87,27,67,163,224,247,90,105,102,136,250,211,175,88,213,67,159,16,158,179,210,9,202,21,86,63,111,213,99,165,147,151,110,58,208,132,118,251,196,184,132,183,
78,46,252,133,213,122,43,29,17,111,182,250,129,149,206,2,191,207,202,15,253,143,214,153,93,189,238,15,173,180,157,90,116,148,214,156,77,189,230,41,43,245,218,68,103,181,175,178,242,179,141,96,152,133,
130,132,171,20,214,95,121,244,169,143,76,33,172,189,52,146,126,193,74,121,224,80,184,254,130,213,63,88,125,204,234,95,172,52,232,210,73,66,77,15,212,215,17,171,31,179,186,219,74,126,209,74,163,226,63,
45,174,157,233,97,43,189,70,129,253,187,86,223,177,122,221,234,103,172,212,107,215,188,113,39,15,220,212,155,87,190,232,171,182,123,169,149,232,251,127,212,106,143,149,178,227,191,172,220,39,91,53,187,
165,223,74,39,71,67,17,135,113,160,254,167,124,221,234,219,86,95,181,210,255,24,253,240,243,86,250,40,242,164,149,2,252,152,85,53,58,130,234,99,202,103,172,116,196,125,196,234,62,43,77,150,159,140,230,
119,106,255,127,100,245,9,171,159,179,250,85,171,49,43,77,5,250,109,171,111,90,157,225,174,91,126,242,197,139,23,205,209,251,171,141,176,110,170,227,99,227,185,99,39,39,202,107,8,131,194,186,103,248,120,
247,139,187,7,54,245,189,59,220,189,175,127,160,59,180,251,218,87,247,1,43,253,187,252,61,171,90,51,78,38,163,236,208,39,233,255,46,174,249,115,129,149,70,208,106,163,184,167,4,214,75,163,251,79,89,61,
96,165,131,73,40,226,16,222,10,200,181,86,154,11,41,58,162,234,104,248,183,197,181,210,21,83,58,74,126,173,184,86,217,181,86,26,45,59,71,65,133,176,182,171,185,150,213,204,176,210,15,82,129,255,191,122,
192,168,87,166,137,250,234,151,233,192,161,3,202,213,86,103,156,69,190,235,179,22,222,139,171,132,55,97,29,41,194,123,234,156,176,126,179,127,104,243,246,61,253,155,247,13,28,104,70,88,123,169,117,170,
127,199,191,108,165,1,93,61,126,202,234,70,171,135,172,252,134,119,151,149,70,248,143,91,105,68,63,85,154,150,248,31,86,186,136,71,83,6,67,19,117,120,171,199,173,0,213,81,73,61,40,209,186,46,129,213,127,
176,232,146,83,245,143,156,143,66,149,232,138,42,125,92,250,233,226,90,105,114,191,230,141,78,54,41,126,141,149,230,145,42,164,213,55,19,237,251,22,171,45,197,181,210,1,68,173,27,247,28,212,51,195,155,
176,142,21,194,59,56,133,245,254,99,163,61,63,232,61,184,41,194,176,174,68,179,78,116,101,162,46,128,81,248,37,145,178,227,31,173,212,19,15,85,212,225,125,145,149,250,212,238,222,178,55,64,253,134,183,
38,234,127,190,184,22,44,188,221,63,3,239,190,117,9,173,70,245,191,81,92,43,187,225,154,171,254,236,186,75,87,220,114,126,219,76,237,19,49,66,120,215,22,227,176,70,0,81,135,119,165,144,213,9,15,245,186,
116,2,81,116,3,24,141,126,191,82,92,171,76,39,28,116,66,192,185,148,86,31,125,190,108,117,69,113,173,50,93,86,171,176,86,63,204,233,167,247,90,233,99,150,78,96,138,194,91,97,94,245,166,53,107,86,175,220,
176,176,109,110,103,103,199,130,252,146,182,150,206,13,107,22,234,245,136,8,225,125,54,194,58,157,162,14,111,245,147,117,178,82,173,11,135,110,252,162,247,165,214,137,78,38,170,231,173,48,119,2,181,18,
157,148,208,118,116,115,25,5,241,239,91,233,106,38,221,135,96,50,186,155,216,23,173,212,219,214,84,193,183,172,220,151,213,42,188,213,255,210,201,76,223,230,183,183,175,62,111,126,91,231,37,43,151,118,
173,89,220,150,95,187,104,94,158,81,122,115,16,222,132,117,86,68,29,222,154,143,169,233,57,106,234,59,39,5,53,61,232,239,173,116,71,49,45,43,60,157,19,22,26,73,107,170,77,165,201,244,154,149,242,160,149,
166,249,168,199,164,19,150,90,86,123,68,243,63,43,77,97,210,168,90,163,127,141,234,181,31,253,130,107,202,162,227,215,172,116,131,28,231,100,234,148,104,148,190,170,227,188,252,226,182,57,157,140,210,
27,35,139,225,77,88,103,83,212,225,45,154,62,243,239,86,238,41,121,106,127,104,138,144,104,212,235,76,118,215,220,79,5,247,167,139,107,103,210,212,30,103,27,186,5,227,191,150,22,139,179,80,116,79,96,205,
68,169,52,65,94,207,235,38,56,154,159,249,73,61,224,162,25,46,255,102,165,251,7,55,4,163,244,112,101,33,188,167,207,56,55,183,99,255,161,110,133,117,223,129,161,238,157,189,123,54,19,214,217,19,135,240,
214,168,90,35,80,205,185,214,36,246,201,168,45,162,43,169,190,84,92,243,103,181,149,246,161,57,223,222,43,158,38,163,125,253,141,149,110,229,216,116,140,210,235,83,24,155,200,29,61,57,94,94,75,15,221,
31,132,176,134,91,28,194,91,212,150,208,188,78,133,242,100,87,32,105,250,160,174,176,114,78,102,250,225,180,60,254,170,252,213,15,181,74,244,253,154,158,20,246,189,24,234,198,40,189,182,180,132,183,194,
250,205,254,145,205,219,250,246,111,38,172,81,73,92,194,91,190,96,165,80,214,204,146,168,105,126,183,254,2,70,24,87,87,53,156,51,74,95,189,120,126,126,222,172,25,243,179,60,74,79,106,120,43,172,123,7,
143,118,191,180,107,223,38,194,26,126,196,41,188,17,34,141,210,207,95,218,145,95,101,129,158,165,81,122,82,194,219,29,214,131,35,135,123,26,112,183,61,164,28,225,157,49,105,31,165,199,53,188,143,141,77,
27,222,218,179,127,211,59,7,71,186,53,35,132,176,198,84,17,222,40,142,210,87,44,89,148,95,109,161,158,244,81,122,92,194,91,211,247,222,28,60,190,249,141,119,6,138,247,7,33,172,17,54,194,27,85,105,148,
126,233,234,21,93,139,230,206,234,76,202,40,253,196,248,68,238,240,137,230,135,183,194,218,185,243,30,97,141,102,32,188,17,72,220,71,233,205,10,111,111,88,15,15,31,234,225,36,35,154,137,240,70,40,52,74,
215,20,198,197,109,173,145,142,210,27,21,222,238,176,238,59,48,216,205,85,140,136,26,225,141,134,89,182,164,227,138,149,75,59,242,139,230,181,116,54,107,148,30,86,120,43,172,15,158,28,239,217,186,163,
52,178,38,172,17,55,132,55,154,206,61,74,191,100,197,226,252,186,182,233,254,254,42,145,15,245,134,183,194,154,251,131,32,73,8,111,196,130,70,233,231,119,44,204,47,110,159,91,28,165,175,95,209,222,213,
54,107,198,252,242,211,190,249,13,111,194,26,73,71,120,35,182,102,207,154,213,190,124,105,71,222,25,165,95,184,120,110,190,214,223,14,173,22,222,132,53,210,134,240,70,226,56,163,244,11,150,45,202,119,
204,153,217,233,30,165,159,180,240,30,177,240,38,172,145,118,132,55,82,193,25,165,175,236,56,47,223,59,112,144,217,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,196,194,246,242,87,199,41,171,155,74,139,103,208,227,170,
219,138,107,254,220,107,165,215,120,247,49,25,237,219,217,215,26,61,96,244,88,144,253,2,64,106,41,24,221,1,41,78,104,122,195,91,225,123,77,105,49,247,184,149,179,60,25,133,173,194,91,180,61,103,121,50,
218,174,19,244,122,95,238,208,215,235,253,108,3,0,82,173,90,8,43,48,221,225,237,14,84,209,115,122,109,45,238,192,23,239,129,162,18,133,179,123,132,173,253,184,223,139,223,3,7,208,20,211,203,95,129,102,
81,0,174,179,218,82,92,155,220,135,172,220,225,189,199,74,175,157,140,66,122,173,149,251,47,255,239,176,90,94,90,172,234,99,86,189,165,197,162,157,86,171,74,139,69,119,89,221,81,90,4,162,71,120,163,217,
20,200,79,150,22,125,81,136,214,163,158,215,233,224,80,141,14,54,215,151,22,129,232,17,222,104,54,253,49,134,158,210,98,34,213,106,191,0,77,65,120,35,206,158,179,82,59,195,113,190,85,173,81,187,70,220,
106,147,184,251,211,106,163,212,106,211,104,187,250,84,224,80,72,107,255,0,0,227,158,9,226,229,61,97,41,238,147,143,222,19,145,213,184,247,49,217,254,220,180,93,167,191,238,94,118,211,137,79,0,200,36,
239,52,60,135,30,171,52,93,80,223,239,60,238,157,13,50,89,152,58,207,187,247,165,237,122,183,239,166,237,59,251,242,182,71,20,232,126,102,186,0,64,106,133,53,237,78,33,92,79,15,218,125,16,240,75,163,247,
48,222,51,0,36,90,165,209,109,16,10,83,63,237,16,55,133,175,246,27,148,223,214,11,0,100,66,165,246,73,220,104,116,95,207,72,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,169,202,229,254,31,66,232,52,70,194,182,201,67,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* RoomEditor::roomExample_png = (const char*) resource_RoomEditor_roomExample_png;
const int RoomEditor::roomExample_pngSize = 5868;


//[EndFile] You can add extra defines here...
//[/EndFile]

