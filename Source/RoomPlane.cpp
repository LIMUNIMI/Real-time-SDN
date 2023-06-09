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

        listenerCenter.setXY(horizontalPosToPointCoord(listenerHorizParam), verticalPosToPointCoord(listenerVertParam));
        listenerRect.setCentre(listenerCenter);

        sourceCenter.setXY(horizontalPosToPointCoord(sourceHorizParam), verticalPosToPointCoord(sourceVertParam));
        sourceRect.setCentre(sourceCenter);
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
    g.drawLine(listenerCenter.getX() - figureSize / 2, listenerCenter.getY() - figureSize / 2, listenerCenter.getX() + figureSize / 2, listenerCenter.getY() + figureSize / 2);
    g.drawLine(listenerCenter.getX() - figureSize / 2, listenerCenter.getY() + figureSize / 2, listenerCenter.getX() + figureSize / 2, listenerCenter.getY() - figureSize / 2);

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

    listenerCenter.setXY(horizontalPosToPointCoord(listenerHorizParam), verticalPosToPointCoord(listenerVertParam));
    listenerRect.setCentre(listenerCenter);
    sourceCenter.setXY(horizontalPosToPointCoord(sourceHorizParam), verticalPosToPointCoord(sourceVertParam));
    sourceRect.setCentre(sourceCenter);
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
        Point<int> newCoord = event.getMouseDownPosition() + event.getOffsetFromDragStart() - roomArea.getPosition();
        float newPosHoriz = std::max(std::min((float)newCoord.getX() / roomArea.getWidth(), 1.0f), 0.0f);
        float newPosVert = std::max(std::min((float)newCoord.getY() / roomArea.getHeight(), 1.0f), 0.0f);

        valueTreeState.getParameter(sourceHorizParam)->beginChangeGesture();
        valueTreeState.getParameter(sourceHorizParam)->setValueNotifyingHost(newPosHoriz);
        valueTreeState.getParameter(sourceHorizParam)->endChangeGesture();

        valueTreeState.getParameter(sourceVertParam)->beginChangeGesture();
        valueTreeState.getParameter(sourceVertParam)->setValueNotifyingHost(newPosVert);
        valueTreeState.getParameter(sourceVertParam)->endChangeGesture();
    }
    else if (movingListener)
    {
        Point<int> newCoord = event.getMouseDownPosition() + event.getOffsetFromDragStart() - roomArea.getPosition();
        float newPosHoriz = std::max(std::min((float)newCoord.getX() / roomArea.getWidth(), 1.0f), 0.0f);
        float newPosVert = std::max(std::min((float)newCoord.getY() / roomArea.getHeight(), 1.0f), 0.0f);

        valueTreeState.getParameter(listenerHorizParam)->beginChangeGesture();
        valueTreeState.getParameter(listenerHorizParam)->setValueNotifyingHost(newPosHoriz);
        valueTreeState.getParameter(listenerHorizParam)->endChangeGesture();

        valueTreeState.getParameter(listenerVertParam)->beginChangeGesture();
        valueTreeState.getParameter(listenerVertParam)->setValueNotifyingHost(newPosVert);
        valueTreeState.getParameter(listenerVertParam)->endChangeGesture();
    }
}

void RoomPlane::mouseUp(const MouseEvent& event)
{
    movingSource = false;
    movingListener = false;
}



float RoomPlane::verticalPosToPointCoord(String positionParam)
{
    return (1.0f - valueTreeState.getParameter(positionParam)->getValue()) * roomArea.getHeight() + roomArea.getY();
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
