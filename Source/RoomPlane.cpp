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

//TODO only calc postion on param change
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
    float ListenerHorizontal = horizontalPosToPointCoord(listenerHorizParam);
    float ListenerVertical = verticalPosToPointCoord(listenerVertParam);
    listenerRect.setSize(pointSize, pointSize);
    listenerRect.setCentre(ListenerHorizontal, ListenerVertical);
    g.drawLine(ListenerHorizontal - pointSize / 2, ListenerVertical - pointSize / 2, ListenerHorizontal + pointSize / 2, ListenerVertical + pointSize / 2);
    g.drawLine(ListenerHorizontal - pointSize / 2, ListenerVertical + pointSize / 2, ListenerHorizontal + pointSize / 2, ListenerVertical - pointSize / 2);

    //
    //Draw Emitter as a circle
    //
    float SourceHorizontal = horizontalPosToPointCoord(sourceHorizParam);
    float SourceVertical = verticalPosToPointCoord(sourceVertParam);
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
