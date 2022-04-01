#include <random>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include "Bai09.h"
//Nhập thủ công
void nhapSV(SinhVien &p)
{
    cout << "Mã sinh viên: ";
    cin >> p.maSV;
    cout << "Họ tên: ";
    getline(cin, p.hoTen);
    cout << "Điểm trung bình: ";
    cin >> p.dtb;
}

//XUẤT

void xuatSV(SinhVien p)
{
    cout << p.maSV << "\t|" << p.hoTen << "\t|" << p.dtb << "\t\t|" << p.xeploai << endl;
}

//KHỞI TẠO NGẪU NHIÊN CÁC SINH VIÊN

//Khởi tạo ngẫu nhiên mã sinh viên
//arr {20000000,...,30000000}
//shuffle(arr)
int* create_arr_masv(int min, int max)
{
    int length = max - min + 1;
    int *x = new int[length];
    for (int i = 0; i < length; i++)
    {
        x[i] = min++;
    }
    return x;
}
void shuffle_arr(int *arr, int n)
{
    unsigned seed = 0;

    shuffle(arr, arr + n, default_random_engine(seed));
}
//Random ngẫu nhiên số nguyên
int randomMaSV(int min, int max)
{
    srand((unsigned) time(NULL));
    return rand() % (max - min + 1) + min;
}

//Khởi tạo ngẫu nhiên kí tự
string randomHoTen()
{
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz");
    random_device rd;
    mt19937 generator(rd());

    shuffle(str.begin(), str.end(), generator);

    char* s;
    string temp = str.substr(0, 10);
    s = new char[temp.length() + 1];
    strcpy_s(s, temp.length() + 1, temp.c_str());
    return s;
}
//Khởi tạo ngẫu nhiên số thực
float randomDiemTB(float min, float max)
{
    return (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
}
//Khởi tạo sinh viên
void randomSV(SinhVien p[], int n)
{
    int min, max;
    int *arr_int = NULL;
    min = 20000000;
    max = 30000000;
    arr_int = create_arr_masv(min, max);
    shuffle_arr(arr_int, max - min + 1);

    for (int i = 0; i < n; i++)
    {
        string hoTen = randomHoTen();
        float diemTB = randomDiemTB(4.0, 10.0);
        p[i].maSV = arr_int[i];
        p[i].hoTen = hoTen;
        p[i].dtb = diemTB;
    }
}

SinhVien dTB_Max(SinhVien p[], int n)
{
    SinhVien max = p[0];
    for (int i = 1; i < n; i++)
    {
        max = (max.dtb < p[i].dtb) ? p[i] : max;
    }
    return max;
}

SinhVien dTB_Max(SinhVien p[], int n, int *check)
{
    int x;
    SinhVien max = p[0];
    for (int i = 1; i < n; i++)
    {
        if (max.dtb < p[i].dtb && check[i] == 0)
        {
            max = p[i];
            x = i;
        }
    }
    check[x] = 1;
    return max;
}

SinhVien dTB_Min(SinhVien p[], int n, int *check)
{
    int x;
    SinhVien min = p[0];
    for (int i = 1; i < n; i++)
    {
        if (min.dtb < p[i].dtb && check[i] == 0)
        {
            min = p[i];
            x = i;
        }
    }
    check[x] = 1;
    return min;
}

string xepLoai(SinhVien p)
{
    string loai;
    if (p.dtb < 3.5)
    {
        loai = "Kem";
    }
    else if (p.dtb < 5.0)
    {
        loai = "Yeu";
    }
    else if (p.dtb < 7.0)
    {
        loai = "Trung binh";
    }
    else if (p.dtb < 8.0)
    {
        loai = "Kha";
    }
    else if (p.dtb < 9.0)
    {
        loai = "Gioi";
    }
    else if (p.dtb <= 10.0)
    {
        loai = "Xuat sac";
    }
    return loai;
}

void capNhatXepLoai(SinhVien p[], int n)
{
    for (int i = 0; i < n; i++)
        p[i].xeploai = xepLoai(p[i]);
}

void searchMaSV(SinhVien p[], int n, int maSV)
{
    for (int i = 0; i < n; i++)
        if (p[i].maSV == maSV)
        {
            xuatSV(p[i]);
        }
}

void searchDTB(SinhVien p[], int n, float dtb)
{
    for (int i = 0; i < n; i++)
        if (p[i].dtb == dtb)
        {
            xuatSV(p[i]);
        }
}


int main()
{
    int x, n, ma, *check;
    char resume;
    float dtb;
    SinhVien sv[200];
    cout << "/////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Nhập thủ công n SV.\n";
    cout << "// 2. Khởi tạo ngẫu nghiên các SV.\n";
    cout << "// 3. Xuất (in) thông tin SV ra màn hình.\n";
    cout << "// 4. Xuất (in) ra thông tin sinh viên có điểm TB lớn nhất\n";
    cout << "// 5. Cập nhật xếp loại học lực SV\n";
    cout << "// 6. Tìm SV theo mã sinh viên.\n";
    cout << "// 7. Tìm các SV có điểm trung bình cho trước.\n";
    cout << "// 8. Trả về 10 SV có điểm trung bình cao nhất.\n";
    cout << "// 9. Trả về 10 SV có điểm trung bình thấp nhất.\n";
    cout << "/////////////////////////////////\n\n";
    
     while (1)
    {
        cout << "Chọn một chức năng: "; 
        cin >> x;
        while (x < 1 || x > 9)
        {    
            cout << "Chọn lại chức năng: "; 
            cin >> x;
        }

        switch (x)
        {
        case 1:
            cout << "Nhập thủ công n SV\n";
            cout << "Nhập n: "; 
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                nhapSV(sv[i]);
                cout << endl;
            }
            break;
        case 2:
            cout << "Khởi tạo ngẫu nghiên các SV\n";
            cout << "Nhập n: "; 
            cin >> n;
            randomSV(sv, n);
            cout << endl;
            break;
        case 3:
            cout << "Xuất (in) thông tin SV ra màn hình\n";
            cout << "Mã sinh viên\t|Họ Tên\t\t|Điểm trung bình\t|Xếp loại\n";
            for (int i = 0; i < n; i++)
            {
                xuatSV(sv[i]);
                cout << endl;
            }
            cout << endl;
            break;
        case 4:
            cout << "Xuất (in) ra thông tin sinh viên có điểm TB lớn nhất\n";
            cout << "Mã sinh viên\t|Họ Tên\t\t|Điểm trung bình\t|Xếp loại\n";
            xuatSV(dTB_Max(sv, n));
            cout << endl;
            break;
        case 5:
            cout << "Cập nhật xếp loại học lực SV\n";
            capNhatXepLoai(sv, n);
            cout << "Đã cập nhật!";
            cout << endl;
            break;
        case 6:
            cout << "Tìm SV theo mã sinh viên\n";
            cout << "Nhập mã sinh viên cần tìm: ";
            cin >> ma; 
            cout << "Danh sách sinh viên có mã SV = " << ma << ":\n";
            cout << "Mã sinh viên\t|Họ Tên\t\t|Điểm trung bình\t|Xếp loại\n";
            searchMaSV(sv, n, ma);
            cout << endl;
            break;
        case 7:
            cout << "Tìm các SV có điểm trung bình cho trước\n";
            cout << "Nhập điểm trung bình cần tìm: ";
            cin >> dtb; 
            cout << "Danh sách sinh viên có điểm trung bình = " << dtb << ":\n";
            cout << "Mã sinh viên\t|Họ Tên\t\t|Điểm trung bình\t|Xếp loại\n";
            searchDTB(sv, n, dtb);
            cout << endl;
            break;
        case 8:
            check = new int[200]{0};
            cout << "Trả về 10 SV có điểm trung bình cao nhất\n";
            cout << "Mã sinh viên\t|Họ Tên\t\t|Điểm trung bình\t|Xếp loại\n";
            for (int i = 0; i < 10; i++)
            {
                xuatSV(dTB_Max(sv, n, check));
            }
            delete[] check;
            break;
        case 9:
            check = new int[200]{0};
            cout << "Trả về 10 SV có điểm trung bình thấp nhất\n";
            cout << "Mã sinh viên\t|Họ Tên\t\t|Điểm trung bình\t|Xếp loại\n";
            for (int i = 0; i < 10; i++)
            {
                xuatSV(dTB_Min(sv, n, check));
            }
            delete[] check;
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