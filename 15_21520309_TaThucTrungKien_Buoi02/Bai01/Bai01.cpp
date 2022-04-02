#include <random>
#include "PhanSo.h"

PhanSo::PhanSo(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau;
}
int PhanSo::getTu()
{
    return tu;
}
int PhanSo::getMau()
{
    return mau;
}
void PhanSo::setTu(int tu)
{
    this->tu = tu;
}
void PhanSo::setMau(int mau)
{
    this->mau = mau;
}
void PhanSo::nhapPS()
{
    // int tu, mau;
    cout << "Nhập phân số:\n";
    cin >> this->tu;
    cin >> this->mau;
    // setTu(tu);
    // setMau(mau);
}
void PhanSo::xuatPS()
{
    //Tu = 0;
    //Mau = 0;
    //Mau = 1;
    //Tu = mau;
    //tu > 0, mau < 0;
    //tu < 0, mau < 0;
    if (tu == 0 || mau == 0)
        cout << 0;
    else if (mau == 1)
        cout << tu;
    else if (tu == mau)
        cout << 1;
    else if ((tu > 0 && mau < 0) || (tu < 0 && mau < 0))
        cout << -tu << "/" << -mau;
    else
        cout << tu << "/" << mau;
}
int PhanSo::ucln()
{
    int t = tu, m = mau;
    if (t < 0) t = -t;
    if (m < 0) m = -m;
    while (t * m != 0)
    {
        if (t > m)
            t %= m;
        else 
            m %= t;
    }
    return t + m;
}
int PhanSo::rutGon()
{
    int uc = ucln();
    if (uc == 1)
        return 0;
    tu /= uc;
    mau /= uc;
    return 1;
}
PhanSo PhanSo::congPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau + a.tu * mau;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::truPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau - a.tu * mau;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::nhanPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.tu;
    t.mau = mau * a.mau;
    t.rutGon();
    return t;
}
PhanSo PhanSo::chiaPS(PhanSo a)
{
    PhanSo t;
    t.tu = tu * a.mau;
    t.mau = mau * a.tu;
    t.rutGon();
    return t;
}
int PhanSo::randomInt(int min, int max)
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}
void PhanSo::randomPhanSo()
{
    setTu(randomInt(-50, 50));
    setMau(randomInt(-50, 50));
}

int main()
{
    int n, imported = 0;
    char resume;
    PhanSo x, y;
    
    //Chọn chức năng
    cout << "/////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Nhập phân số từ bàn phím\n";
    cout << "// 2. Nhập phân số theo phương pháp tự động\n";
    cout << "// 3. Xuất phân số\n";
    cout << "// 4. Cộng hai phân số\n";
    cout << "// 5. Trừ hai phân số\n";
    cout << "// 6. Nhân hai phân số\n";
    cout << "// 7. Chia hai phân số\n";
    cout << "/////////////////////////////////\n\n";
    while (1)
    {
        cout << "Chọn một chức năng: "; 
        cin >> n;
        while (n < 1 || n > 7)
        {    
            cout << "Chọn lại chức năng: "; 
            cin >> n;
        }
        
        //Thực thi chức năng
        switch (n)
        {
        case 1:
            imported = 1;
            cout << "Nhập vào 2 phân số:\n";
            x.nhapPS();
            y.nhapPS();
            cout << endl;
            break;
        case 2:
            imported = 1;
            cout << "Khởi tạo tự động 2 phân số\n";
            x.randomPhanSo();
            y.randomPhanSo();
            cout << "Phân số 1: ";
            x.xuatPS();
            cout << endl;
            cout << "Phân số 2: ";
            y.xuatPS();
            cout << endl;
            break;
        case 3:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else 
            {
                cout << "Xuất hai phân số\n";
                cout << "- Phân số thứ nhất: ";
                x.xuatPS();
                cout << endl;
                cout << "- Phân số thứ hai: ";
                y.xuatPS();
                cout << endl << endl;
            }
            break;
        case 4:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Cộng hai phân số\n";
                x.xuatPS(); 
                cout << " + ";
                y.xuatPS();
                cout << " = ";
                x.congPS(y).xuatPS();
                cout << endl;
            }
            break;
        case 5:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Trừ hai phân số\n";
                x.xuatPS(); 
                cout << " - ";
                y.xuatPS();
                cout << " = ";
                x.truPS(y).xuatPS();
                cout << endl;
            }
            break;
        case 6:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Nhân hai phân số\n";
                x.xuatPS(); 
                cout << " * ";
                y.xuatPS();
                cout << " = ";
                x.nhanPS(y).xuatPS();
                cout << endl;
            }
            break;
        case 7:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Chia hai phân số\n";
                x.xuatPS(); 
                cout << " / ";
                y.xuatPS();
                cout << " = ";
                x.chiaPS(y).xuatPS();
                cout << endl;
            }
            break;
        default:
            break;
        }
        cout << endl;
        //Tiếp tục thực hiện các chức năng
        cout << "Bạn có muốn tiếp tục? ( y / n )\n";
        cin >> resume;
        while (resume != 'y' && resume != 'n')
        {
            cout << "Bạn có muốn tiếp tục? ( y / n )\n";
            cin >> resume;
        }
        if (resume == 'n') break; 
        cout << endl;
    }
    return 0;
}