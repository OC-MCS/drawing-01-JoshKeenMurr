#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape drawSpace;
public:
	//===========================================================================
	//DrawingUI: constructor for the DrawingUI class
	// parameters:
	//	p: vector2f variable that is the position for the canvas area
	// return type: N/A
	//===========================================================================
	DrawingUI(Vector2f p)
	{
		//drawing area
		Vector2f posSpace(250, 50);
		drawSpace.setPosition(posSpace);
		drawSpace.setOutlineColor(Color::White);
		drawSpace.setOutlineThickness(2);
		drawSpace.setSize(Vector2f(500, 500));
		drawSpace.setFillColor(Color::White);
	}

	//===========================================================================
	//draw: function that gets the vector and draws the contents of the vector
	// parameters:
	//	mgr: pointer to ShapeMgr variable that contains the vector
	//  win: window being passed by reference to be drawn on
	// return type: void  
	//===========================================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(drawSpace);
		for (int i = 0; i < mgr->getinfo().size();i++)
			mgr->getinfo()[i]->draw(win);

	}
	
	//===========================================================================
	//isMouseInCanvas: function to tell if the mouse is in the drawing canvas space 
	// parameters:
	//	mousePos: vector 2f variable to ttell whether or not the cursor is in the canvas area
	// return type: bool
	//===========================================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool good;

		if (drawSpace.getGlobalBounds().contains(mousePos) && mousePos.x < 735 && mousePos.y < 534)
			good = true;
		else
			good = false; 
		return good;
	}

};

