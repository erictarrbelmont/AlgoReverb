/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessor::AlgoReverbAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

AlgoReverbAudioProcessor::~AlgoReverbAudioProcessor()
{
}

//==============================================================================
const String AlgoReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AlgoReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AlgoReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AlgoReverbAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AlgoReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AlgoReverbAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AlgoReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AlgoReverbAudioProcessor::setCurrentProgram (int index)
{
}

const String AlgoReverbAudioProcessor::getProgramName (int index)
{
    return {};
}

void AlgoReverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AlgoReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    Fs = sampleRate;
}

void AlgoReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AlgoReverbAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
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

void AlgoReverbAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    float predelaySamples = predelayMS * Fs / 1000.0f;
    predelay.setDelaySamples(predelaySamples);
    predelay.setDepth(0.f);
    fdn.setDepth(modulationAmount);
    fdn.setFeedbackGain(timeAmount);
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float * channelData = buffer.getWritePointer (channel);

        for (int n = 0; n < buffer.getNumSamples() ; ++n){
            
            float dryPath = channelData[n];
            
            float wetPath = dryPath;
            wetPath = predelay.processSample(wetPath,channel);
            wetPath = fdn.processSample(wetPath, channel);
            
            channelData[n] = (1.f-wetAmount) * dryPath + wetAmount * wetPath;
        }
    }
}

//==============================================================================
bool AlgoReverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AlgoReverbAudioProcessor::createEditor()
{
    return new AlgoReverbAudioProcessorEditor (*this);
}

//==============================================================================
void AlgoReverbAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AlgoReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AlgoReverbAudioProcessor();
}
