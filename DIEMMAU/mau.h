#ifndef MAU_H
#include <iostream>
using namespace std;
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
#endif // MAU_H
