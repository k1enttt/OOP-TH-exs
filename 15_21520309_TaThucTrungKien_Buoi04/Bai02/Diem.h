#include <iostream>
#include <math.h>
using namespace std;

class Diem
{
private:
    float x;
    float y;
public:
    Diem(){};
    Diem(float, float);
    void setX(float);
    float getX();
    void setY(float);
    float getY();
    void xuatD();
    double khoangCach(Diem);
};
void Diem::setX(float xx)
{
    x = xx;
}
float Diem::getX()
{
    return x;
}
void Diem::setY(float yy)
{
    y = yy;
}
float Diem::getY()
{
    return y;
}
void Diem::xuatD()
{
    cout << "(" << x << ", " << y << ")";
}
double Diem::khoangCach(Diem a)
{
    return sqrt((a.getX() - getX()) * (a.getX() - getX()) + (a.getY() - getY()) * (a.getY() - getY()));
}