/*
  ==============================================================================

    DetailViewActionsTray.cpp
    Created: 8 Jul 2022 4:35:03pm
    Author:  Marc Specter

  ==============================================================================
*/

#include "DetailViewActionsTray.h"




//==============================================================================
DetailViewActionsTray::DetailViewActionsTray()
{
    setBufferedToImage(true);
    
    filterComboBox1.setComponentID("filterTarget1");
    filterComboBox1.addItem("name", 1);            // crazy shit
    filterComboBox1.addItem("reel", 2);
    filterComboBox1.addItem("note", 3);
    filterComboBox1.addItem("TC", 4);
    filterComboBox1.addItem("scene", 5);
    filterComboBox1.addItem("slate", 6);
    filterComboBox1.addItem("take", 7);
    filterComboBox1.addItem("date", 8);
    filterComboBox1.addItem("originator",9);
    filterComboBox1.addItem("tracks", 10);
    filterComboBox1.addItem("any", 11);
    filterComboBox1.setSelectedId(1);
    
    filterComboBox2.setComponentID("filterTarget2");
    filterComboBox2.addItem("name", 1);
    filterComboBox2.addItem("reel", 2);
    filterComboBox2.addItem("note", 3);
    filterComboBox2.addItem("TC", 4);
    filterComboBox2.addItem("scene", 5);
    filterComboBox2.addItem("slate", 6);
    filterComboBox2.addItem("take", 7);
    filterComboBox2.addItem("date", 8);
    filterComboBox2.addItem("originator", 9);
    filterComboBox2.addItem("tracks", 10);
    filterComboBox2.setSelectedId(3);
    
    containsCB1.setComponentID("filterMode1");

    containsCB1.addItem("contains", 1);
    containsCB1.addItem("matches", 2);
    
    containsCB2.setComponentID("filterMode2");

    containsCB2.addItem("contains", 1);
    containsCB2.addItem("matches", 2);
    
    andToggle.setButtonText("AND");
    orToggle.setButtonText("OR");
    
    andToggle.setToggleState(true, dontSendNotification);
    andToggle.setRadioGroupId(1);
    orToggle.setRadioGroupId(1);
    
    containsCB1.setLookAndFeel(&privCBLookAndFeel);
    containsCB2.setLookAndFeel(&privCBLookAndFeel);
    
    filterComboBox1.setLookAndFeel(&privCBLookAndFeel);
    filterComboBox2.setLookAndFeel(&privCBLookAndFeel);
    
    searchTerms1.setComponentID("searchTerms1");
    searchTerms2.setComponentID("searchTerms2");
    
   
   

    
    addAndMakeVisible(&filterComboBox1);
    addAndMakeVisible(&filterComboBox2);
    addAndMakeVisible(&containsCB1);
    addAndMakeVisible(&containsCB2);
    addAndMakeVisible(&andToggle);
    addAndMakeVisible(&orToggle);
    addAndMakeVisible(&searchTerms1);
    addAndMakeVisible(&searchTerms2);
    addAndMakeVisible(&showAllButton);
    addAndMakeVisible(&hideAllButton);
    
    containsCB1.setSelectedId(1);
    containsCB2.setSelectedId(1);
    
    searchTerms1.setColour(TextEditor::backgroundColourId, Colours::white.withAlpha(0.9f));
    searchTerms1.setColour(TextEditor::textColourId, Colours::black);
    searchTerms1.setColour(TextEditor::outlineColourId, Colours::transparentWhite);
    searchTerms1.setColour(TextEditor::highlightColourId, Colours::royalblue);
    
    
    searchTerms2.setColour(TextEditor::textColourId, Colours::black);
    searchTerms2.setColour(TextEditor::backgroundColourId, Colours::white.withAlpha(0.9f));
    searchTerms2.setColour(TextEditor::outlineColourId, Colours::transparentWhite);
    searchTerms2.setColour(TextEditor::highlightColourId, Colours::royalblue);
    
    
    andToggle.setColour(ToggleButton::textColourId, Colours::white.withAlpha(0.7f));
    andToggle.setColour(ToggleButton::tickColourId, Colours::white.withAlpha(0.7f));
    andToggle.setColour(ToggleButton::tickDisabledColourId, Colours::white.withAlpha(0.7f));
    
    orToggle.setColour(ToggleButton::textColourId, Colours::white.withAlpha(0.7f));
    orToggle.setColour(ToggleButton::tickColourId, Colours::white.withAlpha(0.7f));
    orToggle.setColour(ToggleButton::tickDisabledColourId, Colours::white.withAlpha(0.7f));
    
    filterComboBox2.setEnabled(false);
    containsCB2.setEnabled(false);
    searchTerms2.setEnabled(false);
}

DetailViewActionsTray::~DetailViewActionsTray()
{
}
void DetailViewActionsTray::addSettingButton(std::string title, std::string setting){
    std::cout<<"add setting:"<<title<<" - "<<setting<<"\n";
    auto* button = settingsButtons.add(new ToggleButton(title));
    button->setBufferedToImage(true);
    button->setComponentID(setting);    //experiment to use the id as the identifier
    button->setColour(ToggleButton::textColourId, Colours::white.withAlpha(0.7f));
    button->setColour(ToggleButton::tickColourId, Colours::white.withAlpha(0.7f));
    button->setColour(ToggleButton::tickDisabledColourId, Colours::white.withAlpha(0.7f));

    addAndMakeVisible(button);
    
    button->onClick = [this,setting]{
    };
    
    
}
void DetailViewActionsTray::addActionButton(std::string title, std::string command){
    
    std::cout<<"add action:"<<title<<" - "<<command<<"\n";
    auto* button = actionButtons.add(new TextButton(title));
    button->setBufferedToImage(true);

    addAndMakeVisible(button);
    
    
}
void DetailViewActionsTray::paint (juce::Graphics& g)
{
    TopDownTray::paint(g);

}

void DetailViewActionsTray::resized()
{
    const auto width = getWidth();
    auto widgetY = getHeight()*0.3;
    auto widgetHeight = 20;
    auto smallWidgetHeight = 15;
    const int XGap = 10;

    auto desiredComboBoxWidth =  80;   //width/2 - (widgetW*2 + 60);
    auto desiredTextEditorX = containsCB1.getRight()+10 ;
    auto desiredTextEditorWidth = width-(desiredTextEditorX+10);
    
    andToggle.setVisible(true);;
    orToggle.setVisible(true);
    containsCB1.setVisible(true);
    containsCB2.setVisible(true);
    filterComboBox1.setVisible(true);;
    filterComboBox2.setVisible(true);

    if (width < 950)
    {
        desiredTextEditorWidth = 120;
        desiredTextEditorWidth = getWidth()-(desiredTextEditorX+XGap);
    }
    
    if (width< 670)
    {
        filterComboBox1.setSize(0, 0);
        desiredTextEditorWidth = getWidth()-(desiredTextEditorX+XGap);
        
    }
 
    const int andWidth = 50;
    const int andX = width/2-andWidth/2;

    andToggle.setBounds(andX, 10, andWidth, smallWidgetHeight);
    orToggle.setBounds(andX, andToggle.getBottom()+4, andWidth, smallWidgetHeight);
    
    Rectangle<int> comboBoxBounds(XGap, widgetY, jlimit(50, 120, desiredComboBoxWidth), widgetHeight);
    filterComboBox1.setBounds(comboBoxBounds);
    containsCB1.setBounds(comboBoxBounds.withX(filterComboBox1.getRight()+XGap));
    filterComboBox2.setBounds(comboBoxBounds.withX(andToggle.getRight()+16));
    containsCB2.setBounds(comboBoxBounds.withX(filterComboBox2.getRight()+XGap).withY(filterComboBox2.getY()));
    
    desiredTextEditorWidth = (width*0.45) - (containsCB1.getRight()+XGap+XGap);
    
    searchTerms1.setBounds(containsCB1.getRight()+XGap, widgetY, desiredTextEditorWidth, widgetHeight);
    searchTerms2.setBounds(containsCB2.getRight()+XGap, filterComboBox2.getY(), desiredTextEditorWidth, widgetHeight);

    
    

//    showAllButton.setBounds(width-110, widgetY, 40, 40);
//    hideAllButton.setBounds(width-70, widgetY, 40, 40);
    
}


//========================================================================================================================


Colour privateCBLookAndFeel::findPopupColour (int colourId, juce::Component* target)
{
    if (target)
        return target->findColour (colourId);

    return findColour (colourId);
}

void privateCBLookAndFeel::drawPopupMenuItemWithOptions (juce::Graphics& g, const juce::Rectangle<int>& area,
                                                       bool isHighlighted,
                                                       const juce::PopupMenu::Item& item,
                                                       const juce::PopupMenu::Options& options)
{
    using namespace Colours;
    
    auto* target = options.getTargetComponent();
    
    
    g.setColour (findPopupColour (isHighlighted ? juce::PopupMenu::highlightedBackgroundColourId
                                : juce::ComboBox::backgroundColourId,
                               target));


    const auto hasSubMenu = item.subMenu != nullptr
                            && (item.itemID == 0 || item.subMenu->getNumItems() > 0);

    if (item.isSeparator)
    {
        auto r = area.reduced (5, 0);
        r.removeFromTop (r.getHeight() / 2 - 1);

        g.setColour (grey);
        g.fillRect (r.removeFromTop (1));

        g.setColour (grey);
        g.fillRect (r.removeFromTop (1));
    }
    
    else
    {
        auto textColour = findPopupColour (juce::ComboBox::textColourId, target);

        auto r = area.reduced (1);

        if (isHighlighted)
        {
            g.setColour (royalblue);
            g.fillRect (r);

            g.setColour (findPopupColour (juce::PopupMenu::backgroundColourId, target));
        }
        else
        {
            g.setColour (textColour);
        }

        if (! item.isEnabled)
            g.setOpacity (0.3f);

        juce::Font font (getPopupMenuFont());

        auto maxFontHeight = (float) area.getHeight() / 1.3f;

        if (font.getHeight() > maxFontHeight)
            font.setHeight (maxFontHeight);

        g.setFont (font);

        auto iconArea = r.removeFromLeft ((r.getHeight() * 5) / 4).reduced (3).toFloat();

        auto* icon = item.image.get();
        if (icon != nullptr)
        {
            icon->drawWithin (g, iconArea,
                              juce::RectanglePlacement::centred | juce::RectanglePlacement::onlyReduceInSize,
                              1.0f);
        }
        else if (item.isTicked)
        {
            auto tick = getTickShape(0.5);
            g.fillPath (tick, tick.getTransformToScaleToFit (iconArea.reduced(6, 6), true));
        }

        if (hasSubMenu)
        {
            auto arrowH = 0.6f * getPopupMenuFont().getAscent();

            auto x = (float) r.removeFromRight ((int) arrowH).getX();
            auto halfH = (float) r.getCentreY();

            juce::Path p;
            p.addTriangle (x, halfH - arrowH * 0.5f,
                           x, halfH + arrowH * 0.5f,
                           x + arrowH * 0.6f, halfH);

            g.fillPath (p);
        }

        r.removeFromRight (3);
        g.drawFittedText (item.text, r, juce::Justification::centredLeft, 1);

        if (item.shortcutKeyDescription.isNotEmpty())
        {
            juce::Font f2 (font);
            f2.setHeight (f2.getHeight() * 0.75f);
            f2.setHorizontalScale (0.95f);
            g.setFont (f2);

            g.drawText (item.shortcutKeyDescription, r, juce::Justification::centredRight, true);
        }
    }
}
