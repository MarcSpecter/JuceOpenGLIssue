/*
  ==============================================================================

    ViewPanel.h
    Created: 8 Jul 2022 11:53:21am
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>
#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include <unordered_map>
#include "moduleToolbar.h"
#include "TopDownTray.h"
#include "ToolbarAccessory.h"


class ourJuceConcertinaPanel;
class kViewInterface;
class kUIController;

class EmptyTray : public TopDownTray
{
public:
    EmptyTray() {};
    
    void paint(Graphics& g) override
    {
        g.setColour(Colours::white);
        g.drawText("Fook", getLocalBounds(), Justification::centred);
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EmptyTray)
};
//enum {
//    USE_IN_CONTEXT_MENU = 1,
//    USE_IN_TRAY = 2
//};
//
struct menuItem{
    std::string label;
    std::string command;
    int context;
    
   
};


//==============================================================================
/*
*/
class ViewPanel  : public Component,
                   public DragAndDropContainer      //drag button
{
public:

    ViewPanel();
    ~ViewPanel() override;
    
    virtual kViewInterface* Interface(){};    //TODO: make pure virtual   =0
    virtual void setInterface(kViewInterface* interface) {};  //TODO: make pure virtual   =0
    
    virtual kUIController* getInternalUIController(){};   //make pure
    virtual kUIController* getExternalUIController(){};   
    
    virtual void turnOn() {};
    
    virtual void onAdd(){};
    virtual void onRemove(){};
    
    void initCommonStuff();
    void initMenus(std::function<void(std::string)> actionHandler, std::function<void(std::string)> settingsHandler);
    void setTrayStatus(TopDownTray& tray, bool shouldOpen);
    
//    virtual std::unordered_map<std::string, setting>& getSettings() = 0;

//    virtual int GetTrayHeight();
//    virtual TopDownTray& GetToolbarAccessory() = 0;
    
    void addSettingButton(const std::string& key);

    void setOpenTray(TopDownTray* tray);
    void mouseDown  (const MouseEvent&) override;
    void mouseDoubleClick  (const MouseEvent&) override;
    void resized() override;
    
    ourJuceConcertinaPanel* concertina; //containing concertina

protected:
    
public:
    int plop = 54321;
protected:
    moduleToolbar toolbar;
    EmptyTray emptyTray; //placeholder
    TopDownTray* currentOpenTray = nullptr;
    //bool isTrayVisible = false;
    //bool isOtherTrayVisible = false;

    PopupMenu actionMenu;
    PopupMenu settingsMenu;
    


private:
    
    
   
    
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ViewPanel)
};



