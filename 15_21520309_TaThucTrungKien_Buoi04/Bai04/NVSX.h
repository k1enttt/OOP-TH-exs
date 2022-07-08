#include "NhanVien.h"

class NVSX : public NhanVien
{
private:
    int soNgay;
public:
    NVSX(){};
    NVSX(string, string, int, int);
    void setSN(int);
    int getSN();
};

NVSX::NVSX(string ma, string ht, int luong, int sn) : NhanVien(ma, ht, luong)
{
    soNgay = sn;
}
void NVSX::setSN(int sn)
{
    soNgay = sn;
}
int NVSX::getSN()
{
    return soNgay;
}