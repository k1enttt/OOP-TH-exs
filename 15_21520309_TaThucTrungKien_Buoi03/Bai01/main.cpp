#include "Bai01.cpp"
int main()
{
    int n, imported = 0;
    char resume;
    PhanSo x, y, t;
    
    //Chọn chức năng
    cout << "/////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Nhập phân số từ bàn phím\n";
    cout << "// 2. Nhập phân số theo phương pháp tự động\n";
    cout << "// 3. Xuất phân số\n";
    cout << "// 4. Cộng, trừ, nhân, chia hai phân số\n";
    cout << "// 5. So sánh hai phân số\n";
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
            cout << "Nhập vào 2 phân số:\n";
            cout << "Phân số 1:\n";
            cin >> x;
            cout << "Phân số 2:\n";
            cin >> y;
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
                cout << "Cộng, trừ, nhân, chia hai phân số\n";
                cout << x << " + " << y << " = " << x + y;
                cout << x << " - " << y << " = " << x - y;
                cout << x << " * " << y << " = " << x * y;
                cout << x << " / " << y << " = " << x / y;
                cout << endl;
            }
            break;
        case 5:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "So sánh hai phân số\n";
                if (x == y)
                    cout << x << " = " << y;
                if (x > y)
                    cout << x << " > " << y;
                if (x < y) 
                    cout << x << " < " << y;
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