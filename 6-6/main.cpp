#include <iostream>
using namespace std;
class cNgay
{
private:
    int ngay;
    int thang;
    int nam;
public:
    cNgay();
    cNgay(int year, int month);
    cNgay(int year, int month, int day);
    bool operator< (cNgay a);
    friend ostream& operator<< (ostream& os, cNgay& a);
    friend istream& operator>> (istream& is, cNgay& a);
};
cNgay::cNgay()
{
    ngay = 1;
    thang = 1;
    nam = 1;
}
cNgay::cNgay(int year, int month)
{
    nam = year;
    thang = month;
    ngay = 1;
}
cNgay::cNgay(int year, int month, int day)
{
    nam = year;
    thang = month;
    ngay = day;
}
bool cNgay::operator< (cNgay a)
{
    if (nam == a.nam)
        if (thang == a.thang)
            return a.ngay - ngay > 0;
        else
            return a.thang = thang > 0;
        else
    return a.nam - nam > 0;
}
ostream& operator<< (ostream& os, cNgay& a)
{
    os << "ngay "<< a.ngay << " tháng " << a.thang << " nam " << a.nam << endl;
}
istream& operator>> (istream& is, cNgay& a)
{
    is >> a.nam >> a.thang >> a.nam;
}
