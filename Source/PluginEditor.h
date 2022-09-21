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
    
    void setSliderParams(juce::Slider& slider);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    juce::ComboBox oscSelector;
    
    // unique pointers liberam a memoria da UI sempre que ela é fechada
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decayAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseAttachment;
    
 //   std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;

    SimplestSynthAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimplestSynthAudioProcessorEditor)
};
