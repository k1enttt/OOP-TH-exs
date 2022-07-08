
#include "PhanSo.h"

class HonSo: public PhanSo
{
private:
    int nguyen;
public:
    HonSo(){};
    HonSo(int n, int t, int m);
    HonSo(PhanSo a);
    void setNguyen(int);
    int getNguyen();
    
    //Nhập hỗn số thủ công
    void nhapHonSo();
    
    //Nhập hỗn số theo phương pháp tự động
    HonSo randomHonSo();
    
    //Xuất hỗn số
    void xuatHonSo();
    
    //Chuyển hỗn số thành phân số
    PhanSo chuyen(HonSo);

    //Chuyển phân số thành hỗn số
    HonSo chuyen(PhanSo);

    //Thực hiện các phép toán (overload)
    HonSo operator+ (HonSo a);

    HonSo operator- (HonSo a);

    HonSo operator* (HonSo a);

    HonSo operator/ (HonSo a);

    bool operator== (HonSo a);

    bool operator!= (HonSo a);

    bool operator> (HonSo a);

    bool operator< (HonSo a);

    friend ostream& operator<< (ostream& os, HonSo a);
    friend istream& operator>> (istream& is, HonSo& a);
};

HonSo::HonSo(int n, int t, int m): PhanSo(t, m)
{
    nguyen = n;
}
HonSo::HonSo(PhanSo a)
{
    int n = abs(a.getTu()) / a.getMau();
    int tu = a.getTu() - n * a.getMau();
    if (a.getTu() < 0)
        nguyen = -n;
    else nguyen = n;
    setTu(a.getTu());
    setMau(a.getMau());
}
void HonSo::setNguyen(int n)
{
    nguyen = n;
}
int HonSo::getNguyen()
{
    return nguyen;
}
//Nhập hỗn số thủ công
void HonSo::nhapHonSo()
{
    int t, m;    
    cout << "Nhập phần nguyên: ";
    cin >> nguyen;
    cout << endl;
    cout << "Nhập tử: ";
    cin >> t;
    cout << endl;
    cout << "Nhập mẫu: ";
    cin >> m;
    cout << endl;
    setTu(t);
    setMau(m);
}
//Nhập hỗn số theo phương pháp tự động
HonSo HonSo::randomHonSo()
{
    HonSo x;
    x.setNguyen(randomInt(1, 9));
    x.setTu(randomInt(1, 9));
    x.setMau(randomInt(1, 9));
    return x;
}
//Xuất hỗn số
void HonSo::xuatHonSo()
{
    cout << nguyen << "|";
    xuatPS();
}
//Chuyễn hỗn số thành phân số
PhanSo HonSo::chuyen(HonSo x)
{
    PhanSo t(x.getNguyen() * x.getMau() + x.getTu(), x.getMau());
    return t;
}   
//Chuyển phân số thành hỗn số
HonSo HonSo::chuyen(PhanSo x)
{
    int n = x.getTu() / x.getMau();
    int tu = x.getTu() - n * x.getMau();
    HonSo t(n, tu, x.getMau());
    return t;
}

HonSo HonSo::operator+ (HonSo a)
{
    PhanSo m = chuyen(HonSo(nguyen, getTu(), getMau()));
    PhanSo n = chuyen(a);
    HonSo t (m + n);
    return t;
    // int tu, mau;
    // tu = (nguyen * getMau() + getTu()) * a.getMau() + (a.nguyen * a.getMau() + a.getTu()) * getMau();
    // mau = getMau() * a.getMau();
    // HonSo t = this->chuyen(PhanSo(tu, mau));
    // return t;
}

HonSo HonSo::operator- (HonSo a)
{
    PhanSo m = chuyen(HonSo(nguyen, getTu(), getMau()));
    PhanSo n = chuyen(a);
    HonSo t (m - n);
    return t;
    // int tu, mau;
    // tu = (nguyen * getMau() + getTu()) * a.getMau() - (a.nguyen * a.getMau() + a.getTu()) * getMau();
    // mau = getMau() * a.getMau();
    // HonSo t = this->chuyen(PhanSo(tu, mau));
    // return t;
}

HonSo HonSo::operator* (HonSo a)
{
    PhanSo m = chuyen(HonSo(nguyen, getTu(), getMau()));
    PhanSo n = chuyen(a);
    HonSo t (m * n);
    return t;
    // int tu, mau;
    // tu = (nguyen * getMau() + getTu()) * (a.nguyen * a.getMau() + a.getTu());
    // mau = getMau() * a.getMau();
    // HonSo t = this->chuyen(PhanSo(tu, mau));
    // return t;
}

HonSo HonSo::operator/ (HonSo a)
{
    PhanSo m = chuyen(HonSo(nguyen, getTu(), getMau()));
    PhanSo n = chuyen(a);
    HonSo t (m / n);
    return t;
}

bool HonSo::operator== (HonSo a)
{
    PhanSo x = chuyen(a);
    PhanSo y = chuyen(HonSo(nguyen, getTu(), getMau()));
    return x == y;
}

bool HonSo::operator> (HonSo a)
{
    PhanSo x = chuyen(a);
    PhanSo y = chuyen(HonSo(nguyen, getTu(), getMau()));
    return y > x;
}

bool HonSo::operator< (HonSo a)
{
    PhanSo x = chuyen(a);
    PhanSo y = chuyen(HonSo(nguyen, getTu(), getMau()));
    return y < x;
}

ostream& operator<< (ostream& os, HonSo a)
{
    os << a.getNguyen() << "|" << a.getTu() << "/" << a.getMau();
    return os;
}
istream& operator>> (istream& is, HonSo& a)
{
    int t, m;
    is >> a.nguyen >> t >> m;
    a.setTu(t);
    a.setMau(m);
    return is;
}