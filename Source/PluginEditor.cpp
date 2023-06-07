#include "PluginProcessor.h"
#include "PluginEditor.h"

RealtimeSDNAudioProcessorEditor::RealtimeSDNAudioProcessorEditor (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), roomEditor(p, vts)
{
    addAndMakeVisible(roomEditor);

    PropertiesFile::Options options;
    options.applicationName = ProjectInfo::projectName;
    options.commonToAllUsers = true;
    options.filenameSuffix = "settings";
    options.osxLibrarySubFolder = "Application Support";
    applicationProperties.setStorageParameters(options);

    Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea; 
    int screenWidth = r.getWidth() - 200; 
    int screenHeight = r.getHeight() - 200;

    if (auto* currConstrainer = getConstrainer())
    {
        currConstrainer->setFixedAspectRatio(static_cast<double> (originalWidth) / static_cast<double> (originalHeight));
        currConstrainer->setSizeLimits(static_cast<int>(originalWidth * minimumScale), static_cast<int>(originalHeight * minimumScale),
            static_cast<int>(screenWidth), static_cast<int>(screenHeight));
    }

    auto sizeRatio{ 1.0 };

    if (auto* currProperties = applicationProperties.getCommonSettings(true))
        sizeRatio = currProperties->getDoubleValue("sizeRatio", 1.0);

    setResizable(true, true);
    setSize(static_cast<int> (originalWidth  * sizeRatio),
            static_cast<int> (originalHeight * sizeRatio));
}

RealtimeSDNAudioProcessorEditor::~RealtimeSDNAudioProcessorEditor()
{
}

void RealtimeSDNAudioProcessorEditor::resized()
{
    const auto scaleFactor = static_cast<float> (getWidth()) / originalWidth;

    if (auto* currProperties = applicationProperties.getCommonSettings(true))
        currProperties->setValue("sizeRatio", scaleFactor);

    roomEditor.setTransform(AffineTransform::scale(scaleFactor));
    roomEditor.setBounds(0, 0, originalWidth, originalHeight);
}
