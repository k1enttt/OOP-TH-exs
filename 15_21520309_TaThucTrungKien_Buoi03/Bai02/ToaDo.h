#include <iostream>
using namespace std;

class ToaDo
{
private:
    float x;
    float y;
public:
    ToaDo(){};
    ToaDo(float, float);
    void setX(float);
    float getX();
    void setY(float);
    float getY();
    void xuat();
};