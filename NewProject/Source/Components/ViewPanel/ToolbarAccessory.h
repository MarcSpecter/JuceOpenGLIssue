/*
  ==============================================================================

    ToolbarAccessory.h
    Created: 10 Jul 2022 4:04:25pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ToolbarAccessory  : public juce::Component
{
public:
    ToolbarAccessory()
    {
        setComponentID("accessory");

    }

    ~ToolbarAccessory() override
    {
    }

    void paint (juce::Graphics& g) override
    {

       // g.fillAll (Colours::darkblue);   // debug draw background

    }

    void resized() override
    {
    }

    virtual int standardLength() = 0;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToolbarAccessory)
};
