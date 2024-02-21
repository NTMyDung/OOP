#ifndef DATHUC__H
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
class DATHUC{
private:
    float a, b, c;
public:
    DATHUC(double=1, double=0, double=0);
    ~DATHUC();
    DATHUC(const DATHUC&);
    void setB2(double);
    void setB1(double);
    void setB0(double);
    double getB2();
    double getB1();
    double getB0();
    void NhapAuto();
    void Nhap();
    void Xuat();
    float GTTaiDiem(float);
    void GiaiPT();
    friend DATHUC operator+(DATHUC , DATHUC);
    friend istream& operator>>(istream&, DATHUC&);
    friend ostream& operator<<(ostream&, DATHUC&);

};
#endif // DATHUC__H
