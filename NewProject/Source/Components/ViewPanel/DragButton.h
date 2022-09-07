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
class DragButton  : public Button
{
public:
    DragButton(const String& buttonName) : Button(buttonName)
    {
    }
    
    ~DragButton() override
    {
    }
    std::function<void()> dragFunc;
    
    void mouseDrag  (const MouseEvent&) override {
        
//        startDragging("DRAGGER", this, ScaledImage(),true);
//
        dragFunc();
//        getParentComponent()
//        auto panel = findParentComponentOfClass<ViewPanel>();
//        bool shouldMoveFiles = false;
//        StringArray files;
//        
//        
//        files.add("/Users/marcspecter/Documents/Pete ACGAS assembly help/LOCKED_220704_ac3_302_US_Split_Tracks.1.L.wav");
////        files.add("/Users/marcspecter/Documents/JUCE Demo Audio Recording.wav");
//        
//        performExternalDragDropOfFiles (files, shouldMoveFiles, this, []{
//                                            //callback
//                                            std::cout<<"DRAG CALLBACK\n";
//                                        });
    }
//    bool shouldDropFilesWhenDraggedExternally (const DragAndDropTarget::SourceDetails& details,
//                                               StringArray& files,
//                                               bool& canMoveFiles) override
//    {
//        //getdraggingpaths
//        canMoveFiles = false;
////        files.add("/Users/marcspecter/Documents/Pete ACGAS assembly help/LOCKED_220704_ac3_302_US_Split_Tracks.1.L.wav");
//        files.add("/Users/marcspecter/Documents/JUCE Demo Audio Recording.wav");
//
//        return true;
//    }
    void paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        const auto xResizer = getWidth()/4;
        const auto yOffset = shouldDrawButtonAsDown;
        auto box = getLocalBounds().reduced(xResizer, getHeight()/3);
        box = shouldDrawButtonAsHighlighted?box.expanded(1):box;
        
        g.setColour(Colours::white.darker(shouldDrawButtonAsDown?0.f : 0.1f).withAlpha(shouldDrawButtonAsHighlighted?1.f:0.7f));
        box.translate(0, yOffset+1);
        Rectangle<float> fbox = box.toFloat();
        g.drawRoundedRectangle(fbox,1, 1.5);
        
        auto boxCentreX = box.getCentreX();
        Line<float> l(boxCentreX, yOffset+(getHeight()*0.8), boxCentreX, yOffset);
        
        Path p;
        p.addArrow(l, 1.5f, 5, 2.5f);
        g.fillPath(p);
        
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DragButton)
};
