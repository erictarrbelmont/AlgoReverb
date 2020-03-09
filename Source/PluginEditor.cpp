/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessorEditor::AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    // REVERB TIME SLIDER
    reverbTimeSlider.addListener(this);
    reverbTimeSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    reverbTimeSlider.setBounds(50, 30, 100, 100);
    reverbTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    reverbTimeSlider.setRange(0.4f, 0.7f, 0.01f);
    addAndMakeVisible(reverbTimeSlider);
    
    reverbTimeLabel.setText("Time", dontSendNotification);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, false);
    reverbTimeLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(reverbTimeLabel);
    
    // MODULATION SLIDER
    modulationSlider.addListener(this);
    modulationSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    modulationSlider.setBounds(150, 30, 100, 100);
    modulationSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    modulationSlider.setRange(1.f, 10.f, 0.01f);
    addAndMakeVisible(modulationSlider);
    
    modulationLabel.setText("Mod", dontSendNotification);
    modulationLabel.attachToComponent(&modulationSlider, false);
    modulationLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modulationLabel);
    
    // WET-DRY SLIDER
    wetDrySlider.addListener(this);
    wetDrySlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    wetDrySlider.setBounds(250, 30, 100, 100);
    wetDrySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    wetDrySlider.setRange(0.f, 1.f, 0.01f);
    addAndMakeVisible(wetDrySlider);
    
    wetDryLabel.setText("Wet/Dry", dontSendNotification);
    wetDryLabel.attachToComponent(&wetDrySlider, false);
    wetDryLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(wetDryLabel);
    
    // DIFFUSION SLIDER
    diffusionSlider.addListener(this);
    diffusionSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    diffusionSlider.setBounds(50, 175, 100, 100);
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    diffusionSlider.setRange(0.2f, 0.9f, 0.01f);
    addAndMakeVisible(diffusionSlider);
    
    diffusionLabel.setText("Diffusion", dontSendNotification);
    diffusionLabel.attachToComponent(&diffusionSlider, false);
    diffusionLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(diffusionLabel);
    
    // LPF SLIDER
    lpfSlider.addListener(this);
    lpfSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    lpfSlider.setBounds(150, 175, 100, 100);
    lpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    lpfSlider.setRange(1000.f, 20000.f, 1.f);
    addAndMakeVisible(lpfSlider);
    
    lpfLabel.setText("LPF", dontSendNotification);
    lpfLabel.attachToComponent(&lpfSlider, false);
    lpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(lpfLabel);
    
    // OUTPUT GAIN SLIDER
    outputSlider.addListener(this);
    outputSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    outputSlider.setBounds(250, 175, 100, 100);
    outputSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    outputSlider.setRange(0.f, 1.f, 0.01f);
    addAndMakeVisible(outputSlider);
    
    outputLabel.setText("Output", dontSendNotification);
    outputLabel.attachToComponent(&outputSlider, false);
    outputLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(outputLabel);
}

AlgoReverbAudioProcessorEditor::~AlgoReverbAudioProcessorEditor()
{
}

//==============================================================================
void AlgoReverbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);
    
}

void AlgoReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
}

void AlgoReverbAudioProcessorEditor::sliderValueChanged(Slider * slider){
    
    if (slider == &reverbTimeSlider){
        
    }
    if (slider == &modulationSlider){
        
    }
    if (slider == &wetDrySlider){
        
    }
    if (slider == &diffusionSlider){
        
    }
    if (slider == &lpfSlider){
        
    }
    if (slider == &outputSlider){
        
    }
    
}
