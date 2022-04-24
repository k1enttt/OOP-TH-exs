#include "math.h"
#include "TamGiac.h"
ToaDo::ToaDo(float xx, float yy)
{
    x = xx;
    y = yy;
}
void ToaDo::setX(float xx)
{
    x = xx;
}
float ToaDo::getX()
{
    return x;
}
void ToaDo::setY(float yy)
{
    y = yy;
}
float ToaDo::getY()
{
    return y;
}
void ToaDo::xuat()
{
    cout << "(" << x << ", " << y << ")\n"; 
}

TamGiac::TamGiac(float xa, float ya, float xb, float yb, float xc, float yc) 
: a(xa, xb), b(xb, yb), c(xc, yc){}
void TamGiac::setA(float xa, float ya)
{
    a.setX(xa);
    a.setY(ya);
}
ToaDo TamGiac::getA()
{
    return a;
}
void TamGiac::setB(float xb, float yb)
{
    b.setX(xb);
    b.setY(yb);
}
ToaDo TamGiac::getB()
{
    return b;
}
void TamGiac::setC(float xc, float yc)
{
    c.setX(xc);
    c.setY(yc);
}
ToaDo TamGiac::getC()
{
    return c;
}
//Nhập tam giác
void TamGiac::nhap()
{
    float x, y;
    cout << "Nhập điếm A:\n";
    cin >> x >> y;
    setA(x, y);
    cout << "Nhập điểm B\n";
    cin >> x >> y;
    setB(x, y); 
    cout << "Nhập điểm C\n";
    cin >> x >> y;
    setC(x, y);
}
//Xuất thông tin tam giác
void TamGiac::xuat()
{
    cout << "Điểm A: (" << a.getX() << ", " << a.getY() << ")\n";
    cout << "Điểm B: (" << b.getX() << ", " << b.getY() << ")\n";
    cout << "Điểm C: (" << c.getX() << ", " << c.getY() << ")\n";
}
//Tính độ dài cạnh
float TamGiac::canh(ToaDo a, ToaDo b)
{
    return sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
}
//Xét loại tam giác
int TamGiac::xetLoaiTG()
{
    float ab = canh(a, b);
    float ac = canh(a, c);
    float bc = canh(b, c);
    int p, q, w, s, rs;
    //0. Thường
    s = (ab + ac <= bc) || (ab + bc <= ac) || (ac + bc <= ab);
    //1. Đều : ab = ac = bc
    p = ab == bc && ab == ac;
    //2. cân
    q = (ab == bc) || (ab == ac) || (bc == ac);
    //3. Vuông
    w = (ac * ac + ab * ab == bc * bc) || (bc * bc + ab * ab == ac * ac) || (ac * ac + bc * bc == ab * ab);
    if (s)
    {
        rs = 0;
    }
    else if (p)
    {
        rs = 1;
    }
    else if (q == 1 && w == 1)
    {
        rs = 23;
    }
    else if (q)
    {
        rs = 2;
    }
    else if (w)
    {
        rs = 3;
    }
    return rs;
}
//Tính chu vi
float TamGiac::chuVi()
{
    float ab = canh(a, b);
    float ac = canh(a, c);
    float bc = canh(b, c);
    return ab + ac + bc;
}
//Tính diện tích
double TamGiac::dienTich()
{
    float ab = canh(a, b);
    float ac = canh(a, c);
    float bc = canh(b, c);
    float p = (ab + ac + bc) / 2;
    return sqrt(p * (p - ac) * (p - ab) * (p - bc));
}
//Tính tâm đường tròn ngoại tiếp tam giác
ToaDo TamGiac::tamNgoaiTiepTG()
{
    //1. Đều : x = (xa + xb + xc) / 3, y = (ya + yb + yc) / 3
    //23, 3. Vuông : Trung điểm cạnh huyền
    float x, y;
    float ab = canh(a, b);
    float ac = canh(a, c);
    float bc = canh(b, c);
    int type = xetLoaiTG();
    switch (type)
    {
    case 1:
        x = (a.getX() + b.getX() + c.getX()) / 3;
        y = (a.getY() + b.getY() + c.getY()) / 3;
        break;
    case 3: 
    case 23:
        if (ac * ac + ab * ab == bc * bc)
        {
            x = (b.getX() + c.getX()) / 2;
            y = (b.getY() + c.getY()) / 2;
        }
        else if (bc * bc + ab * ab == ac * ac)
        {
            x = (a.getX() + c.getX()) / 2;
            y = (a.getY() + c.getY()) / 2;
        }
        else if (ac * ac + bc * bc == ab * ab)
        {
            x = (a.getX() + b.getX()) / 2;
            y = (a.getY() + b.getY()) / 2;
        }
        break;
    default:
        break;
    }
    return a;
}
//Tính tâm đường tròn nội tiếp tam giác
ToaDo TamGiac::tamNoiTiepTG()
{
    ToaDo a;
    float x, y;
    float ab = canh(a, b);
    float ac = canh(a, c);
    float bc = canh(b, c);
    x = (ab * c.getX() + ac * b.getX() + bc * a.getX()) / (ab + ac + bc);
    y = (ab * c.getY() + ac * b.getY() + bc * a.getY()) / (ab + ac + bc);
    a.setX(x);
    a.setY(y);
    return a;
}