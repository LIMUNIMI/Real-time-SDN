/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <ScatteringNode.h>
#include <Point3d.h>
#include <Room.cpp>

//==============================================================================
RealtimeSDNAudioProcessor::RealtimeSDNAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

RealtimeSDNAudioProcessor::~RealtimeSDNAudioProcessor()
{
}

//==============================================================================
const juce::String RealtimeSDNAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool RealtimeSDNAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool RealtimeSDNAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool RealtimeSDNAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double RealtimeSDNAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int RealtimeSDNAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int RealtimeSDNAudioProcessor::getCurrentProgram()
{
    return 0;
}

void RealtimeSDNAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String RealtimeSDNAudioProcessor::getProgramName (int index)
{
    return {};
}

void RealtimeSDNAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}


float attenuation;
dsp::DelayLine<float> delay;
dsp::DelayLine<float> delay2;
AudioBuffer<float> dry;
juce::dsp::ProcessorChain<dsp::Gain<float>, dsp::DelayLine<float>, dsp::DelayLine<float>> processorChain;
Room currentRoom;
//==============================================================================
void RealtimeSDNAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    Point3d sourcePos = { 1, 1, 1 };
    Point3d playerPos = { 5, 2, 3 };

    std::shared_ptr<Source> source = std::make_shared<Source>(sourcePos, getTotalNumInputChannels(), samplesPerBlock);
    std::shared_ptr<Listener> player = std::make_shared<Listener>(playerPos, getTotalNumInputChannels(), samplesPerBlock);
    currentRoom = Room({10, 10, 10}, source, player);
    currentRoom.prepare(sampleRate);
}

void RealtimeSDNAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool RealtimeSDNAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void RealtimeSDNAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    //currentRoom.printTest();
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    int numSamples = buffer.getNumSamples();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.

    //AudioBuffer<float> reflection;
    //reflection.makeCopyOf(buffer);
    //auto reflCont = dsp::ProcessContextReplacing<float>(dsp::AudioBlock<float>(reflection));
    //processorChain.process(reflCont);


    //buffer.applyGain(attenuation);
    //dry.makeCopyOf(buffer);
    currentRoom.process(buffer);
    //auto context = dsp::ProcessContextReplacing<float> (dsp::AudioBlock<float>(buffer));
    //delay.process(context);

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        auto* channelData2 = currentRoom.getPlayer()->getBuffer()->getReadPointer(channel);

        //auto* reflData = reflection.getWritePointer(channel);
        //std::transform(channelData, channelData + numSamples, channelData2, channelData, std::plus<float>());
        //std::transform(channelData, channelData + numSamples, reflData, channelData, std::plus<float>());
        //std::transform(channelData, channelData + numSamples, channelData, [](float& sample) { return sample * attenuation; });
        /*for (int j = 0; j < numSamples; j++)
        {
            printf(" %f ", channelData2[j]);
        }*/
    }

    buffer.makeCopyOf(*currentRoom.getPlayer()->getBuffer());
    
}

//==============================================================================
bool RealtimeSDNAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* RealtimeSDNAudioProcessor::createEditor()
{
    return new RealtimeSDNAudioProcessorEditor (*this);
}

//==============================================================================
void RealtimeSDNAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void RealtimeSDNAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RealtimeSDNAudioProcessor();
}
