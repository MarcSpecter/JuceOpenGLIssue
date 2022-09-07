/*
  ==============================================================================

    DetailViewSettingsTray.cpp
    Created: 8 Jul 2022 4:35:03pm
    Author:  Marc Specter

  ==============================================================================
*/

#include "DetailViewSettingsTray.h"



//==============================================================================
DetailViewSettingsTray::DetailViewSettingsTray()
{
    setBufferedToImage(true);

  
    addAndMakeVisible(&showAllButton);
    addAndMakeVisible(&hideAllButton);
    
   
}

DetailViewSettingsTray::~DetailViewSettingsTray()
{
}
void DetailViewSettingsTray::addSettingButton(std::string title, std::string setting){
    std::cout<<"add setting:"<<title<<" - "<<setting<<"\n";
    auto* button = settingsButtons.add(new ToggleButton(title));
    button->setBufferedToImage(true);
    button->setComponentID(setting);    //experiment to use the id as the identifier
    button->setColour(ToggleButton::textColourId, Colours::white.withAlpha(0.7f));
    button->setColour(ToggleButton::tickColourId, Colours::white.withAlpha(0.7f));
    button->setColour(ToggleButton::tickDisabledColourId, Colours::white.withAlpha(0.7f));

    addAndMakeVisible(button);
    
  
    
    
}

void DetailViewSettingsTray::paint (juce::Graphics& g)
{
    TopDownTray::paint(g);

}

void DetailViewSettingsTray::resized()
{
    Rectangle<float> settingsBox(3,3,450,getHeight()-6);
    bool squashSettings = getWidth()<(740);
    
   
    const int numPerColumn = 3;
    const int h = 15;           // rather have an hardcoded number
    int w = squashSettings?75:90;
    
    for (int i=0;i<settingsButtons.size();i++)
    {
        const auto& btn = settingsButtons[i];
        btn->setBounds(w*(i/numPerColumn)+settingsBox.getY(), 2+(h*(i%numPerColumn)+getX()), w, h);
    }

    

//    showAllButton.setBounds(width-110, widgetY, 40, 40);
//    hideAllButton.setBounds(width-70, widgetY, 40, 40);
    
}


//========================================================================================================================



