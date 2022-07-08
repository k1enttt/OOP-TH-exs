#include "HonSo.cpp"
int main()
{
    int n, imported = 0;
    char resume;
    HonSo x, y, k;
    PhanSo t;
    //Chọn chức năng
    cout << "/////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Nhập hỗn số từ bàn phím\n";
    cout << "// 2. Nhập hỗn số theo phương pháp tự động\n";
    cout << "// 3. Xuất hỗn số\n";
    cout << "// 4. Chuyển đổi phân số thành hỗn số\n";
    cout << "// 5. Chuyển đổi hỗn số thành phân số\n";
    cout << "// 6. Cộng, trừ, nhân, chia hai hỗn số\n";
    cout << "// 7. So sánh hai hỗn số\n";
    cout << "// 8. Test\n";
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
            cout << "Nhập vào 2 hỗn số:\n";
            cout << "Hỗn số 1:\n";
            cin >> x;
            cout << "Hỗn số 2:\n";
            cin >> y;
            cout << endl;
            break;
        case 2:
            imported = 1;
            cout << "Khởi tạo tự động 2 hỗn số\n";
            x = x.randomHonSo();
            y = y.randomHonSo();
            cout << "Hỗn số 1: " << x << endl;
            cout << "Hỗn số 2: " << y << endl;
            break;
        case 3:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else 
            {
                cout << "Xuất hai hỗn số\n";
                cout << "- Hỗn số thứ nhất: " << x << endl;
                cout << "- Hỗn số thứ hai: " << y << endl;
                cout << endl;
            }
            break;
        case 4:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Chuyển phân số thành hỗn số:\n";
                cout << " - Nhập phân số:\n";
                cin >> t;
                cout << x.chuyen(t) << endl;
            }
            break;
        case 5:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Chuyển hỗn số thành phân số:\n";
                cout << " - Nhập hỗn số:\n";
                cin >> k;
                cout << x.chuyen(k) << endl;
            }
            break;
        case 6:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else
            {
                cout << "Cộng, trừ, nhân, chia hai phân số\n";
                cout << x << " + " << y << " = " << x + y << endl;
                cout << x << " - " << y << " = " << x - y << endl;
                cout << x << " * " << y << " = " << x * y << endl;
                cout << x << " / " << y << " = " << x / y << endl;
                cout << endl;
            }
            break;
        case 7:
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
            HonSo a(1, 2, 3), c(2, 1, 3);
            PhanSo b = a.chuyen(a);
            cout << "Cộng, trừ, nhân, chia hai phân số\n";
            cout << a << " + " << c << " = " << a + c << endl;
            cout << a << " - " << c << " = " << a - c << endl;
            cout << a << " * " << c << " = " << a * c << endl;
            // Phép nhân sai
            cout << a << " / " << c << " = " << a / y << endl;
            cout << endl;
            cout << a << endl << b;
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