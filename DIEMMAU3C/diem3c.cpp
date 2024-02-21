#include "diem3c.h"

DIEM3C::DIEM3C(double x, double y, double z):DIEMM(x,y), z(z){
}
DIEM3C:: ~DIEM3C(){

}
void DIEM3C::setZ(double z){
    this->z=z;
}
void DIEM3C::setXYZ(double a, double b, double c){
    SetXY(a,b);
    setZ(c);
}
double DIEM3C::getZ(){
    return z;
}
bool DIEM3C::KtraTrung(DIEM3C B){
    return x==B.x && y==B.y && this->z==B.z;
}
void DIEM3C::DiChuyen (double m, double n, double k){
    DIEMM::DiChuyen(m,n);
    z+=k;
}
double DIEM3C::KhoangCach(DIEM3C B){
    return sqrt((x- B.x)*(x- B.x)+ (y-B.y)*(y-B.y) + (z-B.z)*(z-B.z));
}
DIEM3C DIEM3C::DoiXung() const{
    return DIEM3C(-this->x==0 ? this->x : -this->x, -this->y==0 ? this->y : -this->y, -this->z==0 ? this->z : -this->z);
}
void DIEM3C::Nhap(){
    DIEMM::Nhap();
    cout<<"Nhap cao do: ";
    cin>>z;
}
void DIEM3C::Xuat(){
    cout<<"Toa do: "<< "("<<x<< ","<<y<< ","<<z<< ")";
}
bool DIEM3C::KTTamGiacHopLe( DIEM3C d1, DIEM3C d2){
    double a=this->KhoangCach(d1);
    double b=d1.KhoangCach(d2);
    double c=d2.KhoangCach(*this);
    return a>0 && b>0 && c>0 &&a+b>c && a+c>b && b+c>a;
}
double DIEM3C::ChuViTamGiac( DIEM3C d1, DIEM3C d2){
    double a=this->KhoangCach(d1);
    double b=d1.KhoangCach(d2);
    double c=d2.KhoangCach(*this);
    return KTTamGiacHopLe(d1,d2) ? a+b+c : 0;
}
double DIEM3C::DienTichTamGiac( DIEM3C d1, DIEM3C d2){
    double a=this->KhoangCach(d1);
    double b=d1.KhoangCach(d2);
    double c=d2.KhoangCach(*this);
    double p=(a+b+c)/2;
    return KTTamGiacHopLe(d1,d2) ? sqrt(p*(p-a)*(p-b)*(p-c)): 0;
}
istream& operator>>(istream& is, DIEM3C& d){
    d.Nhap();
    return is;
}
ostream& operator<<(ostream& os, DIEM3C& d){
    d.Xuat();
    return os;
}

