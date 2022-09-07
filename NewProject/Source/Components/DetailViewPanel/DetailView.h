/*
  ==============================================================================

    DetailView.h
    Created: 15 Jun 2022 1:23:35pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//#include "../ViewPanel/ViewPanel.h"


class moduleToolbar;
class kDetailViewInterface;
using namespace juce;
//==============================================================================
/*
*/
class DetailView  : public juce::Component,
                    public juce::TableListBoxModel
{
public:
    DetailView(kDetailViewInterface* interface);
    ~DetailView() override;
    
    void setInterface(kDetailViewInterface* interface);

    
    void paint (juce::Graphics& g) override;
    void resized() override;
    void addMultipleColumns(std::unique_ptr<TableHeaderComponent>& t_Header);
    
    //=== TABLE STUFF ============================================================================================
    void selectedRowsChanged(int row) override;
    void cellClicked (int, int, const MouseEvent&) override ;
    int getNumRows() override; //{return 20;};
    void sortOrderChanged (int, bool)override ;
    void paintRowBackground(juce::Graphics &, int rowNumber, int width, int height, bool rowIsSelected) override;
    void paintCell(juce::Graphics &, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
    void animateTable();
    
    
    moduleToolbar* toolbar;     //just for now to allow engine to speak to toolbar from content view
    TableListBox table;
    kDetailViewInterface* interface;
private:
    
    
    int lastRow;
    Viewport viewPort;

    bool isPanelShowing = false;
    ScrollBar* hScrollbar;
    ScrollBar* vScrollbar;
    
    const int channelFlags = TableHeaderComponent::visible| TableHeaderComponent::resizable;
    
    const int minSize = 20;
    
public:
  
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DetailView)
};
