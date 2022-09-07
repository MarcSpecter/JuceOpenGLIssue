/*
  ==============================================================================

    PanelLayoutButton.h
    Created: 4 Jul 2022 4:36:54pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>

#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

using namespace juce;
//==============================================================================
/*
*/
class PanelLayoutButton  : public juce::Button
{
public:
    PanelLayoutButton(const String& buttonName) : Button(buttonName)
    {
     
    }

    ~PanelLayoutButton() override
    {
    }

    void paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
//        const auto bounds = getLocalBounds();
//        const auto xBorder = 5;
//        const auto sliceHeight = bounds.getHeight()/7;
//
//
//        g.setColour(Colours::white.darker(shouldDrawButtonAsDown?0.f : 0.1f).withAlpha(0.5f));
//
//        for (auto i = 1; i < 7; i+=2)
//        {
//
//            g.fillRect(xBorder, sliceHeight*i+shouldDrawButtonAsDown, getWidth()-2*xBorder, sliceHeight);
//        }
        
        auto width = getLocalBounds().getWidth();
        auto height = getLocalBounds().getHeight();
        
        
        
    
    };

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PanelLayoutButton)
   // Image burgImage = ImageCache::getFromMemory(BinaryData::BurgerIcon_png, BinaryData::BurgerIcon_pngSize);
    Image burgImageAlphaed;
};
