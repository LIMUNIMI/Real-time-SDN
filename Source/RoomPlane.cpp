#include "RoomPlane.h"

using namespace Eigen;

RoomPlane::RoomPlane(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, char horizAxis, char vertAxis)
    : processor(p), valueTreeState(vts), horizontalAxis(horizAxis), verticalAxis(vertAxis)
{
    startTimerHz(120);
    listenerHorizParam = String("Listener") + String::charToString(horizAxis);
    listenerVertParam = String("Listener") + String::charToString(vertAxis);
    sourceHorizParam = String("Source") + String::charToString(horizAxis);
    sourceVertParam = String("Source") + String::charToString(vertAxis);

    rotatedListener = Vector3f(0, 0, 1);
    
    switch (horizAxis)
    {
    case 'X':
        horizRot = &rotatedListener.x();
        break;
    case 'Y':
        horizRot = &rotatedListener.y();
        break;
    case 'Z':
        horizRot = &rotatedListener.z();
        break;
    default:
        break;
    }

    switch (vertAxis)
    {
    case 'X':
        vertRot = &rotatedListener.x();
        break;
    case 'Y':
        vertRot = &rotatedListener.y();
        break;
    case 'Z':
        vertRot = &rotatedListener.z();
        break;
    default:
        break;
    }
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
    //Draw listener as a circle + "nose" to represent rotation
    //
    g.drawEllipse(listenerRect, 1.0f);
    g.drawEllipse(listenerRotRect, 1.0f);

    //
    //Draw Emitter as a concentric circles
    //
    g.drawEllipse(sourceRect, 1.0f);
    g.drawEllipse(sourceRect.getX() + sourceRect.getWidth() * 0.125, sourceRect.getY() + sourceRect.getWidth() * 0.125, sourceRect.getWidth() * 0.75, sourceRect.getWidth() * 0.75, 1.0f);
    g.drawEllipse(sourceRect.getX() + sourceRect.getWidth() * 0.25, sourceRect.getY() + sourceRect.getWidth() * 0.25, sourceRect.getWidth() * 0.5, sourceRect.getWidth() * 0.5, 1.0f);

}

void RoomPlane::resized()
{
    drawableAspectRatio = getLocalBounds().getAspectRatio();
    figureSize = 0.05 * getWidth();
    sourceRect.setSize(figureSize, figureSize);
    listenerRect.setSize(figureSize, figureSize);
    listenerRotRect.setSize(figureSize / 4, figureSize / 4);

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
    updateRotation();
    sourceRect.setCentre(horizontalPosToPointCoord(sourceHorizParam), verticalPosToPointCoord(sourceVertParam));
}

void RoomPlane::updateRotation()
{
    listenerRot = AngleAxisf(DEG2RAD(*valueTreeState.getRawParameterValue("ListenerRotz")), Vector3f::UnitZ())
        * AngleAxisf(DEG2RAD(*valueTreeState.getRawParameterValue("ListenerRoty")), Vector3f::UnitY())
        * AngleAxisf(DEG2RAD(*valueTreeState.getRawParameterValue("ListenerRotx")), Vector3f::UnitX());

    rotatedListener = listenerRot * forward;
    rotatedListener.normalize();

    listenerRotRect.setCentre(listenerRect.getCentreX() + (figureSize * 0.5 * *horizRot), 
        listenerRect.getCentreY() - (figureSize * 0.5 * *vertRot));
}
