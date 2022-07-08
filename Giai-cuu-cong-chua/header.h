#pragma once
#include <iostream>
using namespace std;
/*
100 9 10
90 9 10
90 9 10
90 9 6
90 9 6
*/
class HoangTu
{
private:
    int tien;
    int triTue;
    int sucManh;
public:
    HoangTu(){};
    HoangTu(int, int, int);
    void nhap();
    void xuat();
    int getTien();
    void setTien(int);
    int getTriTue();
    void setTriTue(int);
    int getSucManh();
    void setSucManh(int);
};   

class Cong
{
protected:
    int loai;
public:
    virtual void nhap(){};
    virtual bool Confirm(HoangTu&) = 0;
};

class Business: public Cong
{
private:
    int cost;
    int amount;
public:
    Business(){};
    Business(int, int);
    void nhap();
    bool Confirm(HoangTu&);
};

class Academic: public Cong
{
private:
    int iq;
public:
    Academic(){};
    Academic(int);
    void nhap();
    bool Confirm(HoangTu&);
};

class Power: public Cong
{
private:
    int strength;
public:
    Power(){};
    Power(int);
    void nhap();
    bool Confirm(HoangTu&);
};

//////////////////////////////////////////////////////////

HoangTu::HoangTu(int tien, int triTue, int sucManh)
{
    this->tien = tien;
    this->triTue = triTue;
    this->sucManh = sucManh;
}
void HoangTu::nhap()
{
    cin >> tien >> triTue >> sucManh;
}
void HoangTu::xuat()
{
    cout << tien << " " << triTue << " " << sucManh << endl;
}
int HoangTu::getTien()
{
    return tien;
}
void HoangTu::setTien(int tien)
{
    this->tien = tien;
}
int HoangTu::getTriTue()
{
    return triTue;
}
void HoangTu::setTriTue(int triTue)
{
    this->triTue = triTue;
}
int HoangTu::getSucManh()
{
    return sucManh;
}
void HoangTu::setSucManh(int sucManh)
{
    this->sucManh = sucManh;
}

//-------------------------------------------

Business::Business(int cost, int amount)
{
    this->cost = cost;
    this->amount = amount;
}

void Business::nhap()
{
    cin >> cost >> amount;
}

bool Business::Confirm(HoangTu& a)
{
    if (a.getTien() >= cost * amount)
    {
        a.setTien(a.getTien() - cost * amount);
        return true;
    }
    return false;
}

//-------------------------------------------

Academic::Academic(int iq)
{
    this->iq = iq;
}

void Academic::nhap()
{
    cin >> iq;
}

bool Academic::Confirm(HoangTu& a)
{
    if (a.getTriTue() >= iq)
        return true;
    return false;
}

//-------------------------------------------

Power::Power(int strength)
{
    this->strength = strength;
}

void Power::nhap()
{
    cin >> strength;
}

bool Power::Confirm(HoangTu& a)
{
    if (a.getSucManh() >= strength)
    {
        a.setSucManh(a.getSucManh() - strength);
        return true;
    }
    return false;
}

