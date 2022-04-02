#include "ToaDo.h"

ToaDo::ToaDo(int hoanhdo, int tungdo)
{
    this->hoanhdo = hoanhdo;
    this->tungdo = tungdo;
}
ToaDo ToaDo::nhap()
{
    cout << "Nhập tọa độ:\n";
    cin >> hoanhdo >> tungdo;
    ToaDo t(hoanhdo, tungdo);
    return t;
}
void ToaDo::xuat()
{
    cout << "(" << hoanhdo << ", " << tungdo << ")";
}
int ToaDo::getHoanhDo()
{
    return hoanhdo;
}
void ToaDo::setHoanhDo(int hoanhdo)
{
    this->hoanhdo = hoanhdo;
}
int ToaDo::getTungDo()
{
    return tungdo;
}
void ToaDo::setTungDo(int tungdo)
{
    this->tungdo = tungdo;
}
ToaDo ToaDo::midPoint(ToaDo a, ToaDo b)
{
    ToaDo x;
    x.setHoanhDo( (a.getHoanhDo() + b.getHoanhDo()) / 2 );
    return x;
}
float ToaDo::distance(int hoanh, int tung)
{
    return (getHoanhDo() - hoanh) * (getHoanhDo() - hoanh) + (getTungDo() - tung) * (getTungDo() - tung);
}

int main()
{
    int n, imported = 0, hoanh, tung;
    //Biến kí tự để tiếp tục dòng while
    char resume;
    ToaDo x;
    
    //Chọn chức năng
    cout << "////////////////////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Nhập tọa độ một điểm\n";
    cout << "// 2. xuất tọa độ một điểm\n";
    cout << "// 3. Lấy tọa độ một điểm\n";
    cout << "// 4. Thay đổi tọa độ điểm\n";
    cout << "// 5. Di chuyển đến tọa độ\n";
    cout << "// 6. Khoảng cách hai điểm\n";
    cout << "// 7. Tìm toa độ trung điểm khi biết hai điểm\n";
    cout << "// 8. Xóa tọa độ điểm\n";
    cout << "// 9. Sao chép điểm tọa độ\n";
    cout << "////////////////////////////////////////////////\n\n";
    while (1)
    {
        cout << "Chọn một chức năng: "; 
        cin >> n;
        while (n < 1 || n > 9)
        {    
            cout << "Chọn lại chức năng: "; 
            cin >> n;
        }
        
        //Thực thi chức năng
        switch (n)
        {
        case 1:
            imported = 1;
            cout << "Nhập tọa độ một điểm\n";
            x.nhap();
            break;
        case 2:
            if (imported != 1)
                cout << "Chưa nhập tọa độ điểm\n";
            else
            {
                cout << "Xuất tọa độ một điểm\n";
                x.xuat();
                cout << endl;
            }
            break;
        case 3:
            if (imported != 1)
                cout << "Chưa nhập tọa độ điểm\n";
            else
            {
                cout << "Lấy tọa độ một điểm\n";
                cout << "Hoành độ: " << x.getHoanhDo() << endl;
                cout << "Tung độ: " << x.getTungDo() << endl;
            }
            break;
        case 4:
            if (imported != 1)
                cout << "Chưa nhập tọa độ điểm\n";
            else
            {
                cout << "Thay đổi tọa độ điểm\n";
                cout << "x: "; cin >> hoanh;
                x.setHoanhDo(hoanh);
                cout << "y: "; cin >> tung;
                x.setTungDo(tung);
                cout << endl;
            }
            break;
        case 5:
            if (imported != 1)
                cout << "Chưa nhập tọa độ điểm\n";
            else
            {
                cout << "Di chuyển đến tọa độ\n";
                cout << "Tọa độ mới:\n";
                cin >> hoanh;
                cin >> tung;
                x.setHoanhDo(hoanh);
                x.setTungDo(tung);
                cout << endl;
            }
            break;
        case 6:
            if (imported != 1)
                cout << "Chưa nhập tọa độ điểm\n";
            else
            {
                cout << "Khoảng cách hai điểm\n";
                cout << "Tọa độ điểm thứ 2:\n";
                cin >> hoanh >> tung;
                cout << "Khoảnh cách giữa 2 điểm: " << x.distance(hoanh, tung) << endl;
            }
            break;
        case 7:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else 
            {
                cout << "Tìm toa độ trung điểm khi biết hai điểm\n";
                cout << "Tọa độ điểm thứ 2:\n";
                cin >> hoanh >> tung;
                ToaDo y(hoanh, tung);
                cout << "Trung điểm: ";
                x.midPoint(x, y).xuat();
                cout << endl;
            }
            break;
        case 8:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else 
            {
                cout << "Xóa tọa độ điểm\n";
                imported = 0;
                cout << endl;
            }
            break;
        case 9:
            if (imported != 1)
                cout << "Chưa nhập phân số\n";
            else 
            {
                cout << "Sao chép điểm tọa độ\n";
                ToaDo z(x.getHoanhDo(), x.getTungDo());
                cout << "Đã sao chép.";
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