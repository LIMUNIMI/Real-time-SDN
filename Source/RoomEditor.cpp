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

    gain.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (gain.get());
    gain->setRange (0, 10, 0);
    gain->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    gain->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    gain->setBounds (40, 600, 96, 96);

    microphone.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (microphone.get());
    microphone->setRange (0, 10, 0);
    microphone->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    microphone->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    microphone->setBounds (232, 600, 104, 96);

    los.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (los.get());
    los->setButtonText (TRANS("LOS"));
    los->addListener (this);
    los->setToggleState (true, juce::dontSendNotification);

    los->setBounds (152, 672, 72, 24);

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

    backView.reset (new RoomPlane (processor, valueTreeState,
                                   'X',
                                   'Y'));
    addAndMakeVisible (backView.get());
    backView->setName ("new component");

    backView->setBounds (8, 344, 360, 224);

    TopDown2.reset (new RoomPlane (processor, valueTreeState,
                                   'X',
                                   'Z'));
    addAndMakeVisible (TopDown2.get());
    TopDown2->setName ("new component");

    TopDown2->setBounds (8, 88, 360, 224);

    load_HRTF.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (load_HRTF.get());
    load_HRTF->setButtonText (TRANS("Load HRTF"));
    load_HRTF->addListener (this);

    load_HRTF->setBounds (160, 608, 48, 48);

    juce__tabbedComponent.reset (new juce::TabbedComponent (juce::TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (juce__tabbedComponent.get());
    juce__tabbedComponent->setTabBarDepth (30);
    juce__tabbedComponent->addTab (TRANS("Tab 0"), juce::Colours::lightgrey, new GeometryPanel (processor, valueTreeState), true);
    juce__tabbedComponent->addTab (TRANS("Tab 1"), juce::Colours::lightgrey, new WallFiltersUI (processor, valueTreeState), true);
    juce__tabbedComponent->setCurrentTabIndex (0);

    juce__tabbedComponent->setBounds (376, 64, 630, 600);

    HRTF_dragAndDrop.reset (new juce::Viewport ("new viewport"));
    addAndMakeVisible (HRTF_dragAndDrop.get());
    HRTF_dragAndDrop->setScrollBarsShown (false, false);
    HRTF_dragAndDrop->setViewedComponent (new DragAndDropPanel (processor, valueTreeState));

    HRTF_dragAndDrop->setBounds (344, 208, 472, 240);


    //[UserPreSize]
    HRTF_dragAndDrop->setVisible(false);

    gainAttachment.reset(new SliderAttachment(valueTreeState, "sourceGain", *gain));
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
    gainAttachment.reset();
    microphoneAttachment.reset();
    losAttachment.reset();
    //[/Destructor_pre]

    gain = nullptr;
    microphone = nullptr;
    los = nullptr;
    load = nullptr;
    save = nullptr;
    undo = nullptr;
    redo = nullptr;
    backView = nullptr;
    TopDown2 = nullptr;
    load_HRTF = nullptr;
    juce__tabbedComponent = nullptr;
    HRTF_dragAndDrop = nullptr;


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
        int x = 228, y = 588, width = 108, height = 20;
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
        int x = 44, y = 588, width = 84, height = 20;
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
        int x = 8, y = 312, width = 360, height = 30;
        juce::String text (TRANS("Back view"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (21.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 8, y = 56, width = 360, height = 30;
        juce::String text (TRANS("Top-down view"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (21.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
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
    else if (buttonThatWasClicked == load_HRTF.get())
    {
        //[UserButtonCode_load_HRTF] -- add your button handler code here..
        //CallOutBox::launchAsynchronously(std::make_unique<DragAndDropPanel>(), Rectangle<int>(0, 0, 0, 0), this);
        HRTF_dragAndDrop->setVisible(!HRTF_dragAndDrop->isVisible());
        //[/UserButtonCode_load_HRTF]
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
    <TEXT pos="228 588 108 20" fill="solid: ffffffff" hasStroke="0" text="Output format"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="44 588 84 20" fill="solid: ffffffff" hasStroke="0" text="Gain"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="20 12 484 30" fill="solid: ffffffff" hasStroke="0" text="SDN Reverb by Laboratorio di Informatica Musicale"
          fontname="Default font" fontsize="18.0" kerning="0.0" bold="1"
          italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="788 12 200 30" fill="solid: ffffffff" hasStroke="0" text="Coded by Marco Fontana"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="8 312 360 30" fill="solid: ffffffff" hasStroke="0" text="Back view"
          fontname="Default font" fontsize="21.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="8 56 360 30" fill="solid: ffffffff" hasStroke="0" text="Top-down view"
          fontname="Default font" fontsize="21.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="3b7355fbb7fbc0bf" memberName="gain" virtualName=""
          explicitFocusOrder="0" pos="40 600 96 96" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="new slider" id="6d6dc1f71cee9106" memberName="microphone"
          virtualName="" explicitFocusOrder="0" pos="232 600 104 96" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="new toggle button" id="dd7455385ad38f23" memberName="los"
                virtualName="" explicitFocusOrder="0" pos="152 672 72 24" buttonText="LOS"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
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
  <GENERICCOMPONENT name="new component" id="237d2c8ded89baef" memberName="backView"
                    virtualName="" explicitFocusOrder="0" pos="8 344 360 224" class="RoomPlane"
                    params="processor, valueTreeState,&#10;'X',&#10;'Y'"/>
  <GENERICCOMPONENT name="new component" id="2a2fc017b3736040" memberName="TopDown2"
                    virtualName="" explicitFocusOrder="0" pos="8 88 360 224" class="RoomPlane"
                    params="processor, valueTreeState,&#10;'X',&#10;'Z'"/>
  <TEXTBUTTON name="new button" id="fb9edc7d920f375" memberName="load_HRTF"
              virtualName="" explicitFocusOrder="0" pos="160 608 48 48" buttonText="Load HRTF"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TABBEDCOMPONENT name="new tabbed component" id="7ac39ee7e4771e11" memberName="juce__tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="376 64 630 600" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Tab 0" colour="ffd3d3d3" useJucerComp="0" contentClassName="GeometryPanel"
         constructorParams="processor, valueTreeState" jucerComponentFile=""/>
    <TAB name="Tab 1" colour="ffd3d3d3" useJucerComp="0" contentClassName="WallFiltersUI"
         constructorParams="processor, valueTreeState" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <VIEWPORT name="new viewport" id="46f4e61477c28f26" memberName="HRTF_dragAndDrop"
            virtualName="" explicitFocusOrder="0" pos="344 208 472 240" vscroll="0"
            hscroll="0" scrollbarThickness="8" contentType="2" jucerFile=""
            contentClass="DragAndDropPanel" constructorParams="processor, valueTreeState"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

