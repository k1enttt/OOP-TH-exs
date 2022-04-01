#include <iostream>
#include "Diem.h"
using namespace std;
class TamGiac
{
private:
    Diem mot;
    Diem hai;
    Diem ba;
public:
    TamGiac(){};
    TamGiac(Diem, Diem, Diem);
    void setMot(Diem);
    Diem getMot();
    void setHai(Diem);
    Diem getHai();
    void setBa(Diem ba);
    Diem getBa();
    void nhapTG();
    void xuatTG();
    float doDaiCanh(Diem, Diem);
    int xepLoaiTamGiac();
    float chuVi();
    float dienTich();
};