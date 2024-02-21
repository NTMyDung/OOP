#pragma once
#ifndef DIEMMAU_H
#include "diem2c.h"
#include "mau.h"
class DIEMMAU: public DIEMM, public MAU{
public:
    DIEMMAU(double=0, double=0, int=0, int =0, int =0);
    ~DIEMMAU();
    DIEMMAU(const DIEMMAU&);
    void Nhap();
    void Xuat();
    friend istream& operator>>(istream&, DIEMMAU&);
    friend ostream& operator<<(ostream&, DIEMMAU&);
} ;
#endif // DIEMMAU_H
