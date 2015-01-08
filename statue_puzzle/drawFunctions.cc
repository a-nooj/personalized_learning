#include "drawFunctions.h"
#include "ccc_win.h"
#include <cmath>
#include <string>
#include <sstream>


std::string intToString(int i) {
	ostringstream strm;
	strm << i;
	return strm.str();
}

void drawRectangle(double given_width, double given_height, Point llcorner, std::string color) {
	double startingXPos = llcorner.get_x();
	double endingXPos = startingXPos + given_width;
	double bottomYPos = llcorner.get_y();
	double topYPos = llcorner.get_y() + given_height;

	Point ulcorner(startingXPos, topYPos);
	Line ll_to_ul(llcorner, ulcorner, color);
	cwin << ll_to_ul;

	Point lrcorner(endingXPos, bottomYPos);
	Line ll_to_lr(llcorner, lrcorner, color);
	cwin << ll_to_lr;

	Point urcorner(endingXPos, topYPos);
	Line lr_to_ur(lrcorner, urcorner, color);
	cwin << lr_to_ur;

	Line ul_to_ur(ulcorner, urcorner, color);
	cwin << ul_to_ur;
}

Line drawRadialSegment(double inner_radius, double outer_radius, double angle, Point center, std::string color) {
	double xOffset = center.get_x();
	double yOffset = center.get_y();

	double xPosSegInner = inner_radius * sin(angle);
	double yPosSegInner = inner_radius * cos(angle);
	Point segmentPosInner(xPosSegInner + xOffset, yPosSegInner + yOffset);

	double xPosSegOuter = outer_radius * sin(angle);
	double yPosSegOuter = outer_radius * cos(angle);
	Point segmentPosOuter(xPosSegOuter + xOffset, yPosSegOuter + yOffset);

	Line segment(segmentPosInner, segmentPosOuter, color);
	return segment;
}

void drawSector(double given_radius, double startingAngle, double endingAngle, Point center, double angleIncrement, std::string color) {

	Point outerEdge(given_radius * cos(startingAngle), given_radius * sin(startingAngle));
	for (double angle = startingAngle; angle <= endingAngle; angle += angleIncrement) {
	    cwin << drawRadialSegment(0, given_radius, angle, center, color);
	}
}

void drawSolidCircle(double given_radius, Point center, double radiusIncrement, std::string color) {
	for (double radius = 0.0; radius <= given_radius; radius += radiusIncrement) {
	    cwin << Circle(center, radius, color);
	}
}

void drawSolidRectangle(double givenWidth, double givenHeight, Point llcorner, double widthIncrement, std::string color) {
	Point rectPos(llcorner.get_x(), llcorner.get_y());

	for (double width = 0; width < givenWidth / 2; width += widthIncrement) {
		rectPos.move(widthIncrement,0);
	    drawRectangle(width, givenHeight, rectPos, color);
	}
}

int max(int a, int b) {
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}

void drawMapTower(double squareSize, Point llcorner, std::string primaryColor, std::string secondaryColor) {
	llcorner = Point (llcorner.get_x(), llcorner.get_y());
	Point llcornerAdj(llcorner.get_x() + 0.01, llcorner.get_y() + 0.01);
	drawSolidRectangle(squareSize, squareSize, llcorner, WIDTH_INCREMENT, primaryColor);

	drawSolidRectangle(squareSize / 4, squareSize / 4, llcornerAdj, WIDTH_INCREMENT, secondaryColor);
	Point ulsquare(llcornerAdj.get_x(),llcornerAdj.get_y() + squareSize * 0.75);
	drawSolidRectangle(squareSize / 4, squareSize / 4, ulsquare, WIDTH_INCREMENT, secondaryColor);
	Point ursquare(llcornerAdj.get_x() + squareSize * 0.75,llcornerAdj.get_y() + squareSize * 0.75);
	drawSolidRectangle(squareSize / 4, squareSize / 4, ursquare, WIDTH_INCREMENT, secondaryColor);
	Point lrsquare(llcornerAdj.get_x() + squareSize * 0.75,llcornerAdj.get_y());
	drawSolidRectangle(squareSize / 4, squareSize / 4, lrsquare, WIDTH_INCREMENT, secondaryColor);
}

void drawWestUnit(double squareSize, Point llcorner, std::string color) {
	// 2.7 and 3.7 for top arrow
	// -0.5, 0.5 for bottom arrow
	Point sectorCenter(llcorner.get_x() + squareSize * 0.2, llcorner.get_y() + squareSize * 0.4);
	Point llcornerRect(llcorner.get_x() + squareSize * 0.4, llcorner.get_y() + squareSize * 0.36);
	drawSector(squareSize * 0.25, 1, 2, sectorCenter, 0.05, color);
	drawSolidRectangle(0.25 * squareSize, 0.1 * squareSize, llcornerRect, 0.05, color);
}

void drawEastUnit(double squareSize, Point llcorner, std::string color) {
	Point sectorCenter(llcorner.get_x() + squareSize * 0.7, llcorner.get_y() + squareSize * 0.4);
	Point llcornerRect(llcorner.get_x() + squareSize * 0.2, llcorner.get_y() + squareSize * 0.36);
	drawSector(squareSize * 0.25, 4.3,5.3, sectorCenter, 0.05, color);
	drawSolidRectangle(0.25 * squareSize, 0.1 * squareSize, llcornerRect, 0.05, color);
}

void drawNorthUnit(double squareSize, Point llcorner, std::string color) {
	Point sectorCenter(llcorner.get_x() + squareSize * 0.42, llcorner.get_y() + squareSize * 0.7);
	Point llcornerRect(llcorner.get_x() + squareSize * 0.35, llcorner.get_y() + squareSize * 0.25);
	drawSector(squareSize * 0.25, 2.7, 3.7, sectorCenter, 0.05, color);
	drawSolidRectangle(0.1 * squareSize, 0.25 * squareSize, llcornerRect, 0.05, color);
}

void drawSouthUnit(double squareSize, Point llcorner, std::string color) {
	Point sectorCenter(llcorner.get_x() + squareSize * 0.4, llcorner.get_y() + squareSize * 0.2);
	Point llcornerRect(llcorner.get_x() + squareSize * 0.35, llcorner.get_y() + squareSize * 0.45);
	drawSector(squareSize * 0.25, -0.5, 0.5, sectorCenter, 0.05, color);
	drawSolidRectangle(0.1 * squareSize, 0.25 * squareSize, llcornerRect, 0.05, color);
}

bool isSquareLoc(int num) {
	if (num == 2 || num == 15 || num == 19 || num == 20 || num == 24 || num == 25 || num == 26 || num == 28 || num == 29) {
		return false;
	} else if (num >= 0 && num < 30) {
		return true;
	} else {
		return false;
	}
}

