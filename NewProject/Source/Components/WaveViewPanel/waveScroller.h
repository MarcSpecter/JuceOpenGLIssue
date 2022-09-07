/*
  ==============================================================================

    waveScroller.h
    Created: 2 Jul 2022 8:42:40pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
using namespace juce;
class kWaveViewInterface;

//==============================================================================
/*
*/
class waveScroller  : public juce::Component
{
public:
    waveScroller(kWaveViewInterface* interface);
    ~waveScroller() override;
    
    void updateOffset(float offset, float zoom);

    void paint (juce::Graphics&) override;
    
    double waveOffset=0;
    float playPos=0;
   
    void mouseDown  (const MouseEvent&) override;
    void mouseDrag  (const MouseEvent&) override;

    kWaveViewInterface* interface;
private:
    
//    float position=0;
    float length=1;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (waveScroller)
};


