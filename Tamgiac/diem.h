#ifndef _DIEM_H
#include <iostream>
#include <math.h>
#include <string>
class DIEM{
private:
    double x, y;
    static int dem;
public:
    ~DIEM();
    DIEM(double=0, double=0);
    DIEM(const DIEM&);
    double GetX() const;
    double GetY() const;
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    static int GetDem();
    void Nhap();
    void Xuat()const;
    void DiChuyen (double, double);
    bool KiemTraTrung(const DIEM&) const;
    double TinhKhoangCach(const DIEM&) const;
    DIEM TimDoiXung() const;
    bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
    bool KiemTraTamGiacHopLe(double, double, double) const;
    double TinhChuViTamGiac (const DIEM&, const DIEM&) const;
    double TinhDienTichTamGiac (const DIEM&, const DIEM&) const;
    //string PhanLoaiTamGiac (const DIEM&, const DIEM&)const;
};
#endif // _DIEM_H
