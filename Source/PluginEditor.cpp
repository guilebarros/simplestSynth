#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimplestSynthAudioProcessorEditor::SimplestSynthAudioProcessorEditor (SimplestSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), adsr(audioProcessor.apvts)
{
    
    setSize (400, 300);
    

    
    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "OSC", oscSelector);
    
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

}
