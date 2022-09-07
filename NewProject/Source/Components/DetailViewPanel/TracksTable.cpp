/*
  ==============================================================================

    TracksTable.cpp
    Created: 14 Jun 2022 6:20:09pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TracksTable.h"
using namespace juce;
//==============================================================================
TracksTable::TracksTable()
{
    addAndMakeVisible(lBox);
    lBox.setRowHeight (20);
    lBox.setModel (this);
    lBox.setColour (ListBox::textColourId, Colours::white);
    lBox.setColour (ListBox::backgroundColourId, Colour(61, 59, 57));
    
    auto m_Header = std::make_unique<TableHeaderComponent>();
    
    
    
    m_Header->setColour(TableHeaderComponent::textColourId, Colours::lightgrey);
    m_Header->setColour(TableHeaderComponent::backgroundColourId, Colour(43, 41, 39));
    
//    m_Header.reset(&t_Header);  //aha!!! YOu are making a unique pointer from an object owned elsewhere!!!
    //that is illegal
    
    lBox.setHeader(std::move(m_Header));
    
   
    lBox.setAlwaysOnTop(true);
}

TracksTable::~TracksTable()
{
}

void TracksTable::paint (juce::Graphics& g)
{
    g.setColour(Colours::lightgrey);
    g.drawLine(0, 0.25f, getWidth(), 0.25f, 0.2f);
}

void TracksTable::resized()
{
    lBox.setBounds(0, 1, getWidth(), getHeight());
//    t_Header.setSize(getWidth(), 28);
    
}


int TracksTable::getNumRows()
{
    return 100;
}


void TracksTable::paintRowBackground (Graphics &g, int rowNumber, int width, int height, bool rowIsSelected)
{
    if (rowIsSelected)
    {
        g.fillAll (juce::Colours::lightblue);
    }
}

void TracksTable::paintCell (Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
    g.setColour (getLookAndFeel().findColour (juce::ListBox::backgroundColourId));
    g.fillRect (width - 1, 0, 1, height);
    
    g.setColour(Colours::white);
    
    switch (columnId)
    {
        case 1:
        {
            auto text = "rocky";
            g.drawText(text, 2, 0, width, height, dontSendNotification);
        }
        case 2:
        {
            
        }
    }
}





