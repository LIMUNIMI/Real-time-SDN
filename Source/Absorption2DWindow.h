#pragma once

#include "JuceHeader.h"
#include "Absorption2DPanel.h"


class Absorption2DWindow : public juce::DocumentWindow
{
public:
    Absorption2DWindow(Absorption2DPanel* panel, const juce::String& name, 
        juce::Colour backgroundColour, int buttonsNeeded);

    void closeButtonPressed() override;
    void setWallId(int newId);
    int getWallId() { return absorptionPanel->getCurrentWallId(); };
    int getPanelHeight() { return absorptionPanel->getHeight(); };
    int getPanelWidth() { return absorptionPanel->getWidth(); };
    void setPickerCoords(Point<float>* newCoords) { absorptionPanel->setWallCoords(newCoords); };

private:

    Absorption2DPanel* absorptionPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Absorption2DWindow)
};