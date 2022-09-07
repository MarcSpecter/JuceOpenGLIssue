/*
  ==============================================================================

    moduleToolbar.cpp
    Created: 10 Jul 2022 4:32:59pm
    Author:  Marc Specter

  ==============================================================================
*/

#include "moduleToolbar.h"


moduleToolbar::moduleToolbar()
{
    setComponentID("toolbar");
    setGradientColours(colour_one);
    setBufferedToImage(true);
    addAndMakeVisible(drag);
    
    panelLayoutButton.setTooltip("Panel Control");
    addAndMakeVisible(panelLayoutButton);
    
//    panelLayoutButton.onClick=[this]{
//        PopupMenu menu;
//        menu.addItem("Move Up", [this]{
//            auto* concertina = findParentComponentOfClass<ourJuceConcertinaPanel>();
//            moveUpModuleAtIndex(concertina->indexOfPanel((ViewPanel*)getParentComponent()));
//
////            concertina->movePanelUp((ViewPanel*)getParentComponent());
//        });
//        menu.addItem("Move Down", [this]{
//            auto* concertina = findParentComponentOfClass<ourJuceConcertinaPanel>();
//            moveDownModuleAtIndex(concertina->indexOfPanel((ViewPanel*)getParentComponent()));
//
////            concertina->movePanelDown((ViewPanel*)getParentComponent());
//        });
//        menu.addItem("Remove", [this]{
//
//            auto* concertina = findParentComponentOfClass<ourJuceConcertinaPanel>();
//            removeModuleAtIndex(concertina->indexOfPanel((ViewPanel*)getParentComponent()));
//        });
//        menu.addItem("Fill Window", [this]{
//            auto* concertina = findParentComponentOfClass<ourJuceConcertinaPanel>();
//            fillModuleAtIndex(concertina->indexOfPanel((ViewPanel*)getParentComponent()));
////            concertina->expandPanelFully((ViewPanel*)getParentComponent(), true);
//        });
//        //            menu.addItem("Reset All", [this]{
//        //                auto* concertina = findParentComponentOfClass<ourJuceConcertinaPanel>();
//        //                auto parent = getParentComponent();
//
//        //            });
//        menu.show();
//    };
    
    
    
    path.onTextChange = [this]
    {
        fullPath = path.getText(); // at this moment the path get text is full path!
        path.setTooltip(fullPath);
        recalculatePathLayout();
    };
    
    path.setColour(Label::textColourId, Colours::white.withAlpha(0.95f));
    path.setComponentID("path");
    path.setMinimumHorizontalScale(1);

    addAndMakeVisible(path);
    
    
    
}


void moduleToolbar::setAccessory(ToolbarAccessory* acc){
    accessory = acc;
    addAndMakeVisible(accessory);
}
void moduleToolbar::paint (juce::Graphics& g)
{
    m_Gradient = ColourGradient::vertical(colour_one, colour_three, getBounds());
    m_Gradient.addColour(0.25, colour_two);
    m_Gradient.addColour(0.75, colour_two);
    
    g.setGradientFill(m_Gradient);
    g.fillAll();
    
//    g.setColour (juce::Colours::lightgrey);
//    g.drawRect (getLocalBounds(), 0.5f);   // draw an outline around the component
//        g.setColour (juce::Colours::lightgrey);
//        g.fillRect (path.getLocalBounds());   // draw an outline around path
//
//    g.setColour (juce::Colours::lightgrey.withAlpha(0.1f));
//    auto buttonsContainer = Rectangle<int>(panelLayoutButton.getX()-3, 2, advSettingsButton.getRight()-(panelLayoutButton.getX()-1), getHeight()-4);
//
//    g.fillRoundedRectangle(buttonsContainer.toFloat(), 1.5f);
}

void moduleToolbar::resized()
{
    const int border = 3;
    
   
    
    if(accessory)
    {
        accessory->setBounds(getWidth()-(accessory->standardLength()+border), 1, accessory->standardLength(), getHeight()-2);
    }
    
    recalculatePathLayout();
    
    
    
}

void moduleToolbar::recalculatePathLayout()
{
    if (fullPath.isEmpty())
        return;
    
    int rightEdge = accessory?accessory->getX()+border:getRight()-border;
    int leftEdge = actionsButton.getRight();

     path.setBounds(leftEdge, 1, ((rightEdge)-leftEdge)-10, 20);
    
    if (path.getText().isEmpty())
        return;
    
    int fullPathLength = path.getFont().getStringWidth(fullPath);
//    int pathLength = path.getFont().getStringWidth(path.getText());
    int labelLength = path.getWidth();
    
    float ratio = (float)labelLength/fullPathLength;
    int cutSize = fullPath.length()*(1-ratio)+12;    //extra 12 to eliminate ellipsis
    String subString = fullPath.substring(cutSize);
    if(cutSize>0){
        subString = "..."+subString;
    }

    path.setText(subString, dontSendNotification);
}

void moduleToolbar::mouseDown (const MouseEvent& event) {
    
   
}
void moduleToolbar::mouseDoubleClick (const MouseEvent&) {
    //onDoubleClick();
}

void moduleToolbar::setGradientColours(Colour c)
{
    colour_one = c;
    
    auto red = colour_one.getRed();
    auto green = colour_one.getGreen();
    auto blue = colour_one.getBlue();
    
    colour_two = Colour(red-20 <= 0? 0: red-20,
                        
                        green-18<=0? 0: green-18,
                        blue-20 <= 0? 0: blue-20);
    
    colour_three = Colour(red-45 <= 0? 0: red-45,
                          green-43<=0? 0: green-43,
                          blue-45 <= 0? 0: blue-45);
    }
