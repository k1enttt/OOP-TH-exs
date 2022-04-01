#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;
public:
    PhanSo(){}
    PhanSo(int tu, int mau);
    void nhapPS();
    void xuatPS();
    int ucln();
    void rutGon();
    PhanSo congPS(PhanSo a);
    PhanSo truPS(PhanSo a);
    PhanSo nhanPS(PhanSo a);
    PhanSo chiaPS(PhanSo a); 
    void nhanPS(PhanSo a, PhanSo b);
};

PhanSo::PhanSo(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau;
}

void PhanSo::nhapPS()
{
    cout << "Nhập phân số:\n";
    cin >> this->tu;
    cin >> this->mau;
}
void PhanSo::xuatPS()
{
    //Tu = 0;
    //Mau = 0;
    //Mau = 1;
    //Tu = mau;
    //tu > 0, mau < 0;
    //tu < 0, mau < 0;
    if (tu == 0 || mau == 0)
        cout << 0;
    else if (mau == 1)
        cout << tu;
    else if (tu == mau)
        cout << 1;
    else if ((tu > 0 && mau < 0) || (tu < 0 && mau < 0))
        cout << -tu << "/" << -mau;
    else
        cout << tu << "/" << mau;
    cout << endl;
}
int PhanSo::ucln()
{
    int t = tu, m = mau;
    if (t < 0) t = -t;
    if (m < 0) m = -m;
    while (t * m != 0)
    {
        if (t > m)
            t %= m;
        else 
            m %= t;
    }
    return t + m;
}
void PhanSo::rutGon()
{
    int uc = ucln();
    tu /= uc;
    mau /= uc;
}
PhanSo PhanSo::congPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau + a.tu * mau;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::truPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau - a.tu * mau;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::nhanPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.tu;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::chiaPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau;
    t.mau = mau * a.tu;
    t.rutGon();
    return t;
}
void PhanSo::nhanPS(PhanSo a, PhanSo b)
{
    tu = a.tu * b.tu;
    mau = a.mau * b.mau;
    rutGon();
}

int main()
{
    PhanSo ps(2, 4), ps1(4, 12), ps2(10, -2), ps3;
    ps.rutGon();
    ps.xuatPS();

    //Cộng, trừ, nhân, chia ps1 và ps2
    cout << "Phân số 1: ";
    ps1.xuatPS();
    cout << "Phân số 2: ";
    ps2.xuatPS();

    ps1.congPS(ps2).xuatPS();
    ps1.truPS(ps2).xuatPS();
    ps1.nhanPS(ps2).xuatPS();
    ps3.nhanPS(ps1, ps2);
    ps3.xuatPS();
    ps1.chiaPS(ps2).xuatPS();
    return 0;
}