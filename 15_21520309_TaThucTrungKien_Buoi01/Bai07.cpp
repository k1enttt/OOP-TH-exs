#include <iostream>
using namespace std;

struct Date
{
    int ngay;
    int thang;
    int nam;
};
void nhapDate(Date &x){
    cin >> x.ngay >> x.thang >> x.nam;
}
void xuatDate(Date x){
    cout << "Ngay/thang/nam: ";
    cout << x.ngay << "/" << x.thang << "/" << x.nam;
}
Date FindNextDay(Date x){
    // Ngay = 29/2 or 30/(4,6,9,11) or 31/(1,3,5,7,8,10,12),
    switch (x.thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (x.ngay == 31){
            if (x.thang == 12){
                ++x.nam;
                x.ngay = 1;
                x.thang = 1;
            }
            else {
                ++x.thang;
                x.ngay = 1;
            }
        }
        else ++x.ngay;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (x.ngay == 30){
                ++x.thang;
                x.ngay = 1;
        }
        else ++x.ngay;
        break;
    case 2:
        if (x.nam % 4 == 0){
        //Nam nhuan
            if (x.ngay == 29){
                ++x.thang;
                x.ngay = 1;
            }
            else ++x.ngay;
        }
        else {
        //Nam khong nhuan
            if (x.ngay == 28){
                ++x.thang;
                x.ngay = 1;
            }
            else ++x.ngay;
        } 
        break;
    }
    return x;
}
int main()
{
    Date today, tomorrow;
    cout << "Hôm nay:\n";
    nhapDate(today);
    tomorrow = FindNextDay(today);
    cout << "Ngày mai: \n";
    xuatDate(tomorrow);
}