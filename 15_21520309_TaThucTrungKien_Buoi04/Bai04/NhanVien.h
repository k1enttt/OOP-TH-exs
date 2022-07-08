#include <iostream>
using namespace std;

class NhanVien
{
private:
    string maNV;
    string hoTen;
    int luong;
public:
    NhanVien(){};
    NhanVien(string, string, int);
    void setMaNV(string);
    void setHoTen(string);
    void setLuong(int);
    string getMaNV();
    string getHoTen();
    int setLuong();
};

NhanVien::NhanVien(string m, string ht, int l)
{
    maNV = m;
    hoTen = ht;
    luong = l;
}

void NhanVien::setMaNV(string x)
{
    maNV = x;
}
void NhanVien::setHoTen(string x)
{
    hoTen = x;
}
void NhanVien::setLuong(int x)
{
    luong = x;
}
string NhanVien::getMaNV()
{
    return maNV;    
}
string NhanVien::getHoTen()
{
    return hoTen;
}
int NhanVien::setLuong()
{
    return luong;
}