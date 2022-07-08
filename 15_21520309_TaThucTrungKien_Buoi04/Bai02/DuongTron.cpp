#include "Diem.h"

class DuongTron: public Diem
{
private:
    float r;
public:
    DuongTron(){};
    DuongTron(float, float, float);
    void setR(float);
    float getR();
    void xuatDT();
    double chuVi();
    double dienTich();
    int checkStatus(DuongTron);
};

DuongTron::DuongTron(float rr, float xx, float yy): Diem(xx, yy)
{
    r = rr;
}
void DuongTron::xuatDT()
{
    cout << "Đường tròn có tâm ";
    xuatD();
    cout << ", bán kính r = " << r;
}
void DuongTron::setR(float rr)
{
    r = rr;
}
float DuongTron::getR()
{
    return r;
}
double DuongTron::chuVi()
{
    return 3.14 * 2 * r;
}
double DuongTron::dienTich()
{
    return 3.14 * r * r;
}
int DuongTron::checkStatus(DuongTron x)
{
    //1. Giao
    //2. Tiếp xúc
    //3. Không giao
    int kcTam, kcR, d;
    kcTam = khoangCach(x);
    kcR = r + x.getR();

    d = kcR - kcTam;
    if (d < 0)
    {
        return 1;
    }
    else if (d == 0)
    {
        return 2;
    }
    else 
    {
        return 3;
    }
}
