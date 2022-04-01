#include <iostream>
using namespace std;
#include "TamGiac.h"

Diem::Diem(float x, float y)
{
    this->x = x;
    this->y = y;
}
void Diem::setX(float x)
{
    this->x = x;
}
float Diem::getX()
{
    return x;
}
void Diem::setY(float y)
{
    this->y = y;
}
float Diem::getY()
{
    return y;
}
void Diem::nhapDiem(){
    cout << "Nhập điểm: \n";
    cin >> this->x;
    cin >> this->y;
}
void Diem::xuatDiem(){
    cout << "(" << x << ", " << y << ")";
}
TamGiac::TamGiac(Diem mot, Diem hai, Diem ba)
{
    this->mot.setX(mot.getX());
    this->mot.setY(mot.getY());
    this->hai.setX(hai.getX());
    this->hai.setY(hai.getY());
    this->ba.setX(ba.getX());
    this->ba.setY(ba.getY());

}
void TamGiac::setMot(Diem x)
{
    this->mot.setX(x.getX());
    this->mot.setY(x.getY());
}
Diem TamGiac::getMot()
{
    return mot;
}
void TamGiac::setHai(Diem x)
{
    this->hai.setX(x.getX());
    this->hai.setY(x.getY());
}
Diem TamGiac::getHai()
{
    return hai;
}
void TamGiac::setBa(Diem x)
{
    this->ba.setX(x.getX());
    this->ba.setY(x.getY());
}
Diem TamGiac::getBa()
{
    return ba;
}
void TamGiac::nhapTG(){
    cout << "Nhập tọa độ 3 điểm: \n";
    this->mot.nhapDiem();
    this->hai.nhapDiem();
    this->ba.nhapDiem();
}
void TamGiac::xuatTG(){
    cout << "Tam giác gồm 3 điểm có tọa độ:\n";
    this->mot.xuatDiem();
    cout << ", ";
    this->hai.xuatDiem();
    cout << ", ";
    this->ba.xuatDiem();
}
float TamGiac::doDaiCanh(Diem x, Diem y){
    float tX = x.getX() - y.getX();
    float tY = x.getY() - y.getY();
    return tX * tX  + tY * tY;
}
int TamGiac::xepLoaiTamGiac(){

}
float TamGiac::chuVi(){

}
float TamGiac::dienTich(){

}
//-----MAIN CODE------
int main()
{
    int n;
    char resume;
    
    //Chọn chức năng
    cout << "/////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Nhập đường tròn\n";
    cout << "// 2. Xuất thông tin đường tròn\n";
    cout << "// 3. Xét loại tam giác\n";
    cout << "// 4. Tính chu vi\n";
    cout << "// 5. Tính diện tích\n";
    cout << "/////////////////////////////////\n\n";
    while (1)
    {
        cout << "Chọn một chức năng: "; 
        cin >> n;
        while (n < 1 || n > 5)
        {    
            cout << "Chọn lại chức năng: "; 
            cin >> n;
        }
        
        //Thực thi chức năng
        switch (n)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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
