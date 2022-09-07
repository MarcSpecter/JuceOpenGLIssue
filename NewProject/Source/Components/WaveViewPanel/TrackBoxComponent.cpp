/*
  ==============================================================================

    TimecodeFields.cpp
    Created: 2 Jul 2022 8:42:40pm
    Author:  Tony Tormenta

  ==============================================================================
*/

#include <JuceHeader.h>


#include "TrackBoxComponent.h"


//==============================================================================
TrackBoxComponent::TrackBoxComponent(kWaveViewInterface* iface):interface(iface)
{
    setBufferedToImage(true);
    std::cout<<"KrakenBridge TrackBoxComponent construct iface="<<iface<<"\n";

}

TrackBoxComponent::~TrackBoxComponent(){
    
}
void TrackBoxComponent::setInterface(kWaveViewInterface* iface){
    interface = iface;
    std::cout<<"KrakenBridge TrackBoxComponent setInterface:"<<interface<<"\n";

}

void TrackBoxComponent::paint(Graphics& g)
{
    
}
   
void TrackBoxComponent::updateTrackNameFont()
{
   
}
void TrackBoxComponent::resized(){
    
}

void TrackBoxComponent::drawChannelNameText(juce::Graphics& g, String text, Rectangle<int>& pos, bool soloed, bool hovered){
  
}

void TrackBoxComponent::mouseDrag (const MouseEvent& e){
    int ey = getHeight() - e.y;
    
    //if mouse drag STARTED in the channel names, send a track name drag
}

void TrackBoxComponent::mouseDown  (const MouseEvent& e){
    if(e.mods.isRightButtonDown())
    {
        getParentComponent()->getParentComponent()->mouseDown(e);  //  ??????????
    }
    else
    {
    }
}

void TrackBoxComponent::mouseMove (const MouseEvent& e){
}

void TrackBoxComponent::mouseExit(const MouseEvent& e){
}
