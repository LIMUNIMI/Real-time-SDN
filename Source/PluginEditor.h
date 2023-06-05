#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "RoomEditor.h"

class RealtimeSDNAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    RealtimeSDNAudioProcessorEditor (RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~RealtimeSDNAudioProcessorEditor() override;

    void resized() override;

private:
    static constexpr int originalWidth{ 1018 };
    static constexpr int originalHeight{ 720 };
    static constexpr double minimumScale{ 0.75 };
    static constexpr double maximumScale{ 2.00 };

    RoomEditor roomEditor;
    ApplicationProperties applicationProperties;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RealtimeSDNAudioProcessorEditor)
};
