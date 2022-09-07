/*
  ==============================================================================

    TopDownMenu.h
    Created: 23 Jun 2022 2:47:29pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>
#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "moduleToolbar.h"

//==============================================================================
/*
*/
class TopDownTray  : public juce::Component
{
public:
    TopDownTray();
    ~TopDownTray() override;
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void mouseDoubleClick(const MouseEvent& e) override;

    Colour mainColour;
protected:
    bool isShowing = false;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TopDownTray)
};
