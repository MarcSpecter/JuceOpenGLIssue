/*
  ==============================================================================

    DetailViewSettingsTray.h
    Created: 8 Jul 2022 4:35:03pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "../ViewPanel/TopDownTray.h"

class kDetailViewInterface;
//==============================================================================
/*
*/


class DetailViewSettingsTray  : public TopDownTray
{
public:
    DetailViewSettingsTray();
    ~DetailViewSettingsTray() override;
    
    kDetailViewInterface* interface;

    
    void addSettingButton(std::string title, std::string setting);

    void paint (juce::Graphics&) override;
    void resized() override;

    TextButton showAllButton { "Show All Columns" }, hideAllButton { "Hide All Columns" };
    
    OwnedArray<ToggleButton> settingsButtons;

    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DetailViewSettingsTray)
};


