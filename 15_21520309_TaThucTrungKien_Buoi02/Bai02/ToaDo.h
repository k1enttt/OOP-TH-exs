#include <iostream>
using namespace std;

class ToaDo
{
private:
    float hoanhdo;
    float tungdo;
public:
    ToaDo(){};
    ToaDo(int hoanhdo, int tungdo);
    void nhap();
    void xuat();
    int getHoanhDo();
    void setHoanhDo(int hoanhdo);
    int getTungDo();
    void setTungDo(int tungdo);
    ToaDo midPoint(ToaDo a, ToaDo b);
};

