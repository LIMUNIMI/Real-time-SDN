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
    
    room.prepare(sampleRate, roomDim, sourceNormPos, playerNormPos, getTotalNumOutputChannels(), samplesPerBlock/*Parameters::INTERNAL_PROCESS_BLOCK_SIZE*/);

    setRoomToParamValues();

    //outBuffer.prepare(sampleRate, getTotalNumOutputChannels(), sampleRate * 5, Parameters::INTERNAL_PROCESS_BLOCK_SIZE);
    //internalBuffer.setSize(std::max(getTotalNumOutputChannels(), getTotalNumInputChannels()), Parameters::INTERNAL_PROCESS_BLOCK_SIZE);
    //setLatencySamples(Parameters::INTERNAL_PROCESS_BLOCK_SIZE);
    //internalBufferFill = 0;

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

    //while (samplesToProcess >= Parameters::INTERNAL_PROCESS_BLOCK_SIZE)
    //{
    //    for (int ch = 0; ch < getTotalNumInputChannels(); ch++)
    //    {
    //        internalBuffer.copyFrom(ch, internalBufferFill, buffer, ch, inBufferSamplesProcessed, Parameters::INTERNAL_PROCESS_BLOCK_SIZE - internalBufferFill);
    //    }

    //    room.process(internalBuffer, totalNumInputChannels);

    //    outBuffer.storeInBuffer(internalBuffer);

    //    samplesToProcess -= Parameters::INTERNAL_PROCESS_BLOCK_SIZE;
    //    inBufferSamplesProcessed += Parameters::INTERNAL_PROCESS_BLOCK_SIZE - internalBufferFill;
    //    internalBufferFill = 0;
    //}

    //for (int ch = 0; ch < getTotalNumInputChannels(); ch++)
    //{
    //    internalBuffer.copyFrom(ch, internalBufferFill, buffer, ch, inBufferSamplesProcessed, buffer.getNumSamples() - inBufferSamplesProcessed);
    //}
    //internalBufferFill = samplesToProcess;

    //outBuffer.readFromBuffer(buffer);

    room.process(buffer, totalNumInputChannels);
    
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
    xml->setAttribute("HRTF_file_path", hrtfPath);
    copyXmlToBinary(*xml, destData);
}

void RealtimeSDNAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
        {
            parameters.replaceState(ValueTree::fromXml(*xmlState));
            setHRTF(xmlState->getStringAttribute("HRTF_file_path"));
        }
}

void RealtimeSDNAudioProcessor::setHRTF(const String& newPath)
{
    if (newPath.fromLastOccurrenceOf(".", false, false) == "sofa")
    {
        hrtfPath = newPath;
#ifdef _BRT_LIBRARY_
        room.setHRTF(newPath.toStdString());
#endif
    }
}

void RealtimeSDNAudioProcessor::lookAtSource()
{
    Eigen::Vector3f dir = MathUtils::dirVector(room.getSource()->getPosition(), room.getPlayer()->getPosition());
    dir.normalize();

    float azi = atan2f(dir.x(), dir.z());
    float elev = -asinf(dir.y() / dir.norm());

    azi = radiansToDegrees(azi);
    elev = radiansToDegrees(elev);

    parameters.getParameter("ListenerRotz")->setValueNotifyingHost(0.5);
    parameters.getParameter("ListenerRoty")->setValueNotifyingHost((azi + 180) / 360);
    parameters.getParameter("ListenerRotx")->setValueNotifyingHost((elev + 180) / 360);
}

void RealtimeSDNAudioProcessor::parameterChanged(const String& paramID, float newValue)
{
    if (paramID == "SourceX")
        room.setSourcePos(juce::jlimit(0.0001f, 0.9999f, newValue), 'x');
    if (paramID == "SourceY")
        room.setSourcePos(juce::jlimit(0.0001f, 0.9999f, newValue), 'y');
    if (paramID == "SourceZ")
        room.setSourcePos(juce::jlimit(0.0001f, 0.9999f, newValue), 'z');

    if (paramID == "ListenerX")
        room.setListenerPos(juce::jlimit(0.0001f, 0.9999f, newValue), 'x');
    if (paramID == "ListenerY")
        room.setListenerPos(juce::jlimit(0.0001f, 0.9999f, newValue), 'y');
    if (paramID == "ListenerZ")
        room.setListenerPos(juce::jlimit(0.0001f, 0.9999f, newValue), 'z');

    if (paramID == "OutputMode")
    {
        setOutputMode(newValue);
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

    if (paramID == "airAbsorption")
        room.enableAirAbsorption(newValue);
}

void RealtimeSDNAudioProcessor::setOutputMode(int mode)
{
    int value = mode;
    //check if chosen output can be done with available channels if not default to MONO
#ifdef _BRT_LIBRARY_
    if (value == 0 || (value > 2 && ORDER2NSH(value - 2) <= getNumOutputChannels()) || (value == 1 && getNumOutputChannels() > 1) || (value == 2 && getNumOutputChannels() > 1))
#else
    if (value == 0 || (value > 1 && ORDER2NSH(value - 1) <= getNumOutputChannels()) || (value == 1 && getNumOutputChannels() > 1))
#endif
    {
        room.setOutputMode(value, getNumOutputChannels());
    }
    else
    {
        parameters.getParameter("OutputMode")->setValueNotifyingHost(0);
        room.setOutputMode(0, getNumOutputChannels());
    }
}

void RealtimeSDNAudioProcessor::setRoomToParamValues()
{
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

    room.muteLOS(*parameters.getRawParameterValue("LOS") < 0.5f);
    float gain = *parameters.getRawParameterValue("sourceGain");
    room.setSourceGain(Decibels::decibelsToGain(gain));


#ifdef _BRT_LIBRARY_
    if (hrtfPath.fromLastOccurrenceOf(".", false, false) == "sofa")
    {
        room.setHRTF(hrtfPath.toStdString());
    }
#endif

    setOutputMode(*parameters.getRawParameterValue("OutputMode"));

}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RealtimeSDNAudioProcessor();
}
