#include "ToaDo.h"

ToaDo::ToaDo(int hoanhdo, int tungdo)
{
    this->hoanhdo = hoanhdo;
    this->tungdo = tungdo;
}
void ToaDo::nhap()
{
    cout << "Nhập tọa độ:\n";
    cin >> hoanhdo >> tungdo;
}
void ToaDo::xuat()
{
    cout << "(" << hoanhdo << ", " << tungdo << ")";
}
int ToaDo::getHoanhDo()
{
    return hoanhdo;
}
void ToaDo::setHoanhDo(int hoanhdo)
{
    this->hoanhdo = hoanhdo;
}
int ToaDo::getTungDo()
{
    return tungdo;
}
void ToaDo::setTungDo(int tungdo)
{
    this->tungdo = tungdo;
}
ToaDo midPoint(ToaDo a, ToaDo b)
{
    ToaDo x;
    x.setHoanhDo( (a.getHoanhDo() + b.getHoanhDo()) / 2 );
}

int main()
{
    
}