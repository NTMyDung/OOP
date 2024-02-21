#ifndef PHANSO_H
#include<iostream>
#include <cmath>
using namespace std;

class PhanSo {
private:
    int ts;
    int ms;
public:
    PhanSo( double=1, double=1);
    void SetTs (int);
    void SetMs (int);
    void SetTMs ( int, int);
    int getTs ();
    int getMs ();
    void Nhap();
    int UCLN (int t, int m);
    void rutGonVaXuat();
    friend PhanSo operator+(PhanSo, PhanSo);
    friend PhanSo operator-(PhanSo, PhanSo);
    friend PhanSo operator*(PhanSo, PhanSo);
    friend PhanSo operator/(PhanSo, PhanSo);
    friend bool operator==(PhanSo, PhanSo);
    friend bool operator!=(PhanSo, PhanSo);
    friend bool operator>(PhanSo, PhanSo);
    friend bool operator>=(PhanSo, PhanSo);
    friend bool operator<(PhanSo, PhanSo);
    friend bool operator<=(PhanSo, PhanSo);
    friend istream& operator>>(istream&, PhanSo&);
    friend ostream& operator<<(ostream&, PhanSo&);

};
#endif // PHANSO_H
