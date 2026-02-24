#include "Absorption2DPanel.h"
#include "Absorption2DUI.h"
using namespace juce;

Absorption2DPanel::Absorption2DPanel(RealtimeSDNAudioProcessor& p, AudioProcessorValueTreeState& vts, Absorption2DUI& parent)
	: processor(p), valueTreeState(vts), ui(parent)
{
	startTimerHz(60);

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

	//setSize(400, 400);
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
	
	pickerRect.setSize(0.02 * getWidth(), 0.02 * getWidth());
	pickerRect.setCentre(getBounds().getCentre().toFloat());
	pickerRectInternal.setSize( pickerRect.getWidth(), pickerRect.getWidth());
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
		g.setColour(Colours::white);
		g.drawEllipse(pickerRectInternal,4);
		g.setColour(Colours::black);
		g.drawEllipse(pickerRect, 3);
	}
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

void Absorption2DPanel::setWallCoords(Point<float>* newCoords, Absorp* wal)
{
	wallCoords = newCoords;
	wall = wal;
	if (wallCoords->x != -1)
	{
		pickerRect.setCentre(*wallCoords);
		pickerRectInternal.setCentre(pickerRect.getCentre());
		float newPosHoriz = std::max(std::min(newCoords->getX(), (float)getWidth()), 0.0f);
		float newPosVert = std::max(std::min(newCoords->getY(), (float)getHeight()), 0.0f);

		ui.setSliderValues(newPosHoriz / getHeight(), 1 - (newPosVert / getWidth()));
		validPosition = true;
	}
	else
	{
		validPosition = false;
	}
}

void Absorption2DPanel::update2DCoords(float x, float y)
{
	wallCoords->setXY(x, y);
	validPosition = true;
	pickerRect.setCentre(x, y);
	pickerRectInternal.setCentre(pickerRect.getCentre());
	findFilter();
}

void Absorption2DPanel::updateX(float x)
{
	wallCoords->setX(x);
	if (!validPosition)
	{
		wallCoords->setY((1 - ui.getYsliderValue()) * getHeight());
		validPosition = true;
	}
	pickerRect.setCentre(*wallCoords);
	pickerRectInternal.setCentre(pickerRect.getCentre());
	findFilter();
}

void Absorption2DPanel::updateY(float y)
{
	wallCoords->setY(y);
	if (!validPosition)
	{
		wallCoords->setX(ui.getXsliderValue() * getWidth());
		validPosition = true;
	}
	pickerRect.setCentre(*wallCoords);
	pickerRectInternal.setCentre(pickerRect.getCentre());
	findFilter();
}

void Absorption2DPanel::positionChangeOnMouseDrag(const MouseEvent& event)
{
    newCoord = event.mouseDownPosition + clickoffset + event.getOffsetFromDragStart().toFloat() - backgroundImg->getPosition().toFloat();
    float newPosHoriz = std::max(std::min(newCoord.getX(), (float)getWidth()), 0.0f);
    float newPosVert = std::max(std::min(newCoord.getY(), (float)getHeight()), 0.0f);

	ui.setSliderValues(newPosHoriz / getHeight(), 1-(newPosVert / getWidth()));

	findFilter();
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

void Absorption2DPanel::findFilter()
{
	intersectionLine.setEnd(*wallCoords);
	intersectionLine = convexHull.getClippedLine(intersectionLine, false);
	float x = intersectionLine.getEndX() - (signbit(wallCoords->x - getBounds().getCentreX()) ? -1 : 1),
		y = intersectionLine.getEndY() - (signbit(wallCoords->y - getBounds().getCentreY()) ? -1 : 1);

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
			v2.setXY((x / getWidth()) - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][0],
				(y / getHeight()) - AbsorptionSpace::points[AbsorptionSpace::simplices[i][0]][1]);

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
