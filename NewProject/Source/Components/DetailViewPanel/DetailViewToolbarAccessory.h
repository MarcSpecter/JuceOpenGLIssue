/*
  ==============================================================================

    DetailViewToolbarAccessory.h
    Created: 10 Jul 2022 4:05:56pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../ViewPanel/ToolbarAccessory.h"
using namespace juce;
//==============================================================================
/*
*/
class DetailViewToolbarAccessory  : public ToolbarAccessory
{
public:
    DetailViewToolbarAccessory();
    ~DetailViewToolbarAccessory() override;

    void mouseDoubleClick (const MouseEvent& ev) override {
        getParentComponent()->mouseDoubleClick(ev);
    }

    void resized() override;
    int standardLength() override {return 300;};

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DetailViewToolbarAccessory)
};
