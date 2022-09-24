#include "OscData.h"

void OscData::setWaveType(const int choice)
{
    // WAVE EQUATIONS
 
    switch (choice) {
        case 0:
            //sine
            initialise([](float x){ return std::sin (x); });
            break;
        case 1:
            // saw
            initialise([](float x){ return x / juce::MathConstants<float>::pi; });
            break;
        case 2:
            //square
            initialise([](float x){ return x < 0.0f ? -1.0f : 1.0f; });
            break;
            
        default:
            jassertfalse; // Deu tudo errado 
            break;
    }
}
