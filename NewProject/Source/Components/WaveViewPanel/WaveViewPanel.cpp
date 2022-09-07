/*
  ==============================================================================

    WaveViewPanel.cpp
    Created: 8 Jul 2022 4:47:16pm
    Author:  Marc Specter

  ==============================================================================
*/

//#include <JuceHeader.h>
//#include <juce_core/juce_core.h>


#include "WaveViewPanel.h"



#include <vector>

//#include "../../juceImplementation/kUIController_WaveView_JuceBridge.h"

//==============================================================================
WaveViewPanel::WaveViewPanel()
: waveview(nullptr)
{
     //default to internal dummy interface until proper interface is patched
    
    //waveview.interface = interface;

    
    initCommonStuff();
 

}

WaveViewPanel::~WaveViewPanel(){
    
}





//==========================================================
//MARK - interface only






