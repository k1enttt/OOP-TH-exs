#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(){};
    Point(int, int);
    void setX(int);
    int getX();
    void setY(int);
    int getY();
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point::setX(int x)
{
    this->x = x;
}
int Point::getX()
{
    return x;
}
void Point::setY(int)
{
    this->y = y;
}
int Point::getY()
{
    return y;
}