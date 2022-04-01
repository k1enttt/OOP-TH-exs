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
//ƯỚC CHUNG LỚN NHẤT
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
//RÚT GỌN
int rutGon(PhanSo& x)
{
    int uc = uocChungLN(x.tu, x.mau);
    x.tu = x.tu / uc;
    x.mau = x.mau / uc;
    return (uc == 1) ? 0 : 1;
}
//CỘNG 2 PHÂN SỐ
PhanSo sum(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.mau + y.tu * x.mau;
    t.mau = x.mau * y.mau;
    rutGon(t);
    return t;
}
//TRỪ 2 PHÂN SỐ
PhanSo difference(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.mau - y.tu * x.mau;
    t.mau = x.mau * y.mau;
    rutGon(t);
    return t;   
}
//NHÂN 2 PHÂN SỐ
PhanSo product(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.tu;
    t.mau = x.mau * y.mau;
    rutGon(t);
    return t; 
}
//CHIA 2 PHÂN SỐ
PhanSo fraction(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.mau;
    t.mau = x.mau * y.tu;
    rutGon(t);
    return t; 
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

    cout << "Tổng: ";
    xuat(sum(x, y));
    cout << endl;
    cout << "Hiệu: ";
    xuat(difference(x, y));
    cout << endl;
    cout << "Tích: ";
    xuat(product(x, y));
    cout << endl;
    cout << "Thương: ";
    xuat(fraction(x, y));
    cout << endl;

}