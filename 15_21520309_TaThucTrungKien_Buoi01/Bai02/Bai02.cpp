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
    cin >> x.tu >> x.mau;
}

int uocChungLN(int x, int y)
{
    if (x < 0){
        x = abs(x);
    }
    if (y < 0){
        y = abs(y);
    }
    while (x * y != 0) {
        if (y > x) y %= x;
        else x %= y;
    }
    return x + y;
}

int rutGon(PhanSo& x)
{
    int uc = uocChungLN(x.tu, x.mau);
    x.tu = x.tu / uc;
    x.mau = x.mau / uc;
    return (uc == 1) ? 0 : 1;
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
    PhanSo x;
    cout << "Nhập tử, mẫu của phân số: \n";
    nhap(x);
    rutGon(x);
    xuat(x);
}