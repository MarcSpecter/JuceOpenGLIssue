/*
  ==============================================================================

    WaveViewSettingsTray.cpp
    Created: 8 Jul 2022 4:52:19pm
    Author:  Marc Specter

  ==============================================================================
*/





//==============================================================================
WaveViewSettingsTray::WaveViewSettingsTray(){
    setBufferedToImage(true);
}

WaveViewSettingsTray::~WaveViewSettingsTray(){
}

ToggleButton* WaveViewSettingsTray::addSettingButton(std::string title, std::string setting){
    std::cout<<"add setting:"+title+" - "+setting<<"\n";
    auto* button = settingsButtons.add(new ToggleButton(title));
    
    button->setComponentID(setting);    //experiment to use the id as the identifier
    button->setBufferedToImage(true);
    button->setColour(ToggleButton::textColourId, Colours::white.withAlpha(0.7f));
    button->setColour(ToggleButton::tickColourId, Colours::white.withAlpha(0.7f));
    button->setColour(ToggleButton::tickDisabledColourId, Colours::white.withAlpha(0.7f));
    addAndMakeVisible(button);
    
    button->onClick = [this, button]{
//        we can still go the 'notification' route
//        notificationData data(button->getComponentID().toStdString(), button->getToggleState());
//        kNotification::PostNotificationWithData("setSetting", &data);
        interface->SetSetting(button->getComponentID().toStdString(), button->getToggleState());
    };
    
  
    return button;

}
void WaveViewSettingsTray::addActionButton(std::string title, std::string command){
    
    std::cout<<"add action:"<<title<<" - "<<command<<"\n";
    auto* button = actionButtons.add(new TextButton(title));
    button->setBufferedToImage(true);
    button->setColour(TextButton::buttonColourId, WAVEVIEWCOLOUR.darker(2.f).withAlpha(0.9f));
    button->setColour(TextButton::textColourOffId, WAVEVIEWCOLOUR.brighter(2).withAlpha(0.9f));
    button->setColour(ComboBox::outlineColourId, Colours::black.withAlpha(0.4f));
    addAndMakeVisible(button);
    
    button->onClick = [command]{
        kNotification::PostNotification(command);
//        kWaveViewInterface::HandleEvent(command);

    };

}
void WaveViewSettingsTray::paint (juce::Graphics& g)
{
    TopDownTray::paint(g);
    
}

void WaveViewSettingsTray::resized()
{
    Rectangle<float> settingsBox(3,3,getWidth(),getHeight()-6);
    bool squashSettings = false;
    int numColumns = 5;
    
    
    const int numPerColumn = 3;
    const int h = 15;
    int w = 150;
    
    if (getWidth() < w*numColumns){
        squashSettings = true;
    }
    
    w = squashSettings?w*0.8:w;
    
    for (int i=0;i<settingsButtons.size();i++)
    {
        const auto& btn = settingsButtons[i];
        btn->setBounds(w*(i/numPerColumn)+settingsBox.getY(), 2+(h*(i%numPerColumn)+getX()), w, h);
    }

    


    
}
