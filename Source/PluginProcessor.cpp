#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RealtimeSDNAudioProcessor::RealtimeSDNAudioProcessor() :
    parameters(*this, nullptr, "pluginParams", Parameters::createParameterLayout())
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
    parameters.addParameterListener("SourceX", this);
    parameters.addParameterListener("SourceY", this);
    parameters.addParameterListener("SourceZ", this);
    parameters.addParameterListener("ListenerX", this);
    parameters.addParameterListener("ListenerY", this);
    parameters.addParameterListener("ListenerZ", this);
    parameters.addParameterListener("WallAbsorption", this);
    parameters.addParameterListener("DimensionsX", this);
    parameters.addParameterListener("DimensionsY", this);
    parameters.addParameterListener("DimensionsZ", this);
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
    Point3d sourcePos = { *parameters.getRawParameterValue("SourceX") * roomDim.x , 
        * parameters.getRawParameterValue("SourceY")* roomDim.y, 
        * parameters.getRawParameterValue("SourceZ")* roomDim.z };
    Point3d playerPos = { *parameters.getRawParameterValue("ListenerX") * roomDim.x ,
        *parameters.getRawParameterValue("ListenerY") * roomDim.y,
        *parameters.getRawParameterValue("ListenerZ") * roomDim.z };
    
    room.prepare(sampleRate, roomDim, sourcePos, playerPos, getTotalNumInputChannels(), samplesPerBlock);
    room.setWallAbsorption(*parameters.getRawParameterValue("WallAbsorption"));
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
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    room.process(buffer);
    
}

//==============================================================================
bool RealtimeSDNAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* RealtimeSDNAudioProcessor::createEditor()
{
    return new RealtimeSDNAudioProcessorEditor (*this);
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
            parameters.replaceState(ValueTree::fromXml(*xmlState));
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

    if (paramID == "WallAbsorption")
        room.setWallAbsorption(newValue);

    if (paramID == "DimensionsX")
        room.setDimensions(newValue, 'x');
    if (paramID == "DimensionsY")
        room.setDimensions(newValue, 'y');
    if (paramID == "DimensionsZ")
        room.setDimensions(newValue, 'z');

}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RealtimeSDNAudioProcessor();
}
