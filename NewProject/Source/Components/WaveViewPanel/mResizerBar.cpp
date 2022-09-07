/*
  ==============================================================================

    mResizerBar.cpp
    Created: 18 Jun 2022 2:53:19am
    Author:  Giulio Iacomino

  ==============================================================================
*/

#include "mResizerBar.h"
#include "WaveView.h"




mResizerBar::mResizerBar(Component* componentToResize) : tBox(componentToResize)
{
    setRepaintsOnMouseActivity (true);
    setAlwaysOnTop(true);
    
};

void mResizerBar::mouseDown (const MouseEvent&)
{
    if (tBox == nullptr)
    {
        jassertfalse; // You've deleted the component that this resizer was supposed to be using!
        return;
    }
    originalBounds = tBox->getBounds();
}

void mResizerBar::mouseDrag (const MouseEvent& e)
{
    if (shouldBeActive())
    {

        isBeingDragged = true;
        auto newBounds = originalBounds;
        int w = jmax (0, newBounds.getWidth() + e.getDistanceFromDragStartX());
        w = jlimit(minimumWidth, maximumWidth, w);
        newBounds.setWidth(w);
        tBox->setBounds (newBounds);
        hasBeenMoved();
    }
    updateMouseCursor();
}

void mResizerBar::mouseUp(const MouseEvent&)
{
    isBeingDragged = false;
}

MouseCursor mResizerBar::getMouseCursor()
{

    return shouldBeActive()?MouseCursor::LeftRightResizeCursor:MouseCursor::NormalCursor;
}

void mResizerBar::paint(Graphics& g)
{
    if (useLookAndFeel)
    {
        baseColour_ = LookAndFeel::getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId);
        highlightColour = baseColour_.brighter(0.5f);
        
    }
    
    if (shouldBeActive() && isMouseOverOrDragging()){
        g.setColour(highlightColour);
    }
    else{
        g.setColour(baseColour_);
    }
    g.fillRect(0, 0, getWidth(), getHeight());
}

void mResizerBar::mouseDoubleClick(const MouseEvent &e)
{
    if (shouldBeActive())
    {
        if (WaveView* parent = findParentComponentOfClass<WaveView>())
        {
//            parent->shrinkTrackBoxToFitText();
        }

    }
}

void mResizerBar::hasBeenMoved()
{
    if (WaveView* parent = findParentComponentOfClass<WaveView>())
    {
        parent->resizeWithZoom(false);
    }
    else
    {
        getParentComponent()->resized();
    }
}

void mResizerBar::setMinMax(int minimum, int maximum)
{
    minimumWidth = minimum;
    maximumWidth = maximum;
}

void mResizerBar::setResizerBarColours(Colour baseColour, Colour HighlightedColour)
{
    baseColour_ = baseColour;
    highlightColour = HighlightedColour;
    useLookAndFeel = false;
}


bool mResizerBar::shouldBeActive()
{
    return isEnabled() && ModifierKeys::currentModifiers.isAltDown();
}
