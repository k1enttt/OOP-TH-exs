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
    ToaDo nhap();
    void xuat();
    int getHoanhDo();
    void setHoanhDo(int hoanhdo);
    int getTungDo();
    void setTungDo(int tungdo);
    float distance(int hoanh, int tung);
    ToaDo midPoint(ToaDo a, ToaDo b);
};

