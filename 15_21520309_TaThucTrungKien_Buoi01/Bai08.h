#include <iostream>
using namespace std;

struct PhanSo
{
    int tu;
    int mau;
};
PhanSo nhapPS();
void nhapPS(PhanSo& x);//1
void xuatPS(PhanSo x);//2
int uocChungLN(int x, int y);
int rutGon(PhanSo& x);//3
int comparePhanSo(PhanSo x, PhanSo y);//4
PhanSo sum(PhanSo x, PhanSo y);//5
PhanSo difference(PhanSo x, PhanSo y);//6
PhanSo product(PhanSo x, PhanSo y);//7
PhanSo fraction(PhanSo x, PhanSo y);//8
