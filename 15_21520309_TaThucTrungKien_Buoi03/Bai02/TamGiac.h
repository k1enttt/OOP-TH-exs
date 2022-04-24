#include "ToaDo.h"

class TamGiac
{
private:
    ToaDo a;
    ToaDo b;
    ToaDo c;
public:
    TamGiac(){};
    TamGiac(float, float, float, float, float, float);
    void setA(float, float);
    ToaDo getA();
    void setB(float, float);
    ToaDo getB();
    void setC(float, float);
    ToaDo getC();
    //Nhập tam giác
    void nhap();
    //Xuất thông tin tam giác
    void xuat();
    //Tính độ dài cạnh
    float canh(ToaDo, ToaDo);
    //Xét loại tam giác
    int xetLoaiTG();
    //Tính chu vi
    float chuVi();
    //Tính diện tích
    double dienTich();
    //Tính tâm đường tròn ngoại tiếp tam giác
    ToaDo tamNgoaiTiepTG();
    //Tính tâm đường tròn nội tiếp tam giác
    ToaDo tamNoiTiepTG();
};