#include <iostream>
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