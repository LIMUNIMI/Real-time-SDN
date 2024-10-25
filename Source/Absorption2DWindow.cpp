#include "Absorption2DWindow.h"

Absorption2DWindow::Absorption2DWindow(Absorption2DUI* ui, const juce::String& name, juce::Colour backgroundColour, int buttonsNeeded)
	: juce::DocumentWindow(name, backgroundColour, buttonsNeeded), absorption2dUI(ui)

{
    setResizable(false, false);
    setAlwaysOnTop(true);
    setContentOwned(ui, true);
    setTopLeftPosition(100, 100);
}

Absorption2DWindow::~Absorption2DWindow()
{
    absorption2dUI.reset();
}

void Absorption2DWindow::closeButtonPressed()
{
    setVisible(false);
    absorption2dUI->absorptionPanel->wall->enableAbs();
}

void Absorption2DWindow::focusOfChildComponentChanged(FocusChangeType)
{
    if (isWindowFocused)
    {
        setVisible(false);
        absorption2dUI->absorptionPanel->wall->enableAbs();
        setWindowFocus(false);
    }
}

void Absorption2DWindow::setWallId(int newId)
{
    setName(Parameters::WALL_NAMES[newId]);
    absorption2dUI->absorptionPanel->setCurrentWallId(newId);
}
