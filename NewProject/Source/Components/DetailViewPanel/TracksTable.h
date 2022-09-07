/*
  ==============================================================================

    TracksTable.h
    Created: 14 Jun 2022 6:20:09pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class TracksTable  : public juce::Component,
                     public juce::TableListBoxModel
{
public:
    TracksTable();
    ~TracksTable() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    // ============ TABLE LIST BOX STUFF ========================================
    int getNumRows() override;
    void paintRowBackground (juce::Graphics &, int rowNumber, int width, int height, bool rowIsSelected) override;
    void paintCell (juce::Graphics &, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
//    void addMultipleColumns(TableHeaderComponent& t_Header);

private:
    juce::TableListBox lBox;
//    juce::TableHeaderComponent t_Header;
    
    
    
    enum ColID: int
    {
        InvalidId,
        NameId,
        DurationId,
        C_Id,
        SR_Id,
        FR_Id,
        Reel_Id,
        Scene_Id,
        Timestamp_Id,
        Take_Id,
        Note_Id,
        MRK_Id,
        Ch1_Id,
        Ch2_Id,
        Ch3_Id,
        Ch4_Id,
        Ch5_Id,
        Ch6_Id,
        Ch7_Id
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TracksTable)
};



