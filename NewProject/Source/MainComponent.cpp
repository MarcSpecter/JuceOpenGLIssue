#include "MainComponent.h"


#include "Components/WaveViewPanel/WaveViewPanel.h"
using namespace juce;

//==============================================================================



MainComponent::MainComponent()
{
    //setBufferedToImage(true);
    //openglCtxt.attachTo(*this);
    //Component::juce_collectPaintTimings() = true;
    
    
   
    
//    resizerBar.setMinMax(50, 200);
//    resizerBar.setBufferedToImage(true);
//
//    addAndMakeVisible (resizerBar);
    
   
    addAndMakeVisible(concertinaR);
    
 
    concertinaR.addPanel(-1, new WaveViewPanel, false);
//    concertinaR.addPanel(-1, new WaveViewPanel, false);


#ifdef DEBUG
    Timer:: callAfterDelay (500, [this]{
                //audiopoolpanel.simulateFileDragDrop();
//
       
    });
//    MessageManager::callAsync([this]{
//        audiopoolpanel.simulateFileDragDrop();
//    });
#endif

}

MainComponent::~MainComponent()
{
    LookAndFeel::setDefaultLookAndFeel(nullptr);
    

}



//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    auto backgroundColour = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId);
    Rectangle<int> headerBounds(0, 0, getWidth(), concertinaR.getY());
    g.setColour(backgroundColour.brighter(0.2f));
    g.fillRect(headerBounds);
    
    if (Desktop::getInstance().isDarkModeActive()){

    }
    
}

void MainComponent::resized()
{
    
    auto topHeaderHeight = 40;
    auto topGap = 6;
    auto widgetHeight = topHeaderHeight - topGap*2;
    const int layoutButtonW = widgetHeight; // square
    
   
    concertinaR.setBounds(getRight(), topHeaderHeight, getWidth(), getHeight());
}




void MainComponent::mouseDrag(const MouseEvent &e){
    
}



//
//int juce::ConcertinaPanel::PanelHolder ::PanelSizes::Panel::reduce (int amount) noexcept
//{
//    amount = jmin (amount, size - minSize-30);
//    size -= amount;
//    return amount;
//}



////  ADD THIS TO CONCERTINAPANEL::panel::reduce TO LIMIT SIZE
//marc edit - WORKS

//int reduce (int amount) noexcept
//{
//    amount = jmin (amount, size - minSize-30);
//    size -= amount;
//    return amount;
//}
