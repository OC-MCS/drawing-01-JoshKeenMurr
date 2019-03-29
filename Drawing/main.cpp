//====================================================================
// Joshua Murray
// Due Friday, March 29
// Programming II: Assigment #6
// Description: Program that can draw on a canvas and switch between two shapes and 3 colors
// the drawing is also kept for next use, as well as the setting last used
//====================================================================
#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;


int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);

	SettingsMgr settingsMgr(Color::Cyan, ShapeEnum::CIRCLE);
	SettingsUI  settingsUI(&settingsMgr); 
	ShapeMgr    shapeMgr;
	DrawingUI   drawingUI(Vector2f(200, 50));
	
	// read data from the file
	fstream file;
	file.open("shapes.bin", ios::binary | ios::in);
	if (file)
	{
		settingsMgr.readFile(file);
		shapeMgr.readFile(file);
		file.close(); // close the file once finished reading  
	}

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				fstream file;
				file.open("shapes.bin", ios::binary | ios::out);
				settingsMgr.writeFile(file);
				shapeMgr.writeFile(file);
				file.close();

				// ****** Add code here to write all data to shapes file
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// if mouse button is released, it may be above a setting
				// if above setting, change the setting
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{
				
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				// check to see if mouse is in the drawing area
				if (drawingUI.isMouseInCanvas(mousePos))
				{
					// add a shape to the list based on current settings
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}

		// The remainder of the body of the loop draws one frame of the animation
		window.clear();

		// this should draw the left hand side of the window (all of the settings info)
		settingsUI.draw(window);

		// this should draw the rectangle that encloses the drawing area, then draw the
		// shapes. This is passed the shapeMgr so that the drawingUI can get the shapes
		// in order to draw them. This redraws *all* of the shapes every frame.
		drawingUI.draw(window, &shapeMgr);

		window.display();
	} // end body of animation loop


	return 0;
}