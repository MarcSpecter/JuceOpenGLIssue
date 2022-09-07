/*
  ==============================================================================

    moduleToolbar.h
    Created: 15 Jun 2022 2:51:13pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>
#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

//#include "../../juceOverride/ourJuceConcertinaPanel.h"
#include "PanelLayoutButton.h"
#include "DragButton.h"
#include "PathLabel.h"
#include "ToolbarAccessory.h"
#include "TrayButton.h"


//==============================================================================
/*
*/
class moduleToolbar  : public juce::Component
{
public:
    int plop = 12345;
    
    moduleToolbar();

    ~moduleToolbar() override{}
    void setAccessory(ToolbarAccessory* acc);
    void paint (juce::Graphics& g) override;
    void resized() override;
    void mouseDown (const MouseEvent& event) override;
    void mouseDoubleClick (const MouseEvent&) override;
    void setGradientColours(Colour c);
    

    DragButton drag{"^"};
    PathLabel path;
    String fullPath;
    ToolbarAccessory* accessory = nullptr;  //optional
//    Rectangle<int> accessoryRect;
    PopupMenu settingsMenu;
    TrayButton settingsButton { "Settings "};
    TrayButton actionsButton { "Advanced Settings "};
private:
    void recalculatePathLayout();
    
    const int border=2;
    const int leftSideBorder = 50;
    
    PanelLayoutButton panelLayoutButton {"FFS"};
    
    
    Colour bgcolour;
    ColourGradient m_Gradient;
    
    Colour colour_one;
    Colour colour_two;
    Colour colour_three;
    
  
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (moduleToolbar)
};
