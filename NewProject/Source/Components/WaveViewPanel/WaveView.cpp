/*
  ==============================================================================

    WaveView.cpp
    Created: 18 Jun 2022 2:53:19am
    Author:  Marc Specter

  ==============================================================================
*/

#include "WaveView.h"



WaveView::WaveView(kWaveViewInterface* iface)
:interface(iface), opengl(iface),scroller(iface),trackNames(iface)
{
    
    setWantsKeyboardFocus(true);
    setMouseClickGrabsKeyboardFocus(true);

    setOpaque(false);

    
    setOpaque(true);
    setComponentID("waveview");

    
    opengl.setComponentID("opengl");
    addAndMakeVisible(opengl);
    
    scroller.setComponentID("scroller");
    addAndMakeVisible(scroller);
    
   
    
    addAndMakeVisible(&trackNames);
    trackNames.setComponentID("trackNames");
    trackNames.setBounds(resizerBar.getX(), 0, 0, 0);
    
    addAndMakeVisible(&resizerBar);
    resizerBar.setResizerBarColours(Colours::black, Colours::darkorange.darker(1.3f));
}

WaveView::~WaveView() {
}
void WaveView::setInterface(kWaveViewInterface* iface){
    std::cout<<"KrakenBridge waveview set interface:"<<iface<<" \n";

    interface=iface;
    opengl.interface = iface;
    scroller.interface=iface;
    trackNames.setInterface(iface);
    

}


void WaveView::paint (juce::Graphics& g){
    static int ffff;
    std::cout<<"waveview paint"<<++ffff<<" \n";

  //  assert(isOpaque());
    
    auto& dfltLAF = LookAndFeel::getDefaultLookAndFeel();
    g.fillAll(Colour(30, 32, 34));
    
 
}

void WaveView::resizeWithZoom(bool maintainZoom){
    std::cout<<"waveview resizewithzoom \n";

    opengl.maintainZoomOnResize = maintainZoom;
    resized();
    
    
    opengl.maintainZoomOnResize = true;
}

void WaveView::resized(){
    static int xx;

    std::cout<<"waveview resize"<<++xx<<"\n";
    
   
    
    
  
    opengl.setBounds(getRight(), 0, getWidth(), getHeight());

   
}

void WaveView::mouseDown  (const MouseEvent& e){
    getParentComponent()->mouseDown(e);
}

void WaveView::mouseEnter  (const MouseEvent& e){
    //if (e.x < trackNames.getWidth()) trackNames.mouseEnter(e);
}


bool WaveView::isResizingVertically()
{
    if (getHeight() != oldHeight)
    {
        oldHeight = getHeight();
        return true;
    }
    else return false;
}


