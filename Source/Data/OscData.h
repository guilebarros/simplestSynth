#pragma once
#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>

{
    
public:
    void setWaveType(const int choice);
    
private:
    
};
