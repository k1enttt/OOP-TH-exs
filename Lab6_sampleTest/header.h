#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int d;
    int m;
    int y;
public:
    Date(int, int, int);
};

Date::Date(int d, int m, int y)
{
    this->d = d;
    this->m = m;
    this->y = y;
}

class NhanVien
{
private:
    int maNV;
    string hoTen;
    Date ngaySinh;
    double tongLuong;
public:
    NhanVien(int, string, int, int, int);
};

class QuanLy
{
private:
    int maNV;
    string hoTen;
    Date ngaySinh;
    
public:
    Quan(/* args */);
    ~Qua();
};

Quan::Quan(/* args */)
{
}

Quan::~Qua()
{
}



NhanVien::NhanVien(int maNV, string hoTen, int ngay, int thang, int nam) : ngaySinh{ngay, thang, nam}
{
    this->maNV = maNV;
    this->hoTen = hoTen;
}


