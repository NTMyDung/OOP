
#pragma once
#ifndef hcn_h
#include "diemm.h"
class HCN {
private:
    DIEMM A,B,C,D;
    static int dem;
public:
    ~HCN();
    HCN();
    HCN(const DIEMM&, const DIEMM&);
    HCN(double, double, double, double);
    DIEMM GetA() const;
    DIEMM GetB() const;
    static int GetDem();
    void SetA(const DIEMM&);
    void SetB(const DIEMM&);
    void SetAB(const DIEMM&, const DIEMM&);
    void Nhap();
    void Xuat()const;
    HCN DiChuyen(double, double);
    bool KiemTraHopLe()const;
    double TinhChuVi() const;
    double TinhDienTich() const;
    friend istream& operator>>(istream&, HCN&);
    friend ostream& operator<<(ostream&, HCN&);
};
#endif // hcn_h
