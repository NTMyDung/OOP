#pragma once
#ifndef DIEM3C_H
#include "diem2c.h"
class DIEM3C: public DIEMM{
protected:
    double z;
public:
    DIEM3C(double=0, double=0, double=0);
    ~DIEM3C();
    void setZ(double);
    void setXYZ(double, double, double);
    double getZ();
    bool KtraTrung(DIEM3C);
    void DiChuyen(double, double, double);
    double KhoangCach(DIEM3C);
    DIEM3C DoiXung() const;
    void Nhap();
    void Xuat();
    bool KTTamGiacHopLe(DIEM3C, DIEM3C);
    double ChuViTamGiac(DIEM3C, DIEM3C);
    double DienTichTamGiac(DIEM3C, DIEM3C);
    friend istream& operator>>(istream&, DIEM3C&);
    friend ostream& operator<<(ostream&, DIEM3C&);
};
#endif // DIEM3C_H
