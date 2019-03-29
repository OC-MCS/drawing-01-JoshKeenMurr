#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;

public:
//===========================================================================
//ShapesMgr: default constructor
// parameters:
//	N/A
// return type: N/A
//===========================================================================
	ShapeMgr()
	{
	}

//===========================================================================
// addShape: function to add shapes being drawn to the vector
// parameters:
//	pos: vector2f variable that passes the location of the mouse to make the circle there
//  whichShape: shape enum variable to set the current shape that shape
//  color: color variable to set the current shape as that color
// return type: void
//===========================================================================
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			
			Circle *currentC;
			currentC = new Circle(color, pos); //make a new DA variable to hold the circle

			shapes.push_back(currentC); // push the circle into the vector

			
		}
		else if (whichShape == SQUARE)
		{
			Square *currentS;
			currentS = new Square(color, pos); // make a new DA variable to hold the square

			shapes.push_back(currentS); // push the square into the vector

		}
	}

	//===========================================================================
	//getinfo: returns the vector with the info of the shapes
	// parameters:
	//	N/A
	// return type: vector of pointers to drawing shapes
	//===========================================================================
	vector<DrawingShape*> getinfo()
	{
		return shapes;
	}

	//===========================================================================
	//readFile: read the file and put them into the vector
	// parameters:
	//	file: passing the file that you open that has the info
	// return type: void
	//===========================================================================
	void readFile(fstream &file)
	{
		record temp;

		while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			
			addShape(temp.pos, temp.shape, Color(temp.color));
		}
		
	}

	//===========================================================================
	//writeFile: writes the data from the vector to the file
	// parameters:
	//	file: passes the file by reference so that the info can be written to it
	// return type: void
	//===========================================================================
	void writeFile(fstream &file)
	{
		record temp;
		for (int i = 0; i < shapes.size(); i++) // for loop to go through the vector
		{
			temp = shapes[i]->getFileRecord();
			file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}
};
