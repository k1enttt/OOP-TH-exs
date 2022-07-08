#include <iostream>

using namespace std;

class CaSy
{
protected:
    string hoTen;
    int namLamViec;
    int soDiaBanDuoc;
    int soBuoiLamViec;
    float luong;
public:
    virtual void nhap();
    virtual void tinhLuong();
    float getLuong();
};

class ChuaNoiTieng : public CaSy
{
public:
    void nhap();
    void tinhLuong();
};

class NoiTieng : public CaSy
{
private:
    int soGameshow;
public:
    void nhap();
    void tinhLuong();
};

class QuanLy
{
private:
    CaSy * danhSachCaSy;
public:
    void nhapDS();
    CaSy timCaSyLuongCaoNhat();  
};

