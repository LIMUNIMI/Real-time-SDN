#include "Absorption2DPanel.h"

Absorption2DPanel::Absorption2DPanel(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts)
	: processor(p), valueTreeState(vts)
{
	startTimerHz(60);

	//svgFile = File("C:\\Users\\Marco\\Documents\\Juce\\Real time SDN\\Binary\\FilterSpace.svg");
	//pngFile = File("C:\\Users\\Marco\\Documents\\Juce\\Real time SDN\\Binary\\FilterSpace.png");
	//backgroundImg = Drawable::createFromSVGFile(svgFile);
	//backgroundImg = Drawable::createFromImageFile(pngFile);
	backgroundImg = Drawable::createFromImageData(BinaryData::FilterSpace_png, BinaryData::FilterSpace_pngSize);
	addAndMakeVisible(backgroundImg.get());
	backgroundImg->setBounds(getLocalBounds());

    movingFilter = false;
	filterChanged = false;
	validPosition = false;

	//build the points convex hull
	convexHull.startNewSubPath(
		AbsorptionSpace::points[AbsorptionSpace::convex_hull[0]][0],
		AbsorptionSpace::points[AbsorptionSpace::convex_hull[0]][1]);
	for(int i = 1; i < AbsorptionSpace::NUM_CONVEX_HULL_VERTICES; i++)
	{
		convexHull.lineTo(
			AbsorptionSpace::points[AbsorptionSpace::convex_hull[i]][0],
			AbsorptionSpace::points[AbsorptionSpace::convex_hull[i]][1]);
	}
	convexHull.closeSubPath();
	//convexHull.applyTransform(AffineTransform::scale(getWidth(), getHeight()));

	//build all simplices as triangle paths
	for (int i = 0; i < AbsorptionSpace::NUM_SIMPLICES; i++)
	{
		uiSimplices[i].addTriangle(
			AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][0],
			AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][1],
			AbsorptionSpace::points[AbsorptionSpace::simplices[i][1]][0],
			AbsorptionSpace::points[AbsorptionSpace::simplices[i][1]][1],
			AbsorptionSpace::points[AbsorptionSpace::simplices[i][2]][0],
			AbsorptionSpace::points[AbsorptionSpace::simplices[i][2]][1]);
	}

	setSize(250, 250);
}

Absorption2DPanel::~Absorption2DPanel()
{
}

void Absorption2DPanel::paint(juce::Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void Absorption2DPanel::resized()
{
	for (int i = 0; i < AbsorptionSpace::NUM_SIMPLICES; i++)
	{
		uiSimplices[i].applyTransform(AffineTransform::scale(getWidth(), getHeight()));
	}
	convexHull.scaleToFit(0, 0, getWidth(), getHeight(), false);
	backgroundImg->setTransformToFit(getLocalBounds().toFloat(), RectanglePlacement::stretchToFit);
	
	pickerRect.setSize(0.05 * getWidth(), 0.05 * getWidth());
	pickerRect.setCentre(getBounds().getCentre().toFloat());
	pickerRectInternal.setSize(0.35 * pickerRect.getWidth(), 0.35 * pickerRect.getWidth());
	pickerRectInternal.setCentre(pickerRect.getCentre());
	
	intersectionLine.setStart(getBounds().getCentre().toFloat());
}

void Absorption2DPanel::timerCallback()
{
	repaint();
	updatePluginParams();
}

void Absorption2DPanel::paintOverChildren(Graphics& g)
{
	if (validPosition)
	{
		g.setColour(Colours::black);
		g.fillEllipse(pickerRect);
		g.setColour(Colours::white);
		g.fillEllipse(pickerRectInternal);
	}
	//g.strokePath(convexHull, PathStrokeType(1));
	//g.setColour(Colours::darkred);
	//for (int i = 0; i < AbsorptionSpace::NUM_SIMPLICES; i++)
	//{
	//	g.strokePath(uiSimplices[i], PathStrokeType(1));
	//}
}

void Absorption2DPanel::mouseDown(const MouseEvent& event)
{
	if (validPosition)
	{
		movingFilter = pickerRect.contains(event.getMouseDownX(), event.getMouseDownY());
		if (movingFilter)
		{
			clickoffset = pickerRect.getCentre() - event.getMouseDownPosition().toFloat();
		}
	}
	else
	{
		movingFilter = true;
		clickoffset.setXY(0,0);
		positionChangeOnMouseDrag(event);
		validPosition = true;
	}
}

void Absorption2DPanel::mouseDrag(const MouseEvent& event)
{
    if (movingFilter)
    {
        positionChangeOnMouseDrag(event);
    }
}

void Absorption2DPanel::mouseUp(const MouseEvent& event)
{
	movingFilter = false;
}

void Absorption2DPanel::setCurrentWallId(int newId)
{
	currentWallId = newId;
}

void Absorption2DPanel::setWallCoords(Point<float>* newCoords)
{
	wallCoords = newCoords;
	if (wallCoords->x != -1)
	{
		pickerRect.setCentre(*wallCoords);
		pickerRectInternal.setCentre(pickerRect.getCentre());
		validPosition = true;
	}
	else
	{
		validPosition = false;
	}
}

void Absorption2DPanel::positionChangeOnMouseDrag(const MouseEvent& event)
{
    newCoord = event.mouseDownPosition + clickoffset + event.getOffsetFromDragStart().toFloat() - backgroundImg->getPosition().toFloat();
    float newPosHoriz = std::max(std::min(newCoord.getX(), (float)getWidth()), 0.0f);
    float newPosVert = std::max(std::min(newCoord.getY(), (float)getHeight()), 0.0f);

	pickerRect.setCentre(newPosHoriz, newPosVert);
	pickerRectInternal.setCentre(pickerRect.getCentre());
	wallCoords->setXY(newPosHoriz, newPosVert);

	intersectionLine.setEnd(newPosHoriz, newPosVert);
	intersectionLine = convexHull.getClippedLine(intersectionLine, false);
	float x = intersectionLine.getEndX() - (signbit(newPosHoriz - getBounds().getCentreX()) ? -1 : 1),
		  y = intersectionLine.getEndY() - (signbit(newPosVert - getBounds().getCentreY()) ? -1 : 1);

	for (int i = 0; i < AbsorptionSpace::NUM_SIMPLICES; i++)
	{
		//naive approach for now
		if (uiSimplices[i].contains(x, y, 0.0000000f))
		{
			tempFilter.fill(0);

			v0.setXY(AbsorptionSpace::points[AbsorptionSpace::simplices[i][1]][0] - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][0],
				AbsorptionSpace::points[AbsorptionSpace::simplices[i][1]][1] - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][1]);
			v1.setXY(AbsorptionSpace::points[AbsorptionSpace::simplices[i][2]][0] - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][0],
				AbsorptionSpace::points[AbsorptionSpace::simplices[i][2]][1] - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][1]);
			v2.setXY((x/getWidth()) - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][0],
				(y/getHeight()) - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][1]);
			
			float rec_den = 1 / (v0.x * v1.y - v1.x * v0.y);
			baricentricCoord[1] = (v2.x * v1.y - v1.x * v2.y) * rec_den;
			baricentricCoord[2] = (v0.x * v2.y - v2.x * v0.y) * rec_den;
			baricentricCoord[0] = 1.0f - baricentricCoord[1] - baricentricCoord[2];

			std::unique_lock<std::mutex> lck(mut);
			for (int band = 0; band < AbsorptionSpace::NUM_OCATAVE_BANDS; band++)
			{
				for (int point = 0; point < 3; point++)
				{
					tempFilter[band] += AbsorptionSpace::absorption_values[AbsorptionSpace::simplices[i][point]][band] * baricentricCoord[point];
				}
			}

			tempFilter[6] = tempFilter[5];
			tempFilter[7] = tempFilter[5];
			filterChanged = true;
			lck.unlock();
			break;
		}
	}
}

void Absorption2DPanel::updatePluginParams()
{
	if (filterChanged)
	{
		std::unique_lock<std::mutex> lck(mut);
		for (int i = 0; i < Parameters::NUM_FREQ; i++)
		{
			valueTreeState.getParameter(String("freq") + String(currentWallId) + String(i))->beginChangeGesture();
			valueTreeState.getParameter(String("freq") + String(currentWallId) + String(i))->setValueNotifyingHost(tempFilter[i]);
			valueTreeState.getParameter(String("freq") + String(currentWallId) + String(i))->endChangeGesture();
		}
		filterChanged = false;
		lck.unlock();
	}
}
