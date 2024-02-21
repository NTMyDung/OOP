#include "diemmau.h"

DIEMMAU::DIEMMAU(double x, double y, int r, int g, int b):DIEMM(x,y),MAU(r,g,b) {
}
DIEMMAU::~DIEMMAU(){}
DIEMMAU::DIEMMAU(const DIEMMAU& x){
    DIEMM(DIEMM(x));
    MAU(MAU(x));
}
void DIEMMAU::Nhap(){
    DIEMM::Nhap();
    MAU::Nhap();
}
void DIEMMAU::Xuat(){
    DIEMM::Xuat();
    MAU::Xuat();
}
istream& operator>>(istream& is, DIEMMAU& x){
    x.Nhap();
    return is;
}
ostream& operator<<(ostream& os, DIEMMAU& x){
    x.Xuat();
    return os;
}
