#include "PluginProcessor.h"
#include "PluginEditor.h"
//#include "RoomEditor.h"

//==============================================================================
RealtimeSDNAudioProcessor::RealtimeSDNAudioProcessor() :
    parameters(*this, &undo, "pluginParams", Parameters::createParameterLayout())
#ifndef JucePlugin_PreferredChannelConfigurations
     , AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{

    Parameters::addListenerToAllParameters(parameters, this);
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

//==============================================================================
void RealtimeSDNAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    Point3d roomDim = { *parameters.getRawParameterValue("DimensionsX"), 
        *parameters.getRawParameterValue("DimensionsY"), 
        *parameters.getRawParameterValue("DimensionsZ") };
    Point3d sourceNormPos = { *parameters.getRawParameterValue("SourceX"), 
        * parameters.getRawParameterValue("SourceY"), 
        * parameters.getRawParameterValue("SourceZ") };
    Point3d playerNormPos = { *parameters.getRawParameterValue("ListenerX") ,
        *parameters.getRawParameterValue("ListenerY"),
        *parameters.getRawParameterValue("ListenerZ") };
    
    room.prepare(sampleRate, roomDim, sourceNormPos, playerNormPos, getTotalNumOutputChannels(), Parameters::INTERNAL_PROCESS_BLOCK_SIZE);

    for (int i = 0; i < 3; i++)
    {
        room.setListenerRotation(*parameters.getRawParameterValue("ListenerRot" + String::charToString(Parameters::axishelper[i * 2])), 
            Parameters::axishelper[i * 2]);
    }

    for (int i = 0; i < Parameters::NUM_WALLS; i++)
    {
        for (int j = 0; j < Parameters::NUM_FREQ; j++)
        {
            room.setWallFreqAbsorption(*parameters.getRawParameterValue("freq" + String(i) + String(j)), i, j);
        }
    }

    outBuffer.prepare(sampleRate, getTotalNumOutputChannels(), sampleRate * 5, Parameters::INTERNAL_PROCESS_BLOCK_SIZE);
    internalBuffer.setSize(std::max(getTotalNumOutputChannels(), getTotalNumInputChannels()), Parameters::INTERNAL_PROCESS_BLOCK_SIZE);
    setLatencySamples(Parameters::INTERNAL_PROCESS_BLOCK_SIZE);

    if (!parameters.state.hasType("nonAutoParams"))
    {
        parameters.state.getOrCreateChildWithName("nonAutoParams", nullptr).setProperty("HRTF_file_path", "", nullptr);
    }
    room.setHRTF(parameters.state.getChildWithName("nonAutoParams").getProperty("HRTF_file_path").toString().toStdString());
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
    //if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
    // && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
    //    return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    /*if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;*/
   #endif

    return true;
  #endif
}
#endif

void RealtimeSDNAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    int samplesToProcess = buffer.getNumSamples() + internalBufferFill;
    int inBufferSamplesProcessed = 0;

    while (samplesToProcess >= Parameters::INTERNAL_PROCESS_BLOCK_SIZE)
    {
        for (int ch = 0; ch < getTotalNumInputChannels(); ch++)
        {
            internalBuffer.copyFrom(ch, internalBufferFill, buffer, ch, inBufferSamplesProcessed, Parameters::INTERNAL_PROCESS_BLOCK_SIZE - internalBufferFill);
        }

        room.process(internalBuffer, totalNumInputChannels);

        outBuffer.storeInBuffer(internalBuffer);

        samplesToProcess -= Parameters::INTERNAL_PROCESS_BLOCK_SIZE;
        inBufferSamplesProcessed += Parameters::INTERNAL_PROCESS_BLOCK_SIZE - internalBufferFill;
        internalBufferFill = 0;
    }

    for (int ch = 0; ch < getTotalNumInputChannels(); ch++)
    {
        internalBuffer.copyFrom(ch, 0, buffer, ch, inBufferSamplesProcessed, samplesToProcess);
    }
    internalBufferFill = samplesToProcess;

    outBuffer.readFromBuffer(buffer);
    
}

//==============================================================================
bool RealtimeSDNAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* RealtimeSDNAudioProcessor::createEditor()
{
    return new RealtimeSDNAudioProcessorEditor(*this, parameters);
}

//==============================================================================
void RealtimeSDNAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void RealtimeSDNAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
        {
            parameters.replaceState(ValueTree::fromXml(*xmlState));
            room.setHRTF(parameters.state.getOrCreateChildWithName("nonAutoParams", nullptr).getProperty("HRTF_file_path").toString().toStdString());
        }
}

void RealtimeSDNAudioProcessor::setHRTF(const String& newPath)
{
    parameters.state.getOrCreateChildWithName("nonAutoParams", nullptr).setProperty("HRTF_file_path", newPath, nullptr);
    room.setHRTF(newPath.toStdString());
}

void RealtimeSDNAudioProcessor::parameterChanged(const String& paramID, float newValue)
{
    if (paramID == "SourceX")
        room.setSourcePos(newValue, 'x');
    if (paramID == "SourceY")
        room.setSourcePos(newValue, 'y');
    if (paramID == "SourceZ")
        room.setSourcePos(newValue, 'z');

    if (paramID == "ListenerX")
        room.setListenerPos(newValue, 'x');
    if (paramID == "ListenerY")
        room.setListenerPos(newValue, 'y');
    if (paramID == "ListenerZ")
        room.setListenerPos(newValue, 'z');

    if (paramID == "OutputMode")
    {
        int value = newValue;
        //check if chosen output can be done with available channels if not default to MONO
        if (value == 0 || (value > 2 && ORDER2NSH(value - 2) <= getNumOutputChannels()) || (value == 1 && getNumOutputChannels() > 1) || (value == 2 && getNumOutputChannels() > 1))
        {
            room.setOutputMode(value, getNumOutputChannels());
        }
        else
        {
            parameters.getParameter(paramID)->setValueNotifyingHost(0);
            room.setOutputMode(0, getNumOutputChannels());
        }
    }

    if (paramID.substring(0, 11) == "ListenerRot")
        room.setListenerRotation(newValue, paramID.getLastCharacter());

    if (paramID == "sourceGain")
        room.setSourceGain(Decibels::decibelsToGain(newValue));

    if (paramID == "DimensionsX")
        room.setDimensions(newValue, 'x');
    if (paramID == "DimensionsY")
        room.setDimensions(newValue, 'y');
    if (paramID == "DimensionsZ")
        room.setDimensions(newValue, 'z');

    if (paramID.substring(0, 4) == "freq")
        room.setWallFreqAbsorption(newValue, paramID.substring(4, 5).getIntValue(), paramID.substring(5,6).getIntValue());
    
    if (paramID == "LOS")
        room.muteLOS(newValue < 0.5f);
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RealtimeSDNAudioProcessor();
}
