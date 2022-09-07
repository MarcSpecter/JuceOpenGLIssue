/*
  ==============================================================================

    TopDownMenu.cpp
    Created: 23 Jun 2022 2:47:29pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TopDownTray.h"


//==============================================================================
TopDownTray::TopDownTray()
{
    //setComponentID("tray");
}

TopDownTray::~TopDownTray()
{
}

void TopDownTray::paint (juce::Graphics& g)
{
    auto m_Gradient = ColourGradient::vertical(mainColour.darker(1.5f).darker(0.05),mainColour, getBounds());
    m_Gradient.addColour(0.1, mainColour.darker(1.5f));
    m_Gradient.addColour(0.62, mainColour.darker(1.5f));
    g.setGradientFill(m_Gradient);
    g.fillAll();
    
    g.setColour(Colours::black.withAlpha(0.2f));  // dark outlines
    g.drawRect(0, 0, getWidth(), getHeight(), 2);
    
    g.setColour(mainColour.darker(0.05));         // highlighted bottom
    g.fillRect(0, getHeight()-4, getWidth(), 4);
    
    g.setColour(Colours::black.withAlpha(0.7f)); // bottom border outline
    g.drawRect(0, getHeight()-5, getWidth(), 5);
    g.setColour(Colours::black.withAlpha(0.2f)); // top border shade
    g.fillRect(0, 0, getWidth(), 2);
}

void TopDownTray::resized()
{
}

void TopDownTray::mouseDoubleClick(const MouseEvent& e)
{
    getParentComponent()->mouseDoubleClick(e);
}
