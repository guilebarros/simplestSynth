#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"


class SimplestSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimplestSynthAudioProcessorEditor (SimplestSynthAudioProcessor&);
    ~SimplestSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    
    

private:


    SimplestSynthAudioProcessor& audioProcessor;
    OscComponent osc;
    AdsrComponent adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimplestSynthAudioProcessorEditor)
};
