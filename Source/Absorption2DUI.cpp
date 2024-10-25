#include "Absorption2DUI.h"

#define PANEL_SIZE 400
#define PANEL_OFFSET 10

Absorption2DUI::Absorption2DUI(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts)
	: processor(p), valueTreeState(vts)
{

	absorptionPanel = std::make_unique<Absorption2DPanel>(p, vts, *this);
	addAndMakeVisible(absorptionPanel.get());

	xSlider.reset(new Slider("xSlider"));
	addAndMakeVisible(xSlider.get());
	xSlider->setRange(0, 1, 0);
	xSlider->setSliderStyle(juce::Slider::LinearHorizontal);
	xSlider->setTextBoxStyle(juce::Slider::NoTextBox, false, 80, 20);
	xSlider->setSliderSnapsToMousePosition(false);
	xSlider->setVelocityBasedMode(true);

	xSlider->onValueChange = [this]()
	{
		absorptionPanel->updateX(xSlider->getValue() * PANEL_SIZE);
	};

	ySlider.reset(new Slider("ySlider"));
	addAndMakeVisible(ySlider.get());
	ySlider->setRange(0, 1, 0);
	ySlider->setSliderStyle(juce::Slider::LinearVertical);
	ySlider->setTextBoxStyle(juce::Slider::NoTextBox, false, 80, 20);
	ySlider->setSliderSnapsToMousePosition(false);
	ySlider->setVelocityBasedMode(true);

	ySlider->onValueChange = [this]()
	{
		absorptionPanel->updateY((1 - ySlider->getValue()) * PANEL_SIZE);
	};

	setSize(440, 440);
}

Absorption2DUI::~Absorption2DUI()
{
	absorptionPanel.reset();
}

void Absorption2DUI::paint(juce::Graphics&)
{
}

void Absorption2DUI::resized()
{
	absorptionPanel->setBounds(PANEL_OFFSET, PANEL_OFFSET, PANEL_SIZE, PANEL_SIZE);
	xSlider->setBounds(PANEL_OFFSET - 10, PANEL_SIZE + 15, PANEL_SIZE + 20, 20);
	ySlider->setBounds(PANEL_SIZE + 15, PANEL_OFFSET - 10, 20, PANEL_SIZE + 20);
}

void Absorption2DUI::setSliderValues(float x, float y)
{
	xSlider->setValue(x);
	ySlider->setValue(y);
}
