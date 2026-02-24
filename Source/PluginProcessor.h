/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <Room.h>
#include <CircularBuffer.h>

//==============================================================================
/**
*/
class RealtimeSDNAudioProcessor  : public juce::AudioProcessor, public juce::AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    RealtimeSDNAudioProcessor();
    ~RealtimeSDNAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::File defaultLoc = juce::File::getSpecialLocation(juce::File::SpecialLocationType::commonDocumentsDirectory);

    bool setHRTF(const juce::String& newPath);
    juce::String getHRTFPath() { return hrtfPath; };

    bool geometryHasChanged() { return room.geometryHasChanged(); }
    void lookAtSource();

private:

    void parameterChanged(const juce::String& paramID, float newValue) override;
    void setOutputMode(int mode);
    
    void setRoomToParamValues();

    SDN::Room room;
    juce::AudioProcessorValueTreeState parameters;
    juce::UndoManager undo;
    CircularBuffer outBuffer;
    juce::AudioBuffer<float> internalBuffer;
    int internalBufferFill = 0;
    juce::String hrtfPath = "";
    bool isChangingParams = false;

    //bool wrongOutput = false;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RealtimeSDNAudioProcessor)
};
