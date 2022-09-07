#pragma once

#include <JuceHeader.h>


#include "Components/WaveViewPanel/mResizerBar.h"



class MainComponent  : public juce::Component
                      
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;
    

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    
    
    void mouseDrag (const MouseEvent& e) override;

   
private:
    //==============================================================================
    

    
   
    ConcertinaPanel concertinaR;
    //StretchableLayoutManager stretchableManager;
    //mResizerBar resizerBar { &concertinaL };
    
   


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


class AppContainer : public Component
{
public:
    AppContainer()
    {
        setSize (1200, 700);
        addAndMakeVisible(&app);
        setOpaque(true);

    };
    ~AppContainer() override {};


     //==============================================================================
    void paint (juce::Graphics& g) override
    {
        //std::cout << "BIG BOSS PAINTING\n";
        
        auto backgroundColour = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId);
 
        g.setColour(backgroundColour.brighter(0.2f));
        g.fillAll();
        g.setColour(Colours::black.withAlpha(0.4f));
        g.drawRoundedRectangle(appBounds.withY(39).withHeight(appBounds.getHeight()-39).expanded(1).toFloat(), 3.f, 1.f);

    };
    void resized() override {
        appBounds = Rectangle<int>(borderThickness, 0, getWidth()-(2*borderThickness), getHeight()-borderThickness);
        app.setBounds(appBounds);
    };
    
private:
    MainComponent app;
    const int borderThickness = 6;
    Rectangle<int> appBounds;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AppContainer)
};
