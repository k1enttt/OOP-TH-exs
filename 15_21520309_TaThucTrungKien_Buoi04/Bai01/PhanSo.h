#include <iostream>
#include <random>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;
public:
    PhanSo(){}
    PhanSo(int tu);
    PhanSo(int tu, int mau);
    // PhanSo(HonSo a);
    int getTu();
    int getMau();
    void setTu(int tu);
    void setMau(int mau);
    //Nhập thủ công
    void nhapPS();
    //Random tử, mẫu
    int randomInt(int min, int max);
    //Nhập tự động phân số
    void randomPhanSo();
    //Xuất
    void xuatPS();
    int ucln();
    int rutGon();
    PhanSo congPS(PhanSo a);
    PhanSo truPS(PhanSo a);
    PhanSo nhanPS(PhanSo a);
    PhanSo chiaPS(PhanSo a); 

    PhanSo operator+ (PhanSo a);
    PhanSo operator+ (int a);
    friend PhanSo operator+ (int a, PhanSo b);

    PhanSo operator- (PhanSo a);
    PhanSo operator- (int a);
    friend PhanSo operator- (int a, PhanSo b);

    PhanSo operator* (PhanSo a);
    PhanSo operator* (int a);
    friend PhanSo operator* (int a, PhanSo b);

    PhanSo operator/ (PhanSo a);
    PhanSo operator/ (int a);
    friend PhanSo operator/ (int a, PhanSo b);

    bool operator== (PhanSo a);
    bool operator== (int a);
    friend bool operator== (int a, PhanSo b);

    bool operator!= (PhanSo a);
    bool operator!= (int a);
    friend bool operator!= (int a, PhanSo b);

    bool operator> (PhanSo a);
    bool operator> (int a);
    friend bool operator> (int a, PhanSo b);

    bool operator< (PhanSo a);
    bool operator< (int a);
    friend bool operator< (int a, PhanSo b);

    friend ostream& operator<< (ostream& os, PhanSo& a);
    friend istream& operator>> (istream& is, PhanSo& a);
};

PhanSo::PhanSo(int tu)
{
    this->tu = tu;
    this->mau = 1;
}
PhanSo::PhanSo(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau;
}
int PhanSo::getTu()
{
    return tu;
}
int PhanSo::getMau()
{
    return mau;
}
void PhanSo::setTu(int tu)
{
    this->tu = tu;
}
void PhanSo::setMau(int mau)
{
    this->mau = mau;
}
void PhanSo::nhapPS()
{
    // int tu, mau;
    cout << "Nhập phân số:\n";
    cin >> this->tu;
    cin >> this->mau;
    // setTu(tu);
    // setMau(mau);
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
int PhanSo::rutGon()
{
    int uc = ucln();
    if (uc == 1)
        return 0;
    tu /= uc;
    mau /= uc;
    return 1;
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
int PhanSo::randomInt(int min, int max)
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}
void PhanSo::randomPhanSo()
{
    setTu(randomInt(-50, 50));
    setMau(randomInt(-50, 50));
}

PhanSo PhanSo::operator+ (PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau + a.tu * mau;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::operator+ (int a)
{
    PhanSo t;
    t.tu = tu + a * mau;
    t.mau = mau;
    t.rutGon();
    return t;
}
PhanSo operator+ (int a, PhanSo b)
{
    PhanSo t;
    t.tu = b.tu + a * b.mau;
    t.mau = b.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::operator- (PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau - a.tu * mau;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::operator- (int a)
{
    PhanSo t;
    t.tu = tu - a * mau;
    t.mau = mau;
    t.rutGon();
    return t;
}
PhanSo operator- (int a, PhanSo b)
{
    PhanSo t;
    t.tu = b.tu - a * b.mau;
    t.mau = b.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::operator* (PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.tu;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::operator* (int a)
{
    PhanSo t;
    t.tu = tu * a;
    t.mau = mau;
    t.rutGon();
    return t;
}
PhanSo operator* (int a, PhanSo b)
{
    PhanSo t;
    t.tu = b.tu * a;
    t.mau = b.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::operator/ (PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau;
    t.mau = mau * a.tu;
    t.rutGon();
    return t;
}
PhanSo PhanSo::operator/ (int a)
{
    PhanSo t;
    t.tu = tu;
    t.mau = mau * a;
    t.rutGon();
    return t;
}
PhanSo operator/ (int a, PhanSo b)
{
    PhanSo t;
    t.tu = b.tu;
    t.mau = b.mau * a;
    t.rutGon();
    return t;
}
bool PhanSo::operator== (PhanSo a)
{
    return (tu == a.tu && mau == a.mau);
}
bool PhanSo::operator== (int a)
{
    return (tu == a && mau == 1);
}
bool operator== (int a, PhanSo b)
{
    return (b.tu == a && b.mau == 1);
}

bool PhanSo::operator!= (PhanSo a)
{
    return !(tu == a.tu && mau == a.mau);
}
bool PhanSo::operator!= (int a)
{
    return !(tu == a && mau == 1);
}
bool operator!= (int a, PhanSo b)
{
    return !(b.tu == a && b.mau == 1);
}
bool PhanSo::operator> (PhanSo a)
{
    int t = tu * a.mau - a.tu * mau;
    return t > 0;
}
bool PhanSo::operator< (PhanSo a)
{
    int t = tu * a.mau - a.tu * mau;
    return t < 0;
}
ostream& operator<< (ostream& os, PhanSo& a)
{
    os << a.tu << "/" << a.mau;
    return os;
}
istream& operator>> (istream& is, PhanSo& a)
{
    is >> a.tu >> a.mau;
    return is;
}