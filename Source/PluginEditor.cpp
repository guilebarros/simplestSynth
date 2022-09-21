#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimplestSynthAudioProcessorEditor::SimplestSynthAudioProcessorEditor (SimplestSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    setSize (400, 300);
    
    attackAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ATTACK", attackSlider);
    
    decayAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "RELEASE", releaseSlider);
    
  //  oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "OSC", oscSelAttachment);
    
    setSliderParams(attackSlider);
    setSliderParams(decaySlider);
    setSliderParams(sustainSlider);
    setSliderParams(releaseSlider);
    
    

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
    const auto bounds = getLocalBounds().reduced (10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getWidth() / 4 - padding;
    const auto sliderStartX = 0;
    const auto sliderStartY = bounds.getHeight() / 2 - (sliderHeight / 2);
  
    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);

}

void SimplestSynthAudioProcessorEditor::setSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
}
