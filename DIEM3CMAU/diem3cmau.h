#ifndef DIEM3CMAU_H
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
    bool KtraTrung(const DIEMM&) const;
    double TinhKhoangCach(const DIEMM&) const;
    DIEMM TimDoiXung() const;
    bool KiemTraTamGiacHopLe(const DIEMM&, const DIEMM&) const;
    bool KiemTraTamGiacHopLe(double, double, double) const;
    double TinhChuViTamGiac (const DIEMM&, const DIEMM&) const;
    double TinhDienTichTamGiac (const DIEMM&, const DIEMM&) const;
    string PhanLoaiTamGiac (const DIEMM&, const DIEMM&)const;
    friend istream& operator>>(istream&, DIEMM&);
    friend ostream& operator<<(ostream&, DIEMM&);
};
class DIEM3C: public DIEMM{
protected:
    double z;
public:
    DIEM3C(double=0, double=0, double=0);
    ~DIEM3C();
    void setZ(double);
    void setXYZ(double, double, double);
    double getZ();
    bool KtraTrung(const DIEM3C&);
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
class MAU{
protected:
    int Red, Green, Blue;
public:
    MAU(int =0, int =0, int =0);
    ~MAU();
    MAU(const MAU&);
    void setRed();
    void setGreen();
    void setBlue();
    void setRGB();
    int getRed();
    int getGreen();
    int getBlue();
    bool KtraTrung(const MAU&);
    void Nhap();
    void Xuat();
    friend istream& operator>> (istream&, MAU&);
    friend ostream& operator<< (ostream&, MAU&);
};
class DIEM3CMAU: public DIEM3C, public MAU{
public:
    DIEM3CMAU(double=0, double =0, double=0, int =0, int =0, int=0);
    ~DIEM3CMAU();
    DIEM3CMAU(const DIEM3CMAU&);
    void Nhap();
    void Xuat();
    friend istream& operator>>(istream&, DIEM3CMAU&);
    friend ostream& operator<<(ostream&, DIEM3CMAU&);
};

#endif // DIEM3CMAU_H
