/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             constructionBox.h
 PURPOSE:          The user interface for building towers, ending the current game, and starting the next wave
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef CONSTRUCTIONBOX_H_
#define CONSTRUCTIONBOX_H_

#include "ccc_win.h"
#include "drawConstants.h"
#include "drawFunctions.h"
#include "Square.h"
#include "button.h"


class ConstructionBox {
public:

	ConstructionBox();

	ConstructionBox(double mapWidth, double mapHeight, std::string color, Point llcorner);

	void createButtons();

	void draw();

	Button getTurnCButton() const;

	Button getTurnCCButton() const;

	Button getEndGameButton() const;

	Button getResetButton() const;

	double getBoxHeight() const;

	double getBoxWidth() const;



private:

	Button turnC;
	Button turnCC;
	Button endGame;
	Button reset;
	double BOX_WIDTH;
	double BOX_HEIGHT;
	std::string color;
	Point llcorner;

};


#endif /* CONSTRUCTIONBOX_H_ */
