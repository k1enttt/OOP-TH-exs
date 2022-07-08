#include <iostream>

using namespace std;

struct PS
{
    int tu;
    int mau;
};
typedef struct PS PhanSo;

void nhap(PhanSo& x)
{
    cout << "Nhập tử, mẫu: \n";
    cin >> x.tu >> x.mau;
}
PhanSo psMax(PhanSo x, PhanSo y)
{
    int t = (x.tu / x.mau) - (y.tu / y.mau);
    return (t >= 0) ? x : y; 
}
void xuat(PhanSo x)
{
    //Tử hoặc mẫu = 0
    if ((x.tu == 0) || (x.mau == 0)) 
        cout << 0;
    //Tử = mẫu
    else if (x.tu == x.mau) 
        cout << 1;
    //Mẫu = 1, triệt tiêu mẫu
    else if (x.mau == 1)
        cout << x.tu;
    //Tử dương, mẫu âm
    else if (x.tu > 0 && x.mau < 0)
        cout << -x.tu << "/" << x.mau;
    //Tử âm, mẫu âm
    else if (x.tu < 0 && x.mau < 0)
        cout << -x.tu << "/" << -x.mau;
    else
        cout << x.tu << "/" << x.mau;
}
int main()
{
    PhanSo x, y;
    cout << "Phân số 1: \n";
    nhap(x);
    cout << "Phân số 2: \n";
    nhap(y);
    cout << "Phân số lớn nhất là: ";
    xuat(psMax(x, y));
}