/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EffectTestAudioProcessor::EffectTestAudioProcessor()
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

EffectTestAudioProcessor::~EffectTestAudioProcessor()
{
}

//==============================================================================
const String EffectTestAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EffectTestAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EffectTestAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double EffectTestAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EffectTestAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int EffectTestAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EffectTestAudioProcessor::setCurrentProgram (int index)
{
}

const String EffectTestAudioProcessor::getProgramName (int index)
{
    return String();
}

void EffectTestAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void EffectTestAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void EffectTestAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool EffectTestAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void EffectTestAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    
    //MY CODE declare float variables x and y
    float y = 0.f;
    float x = 0.f;
    
    //MY CODE the below 'for' loop should be used in ALL code and loops between processing the
    //left and right channels (L = 0, R = 1)
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        //MY CODE each channelData points to a memory array of 'channel' ie. 0 or 1 (L or R)
        float* channelData = buffer.getWritePointer (channel);
        
        //MY CODE this 'for loop' loops through the samples in one array (array 0 or 1)
        //before returning to the main loop to process the other side
        for(int i = 0; i < buffer.getNumSamples(); i++){
            
            //MY CODE x = channelData array
            x = channelData[i]; //* 2.0f;  this can be added as gain stage
            
            //MY CODE distortion code
            if (x > 0.0f)
                y = 1.0f - expf(-x);
            else y = -1.0f + expf(x);
            
            //MY CODE new array = result of distortion code
            channelData[i] = y;
                
        }
     
    }
    
}

//==============================================================================
bool EffectTestAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* EffectTestAudioProcessor::createEditor()
{
    return new EffectTestAudioProcessorEditor (*this);
}

//==============================================================================
void EffectTestAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void EffectTestAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new EffectTestAudioProcessor();
}
