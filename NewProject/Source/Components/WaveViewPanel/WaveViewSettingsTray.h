/*
  ==============================================================================

    WaveViewSettingsTray.h
    Created: 8 Jul 2022 4:52:19pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>
#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "../ViewPanel/TopDownTray.h"

//==============================================================================
/*
*/
class kWaveViewInterface;

class WaveViewSettingsTray  : public TopDownTray
{
public:
    WaveViewSettingsTray();
    ~WaveViewSettingsTray() override;
    
    ToggleButton* addSettingButton(std::string title, std::string setting);
    void addActionButton(std::string title, std::string command);
    
    void paint (juce::Graphics&) override;
    void resized() override;

    std::vector<ToggleButton*> playSettings;
    std::vector<ToggleButton*> soloSettings;
    std::vector<ToggleButton*> spotSettings;
    
    OwnedArray<ToggleButton> settingsButtons;

    OwnedArray<TextButton> actionButtons;
    kWaveViewInterface* interface;
private:
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveViewSettingsTray)
};
