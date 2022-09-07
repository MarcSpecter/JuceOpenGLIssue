/*
  ==============================================================================

    DetailView.cpp
    Created: 16 Jun 2022 9:28:19am
    Author:  Giulio Iacomino

  ==============================================================================
*/

#include "DetailView.h"


DetailView::DetailView(kDetailViewInterface* iface)
:interface(iface)
 {
     setComponentID("detailview");
     table.setComponentID("table");
     
     table.setRowHeight(20);    //default is 22, old kraken is 20
     
     //=== TABLE HEADER INITIALIZATION ====================================================
     auto m_Header = std::make_unique<TableHeaderComponent>();
     //addMultipleColumns(m_Header); // hidden away for now - MOVE TO ENGNE
     table.setHeader(std::move(m_Header));
     table.getHeader().setPopupMenuActive(false);
    
     //=== TABLE INITIALIZATION ========================================================
     table.setModel(this);
     addAndMakeVisible(table);
     

     //=== SCROLLBAR INITIALIZATION ====================================================
     hScrollbar = &table.getHorizontalScrollBar();
     vScrollbar = &table.getVerticalScrollBar();
     // JUCE ColourIds not working for scrollbar background (NEEDS CUSTOM LOOK AND FEEL)
     hScrollbar->setColour(ScrollBar::thumbColourId, Colour(160,161,163));
     
     vScrollbar->setColour(ScrollBar::thumbColourId, Colour(160,161,163));
   
     //table.setColour(TableListBox::backgroundColourId, Colours::pink);

}

DetailView::~DetailView()
{
    
}
void DetailView::setInterface(kDetailViewInterface* iface){
    interface = iface;
}

void DetailView::paint (juce::Graphics& g)
{
    std::cout<<"detailview paint\n";
}

void DetailView::resized()
{
  table.setBounds(getLocalBounds());
    
    static int i = 0;
    i += 1;
    
    std::cout << "DETAIL VIEW REPAINTING " << i << "\n";
    
    if (!isVisible())
    {
        std::cout<< "not visible" << '\n';
    }
}

void DetailView::paintRowBackground(juce::Graphics & g, int rowNumber, int width, int height, bool rowIsSelected)
{
    //std::cout<<"detailview paintRowBackground row "<<rowNumber<<"\n";

    if(rowIsSelected){
        g.fillAll(Colour(69, 89, 189));
    }else{
        g.fillAll(getLookAndFeel().findColour(juce::TableListBox::backgroundColourId));
    }
    g.setColour(getLookAndFeel().findColour(ComboBox::outlineColourId).withAlpha(0.5f));
    g.drawLine(0, height, width, height);
}

void DetailView::selectedRowsChanged(int row){
}
void DetailView::cellClicked (int row, int col, const MouseEvent& event)
{
   
}

int DetailView::getNumRows()
{

    return 0;
};
void DetailView::sortOrderChanged (int newSortColumnId, bool isForwards){
    //TODO: add compound sort descriptors somehow?
}
void DetailView::paintCell(juce::Graphics & g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
    //g.setColour(Colours::white);

    std::string val = "NA";
    

//    std::cout<<"val:"<<val<<"\n";
    if (columnId == 1)
    {
        if (!val.empty())
        {
            
          
        }
    }
    else
    {
        g.setColour(rowIsSelected?Colours::white.withAlpha(0.8f):getLookAndFeel().findColour(ComboBox::textColourId));
        g.setFont(13.f);
        g.drawText(val, 4, 0, width, height, Justification::left);
    }
}

void DetailView::addMultipleColumns(std::unique_ptr<TableHeaderComponent>& t_Header)
{
    //moved to engine
//    for(const auto& c:columns){
//        t_Header->addColumn(c.label, c.id,c.startSize, c.minSize, c.maxSize,c.flags);
//    }
//
}


void DetailView::animateTable()
{

}




