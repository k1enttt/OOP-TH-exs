#include "header.h"

int main()
{
    int i, j, k, t;
    int s, n, type, lc = 0, lc2 = 0, ma, maxLuong, minSoSP, maxSoSP;
    int * topTen = new int [10]{-1};
    NhanVien * nv [200];
    ifstream is ("input.txt");
    while (1)
    {
        cout << 
        "MENU\n"
        "1. Nhập, lưu trữ nhiều nhân viên.\n"
        "2. Tạo dữ liệu nhiều nhân viên để kiểm thử.\n"
        "3. Xuất các nhân viên.\n"
        "4. Tính và cập nhật tiền lương.\n"
        "5. Tìm nhân viên theo mã.\n"
        "6. Cập nhật thông tin theo mã.\n"
        "7. Tìm nhân viên có lương cao nhất.\n"
        "8. Tìm nhân viên có số sản phẩm thấp nhất.\n"
        "9. Tìm top 10 nhân viên có số sản phẩn nhiều nhất.\n\n";
        do 
        {
            cout << "Chọn thao tác (1-9):\n";
            cin >> s;
        } while (s < 1 || s > 9);
        switch (s)
        {
        case 1:
            cout << "Nhập và lưu trữ:\n";
            cout << "Số lượng nhân viên: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                nv[i]->nhap();
            }
            lc = 1;
            break;
        case 2:
            cout << "Tạo dữ liệu để kiểm thử:\n";
            cout << "Số lượng nhân viên: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                type = randomInt(1, 2);
                if (type == 1)
                    nv[i] = new NVSX;
                else
                    nv[i] = new NVVP;
                nv[i]->nhapRandom();
            }
            lc = 1;
            break;
        case 3:
            if (lc == 0)
                cout << "Chưa có thông tin.\n";
            else
            {
                cout << "Xuất thông tin:\n";
                for (int i = 0; i < n; i++)
                {
                    nv[i]->xuat();
                }
            }
            break;
        case 4:
            if (lc == 0)
                cout << "Chưa có thông tin.\n";
            else
            {
                cout << "Tính và cập nhật tiền lương:\n";
                for (int i = 0; i < n; i++)
                {
                    nv[i]->tinhLuong();
                }
                lc2 = 1;
                cout << "Đã tính lương.\n";
            }
            break;
        case 5:
            if (lc == 0)
                cout << "Chưa có thông tin.\n";
            else
            {
                cout << "Tìm nhân viên theo mã:\n";
                cout << "Mã nhân viên cần tìm: ";
                cin >> ma;
                for (i = 0; i < n; i++)
                {
                    if (nv[i]->getMaNV() == ma)
                    {
                        nv[i]->xuat();
                        break;
                    }
                }
            }
            break;
        case 6:
            if (lc == 0)
                cout << "Chưa có thông tin.\n";
            else
            {
                cout << "Cập nhật thông tin theo mã nhân viên:\n";
                cout << "Mã nhân viên cần cập nhật: ";
                cin >> ma;
                for (i = 0; i < n; i++)
                {
                    if (nv[i]->getMaNV() == ma)
                    {
                        nv[i]->nhap();
                        break;
                    }
                }
            }
            break;
        case 7:
            if (lc == 0)
                cout << "Chưa có thông tin.\n";
            else if (lc2 == 0)
                cout << "Chưa tính lương.\n";
            else
            {
                cout << "Tìm nhân viên có lương cao nhất:\n";
                maxLuong = -1;
                for (i = 0; i < n; i++)
                {
                    if (maxLuong < nv[i]->getLuong())
                    {
                        maxLuong = nv[i]->getLuong();
                        j = i;
                    }
                }
                nv[j]->xuat();
            }
            break;
        case 8:
            if (lc == 0)
                cout << "Chưa có thông tin.\n";
            else if (lc2 == 0)
                cout << "Chưa tính lương.\n";
            else
            {
                cout << "Tìm nhân viên có số sản phẩm thấp nhất:\n";
                minSoSP = 9999;
                for (i = 0; i < n; i++)
                {
                    if (nv[i]->getSoSP() != -1 && minSoSP > nv[i]->getSoSP())
                    {
                        minSoSP = nv[i]->getSoSP();
                        j = i;
                    }
                }
                nv[j]->xuat();
            }
            break;
        case 9:
            if (lc == 0)
                cout << "Chưa có thông tin.\n";
            else if (lc2 == 0)
                cout << "Chưa tính lương.\n";
            else
            {
                cout << "Top 10 nhân viên có số sản phẩm nhiều nhất:\n";
                //Tìm nhân viên có số sản phẩm nhiều nhất
                k = t = 0; 
                maxSoSP = -9999;
                for (i = 0; i < n; i++)
                {
                    if (nv[i]->getSoSP() != -1)
                    {
                        if (maxSoSP < nv[i]->getSoSP())
                        {
                            maxSoSP = nv[i]->getSoSP();
                            if (t > 9)
                            {
                                t--;
                                for (j = 0; j < t; j++)
                                    topTen[j] = topTen[j+1];
                            }
                        }
                        else
                            if (topTen[t] != -1)
                                t++;
                        topTen[t] = i;
                        k++;
                    }
                }
                for (i = 0; i < k; i++)
                    nv[topTen[i]]->xuat();
            }
            break;
        }
        cout << endl;
    }
}