/*
  ==============================================================================

    DetailViewActionsTray.h
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

class privateCBLookAndFeel : public LookAndFeel_V2
{
    
    void drawPopupMenuItemWithOptions (juce::Graphics& g, const juce::Rectangle<int>& area,
                                       bool isHighlighted,
                                       const juce::PopupMenu::Item& item,
                                       const juce::PopupMenu::Options& options) override;
    
    Colour findPopupColour (int colourId, juce::Component* target);
};





class DetailViewActionsTray  : public TopDownTray
{
public:
    DetailViewActionsTray();
    ~DetailViewActionsTray() override;
    
    kDetailViewInterface* interface;
    
    void addSettingButton(std::string title, std::string setting);
    void addActionButton(std::string title, std::string command);

    void paint (juce::Graphics&) override;
    void resized() override;

    TextButton showAllButton { "Show All Columns" }, hideAllButton { "Hide All Columns" };
    
    OwnedArray<ToggleButton> settingsButtons;
    OwnedArray<TextButton> actionButtons;

    privateCBLookAndFeel privCBLookAndFeel;
    ComboBox filterComboBox1, filterComboBox2;
    ToggleButton andToggle, orToggle;
    ComboBox containsCB1, containsCB2;
    TextEditor searchTerms1, searchTerms2;
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DetailViewActionsTray)
};


