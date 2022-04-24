#include "header.cpp"

int main()
{
    int n, imported = 0, type;
    char resume;
    TamGiac abc;
    //Chọn chức năng
    while (1)
    {
        cout << "/////////////////////////////////\n";
        cout << "//       MENU\n";
        cout << "// 1. Nhập tam giác\n";
        cout << "// 2. Xuất thông tin tam giác\n";
        cout << "// 3. Xét loại tam giác\n";
        cout << "// 4. Tính chu vi\n";
        cout << "// 5. Tính diện tích\n";
        cout << "// 6 .Tìm tâm đường tròn ngoại tiếp\n";
        cout << "// 7. Tìm tâm đường tròn nộp tiếp của tam giác\n";
        cout << "/////////////////////////////////\n\n";
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
            cout << "Nhập tam giác:\n";
            abc.nhap();
            imported = 1;
            break;
        case 2:
            if (imported != 1)    
                cout << "Chưa nhập thông tin tam giác.\n";
            else
            {
                cout << "Xuất thông tin tam giác:\n";
                abc.xuat();
            }
            break;
        case 3:
            if (imported != 1)    
                cout << "Chưa nhập thông tin tam giác.\n";
            else
            {
                cout << "Xét loại tam giác:\n";
                type = abc.xetLoaiTG(); 
                switch (type)
                {
                case 1:
                    cout << "Tam giác đều\n";
                    break;
                case 23: 
                    cout << "Tam giác vuông cân\n";
                    break;
                case 2:
                    cout << "Tam giác cân\n";
                    break;
                case 3:
                    cout << "Tam giác vuông\n";
                    break;
                case 4:
                    cout << "Tam giác thường\n";
                    break;
                default:
                    cout << "Không phải tam giác\n";
                    break;
                }
            }
            break;
        case 4:
            if (imported != 1)    
                cout << "Chưa nhập thông tin tam giác.\n";
            else
            {
                cout << "Tính chu vi:\n";
                cout << abc.chuVi() << endl;
            }
            break;
        case 5:
            if (imported != 1)    
                cout << "Chưa nhập thông tin tam giác.\n";
            else
            {
                cout << "Tính diện tích:\n";
                cout << abc.dienTich() << endl;
            }
            break;
        case 6:
            if (imported != 1)    
                cout << "Chưa nhập thông tin tam giác.\n";
            else
            {
                cout << "Tìm tâm đường tròn ngoại tiếp của tam giác:\n";
                abc.tamNgoaiTiepTG().xuat();
            }
            break;
        case 7:
            if (imported != 1)    
                cout << "Chưa nhập thông tin tam giác.\n";
            else
            {
                cout << "Tìm tâm đường tròn nội tiếp của tam giác:\n";
                abc.tamNoiTiepTG().xuat();
            }
            break;
        default:
            cout << "AB : " << abc.canh(abc.getA(), abc.getB()) << endl;
            cout << "AC : " << abc.canh(abc.getA(), abc.getC()) << endl;
            cout << "BC : " << abc.canh(abc.getB(), abc.getC()) << endl;
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