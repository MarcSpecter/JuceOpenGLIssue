/*
  ==============================================================================

    DetailViewPanel.h
    Created: 8 Jul 2022 4:18:18pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../ViewPanel/ViewPanel.h"

#include "DetailView.h"
#include "DetailViewSettingsTray.h"
#include "DetailViewActionsTray.h"
#include "DetailViewToolbarAccessory.h"



//==============================================================================
/*
*/
class DetailViewPanel  : public ViewPanel
{
public:
    DetailViewPanel(kDetailViewInterface* interface);
    ~DetailViewPanel() override;
        
   
    
    void turnOn() override;
    
    //INLINE INTERFACE
;




private:
    DetailView detailview;

    
  

    const std::vector<menuItem> actions{
        
        {"Reveal In Finder",      "revealInFinder"},
//        {"Shrink Columns",      "shrinkColumns"},
        {"Reset Viewed",      "Request_ResetAlreadyViewed"},

        
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DetailViewPanel)
};
