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
HocSinh nhapHS()
{
    HocSinh sv;
    cout << "Họ tên:\n";
    getline(cin, sv.hoTen);
    cout << "Điểm toán:\n";
    cin >> sv.diemToan;
    cout << "Điểm văn:\n";
    cin >> sv.diemVan;
    sv.diemTB = (sv.diemToan + sv.diemVan) / 2;
    return sv;
}

void xuatHS(HocSinh sv)
{
    cout << "Họ tên: " << sv.hoTen << endl;
    cout << "Điểm toán: " << sv.diemToan << endl;
    cout << "Điểm văn: " << sv.diemVan << endl;
    cout << "Điểm trung bình: " << sv.diemTB << endl;
}
int main(){
    HocSinh hs;
    float dtb;
    hs = nhapHS();
    xuatHS(hs);
    return 0;
}