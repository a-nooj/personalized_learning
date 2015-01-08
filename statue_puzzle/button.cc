#include "button.h"

Button::Button() {
	llcorner = Point(0,0);
	width = 0;
	height = 0;
	text = "";
	color = "black";
	textPos = Point(0,0);
}

Button::Button(Point llcorner, double height, std::string text, std::string color) {
	this->llcorner = llcorner;
	this->width = CHAR_WIDTH * text.size();
	this->height = height;
	this->text = text;
	this->color = color;
	this->textPos = Point(llcorner.get_x(), llcorner.get_y() + height * 5.0 / 6);
}

//determines if Point p is inside the button
bool Button::inRange(Point p) {
	double xMin = llcorner.get_x();
	double yMin = llcorner.get_y();
	double xMax = xMin + width;
	double yMax = yMin + height;
	if ((p.get_x() < xMax && p.get_x() > xMin) && (p.get_y() < yMax && p.get_y() > yMin)) {
		return true;
	}
	return false;
}

std::string Button::getColor() const {
	return color;
}

double Button::getWidth() const {
	return width;
}

Point Button::getLLcorner() const {
	return llcorner;
}

Point Button::getTextPos() const {
	return textPos;
}

std::string Button::getText() const {
	return text;
}

void Button::setWidth(double width) {
	this->width = width;
}

void Button::setHeight(double height) {
	this->height = height;
}

void Button::setText(std::string text) {
	this->text = text;
}

void Button::setTextPos(Point textPos) {
	this->textPos = textPos;
}

void Button::draw() {
	drawSolidRectangle(width, height, llcorner, WIDTH_INCREMENT, color);
	cwin << Message(textPos, text);
}


