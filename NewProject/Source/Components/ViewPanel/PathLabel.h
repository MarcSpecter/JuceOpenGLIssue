/*
  ==============================================================================

    PathLabel.h
    Created: 16 Jul 2022 1:52:28am
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PathLabel  : public Label
{
public:
    PathLabel()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.

    }

    ~PathLabel() override
    {
    }

    void mouseDoubleClick (const MouseEvent& ev) override{
        getParentComponent()->mouseDoubleClick(ev);
    }

    void paint(Graphics& g) override{
//        g.setColour(Colours::cyan.withAlpha(0.5f));
//        g.fillAll();
//        g.setColour(Colours::white.withAlpha(0.5f));
//        g.drawText("textlabel",0,0,200,20,Justification::centred);
        Label::paint(g);
    }
//

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PathLabel)
};
