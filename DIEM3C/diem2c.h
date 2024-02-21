#pragma once
#ifndef DIEM2C_H
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class DIEMM{
protected:
    double x, y;
public:
    ~DIEMM();
    DIEMM(double=0, double=0);
    DIEMM(const DIEMM&);
    double GetX() const;
    double GetY() const;
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void Nhap();
    void Xuat()const;
    void DiChuyen (double, double);
    bool KiemTraTrung(const DIEMM&) const;
    double TinhKhoangCach(const DIEMM&) const;
    DIEMM TimDoiXung() const;
    bool KiemTraTamGiacHopLe(const DIEMM&, const DIEMM&) const;
    bool KiemTraTamGiacHopLe(double, double, double) const;
    double TinhChuViTamGiac (const DIEMM&, const DIEMM&) const;
    double TinhDienTichTamGiac (const DIEMM&, const DIEMM&) const;
    string PhanLoaiTamGiac (const DIEMM&, const DIEMM&)const;
};
#endif

