/*
  ==============================================================================

    DragButton.h
    Created: 4 Jul 2022 5:26:40pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
class ViewPanel;

//==============================================================================
/*
*/
class TrayButton  : public Button
{
public:
    TrayButton(const String& buttonName) : Button(buttonName)
    {
        setBufferedToImage(true);
    }
    
    ~TrayButton() override
    {
    }

    void setButtonIcon(Image* image)
    {
        iconHighlighted = image;
        iconAlphaed = image->createCopy();
        iconAlphaed.multiplyAllAlphas(0.7f);
//        iconAlphaed.rescaled(iconHighlighted->getWidth()+2, iconHighlighted->getHeight()+2);
//        iconAlphaed.moveImageSection(0, 0, 1, 1, iconAlphaed.getWidth()-1, iconAlphaed.getHeight()-1);
    }
    
    void paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        static int x;
        std::cout<<"Paint traybutton "<<x++<<"\n";

        auto width = getLocalBounds().getWidth();
        auto height = getLocalBounds().getHeight();
        bool hl = false;
        
        if (shouldDrawButtonAsHighlighted || highlight)
        {
            hl = true;
        }

        g.drawImage(hl?*iconHighlighted:iconAlphaed,
                    0,
                    hl?0:1,
                    width*(hl?0.85f:0.8f),
                    height*(hl?0.85f:0.8f),
                    0, 0,
                    iconHighlighted->getWidth(), iconHighlighted->getHeight());
        
    }

    void setHighlighted(bool shouldBeHighlighted)
    {
        highlight = shouldBeHighlighted;
        repaint();
    }
    
private:
    Image iconAlphaed;
    Image* iconHighlighted;
    bool highlight = false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrayButton)
};
