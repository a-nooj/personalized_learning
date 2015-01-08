/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             button.h
 PURPOSE:          Buttons display text on the user interface and read user input
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "ccc_win.h"
#include "drawConstants.h"
#include "drawFunctions.h"

class Button {
public:
	Button();
	Button(Point llcorner, double height, std::string text, std::string color);

	/* RETURNS: true if Point p is inside this button
	*/
	bool inRange(Point p);

	std::string getColor() const;

	double getWidth() const;

	Point getLLcorner() const;

	Point getTextPos() const;

	std::string getText() const;

	void setWidth(double width);

	void setHeight(double height);

	void setText(std::string text);

	void setTextPos(Point textPos);

	virtual void draw();

private:
	/* REMARKS: a Point representing the lower left corner of this button
	*/
	Point llcorner;

	/* REMARKS: a Point representing the lower left corner of the text of this button
	*/
	Point textPos;

	double width;

	double height;

	std::string text;

	std::string color;
};


#endif /* BUTTON_H_ */
