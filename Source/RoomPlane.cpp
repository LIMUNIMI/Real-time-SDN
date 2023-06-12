#include "RoomPlane.h"

RoomPlane::RoomPlane(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, char horizAxis, char vertAxis)
    : processor(p), valueTreeState(vts), horizontalAxis(horizAxis), verticalAxis(vertAxis)
{
    startTimerHz(120);
    listenerHorizParam = String("Listener") + String::charToString(horizAxis);
    listenerVertParam = String("Listener") + String::charToString(vertAxis);
    sourceHorizParam = String("Source") + String::charToString(horizAxis);
    sourceVertParam = String("Source") + String::charToString(vertAxis);
}

RoomPlane::~RoomPlane()
{
}

void RoomPlane::paint (juce::Graphics& g)
{

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    //Only update coordinates on params changes
    if (processor.geometryHasChanged())
    {
        updatePlaneCoords();
    }

    //
    //Draw room outline
    //
    g.setColour(Colours::grey);
    g.drawRect(roomArea, 1);

    g.setColour(Colours::white);

    //
    //Draw listener as a cross
    //
    g.drawLine(listenerRect.getCentreX() - figureSize / 2, listenerRect.getCentreY() - figureSize / 2, listenerRect.getCentreX() + figureSize / 2, listenerRect.getCentreY() + figureSize / 2);
    g.drawLine(listenerRect.getCentreX() - figureSize / 2, listenerRect.getCentreY() + figureSize / 2, listenerRect.getCentreX() + figureSize / 2, listenerRect.getCentreY() - figureSize / 2);

    //
    //Draw Emitter as a circle
    //
    g.drawEllipse(sourceRect, 1.0f);

}

void RoomPlane::resized()
{
    drawableAspectRatio = getLocalBounds().getAspectRatio();
    figureSize = 0.05 * getWidth();
    sourceRect.setSize(figureSize, figureSize);
    listenerRect.setSize(figureSize, figureSize);

    updatePlaneCoords();
}

void RoomPlane::timerCallback()
{
    repaint();
}

void RoomPlane::mouseDown(const MouseEvent& event)
{
    movingSource = sourceRect.contains(event.getMouseDownX(), event.getMouseDownY());
    movingListener = listenerRect.contains(event.getMouseDownX(), event.getMouseDownY());

    if (movingSource && movingListener)
    {
        movingSource = (sourceRect.getCentre().getDistanceSquaredFrom(event.getPosition().toFloat())) <
            (listenerRect.getCentre().getDistanceSquaredFrom(event.getPosition().toFloat()));
        movingListener = !movingSource;
    }
}

void RoomPlane::mouseDrag(const MouseEvent& event)
{
    if (movingSource)
    {
        positionChangeOnMouseDrag(event, sourceHorizParam, sourceVertParam);
    }
    else if (movingListener)
    {
        positionChangeOnMouseDrag(event, listenerHorizParam, listenerVertParam);
    }
}

void RoomPlane::mouseUp(const MouseEvent& event)
{
    movingSource = false;
    movingListener = false;
}

float RoomPlane::horizontalPosToPointCoord(String positionParam)
{
    return valueTreeState.getParameter(positionParam)->getValue() * roomArea.getWidth() + roomArea.getX();
}

float RoomPlane::verticalPosToPointCoord(String positionParam)
{
    return (1.0f - valueTreeState.getParameter(positionParam)->getValue()) * roomArea.getHeight() + roomArea.getY();
}

float RoomPlane::getRoomAspectRatio()
{
    return *valueTreeState.getRawParameterValue(String("Dimensions") + String::charToString(horizontalAxis))
        / *valueTreeState.getRawParameterValue(String("Dimensions") + String::charToString(verticalAxis));
}

void RoomPlane::positionChangeOnMouseDrag(const MouseEvent& event, String& horizontalParam, String& veticalParam)
{
    Point<int> newCoord = event.getMouseDownPosition() + event.getOffsetFromDragStart() - roomArea.getPosition();
    float newPosHoriz = std::max(std::min((float)newCoord.getX() / roomArea.getWidth(), 1.0f), 0.0f);
    float newPosVert = std::max(std::min((float)newCoord.getY() / roomArea.getHeight(), 1.0f), 0.0f);

    valueTreeState.getParameter(horizontalParam)->beginChangeGesture();
    valueTreeState.getParameter(horizontalParam)->setValueNotifyingHost(newPosHoriz);
    valueTreeState.getParameter(horizontalParam)->endChangeGesture();

    valueTreeState.getParameter(veticalParam)->beginChangeGesture();
    valueTreeState.getParameter(veticalParam)->setValueNotifyingHost(1.0f - newPosVert);
    valueTreeState.getParameter(veticalParam)->endChangeGesture();
}

void RoomPlane::updatePlaneCoords()
{
    //Use desired aspect ratio to calculate new rectangle scaled to local dimensions
    float targetRatio = getRoomAspectRatio();
    if (targetRatio >= drawableAspectRatio)
    {
        roomArea.setSize(getWidth(), getHeight() * (drawableAspectRatio / targetRatio));
    }
    else if (targetRatio < drawableAspectRatio)
    {
        roomArea.setSize(getWidth() * (targetRatio / drawableAspectRatio), getHeight());
    }
    roomArea.setCentre(getLocalBounds().getCentre());

    listenerRect.setCentre(horizontalPosToPointCoord(listenerHorizParam), verticalPosToPointCoord(listenerVertParam));
    sourceRect.setCentre(horizontalPosToPointCoord(sourceHorizParam), verticalPosToPointCoord(sourceVertParam));
}
