#include <vector>
#include "Point.cpp"

class PolyLine
{
private:
    vector<Point> point;
public:
    PolyLine(){};
    PolyLine(vector<Point>);
    void appendPoint(Point);
    void appendPoint(int, int);
    double getLength();
};

PolyLine::PolyLine(vector<Point> points)
{
    point = points;
}
void PolyLine::appendPoint(Point a)
{
    point.push_back(a);
}
void PolyLine::appendPoint(int x, int y)
{
    Point a(x, y);
    point.push_back(a);
}
double PolyLine::getLength()
{
    double length = 0;
    for (vector<Point>::iterator /*auto*/ i = point.begin(); i != point.end() - 1; i++)
    {
        // length += ;
    }
}