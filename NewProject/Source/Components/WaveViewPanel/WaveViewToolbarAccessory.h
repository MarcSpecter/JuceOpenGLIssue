/*
  ==============================================================================

    WaveViewToolbarAccessory.h
    Created: 10 Jul 2022 4:05:07pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>
#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>
using namespace juce;

#include "../ViewPanel/ToolbarAccessory.h"

//==============================================================================
/*
*/
class WaveViewToolbarAccessory  : public ToolbarAccessory
{
public:
    WaveViewToolbarAccessory();
    ~WaveViewToolbarAccessory() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    int standardLength() override;

private:
    friend class WaveViewPanel;
    friend class kUIController_WaveView_JuceBridge;

    const float leftBorder = 4;
    Rectangle<float> PBrect{ leftBorder, 3.f, 66.f, 14.f };
    float playbackSpeedV = 1.f;
    TextButton playbackSpeedL;
    TextButton minusButton { " - "}, plusButton { " + " };
    Slider volumeSlider;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveViewToolbarAccessory)
};
