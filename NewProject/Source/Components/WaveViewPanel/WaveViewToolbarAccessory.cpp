/*
  ==============================================================================

    WaveViewToolbarAccessory.cpp
    Created: 10 Jul 2022 4:05:07pm
    Author:  Marc Specter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WaveViewToolbarAccessory.h"
#include "kNotification.h"


//==============================================================================
WaveViewToolbarAccessory::WaveViewToolbarAccessory()
{
    setBufferedToImage(true);
    
    auto localWhite = Colours::white.withAlpha(0.7f);
    auto noColour = Colours::white.withAlpha(0.0f);
    
    addAndMakeVisible(&minusButton);
    minusButton.setColour(TextButton::buttonColourId, noColour);
    minusButton.setColour(TextButton::textColourOffId, localWhite);
    minusButton.setColour(ComboBox::outlineColourId, noColour);
    //minusButton.setConnectedEdges(2);
    minusButton.setTooltip("Reduce speed");
    
    minusButton.onClick = []
    {
        notificationData data(0);
        kNotification::PostNotificationWithData("setVarispeed",&data);
//        kWaveViewInterface::setVarispeed(0);//slower
    };
    
    
    addAndMakeVisible(&plusButton);
    plusButton.setColour(TextButton::buttonColourId, noColour);
    plusButton.setColour(TextButton::textColourOffId, localWhite);
    plusButton.setColour(ComboBox::outlineColourId, noColour);
    //plusButton.setConnectedEdges(1);
    plusButton.setTooltip("Increase speed");

    plusButton.onClick = []
       {
           notificationData data(2);
           kNotification::PostNotificationWithData("setVarispeed",&data);
//           kWaveViewInterface::setVarispeed(2);//faster
       };
    
    addAndMakeVisible(&playbackSpeedL);
    playbackSpeedL.setComponentID("varispeedbutton");
    playbackSpeedL.setColour(ComboBox::outlineColourId, Colours::black.withAlpha(0.0f));
    playbackSpeedL.setColour(TextButton::buttonColourId, Colours::black.withAlpha(0.0f));
    playbackSpeedL.setColour(TextButton::textColourOffId, localWhite);
    playbackSpeedL.setButtonText("1.0x");
    playbackSpeedL.setTooltip("Playback Speed - Click to Reset");

    playbackSpeedL.onClick = []
    {
        notificationData data(1);
        kNotification::PostNotificationWithData("setVarispeed",&data);
//        kWaveViewInterface::setVarispeed(1);//reset
    };

    addAndMakeVisible(&volumeSlider);
    volumeSlider.setRange(0.f, 100.0f, 5.0f);
    volumeSlider.setValue(80.0f);
    volumeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    volumeSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    volumeSlider.setColour(Slider::trackColourId, Colours::black);
    volumeSlider.setColour(Slider::backgroundColourId, Colours::black);
    volumeSlider.setColour(Slider::thumbColourId, Colours::grey.brighter().brighter());
    volumeSlider.onValueChange = [this](){
        notificationData data(volumeSlider.getValue());
        kNotification::PostNotificationWithData("setVolume",&data);
//        kWaveViewInterface::setVolume(volumeSlider.getValue());
        volumeSlider.setTooltip(String("Volume: ")+volumeSlider.getValueObject().toString()+String("%"));

    };
    
    speakerImage.multiplyAllAlphas(0.7f);
}

WaveViewToolbarAccessory::~WaveViewToolbarAccessory()
{
}

void WaveViewToolbarAccessory::paint (juce::Graphics& g)
{
    static int xrd;
    std::cout<<"paint WaveViewToolbarAccessory "<<xrd++<<"\n";
    ToolbarAccessory::paint(g);

    auto leftIndent = PBrect.getX()+PBrect.getWidth()/4;
    auto rightIndent = PBrect.getRight()-PBrect.getWidth()/4;
    
    g.setColour(Colours::white.withAlpha(0.5f));
    g.drawLine(leftIndent, PBrect.getY(), leftIndent, PBrect.getBottom());
    g.drawLine(rightIndent, PBrect.getY(), rightIndent, PBrect.getBottom());
    g.drawRoundedRectangle(PBrect, 6.f, 1.f);
    
    g.drawImage(speakerImage, volumeSlider.getX()-14, PBrect.getY(), 14, 14, 0, 0, speakerImage.getWidth(), speakerImage.getHeight());
    return;
  
}
void WaveViewToolbarAccessory::resized()
{
    auto widgetHeight = 15;
    auto buttonsW = 22;
    minusButton.setBounds(PBrect.getX()-2, PBrect.getY(), buttonsW, widgetHeight);
   
    playbackSpeedL.setBounds(minusButton.getRight()-1, PBrect.getY(), buttonsW+4, widgetHeight);
    playbackSpeedL.setCentrePosition(PBrect.getCentreX(), PBrect.getCentreY());
    plusButton.setBounds(PBrect.getRight()-(buttonsW-2), PBrect.getY(), buttonsW, widgetHeight);
    
    volumeSlider.setBounds(plusButton.getRight()+35, PBrect.getY()-3, 76, 20);
}

int WaveViewToolbarAccessory::standardLength()
{
    return 4 + 25 + 40 + 25 + 80 + 4;
}
