#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <random>
using namespace std;

class NhanVien
{
protected:
    int maNV;
    string hoTen;
    int luongCB;
    int luong;
public:
    NhanVien(){};
    NhanVien(int, string, int);
    virtual void nhap() = 0;
    virtual void nhapRandom() = 0;
    void setMaNV(int);
    int getMaNV();
    void setHoTen(string);
    string getHoTen();
    void setLuongCB(int);
    int getLuongCB();
    void setLuong(int);
    int getLuong();
    virtual void tinhLuong() = 0;
    virtual int getSoSP() = 0;
    virtual void xuat() = 0;

    friend int randomInt(int, int);
    friend string randomStr();
};

//Nhân viên sản xuất
class NVSX : public NhanVien
{
private:
    int soSP;
public:
    NVSX(){};
    NVSX(int, string, int);
    void tinhLuong();
    void nhap();
    void setSoSP(int);
    int getSoSP();
    void nhapRandom();
    void xuat();
};

//Nhân viên văn phòng
class NVVP: public NhanVien
{
private:
    int soNgayLam;
public:
    NVVP(){};   
    NVVP(int, string, int);
    void tinhLuong();
    void nhap();
    void setSoNgayLam(int);
    int getSoNgayLam();
    void nhapRandom();
    int getSoSP();
    void xuat();
};

////////////////////////////////////////////////////////////////////////

NhanVien::NhanVien(int maNV, string hoTen, int luongCB)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->luongCB = luongCB;
}
void NhanVien::setMaNV(int maNV)
{
    this->maNV = maNV;
}
int NhanVien::getMaNV()
{
    return maNV;
}
void NhanVien::setHoTen(string hoTen)
{
    this->hoTen = hoTen;
}
string NhanVien::getHoTen()
{
    return hoTen;
}
void NhanVien::setLuongCB(int luongCB)
{
    this->luongCB = luongCB;
}
int NhanVien::getLuongCB()
{
    return luongCB;
}
void NhanVien::setLuong(int luong)
{
    this->luong = luong;
}
int NhanVien::getLuong()
{
    return luong;
}
int randomInt(int min, int max)
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
string randomStr()
{
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz0123456789");
    random_device rd;
    mt19937 generator(rd());

    shuffle(str.begin(), str.end(), generator);

    // char* s;
    string temp = str.substr(0, 5);
    return temp;
}
//------------------------------------------------------------
NVSX::NVSX(int maNV, string hoTen, int soSP)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->soSP = soSP;
}
void NVSX::tinhLuong()
{
    setLuong(luongCB + soSP * 170000);
}
void NVSX::nhap()
{
    cout << "Mã nhân viên:\n";
    cin >> maNV;
    cin.ignore();
    cout << "Họ tên:\n";
    cin >> hoTen;
    luongCB = 5300000;
    cout << "Số sản phẩm:\n";
    cin >> soSP;
}
void NVSX::setSoSP(int soSP)
{
    this->soSP = soSP;
}
int NVSX::getSoSP()
{
    return soSP;
}
void NVSX::nhapRandom()
{
    this->maNV = randomInt(10, 99);
    this->hoTen = randomStr();
    this->luongCB = 5300000;
    this->soSP = randomInt(1, 9);
}
void NVSX::xuat()
{
    cout << maNV << "\t" << hoTen << "\tnvsx\t" << luongCB << "\t"<< luong << endl;
}
//---------------------------------------------------
NVVP::NVVP(int maNV, string hoTen, int soNgayLam)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->soNgayLam = soNgayLam;
}
void NVVP::tinhLuong()
{
    setLuong(luongCB + soNgayLam * 220000);
}
void NVVP::nhap()
{
    cout << "Mã nhân viên:\n";
    cin >> maNV;
    cin.ignore();
    cout << "Họ tên:\n";
    cin >> hoTen;
    luongCB = 4500000;
    cout << "Số sản phẩm:\n";
    cin >> soNgayLam;
}
void NVVP::setSoNgayLam(int soNgayLam)
{
    this->soNgayLam = soNgayLam;
}
int NVVP::getSoNgayLam()
{
    return soNgayLam;
}
void NVVP::nhapRandom()
{
    this->maNV = randomInt(10, 99);
    this->hoTen = randomStr();
    this->luongCB = 5300000;
    this->soNgayLam = randomInt(1, 9);
}
int NVVP::getSoSP()
{
    return -1;
}
void NVVP::xuat()
{
    cout << maNV << "\t" << hoTen << "\tnvvp\t" << luongCB << "\t"<< luong << endl;
}