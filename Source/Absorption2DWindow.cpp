#include "Absorption2DWindow.h"

Absorption2DWindow::Absorption2DWindow(Absorption2DPanel* panel, const juce::String& name, juce::Colour backgroundColour, int buttonsNeeded)
	: juce::DocumentWindow(name, backgroundColour, buttonsNeeded)

{
    setResizable(false, false);
    setAlwaysOnTop(true);
    setContentOwned(panel, true);
    setTopLeftPosition(100, 100);
    absorptionPanel = panel;
}

void Absorption2DWindow::closeButtonPressed()
{
    setVisible(false);
}

void Absorption2DWindow::setWallId(int newId)
{
    setName(Parameters::WALL_NAMES[newId]);
    absorptionPanel->setCurrentWallId(newId);
}
