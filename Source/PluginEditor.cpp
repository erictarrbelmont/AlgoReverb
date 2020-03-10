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
    reverbTimeSlider.setValue(0.5f);
    processor.timeAmount = 0.5f;
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
    modulationSlider.setValue(1.0f);
    processor.modulationAmount = 1.0f;
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
    wetDrySlider.setValue(0.5f);
    processor.wetAmount = 0.5f;
    addAndMakeVisible(wetDrySlider);
    
    wetDryLabel.setText("Wet/Dry", dontSendNotification);
    wetDryLabel.attachToComponent(&wetDrySlider, false);
    wetDryLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(wetDryLabel);
    
    // PREDELAY SLIDER
    predelaySlider.addListener(this);
    predelaySlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    predelaySlider.setBounds(50, 175, 100, 100);
    predelaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    predelaySlider.setRange(0.f, 200.f, 0.1f);
    predelaySlider.setValue(0.0f);
    processor.predelayMS = 0.0f;
    addAndMakeVisible(predelaySlider);
    
    predelayLabel.setText("Predelay", dontSendNotification);
    predelayLabel.attachToComponent(&predelaySlider, false);
    predelayLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(predelayLabel);
    
    // DIFFUSION SLIDER
    diffusionSlider.addListener(this);
    diffusionSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    diffusionSlider.setBounds(150, 175, 100, 100);
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    diffusionSlider.setRange(0.2f, 0.8f, 0.01f);
    diffusionSlider.setValue(0.2f);
    processor.diffusionAmount = 0.2f;
    addAndMakeVisible(diffusionSlider);
    
    diffusionLabel.setText("Diffusion", dontSendNotification);
    diffusionLabel.attachToComponent(&diffusionSlider, false);
    diffusionLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(diffusionLabel);
    
    // LPF SLIDER
    lpfSlider.addListener(this);
    lpfSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    lpfSlider.setBounds(250, 175, 100, 100);
    lpfSlider.setRange(1000.f, 20000.f, 1.f);
    lpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    lpfSlider.setValue(10000.f);
    processor.lpfFreq = 10000.f;
    addAndMakeVisible(lpfSlider);
    
    lpfLabel.setText("LPF", dontSendNotification);
    lpfLabel.attachToComponent(&lpfSlider, false);
    lpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(lpfLabel);
    
    
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
        processor.timeAmount = reverbTimeSlider.getValue();
    }
    if (slider == &modulationSlider){
        processor.modulationAmount = modulationSlider.getValue();
    }
    if (slider == &wetDrySlider){
        processor.wetAmount = wetDrySlider.getValue();
    }
    if (slider == &predelaySlider){
        processor.predelayMS = predelaySlider.getValue();
    }
    if (slider == &diffusionSlider){
        processor.diffusionAmount = diffusionSlider.getValue();
    }
    if (slider == &lpfSlider){
        processor.lpfFreq = lpfSlider.getValue();
    }
    
    
}
