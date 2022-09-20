#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimplestSynthAudioProcessorEditor)
};
