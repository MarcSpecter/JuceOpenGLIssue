/*
  ==============================================================================

    waveScroller.cpp
    Created: 2 Jul 2022 8:42:40pm
    Author:  Marc Specter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "waveScroller.h"



//==============================================================================
waveScroller::waveScroller(kWaveViewInterface* iface):interface(iface)
{
}

waveScroller::~waveScroller()
{
}
void waveScroller::updateOffset(float offset, float zoom){

//    std::cout<<"offset:"<<offset<<" zoom:"<<zoom<<"\n";
    waveOffset = offset;
    length = zoom;  //normalised proportion of range filled

//    position = offset/(1-zoom);
    
    
    if(length>=1.0){
//        position=0;
        length= 1;
    }
    

}
void waveScroller::mouseDown  (const MouseEvent& ev){
}
void waveScroller::mouseDrag  (const MouseEvent& ev){
        // [self.superview mouseDragged:event];   //redirect mouse events to wavhost
}

void waveScroller::paint (juce::Graphics& g)
{

   // g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.fillAll (Colours::grey);

    g.setColour (Colours::white);
    g.fillRect(int(getWidth()*waveOffset), 0, int(getWidth()*length), getHeight());
    
    g.setColour (Colours::orange);
    
    Rectangle<int> playhead(playPos*getWidth()-1,0,2,getHeight());
    g.fillRect(playhead);
  
}


