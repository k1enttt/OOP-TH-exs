#include <iostream>
#include <string>
using namespace std;

struct HocSinh
{
    string hoTen;
    float diemToan;
    float diemVan;
    float diemTB;
};
void nhapHS(HocSinh *hs, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout << "Họ tên:\n";
        getline(cin, hs[i].hoTen);
        cout << "Điểm toán:\n";
        cin >> hs[i].diemToan;
        cout << "Điểm văn:\n";
        cin >> hs[i].diemVan;
        hs[i].diemTB = (hs[i].diemToan + hs[i].diemVan) / 2;
        cout << endl;
    }
}
void xuatHS(HocSinh hs)
{
    cout << "Họ tên: " << hs.hoTen << endl;
    cout << "Điểm toán: " << hs.diemToan << endl;
    cout << "Điểm văn: " << hs.diemVan << endl;
    cout << "Điểm trung bình: " << hs.diemTB << endl;
}
HocSinh search_DTB_Max(HocSinh *hs, int n)
{
    HocSinh temp;
    temp = hs[0];
    for (int i = 1; i < n; i++)
        if (temp.diemTB < hs[i].diemTB)
            temp = hs[i];
    return temp;
}
HocSinh search_DTB_Min(HocSinh *hs, int n)
{
    HocSinh temp;
    temp = hs[0];
    for (int i = 1; i < n; i++)
        if (temp.diemTB > hs[i].diemTB)
            temp = hs[i];
    return temp;
}
int main()
{
    HocSinh hs[100], maxDTB, minDTB;
    int n;
    cout << "Số học sinh:\n";
    cin >> n;
    nhapHS(hs, n);
    maxDTB = search_DTB_Max(hs, n);
    minDTB = search_DTB_Min(hs, n);
    cout << "Học sinh có điểm trung bình cao nhất:\n";
    xuatHS(maxDTB);
    cout << endl;
    cout << "Học sinh có điểm trung bình thấp nhất:\n";
    xuatHS(minDTB);
}
