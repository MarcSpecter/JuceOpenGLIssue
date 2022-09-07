/*
  ==============================================================================

    waveScroller.h
    Created: 2 Jul 2022 8:42:40pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
class kWaveViewInterface;
using namespace juce;
//==============================================================================
/*
*/

class TrackBoxComponent  : public Component
{
public:
    TrackBoxComponent(kWaveViewInterface* interface);
    ~TrackBoxComponent() override;
    
    void setInterface(kWaveViewInterface* interface);
    
    void paint(Graphics& g) override;
    void resized() override;
    
    void updateTrackNameFont();
    void drawChannelNameText(juce::Graphics& g, String text, Rectangle<int>& pos, bool soloed, bool hovered);
    void mouseDrag (const MouseEvent& e) override;
    void mouseDown (const MouseEvent& e) override;
    void mouseMove  (const MouseEvent& e) override;
    void mouseExit(const MouseEvent& e) override;
    
    const float baseFontSize = 17.f;
    Font cachedFont;
    
private:
    kWaveViewInterface* interface;

    const int _channelNameWidth = 50;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackBoxComponent)
};

