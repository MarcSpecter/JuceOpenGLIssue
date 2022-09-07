/*
  ==============================================================================

    WaveViewPanel.h
    Created: 8 Jul 2022 4:47:16pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>
#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "../ViewPanel/ViewPanel.h"

#include "WaveView.h"
#include "WaveViewSettingsTray.h"
#include "WaveViewActionsTray.h"
#include "WaveViewToolbarAccessory.h"



//#include "kUIController_WaveView.h" //testing this as baseclass




//==============================================================================
/*
*/
class WaveViewPanel  : public ViewPanel // - relies on C++ UI library???
{
public:
    WaveViewPanel();
    ~WaveViewPanel() override;
    
   
   
    //==========================================================================
    //INTERFACE - IF THE UI **IS A*** uicontroller (which it cant be cos of cocoa etc)
   
    
 
    // discriminating various repaint calls (performance)override
  
     //==========================================================================


    
    void onAdd()override{
     //   waveview.opengl.openGLContext.attachTo(waveview.opengl); //EUUGGGGH
    }
    void onRemove()override{
    //    waveview.opengl.openGLContext.detach(); //EUGGGGHH
    }
//    void paint(Graphics& g) override;
    
    
    

    
    
  
    

    
private:
    WaveView waveview;
   
    

    
    const std::vector<menuItem> _actions{
        //        {"Zoom In",     "zoomin"},
        //        {"Zoom Out",    "zoomout"},
       
        
        
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveViewPanel)
    

};
