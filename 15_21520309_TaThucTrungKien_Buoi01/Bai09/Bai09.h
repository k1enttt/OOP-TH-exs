#include <iostream>
using namespace std;

struct SV
{
    int maSV;
    string hoTen;
    float dtb;
    string xeploai = "Chưa có xếp loại.";
};
typedef struct SV SinhVien;
void nhapSV(SinhVien &p);
void randomSV(SinhVien *p, int n);
SinhVien dTB_Max(SinhVien *p, int n);
SinhVien dtb_Min(SinhVien *p, int n);
string xepLoai(SinhVien p);
void capNhatXepLoai(SinhVien *p, int n);
void searchDTB(SinhVien *p, int n);
void searchDTB(SinhVien *p, int n, float dtb);