/*
  ==============================================================================

    WaveViewActionsTray.cpp
    Created: 8 Jul 2022 4:52:19pm
    Author:  Marc Specter

  ==============================================================================
*/

#include "WaveViewActionsTray.h"


//==============================================================================
WaveViewActionsTray::WaveViewActionsTray()
{
    setBufferedToImage(true);
}

WaveViewActionsTray::~WaveViewActionsTray()
{
}


void WaveViewActionsTray::addActionButton(std::string title, std::string command){
    
    std::cout<<"add action:"<<title<<" - "<<command<<"\n";
    auto* button = actionButtons.add(new TextButton(title));
    
    
   
}
void WaveViewActionsTray::paint (juce::Graphics& g)
{
    TopDownTray::paint(g);
}

void WaveViewActionsTray::resized()
{
    const int h = 14;
    const int w = 130;
    const int numPerColumn = 5;
    const int indentation = 24;
    
    //auto& settings = GetSettings(); // unused for the moment
    int row = 10;
    
    
    
    for (int i=0;i<actionButtons.size();i++){
        const auto& btn = actionButtons[i];
        
        auto height = 20;
        auto width = height*6;
        auto topleft = 10;
        
        btn->setBounds(topleft+(i/2)*(width*1.1), 2+(i%2 *height), width, height);
    }

    
}
