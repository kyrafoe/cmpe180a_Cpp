#ifndef _XYPOINT_H_
#define _XYPOINT_H_

class XYPoint{

public:
    XYPoint();
    XYPoint(double x, double y);
    ~XYPoint();

    //Getters
    double getX() const;
    double getY() const;

    //Setters
    void setX(double x);
    void setY(double y);

    double distance() const;
    double distance(const XYPoint& xypoint) const;


private:
    double x;
    double y;

};

#endif
