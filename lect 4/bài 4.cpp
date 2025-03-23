#include <iostream>
#include <string>
using namespace std;

struct HocSinh
{
    int maSo;
    string hoTen;
    string lop;
    HocSinh* tiepTheo;
};

HocSinh* danhSach = nullptr;

void themHocSinh(int maSo, string hoTen, string lop)
{
    HocSinh* moi = new HocSinh{ maSo, hoTen, lop, danhSach };
    danhSach = moi;
}

void xoaHocSinh(int maSo)
{
    HocSinh* hienTai = danhSach;
    HocSinh* truocDo = nullptr;
    while (hienTai != nullptr && hienTai->maSo != maSo)
    {
        truocDo = hienTai;
        hienTai = hienTai->tiepTheo;
    }
    if (hienTai != nullptr)
    {
        if (truocDo == nullptr)
        {
            danhSach = hienTai->tiepTheo;
        }
        else
        {
            truocDo->tiepTheo = hienTai->tiepTheo;
        }
        delete hienTai;
    }
}

void thongTinHocSinh(int maSo)
{
    cout << "----------" << endl;
    HocSinh* hienTai = danhSach;
    while (hienTai != nullptr)
    {
        if (hienTai->maSo == maSo)
        {
            cout << hienTai->hoTen << "," << hienTai->lop << endl;
            return;
        }
        hienTai = hienTai->tiepTheo;
    }
    cout << "NA,NA" << endl;
}

void xuLyLenh(string lenh)
{
    if (lenh.substr(0, 6) == "Insert")
    {
        int maSo;
        string hoTen, lop;
        size_t viTri1 = lenh.find('(') + 1;
        size_t viTri2 = lenh.find(',', viTri1);
        maSo = stoi(lenh.substr(viTri1, viTri2 - viTri1));
        viTri1 = viTri2 + 1;
        viTri2 = lenh.find(',', viTri1);
        hoTen = lenh.substr(viTri1, viTri2 - viTri1);
        viTri1 = viTri2 + 1;
        viTri2 = lenh.find(')', viTri1);
        lop = lenh.substr(viTri1, viTri2 - viTri1);
        themHocSinh(maSo, hoTen, lop);
    }
    else if (lenh.substr(0, 6) == "Delete")
    {
        int maSo = stoi(lenh.substr(7));
        xoaHocSinh(maSo);
    }
    else if (lenh.substr(0, 5) == "Infor")
    {
        int maSo = stoi(lenh.substr(6));
        thongTinHocSinh(maSo);
    }
}

int main()
{
    string lenh;
    while (getline(cin, lenh))
    {
        xuLyLenh(lenh);
    }
    return 0;
}
