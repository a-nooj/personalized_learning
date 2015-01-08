#include <cstdio>

#include "ccc_shap.h"

Point::Point()
{  
   x = 0.0;
   y = 0.0;
   color = "black";
}

Point::Point(double x1, double y1)
{  
   x = x1;
   y = y1;
   color = "black";
}


Point::Point(double x1, double y1, string color1)
{  
   x = x1;
   y = y1;
   color = color1;
}

double Point::get_x() const
{  
   return x;
}

double Point::get_y() const
{  
   return y;
}

string Point::get_color() const
{  
   return color;
}

void Point::move(double dx, double dy)
{  
   x += dx;
   y += dy;
}

/*-------------------------------------------------------------------------*/

Circle::Circle()
{  
   radius = 0.0;
   color = "#000000";
}

Circle::Circle(Point p, double r)
{  
   center = p;
   radius = r;
   color = "#000000";
}

Circle::Circle(Point p, double r, string color1)
{  
   center = p;
   radius = r;
   color = color1;
}

Point Circle::get_center() const
{  
   return center;
}

double Circle::get_radius() const
{  
   return radius;
}

string Circle::get_color() const
{  
   return color;
}

void Circle::move(double dx, double dy)
{  
   center.move(dx, dy);
}

/*-------------------------------------------------------------------------*/

Line::Line()
{
   color = "#000000";
}

Line::Line(Point p1, Point p2)
{  
   from = p1;
   to = p2;
   color = "#000000";
}

Line::Line(Point p1, Point p2, string color1)
{  
   from = p1;
   to = p2;
   color = color1;
}

Point Line::get_start() const
{  
   return from;
}

Point Line::get_end() const
{  
   return to;
}

string Line::get_color() const
{  
   return color;
}

void Line::move(double dx, double dy)
{  
   from.move(dx, dy);
   to.move(dx, dy);
}

/*-------------------------------------------------------------------------*/

Message::Message()
{
   color = "#000000";
}

Message::Message(Point s, const string& m)
{  
   start = s;
   text = m;
   color = "#000000";
}

Message::Message(Point s, const string& m, string color1)
{  
   start = s;
   text = m;
   color = color1;
}

Message::Message(Point s, double x)
{  
   start = s;
   char buf[20];
   sprintf(buf, "%g", x);
   text = buf;
   color = "#000000";
}

Message::Message(Point s, double x, string color1)
{  
   start = s;
   char buf[20];
   sprintf(buf, "%g", x);
   text = buf;
   color = color1;
}

Point Message::get_start() const
{  
   return start;
}

string Message::get_text() const
{  
   return text;
}

string Message::get_color() const
{  
   return color;
}

void Message::move(double dx, double dy)
{  
   start.move(dx, dy);
}

