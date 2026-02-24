#pragma once

#include "JuceHeader.h"
#include "Absorption2DUI.h"


class Absorption2DWindow : public juce::DocumentWindow
{
public:
    Absorption2DWindow(Absorption2DUI* ui, const juce::String& name,
        juce::Colour backgroundColour, int buttonsNeeded);
    ~Absorption2DWindow();
    
    void closeButtonPressed() override;
    
    int getWallId() { return absorption2dUI->absorptionPanel->getCurrentWallId(); }
    Absorp* getWallInstance() { return absorption2dUI->absorptionPanel->wall; }
    int getPanelHeight() { return absorption2dUI->absorptionPanel->getHeight(); }
    int getPanelWidth() { return absorption2dUI->absorptionPanel->getWidth(); }
    void setWallId(int newId);
    void setPickerCoords(juce::Point<float>* newCoords, Absorp* wal) { absorption2dUI->absorptionPanel->setWallCoords(newCoords, wal); }
    void setWindowFocus(bool isWindowFocused) { this->isWindowFocused = isWindowFocused; }

protected:

    void focusOfChildComponentChanged(FocusChangeType) override;

private:

    std::unique_ptr<Absorption2DUI> absorption2dUI;
    bool isWindowFocused = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Absorption2DWindow)
};