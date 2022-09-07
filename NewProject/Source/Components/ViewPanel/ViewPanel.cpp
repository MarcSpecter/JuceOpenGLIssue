/*
  ==============================================================================

    ViewPanel.cpp
    Created: 8 Jul 2022 11:53:21am
    Author:  Marc Specter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ViewPanel.h"
//#include "../../juceOverride/ourJuceConcertinaPanel.h"

//==============================================================================

ViewPanel::ViewPanel()
{
}

ViewPanel::~ViewPanel()
{
}

void ViewPanel::initCommonStuff(){
    
    //TOOLBAR
    toolbar.setGradientColours(Colours::pink);
    addAndMakeVisible(toolbar);
    
  
 
    
    
   
    
//    addAndMakeVisible(GetMainComponent());
}

void ViewPanel::initMenus(std::function<void(std::string)> actionHandler, std::function<void(std::string)> settingsHandler){
    
    

}

void ViewPanel::setTrayStatus(TopDownTray& tray, bool shouldOpen)
{
 
}

void ViewPanel::setOpenTray(TopDownTray* tray)
{
    
}


void ViewPanel::mouseDown  (const MouseEvent& ev)
{
    
}

void ViewPanel::mouseDoubleClick  (const MouseEvent&)
{
    setOpenTray(nullptr);
    toolbar.actionsButton.setHighlighted(false);
    toolbar.settingsButton.setHighlighted(false);
}

void ViewPanel::resized()
{
    int trayHeight = 0;
    if(currentOpenTray) {
        Rectangle<int> settingsTrayBounds = currentOpenTray->getBounds();
        currentOpenTray->setBounds(settingsTrayBounds.withWidth(getWidth()));
        trayHeight = currentOpenTray->getHeight();
        
       
    }
    
    
  
    
   
}

