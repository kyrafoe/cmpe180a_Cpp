#include "XYPoint.h"
#include <cmath>
#include <iostream>

// Default constructor
XYPoint::XYPoint()
{
    x = 0;
    y = 0;
}

// Parametrized constructor
XYPoint::XYPoint(double x1, double y1)
{
    x = x1;
    y = y1;
}

// Getter functions
double XYPoint::getX() const
{
    return x;
}

double XYPoint::getY() const
{
    return y;
}

// Setter functions
void XYPoint::setX(double x1)
{
    x = x1;
}

void XYPoint::setY(double y1)
{
    y = y1;
}

// Member function to calculate points distance to origin
double XYPoint::distance() const
{
    //c²= a² +b²
    return std::sqrt(x*x + y*y);
}

// Member function to calculate distance between two points
double XYPoint::distance(const XYPoint& xypoint) const
{
    // Get y between two points
    double diff_y;
    double otherY = xypoint.getY();
    diff_y = std::max(y,otherY) - std::min(y,otherY);
    
    // Get x between two points
    double diff_x;
    double otherX = xypoint.getX();
    diff_y = std::max(x,otherX) - std::min(x,otherX);

    return std::sqrt(diff_x*diff_x + diff_y*diff_y);
}

// Destructor
XYPoint::~XYPoint()
{
    x = 0;
    y = 0;
}

