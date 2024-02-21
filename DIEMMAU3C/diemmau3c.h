#ifndef  DIEMMAU3C_H
#include "diem3c.h"
class DIEMMAU3C: public DIEM3C{
protected:
    int Red, Green, Blue;
public:
    DIEMMAU3C(double=0, double=0, double=0, int =0, int =0, int =0);
    ~DIEMMAU3C();
    DIEMMAU3C(const DIEMMAU3C&);
    void setRed();
    void setGreen();
    void setBlue();
    void setRGB();
    int getRed();
    int getGreen();
    int getBlue();
    bool KtraTrung(const DIEMMAU3C&);
    void Nhap();
    void Xuat();
    friend istream& operator>> (istream&, DIEMMAU3C&);
    friend ostream& operator<< (ostream&, DIEMMAU3C&);

};

#endif // DIEMMAU3C_H
