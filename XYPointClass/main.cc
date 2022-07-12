#include "XYPoint.h"
#include <iostream>

int main()
{
    XYPoint MyPoint(5.5, 6.6);

    XYPoint MySecPoint(9.6,7.0);

    std::cout << MyPoint.distance()<<"\n";

    std::cout << MyPoint.distance(MySecPoint)<<"\n";

    const XYPoint MyconstPoint;


    return 0;
} 
