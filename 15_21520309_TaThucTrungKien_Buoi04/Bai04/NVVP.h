#include "NhanVien.h"

class NVVP : public NhanVien
{
private:
    int soNgay;
public:
    NVVP(){};
    NVVP(string, string, int, int);
    void setSN(int);
    int getSN();
};

NVVP::NVVP(string ma, string ht, int luong, int sn) : NhanVien(ma, ht, luong)
{
    soNgay = sn;
}
void NVVP::setSN(int sn)
{
    soNgay = sn;
}
int NVVP::getSN()
{
    return soNgay;
}