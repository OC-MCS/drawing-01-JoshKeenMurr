#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };



class SettingsMgr
{
private:
	Color cColor;
	ShapeEnum shapeChoice;
public:
	//===========================================================================
	//readFile: function to read the file to see what the last settings used were
	// parameters:
	//	file: file passed so that it can be read
	// return type: void
	//===========================================================================
	void readFile(fstream &file)
	{
		unsigned int colorNumber;
		file.read(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber)); // reading the color
		file.read(reinterpret_cast<char*>(&shapeChoice), sizeof(shapeChoice)); // reading the shape
		
		Color aColor(colorNumber);
		cColor = aColor; // changing the color from a number to a color and storing it in variable

	}

	//===========================================================================
	//writeFile: write the data from the file for the last used settings
	// parameters:
	//	file: file passed so that it can be written on
	// return type: void
	//===========================================================================
	void writeFile(fstream &file)
	{
		unsigned int colorNumber = cColor.toInteger();
		file.write(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber)); // writing the color
		file.write(reinterpret_cast<char*>(&shapeChoice), sizeof(shapeChoice)); // writing the shape
	}

	//===========================================================================
	//settingsMgr: constructor that sets the current color and shape being used
	// parameters:
	//	startingColor: color you are starting with
	// startingShape: shape that you are starting with
	// return type: N/A
	//===========================================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		cColor = startingColor;
		shapeChoice = startingShape;
	}

	//===========================================================================
	//getCurColor: function that returns the current color being used
	// parameters:
	//	N/A
	// return type: Color
	//===========================================================================
	Color getCurColor()
	{
		return cColor; // just to make it compile 
	}

	//===========================================================================
	//getCurShape: function that returns the current Shape being used
	// parameters:
	//	N/A
	// return type: ShapeEnum
	//===========================================================================
	ShapeEnum getCurShape()
	{
		return shapeChoice; // just to make it compile;
	}

	//===========================================================================
	//setColor: sets the color to whatever color is passed
	// parameters:
	//	colin: color variable that is being passed in
	// return type: void
	//===========================================================================
	void setColor(Color colin)
	{
		cColor = colin;
	}

	//===========================================================================
	//setShape: sets the shape to whatever shape is passed
	// parameters:
	//	shapin: ShapeEnum variable that is being passed in
	// return type: void
	//===========================================================================
	void setShape(ShapeEnum shapin)
	{
		shapeChoice = shapin;
	}
};

//===========================================================================
//die: funciton to kill a function
// parameters:
//	msg: string you are passing
// return type: void
//===========================================================================
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

