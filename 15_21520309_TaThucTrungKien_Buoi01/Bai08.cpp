#include "Bai08.h"
//NHẬP
PhanSo nhapPS()
{
    PhanSo x;
    cin >> x.tu >> x.mau;
    return x;
}
void nhapPS(PhanSo& x)
{
    cin >> x.tu >> x.mau;
}
//XUẤT
void xuatPS(PhanSo x)
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
//ƯỚC CHUNG LỚN NHẤT
int uocChungLN(int x, int y)
{
    if (x < 0){
        x = abs(x);
    }
    if (y < 0){
        y = abs(y);
    }
    while (x * y != 0) {
        if (y > x) y %= x;
        else x %= y;
    }
    return x + y;
}
//RÚT GỌN
int rutGon(PhanSo& x)
{
    int uc = uocChungLN(x.tu, x.mau);
    x.tu = x.tu / uc;
    x.mau = x.mau / uc;
    return (uc == 1) ? 0 : 1;
}
//SO SÁNH 2 PHÂN SỐ
int comparePhanSo(PhanSo x, PhanSo y){
    float t = ( (float)x.tu / (float)x.mau) - ( (float)y.tu / (float)y.mau );
    if (t > 0)
        return 1; // x > y
    else if (t < 0)
        return -1; // x < y
    else 
        return 0; // x == y
}
//CỘNG 2 PHÂN SỐ
PhanSo sum(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.mau + y.tu * x.mau;
    t.mau = x.mau * y.mau;
    rutGon(t);
    return t;
}
//TRỪ 2 PHÂN SỐ
PhanSo difference(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.mau - y.tu * x.mau;
    t.mau = x.mau * y.mau;
    rutGon(t);
    return t;   
}
//NHÂN 2 PHÂN SỐ
PhanSo product(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.tu;
    t.mau = x.mau * y.mau;
    rutGon(t);
    return t; 
}
//CHIA 2 PHÂN SỐ
PhanSo fraction(PhanSo x, PhanSo y)
{
    PhanSo t;
    t.tu = x.tu * y.mau;
    t.mau = x.mau * y.tu;
    rutGon(t);
    return t; 
}
//TRONG HÀM MAIN, TẠO MENU GỌI CÁC CHỨC NĂNG TRÊN
int main(){
    int n, check, checkX, checkY, imported = 0;
    char resume;
    PhanSo x, y;
    
    //Chọn chức năng
    cout << "/////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Nhập phân số\n";
    cout << "// 2. Xuất phân số\n";
    cout << "// 3. Rút gọn các phân số đã nhập\n";
    cout << "// 4. So sánh hai phân số\n";
    cout << "// 5. Cộng hai phân số\n";
    cout << "// 6. Trừ hai phân số\n";
    cout << "// 7. Nhân hai phân số\n";
    cout << "// 8. Chia hai phân số\n";
    cout << "/////////////////////////////////\n\n";
    while (1)
    {
        cout << "Chọn một chức năng: "; 
        cin >> n;
        while (n < 1 || n > 8)
        {    
            cout << "Chọn lại chức năng: "; 
            cin >> n;
        }
        
        //Thực thi chức năng
        switch (n)
        {
        case 1:
            imported = 1;
            cout << "Nhập hai phân số\n";
            cout << "- Tử phân số 1: "; 
            cin >> x.tu;
            cout << "- Mẫu phân số 1: ";
            cin >> x.mau;
            cout << "- Tử phân số 2: "; 
            cin >> y.tu;
            cout << "- Mẫu phân số 2: ";
            cin >> y.mau;
            cout << endl;
            break;
        case 2:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else 
            {
                cout << "Xuất hai phân số\n";
                cout << "- Phân số thứ nhất: ";
                xuatPS(x);
                cout << endl;
                cout << "- Phân số thứ hai: ";
                xuatPS(y);
                cout << endl;
            }
            break;
        case 3:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                
                cout << "Rút gọn hai phân số đã nhập\n";
                checkX = rutGon(x);
                checkY = rutGon(y);
                if (checkX == 1) 
                    cout << "- Đã rút gọn phân số 1\n";
                else 
                    cout << "- Không thể rút gọn phân số 1\n";
                if (checkY == 1) 
                    cout << "- Đã rút gọn phân số 2\n";
                else 
                    cout << "- Không thể rút gọn phân số 2\n";
            } 
            break;
        case 4:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "So sánh hai phân số\n";
                check = comparePhanSo(x, y);
                switch (check)
                {
                case 1:
                    xuatPS(x);
                    cout << " > ";
                    xuatPS(y);
                    cout << endl;
                    break;
                case 0:
                    xuatPS(x);
                    cout << " < ";
                    xuatPS(y);
                    cout << endl;
                    break; 
                case -1:
                    xuatPS(x);
                    cout << " = ";
                    xuatPS(y);
                    cout << endl;
                default:
                    break;
                }
            }
            break;
        case 5:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Cộng hai phân số\n";
                xuatPS(x); 
                cout << " + ";
                xuatPS(y);
                cout << " = ";
                xuatPS(sum(x, y));
                cout << endl;
            }
            break;
        case 6:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Trừ hai phân số\n";
                xuatPS(x); 
                cout << " - ";
                xuatPS(y);
                cout << " = ";
                xuatPS(difference(x, y));
                cout << endl;
            }
            break;
        case 7:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Nhân hai phân số\n";
                xuatPS(x); 
                cout << " * ";
                xuatPS(y);
                cout << " = ";
                xuatPS(product(x, y));
                cout << endl;
            }
            break;
        case 8:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Chia hai phân số\n";
                xuatPS(x); 
                cout << " / ";
                xuatPS(y);
                cout << " = ";
                xuatPS(fraction(x, y));
                cout << endl;
            }
            break;
        default:
            break;
        }
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
    
}