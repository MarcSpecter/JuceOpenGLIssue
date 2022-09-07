/*
  ==============================================================================

    WaveView.h
    Created: 15 Jun 2022 12:56:50pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

//#include <JuceHeader.h>
#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "openGLComponent.h"
#include "waveScroller.h"
//#include "TimecodeFields.h"
#include "TrackBoxComponent.h"
#include "mResizerBar.h"

#include <vector>
#include <string>
//==============================================================================
/*
*/

class WaveView  : public juce::Component
{
public:
    WaveView(kWaveViewInterface* interface);
    ~WaveView() override;
    
    void setInterface(kWaveViewInterface* interface);


    
    void mouseDown  (const MouseEvent&) override;
    void mouseEnter  (const MouseEvent&) override;

    void paint (juce::Graphics& g) override;
    void resizeWithZoom(bool maintainZoom);
    void resized() override;
    bool isResizingVertically();
    void shrinkTrackBoxToFitText();
    
    openGLComponent opengl;
private:
    friend class WaveViewPanel;
    friend class kUIController_WaveView_JuceBridge;
    
    kWaveViewInterface* interface;
    
    waveScroller scroller;
    TrackBoxComponent trackNames;
   
    mResizerBar resizerBar {&trackNames};
    int oldHeight = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveView)
};


