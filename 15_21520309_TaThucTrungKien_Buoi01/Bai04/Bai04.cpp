#include <iostream>

using namespace std;

struct PS
{
    int tu;
    int mau;
};
typedef struct PS PhanSo;

void nhap(PhanSo& x)
{
    cout << "Nhập tử, mẫu: \n";
    cin >> x.tu >> x.mau;
}
int psMax(PhanSo x, PhanSo y)
{
    float t = ( (float)x.tu / (float)x.mau) - ((float)y.tu / (float)y.mau);
    return (t >= 0) ? 1 : 0; 
}
PhanSo searchMax(PhanSo *x, int n)
{
    PhanSo max = x[0];
    for (int i = 1; i < n; i++)
        max = (psMax(x[i], max) == 1) ? x[i] : max;
    return max;
}
void sortAscending(PhanSo* x, int n)
{
    PhanSo temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (psMax(x[i], x[j]) == 1)
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
    }
}
void sortDescending(PhanSo* x, int n)
{
    PhanSo temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (psMax(x[i], x[j]) == 0)
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
    }
}
void xuat(PhanSo x)
{
    //Tử hoặc mẫu = 0
    if ((x.tu == 0) || (x.mau == 0)) 
        cout << 0;
    //Tử = mẫu
    else if (x.tu == x.mau) 
        cout << 1;
    //Mẫu = 1, triệt tiêu mẫu
    else if (x.mau == 1)
        cout << x.tu;
    //Tử dương, mẫu âm
    else if (x.tu > 0 && x.mau < 0)
        cout << -x.tu << "/" << x.mau;
    //Tử âm, mẫu âm
    else if (x.tu < 0 && x.mau < 0)
        cout << -x.tu << "/" << -x.mau;
    else
        cout << x.tu << "/" << x.mau;
}
int main()
{
    PhanSo ps[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        nhap(ps[i]);
    }

    cout << "Phân số lớn nhất: ";
    xuat(searchMax(ps, n));
    cout << endl;

    cout << "Sắp sếp tăng dần:\n";
    sortAscending(ps, n);
    for (int i = 0; i < n; i++)
    {    
        xuat(ps[i]);
        cout << " ";
    }
    cout << endl;
    cout << "Sắp xếp giảm dần:\n";
    sortDescending(ps, n);
    for (int i = 0; i < n; i++)
    {    
        xuat(ps[i]);
        cout << " ";
    }
    return 0;
}