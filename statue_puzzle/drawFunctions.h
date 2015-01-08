/*****************************************************************
 COPYRIGHT (C):    2013, All Rights Reserved.
 PROJECT:          TowerDefense
 FILE:             drawFunctions.h
 PURPOSE:          A series of frequently used functions to help display the game
 COMPILER:         i686-apple-darwin10-g++-4.2.1 (GCC) 4.2.1 (Apple Inc. build 5664)
 TARGET:           Mac OS X
 PROGRAMMER:       Helen Wauck and Kevin Dexter
 START DATE:       01/21/2013
 *****************************************************************/

#ifndef DRAWFUNCTIONS_H_
#define DRAWFUNCTIONS_H_

#include <string>
#include "ccc_win.h"
#include "drawConstants.h"

std::string intToString(int i);

/* PURPOSE:  Draws a rectangle
   RECEIVES: given_width, given_height, llcorner, color: width and height of the rectangle, the lower left corner of the rectangle,
   	   	   	 the color of the rectangle
   RETURNS:  nothing
*/
void drawRectangle(double given_width, double given_height, Point llcorner, std::string color);


/* PURPOSE:  Produce a colored radial line segment
   RECEIVES: inner_radius, outer_radius, angle, center, color: radii indicating segment length, angle of segment, center of circle, color of segment
   RETURNS:  a radial segment of the specified length of a circle with the specified center of the specified color
   REMARKS:  The length of the segment is outer_radius - inner_radius
*/
Line drawRadialSegment(double inner_radius, double outer_radius, double angle, Point center, std::string color);

/* PURPOSE:  draws a sector of a circle
   RECEIVES: given_radius - radius of circle, startingAngle - starting angle of sector, endingAngle - ending angle of sector
   	   	   	 center - center of circle, angleIncrement - angle to increment by when drawing radial lines to form sector
   	   	   	 color - color of the sector
   RETURNS:  nothing
   REMARKS:
*/
void drawSector(double given_radius, double startingAngle, double endingAngle, Point center, double angleIncrement, std::string color);

/* PURPOSE:  draws a solid colored circle
   RECEIVES: given_radius - radius of circle, center - center of circle
    	     radiusIncrement - number to increment radius by when drawing concentric circles to form solid circle
   	   	   	 color - color of the circle
   RETURNS:  nothing
   REMARKS:
*/
void drawSolidCircle(double given_radius, Point center, double radiusIncrement, std::string color);

/* PURPOSE:  Draws a solid (filled) rectangle
   RECEIVES: givenWidth, givenHeight, llcorner, widthIncrement, color: width and height of the rectangle, the lower left corner of the rectangle,
   	   	   	 the width to increment by when drawing the smaller rectangles to fill in this rectangle, the color of the rectangle
   RETURNS:  nothing
   REMARKS:  This function draws a filled rectangle by drawing a series of smaller rectangles inside a larger one
*/
void drawSolidRectangle(double givenWidth, double givenHeight, Point llcorner, double widthIncrement, std::string color);

/* PURPOSE:  Calculates the max of two numbers
   RECEIVES: a, b - two integers
   RETURNS:  the max of a and b
   REMARKS:  If a and b are equal, the function returns a
*/
int max(int a, int b);

/* PURPOSE:  Draws a tower
   RECEIVES: squareSize, llcorner, primaryColor, secondaryColor: size of the square on which tower is drawn,
   	   	   	 the lower left corner of the square on which the tower is drawn, the primary and secondary colors
   	   	   	 of the tower's image
   RETURNS:  nothing
*/
void drawMapTower(double squareSize, Point llcorner, std::string primaryColor, std::string secondaryColor);

void drawWestUnit(double squareSize, Point llcorner, std::string color);

void drawEastUnit(double squareSize, Point llcorner, std::string color);

void drawNorthUnit(double squareSize, Point llcorner, std::string color);

void drawSouthUnit(double squareSize, Point llcorner, std::string color);

bool isSquareLoc(int num);

#endif /* DRAWFUNCTIONS_H_ */
