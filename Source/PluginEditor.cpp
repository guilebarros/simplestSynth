#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimplestSynthAudioProcessorEditor::SimplestSynthAudioProcessorEditor (SimplestSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.apvts, "OSC1WAVETYPE"), adsr(audioProcessor.apvts)
{
    
    setSize (400, 300);
    
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    
}

SimplestSynthAudioProcessorEditor::~SimplestSynthAudioProcessorEditor()
{
}

//==============================================================================
void SimplestSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    g.fillAll (juce::Colours::black);
}

void SimplestSynthAudioProcessorEditor::resized()
{
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
    osc.setBounds(10, 10, 100, 30);

}
