#include "RoomPlane.h"

RoomPlane::RoomPlane(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, char horizAxis, char vertAxis)
    : processor(p), valueTreeState(vts), horizontalAxis(horizAxis), verticalAxis(vertAxis)
{
    startTimerHz(120);
}

RoomPlane::~RoomPlane()
{
}

//TODO only calc postion on param change, mouse to move components
void RoomPlane::paint (juce::Graphics& g)
{

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    //
    //Draw roomArea
    //
    g.setColour(Colours::grey);
    //Use desired aspect ratio to calculate new rectangle scaled to local dimensions
    float targetRatio = getRoomAspectRatio();
    if (targetRatio > drawableAspectRatio)
    {
        roomArea.setSize(getWidth(), getHeight() * (drawableAspectRatio / targetRatio));
    }
    else if (targetRatio < drawableAspectRatio)
    {
        roomArea.setSize(getWidth() * (targetRatio / drawableAspectRatio), getHeight());
    }
    roomArea.setCentre(getLocalBounds().getCentre());
    g.drawRect(roomArea, 1);

    //
    //Draw listener as a cross
    //
    float pointSize = 0.05 * getWidth();
    g.setColour(Colours::white);
    float ListenerHorizontal = horizontalPosToPointCoord(String("Listener") + String::charToString(horizontalAxis));
    float ListenerVertical = verticalPosToPointCoord(String("Listener") + String::charToString(verticalAxis));
    g.drawLine(ListenerHorizontal - pointSize / 2, ListenerVertical - pointSize / 2, ListenerHorizontal + pointSize / 2, ListenerVertical + pointSize / 2);
    g.drawLine(ListenerHorizontal - pointSize / 2, ListenerVertical + pointSize / 2, ListenerHorizontal + pointSize / 2, ListenerVertical - pointSize / 2);

    //
    //Draw Emitter as a circle
    //
    float SourceHorizontal = horizontalPosToPointCoord(String("Source") + String::charToString(horizontalAxis));
    float SourceVertical = verticalPosToPointCoord(String("Source") + String::charToString(verticalAxis));
    sourceRect.setSize(pointSize, pointSize);
    sourceRect.setCentre(SourceHorizontal, SourceVertical);
    g.drawEllipse(sourceRect, 1.0f);

}

void RoomPlane::resized()
{
    drawableAspectRatio = getLocalBounds().getAspectRatio();
}

void RoomPlane::timerCallback()
{
    repaint();
}

float RoomPlane::verticalPosToPointCoord(String positionParam)
{
    return valueTreeState.getParameter(positionParam)->getValue() * roomArea.getHeight() + roomArea.getY();
}

float RoomPlane::horizontalPosToPointCoord(String positionParam)
{
    return valueTreeState.getParameter(positionParam)->getValue() * roomArea.getWidth() + roomArea.getX();
}

float RoomPlane::getRoomAspectRatio()
{
    return *valueTreeState.getRawParameterValue(String("Dimensions") + String::charToString(horizontalAxis))
        / *valueTreeState.getRawParameterValue(String("Dimensions") + String::charToString(verticalAxis));
}
