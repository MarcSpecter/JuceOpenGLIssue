/*
  ==============================================================================

    openGLComponent.h
    Created: 15 Jun 2022 10:05:11pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
using namespace juce;

class kWaveViewInterface;

//==============================================================================
/*
*/
class openGLComponent  : public juce::Component,  private OpenGLRenderer
{
public:
    openGLComponent(kWaveViewInterface* interface);
    ~openGLComponent() override;
    
    void newOpenGLContextCreated() override;
    
    void renderOpenGL() override;
    
    void openGLContextClosing() override;
    
    //void drawChannelNameText(juce::Graphics& g, String text, Rectangle<int>& pos, bool soloed);
    //void paint (juce::Graphics&) override;
    void resized() override;
    
    void mouseDown  (const MouseEvent&) override;
    void mouseUp  (const MouseEvent&) override;
    void mouseDrag  (const MouseEvent&) override;
    void mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) override;
    
    std::vector<std::string> channelnames;
    int nameBackgroundWidth = 60;

    OpenGLContext openGLContext;

    bool maintainZoomOnResize = true;
    kWaveViewInterface* interface;
private:
    float desktopScale=1.0;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (openGLComponent)
};
