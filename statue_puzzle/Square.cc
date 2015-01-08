#include "Square.h"
#include <iostream>
#include "drawFunctions.h"

Square::Square() {
	this->color = "blue";
	this->isBuildable = false;
	this->isPath = false;
	this->isOccupied = false;
	this->location = Point(15, 15);
	this->isEndSquare = false;
	this->num = 0;
	this->neighborNorth = NULL;
	this->neighborSouth = NULL;
	this->neighborEast = NULL;
	this->neighborWest = NULL;
}

Square::Square(Point location, std::string color, bool isEndSquare, int num) {
	this->color = color;
	this->isBuildable = false;
	this->isPath = false;
	this->isOccupied = false;
	this->location = location;
	this->isEndSquare = isEndSquare;
	this->num = num;
	this->neighborNorth = NULL;
	this->neighborSouth = NULL;
	this->neighborEast = NULL;
	this->neighborWest = NULL;

}

Square::Square(std::string color, bool isBuildable, bool isPath, Point location) {
	this->color = color;
	this->isBuildable = isBuildable;
	this->isPath = isPath;
	this->isOccupied = false;
	this->location = location;
	this->num = 0;
	this->neighborNorth = NULL;
	this->neighborSouth = NULL;
	this->neighborEast = NULL;
	this->neighborWest = NULL;
}

void Square::draw(double size) {
	drawSolidRectangle(size, size, location, WIDTH_INCREMENT, color);

}

std::string Square::get_color() const {
	return color;
}

bool Square::get_buildable() const {
	return isBuildable;
}

bool Square::get_path() const {
	return isPath;
}

bool Square::get_occupied() const {
	return isOccupied;
}

Point Square::get_location() {
	return location;
}

int Square::get_num() {
	return num;
}

Square* Square::get_north_neighbor() {
	return neighborNorth;
}
Square* Square::get_south_neighbor() {
	return neighborSouth;
} 
Square* Square::get_east_neighbor() {
	return neighborEast;
}
Square* Square::get_west_neighbor() {
	return neighborWest;
}

void Square::set_color(std::string color) {
	this->color = color;
}

void Square::set_buildable(bool isBuildable) {
	this->isBuildable = isBuildable;
}

void Square::set_path(bool isPath) {
	this->isPath = isPath;
}

void Square::set_occupied(bool isOccupied) {
	this->isOccupied = isOccupied;
}

void Square::set_location(Point location) {
	this->location = location;
}

void Square::set_north_neighbor(Square* square) {
	neighborNorth = square;
}

void Square::set_south_neighbor(Square* square) {
	neighborSouth = square;
}

void Square::set_east_neighbor(Square* square) {
	neighborEast = square;
}

void Square::set_west_neighbor(Square* square) {
	neighborWest = square;
}
