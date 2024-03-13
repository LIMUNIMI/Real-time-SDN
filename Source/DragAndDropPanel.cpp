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

#include "DragAndDropPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DragAndDropPanel::DragAndDropPanel (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    fileName_label.reset (new juce::Label ("new label",
                                           TRANS("no HRTF loaded")));
    addAndMakeVisible (fileName_label.get());
    fileName_label->setFont (juce::Font (19.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    fileName_label->setJustificationType (juce::Justification::centred);
    fileName_label->setEditable (false, false, false);
    fileName_label->setColour (juce::Label::textColourId, juce::Colours::black);
    fileName_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    fileName_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    fileName_label->setBounds (24, 168, 424, 40);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (472, 240);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DragAndDropPanel::~DragAndDropPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    fileName_label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DragAndDropPanel::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = -4, y = -4, width = 476, height = 244;
        juce::Colour fillColour = juce::Colour (0xff3d92a3);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        fillColour = customColour;
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = 0, width = 472, height = 240;
        juce::String text (TRANS("Drag your file here..."));
        juce::Colour fillColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (25.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 24, y = 24, width = 424, height = 192;
        juce::Colour strokeColour = juce::Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    //[UserPaint] Add your own custom painting code here..
    /*if (valueTreeState.state.)
    {

    }*/
    //[/UserPaint]
}

void DragAndDropPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
bool DragAndDropPanel::isInterestedInFileDrag(const StringArray& files)
{
    return files.size() == 1 && files[0].fromLastOccurrenceOf(".", false, false) == String("sofa");
}

void DragAndDropPanel::fileDragEnter(const StringArray& files, int x, int y)
{
    if (files.size() != 1
        || files[0].fromLastOccurrenceOf(".", false, false) != String("sofa"))
    {
        customColour = juce::Colours::red;
        repaint();
    }
}

void DragAndDropPanel::fileDragMove(const StringArray& files, int x, int y)
{
}

void DragAndDropPanel::fileDragExit(const StringArray& files)
{
    customColour = juce::Colour(0xff3d92a3);
    repaint();
}

void DragAndDropPanel::filesDropped(const StringArray& files, int x, int y)
{
    customColour = juce::Colour(0xff3d92a3);
    getParentComponent()->getParentComponent()->setVisible(false);

    bool loaded = processor.setHRTF(files[0]);

    if (loaded)
        fileName_label->setText("Current HRTF file: \n" +
            processor.getHRTFPath().fromLastOccurrenceOf("\\", false, false),
            NotificationType::dontSendNotification);
    else
        AlertWindow::showMessageBoxAsync(MessageBoxIconType::WarningIcon, "Sofa", "Failed to load the sofa file", "Accept", this);

    repaint();
}
void DragAndDropPanel::visibilityChanged()
{
    if (processor.getHRTFPath().fromLastOccurrenceOf(".", false, false) == "sofa")
    {
        fileName_label->setText("Current HRTF file: \n" +
            processor.getHRTFPath().fromLastOccurrenceOf("\\", false, false),
            NotificationType::dontSendNotification);
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DragAndDropPanel" componentName=""
                 parentClasses="public juce::Component, public juce::FileDragAndDropTarget"
                 constructorParams="RealtimeSDNAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="processor(p), valueTreeState(vts)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="472" initialHeight="240">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="-4 -4 476 244" fill="solid: ff3d92a3" hasStroke="0"/>
    <TEXT pos="0 0 472 240" fill="solid: ff000000" hasStroke="0" text="Drag your file here..."
          fontname="Default font" fontsize="25.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <RECT pos="24 24 424 192" fill="solid: a5642a" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <LABEL name="new label" id="d6581577d6582d71" memberName="fileName_label"
         virtualName="" explicitFocusOrder="0" pos="24 168 424 40" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="no HRTF loaded"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="19.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

