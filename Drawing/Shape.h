#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;


// struct to hold the vector info in a form that can be put into a binary file
struct record
{
	int color;
	ShapeEnum shape;
	Vector2f pos;
};

// abstract base class for the shapes
class DrawingShape 
{
public:
	virtual void draw(RenderWindow&) = 0;
	virtual record getFileRecord() = 0;
};


class Circle : public DrawingShape
{
private:
	CircleShape cirIn;
public:
	//===========================================================================
	//circle: constructor that will set the passed info into the circle class
	// parameters:
	//	colorIn: color of the current choice
	//  pos: position of the mouse 
	// return type: N/A
	//===========================================================================
	Circle(Color colorIn, Vector2f pos)
	{

		cirIn.setPosition(pos);
		cirIn.setRadius(10);
		cirIn.setOutlineThickness(2);
		cirIn.setFillColor(colorIn);
		cirIn.setOutlineColor(colorIn);
	}
	//===========================================================================
	//draw: funciton to draw the current circle settings
	// parameters:
	//	win: window being passed by reference so that it can be drawn on
	// return type: void
	//===========================================================================
	void draw(RenderWindow& win)
	{
		win.draw(cirIn);
	}

	//===========================================================================
	//getFilerecord: function to set the current info in circle and set into a temp record variable
	// parameters:
	//	N/A
	// return type: record
	//===========================================================================
	record getFileRecord()
	{
		record temp;
		temp.color = cirIn.getFillColor().toInteger(); // converts the Color variable to an integer so that it can be stored in a binary file
		temp.pos = cirIn.getPosition(); // gets to postition of the currently used shape
		temp.shape = CIRCLE;
		
		return temp;

	}
};

class Square : public DrawingShape
{ 
private:
	RectangleShape sIn;
public:
	//===========================================================================
	//Square: constructor that will set the passed info into the Square class
	// parameters:
	//	colorIn: color of the current choice
	//  pos: position of the mouse 
	// return type: N/A
	//===========================================================================
	Square(Color colorIn, Vector2f pos)
	{

		sIn.setPosition(pos);
		sIn.setOutlineColor(colorIn);
		sIn.setOutlineThickness(2);
		sIn.setSize(Vector2f(20, 20));
		sIn.setFillColor(colorIn);
	}

	//===========================================================================
	//draw: funciton to draw the current square settings
	// parameters:
	//	win: window being passed by reference so that it can be drawn on
	// return type: void
	//===========================================================================
	void draw(RenderWindow& win)
	{
		win.draw(sIn); 
	}

	//===========================================================================
	//getFilerecord: function to set the current info in square and set into a temp record variable
	// parameters:
	//	N/A
	// return type: record
	//===========================================================================
	record getFileRecord()
	{
		record temp;
		temp.color = sIn.getFillColor().toInteger(); // converts the Color variable to an integer so that it can be stored in a binary file
		temp.pos = sIn.getPosition(); // gets to postition of the currently used shape
		temp.shape = SQUARE;

		return temp;

	}

};

