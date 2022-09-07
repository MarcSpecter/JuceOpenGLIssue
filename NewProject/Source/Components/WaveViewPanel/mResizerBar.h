/*
  ==============================================================================

    mResizerBar.h
    Created: 15 Jun 2022 12:56:50pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "openGLComponent.h"


#include <vector>
#include <string>
//==============================================================================
/*
*/


class mResizerBar : public Component
{
public:
    
    mResizerBar(Component* componentToResize);
    
    void mouseDown (const MouseEvent&) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent&) override;
    void hasBeenMoved();
    void paint(Graphics& g) override;
    void mouseDoubleClick(const MouseEvent& e) override;
    void setMinMax(int minimum, int maximum);
    void setResizerBarColours(Colour baseColour, Colour HighlightedColour);
    MouseCursor getMouseCursor() override;
    bool shouldBeActive();
    
    bool isBeingDragged = false;
private:
    Component* tBox;
    Rectangle<int> originalBounds;
    Colour baseColour_, highlightColour;
    int minimumWidth = 20;
    int maximumWidth = 500;
    bool useLookAndFeel = true;
    
};
