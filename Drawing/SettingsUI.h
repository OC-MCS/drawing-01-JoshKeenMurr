#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	CircleShape cChoice;
	RectangleShape sChoice;
	CircleShape ColChoice1;
	CircleShape ColChoice2;
	CircleShape ColChoice3;
	SettingsMgr *UI;

public:
	//===========================================================================
	//SettingsUI: constructor that sets a private variable to the passed variable
	// parameters:
	//	mgr: pointer to settings mgr variable
	// return type: N/A
	//===========================================================================
	SettingsUI(SettingsMgr *mgr)
	{
		UI = mgr;
	}

	//===========================================================================
	//handleMouseUp: function that if that mouse is released, if it is over a setting, it will choose the setting it was released over
	// parameters:
	//	mouse: vector2f variable that holds the current mouses position
	// return type: void
	//===========================================================================
	void handleMouseUp(Vector2f mouse)
	{
		if (cChoice.getGlobalBounds().contains(mouse)) // setting shape to Circle
		{
			UI->setShape(CIRCLE);
		}
		else if (sChoice.getGlobalBounds().contains(mouse)) // setting shape to square
		{
			UI->setShape(SQUARE);
		}
		else if (ColChoice1.getGlobalBounds().contains(mouse)) // setting color to red
		{ 
			UI->setColor(Color::Red);
		}
		else if (ColChoice2.getGlobalBounds().contains(mouse)) // setting color to cyan
		{
			UI->setColor(Color::Cyan);
		}
		else if (ColChoice3.getGlobalBounds().contains(mouse)) // setting color to green
		{
			UI->setColor(Color::Green);
		}
	}

	//===========================================================================
	//draw: function to draw all of the settings on the left hand side of the screen
	// parameters:
	//	win: window passed by reference so that it can be drawn on
	// return type: void
	//===========================================================================
	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		//selected color title
		Text selCol("Selected Color", font, 25);
		selCol.setPosition(30, 25);
		win.draw(selCol);

		// selected shape title
		Text selShap("Selected Shape", font, 25);
		selShap.setPosition(30, 330);
		win.draw(selShap);

		// circle shape choice
		Vector2f posC(100, 400);
		cChoice.setPosition(posC);
		cChoice.setRadius(20);
		cChoice.setOutlineThickness(2);
		cChoice.setOutlineColor(Color::White);
		win.draw(cChoice);

		//square shape choice
		Vector2f posS(100, 500);
		sChoice.setPosition(posS);
		sChoice.setOutlineColor(Color::White);
		sChoice.setOutlineThickness(2);
		sChoice.setSize(Vector2f(40, 40));
		win.draw(sChoice);

		// color choice 1
		Vector2f posC1(100, 70);
		ColChoice1.setPosition(posC1);
		ColChoice1.setRadius(20);
		ColChoice1.setOutlineThickness(2);
		ColChoice1.setOutlineColor(Color::Red);
		win.draw(ColChoice1);

		// color choice 2
		Vector2f posC2(100, 160);
		ColChoice2.setPosition(posC2);
		ColChoice2.setRadius(20);
		ColChoice2.setOutlineThickness(2);
		ColChoice2.setOutlineColor(Color::Cyan);
		win.draw(ColChoice2);

		// color choice 3
		Vector2f posC3(100, 250);
		ColChoice3.setPosition(posC3);
		ColChoice3.setRadius(20);
		ColChoice3.setOutlineThickness(2);
		ColChoice3.setOutlineColor(Color::Green);
		win.draw(ColChoice3);

		// following if's will cause the current being used color or shape to be filled in with its color and turn the others transparent
		if (UI->getCurColor() == Color::Cyan) 
		{
			ColChoice1.setFillColor(Color::Transparent);
			ColChoice2.setFillColor(Color::Cyan);
			ColChoice3.setFillColor(Color::Transparent);
		}
		else if (UI->getCurColor() == Color::Red)
		{
			ColChoice1.setFillColor(Color::Red);
			ColChoice2.setFillColor(Color::Transparent);
			ColChoice3.setFillColor(Color::Transparent);
		}
		else if (UI->getCurColor() == Color::Green)
		{
			ColChoice1.setFillColor(Color::Transparent);
			ColChoice2.setFillColor(Color::Transparent);
			ColChoice3.setFillColor(Color::Green);
		}

		if (UI->getCurShape() == SQUARE)
		{
			cChoice.setFillColor(Color::Transparent);
			sChoice.setFillColor(Color::White);

		}
		else if (UI->getCurShape() == CIRCLE)
		{
			cChoice.setFillColor(Color::White);
			sChoice.setFillColor(Color::Transparent);

		}
	}

};



