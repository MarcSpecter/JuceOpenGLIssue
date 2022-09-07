/*
  ==============================================================================

    DetailViewPanel.cpp
    Created: 8 Jul 2022 4:18:18pm
    Author:  Marc Specter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DetailViewPanel.h"

//#include "../../juceImplementation/kUIController_DetailView_JuceBridge.h"


//==============================================================================
DetailViewPanel::DetailViewPanel(kDetailViewInterface* iface): detailview(iface)
{
  
}

DetailViewPanel::~DetailViewPanel(){
//    interface->Shutdown();
}

void DetailViewPanel::turnOn(){         // have to resync from dummy interface to actual one
//    interface->InitUI((void*)this);
//    settingsTray.interface = interface;
//    actionsTray.interface = interface;
//    detailview.interface = interface;

}







