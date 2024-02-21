
#include "diemm.h"
#define epsilon 0.0000000001
int DIEMM::dem=0;

DIEMM::~DIEMM(){
    dem--;
}
DIEMM::DIEMM(double x, double y):x(x), y(y){
    dem++;
}
DIEMM::DIEMM(const DIEMM& d): x(d.x), y(d.y){
    dem++;
}
double DIEMM::GetX() const{
    return x;
}
double DIEMM::GetY() const{
    return y;
}
int DIEMM::GetDem(){
    return dem;
}
void DIEMM::SetX(double x) {
    this->x=x;
}
void DIEMM::SetY(double y) {
    this->y=y;
}
void DIEMM::SetXY(double x, double y) {
    this->x=x;
    this->y=y;
}
void DIEMM::Nhap(){
    cout<<"Nhap hoanh do: ";
    cin>>x;
    cout<<"Nhap tung do: ";
    cin>>y;
}
void DIEMM::Xuat()const {
    cout<<x<<","<<y;
}
void DIEMM::DiChuyen(double dx, double dy){
    x+=dx;
    y+=dy;
}
bool DIEMM::KiemTraTrung(const DIEMM &d)const{
    return this->x==d.x&&this->y==d.y;
}
double DIEMM::TinhKhoangCach(const DIEMM &d)const{
    return sqrt(pow(x-d.x,2)+pow(y-d.y,2));
}
DIEMM DIEMM::TimDoiXung() const{
    return DIEMM(-this->x==0? this->x: -this->x, -this->y==0? this->y: -this->y);
}
bool DIEMM::KiemTraTamGiacHopLe(const DIEMM& d1, const DIEMM& d2) const{
    double a= this->TinhKhoangCach(d1);
    double b= d1.TinhKhoangCach(d2);
    double c= d2.TinhKhoangCach(*this);
    return a>0 && b>0 && c>0 &&a+b>c && a+c>b && b+c>a;
}
bool DIEMM::KiemTraTamGiacHopLe(double a, double b, double c) const{
    return a>0 && b>0 && c>0 &&a+b>c && a+c>b && b+c>a;
}
double DIEMM::TinhChuViTamGiac (const DIEMM& d1, const DIEMM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b= d1.TinhKhoangCach(d2);
    double c= d2.TinhKhoangCach(*this);
    return KiemTraTamGiacHopLe(d1, d2) ? a+b+c: 0;
}
double DIEMM::TinhDienTichTamGiac (const DIEMM& d1, const DIEMM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b= d1.TinhKhoangCach(d2);
    double c= d2.TinhKhoangCach(*this);
    double p = TinhChuViTamGiac(d1, d2)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
string DIEMM::PhanLoaiTamGiac (const DIEMM& d1, const DIEMM& d2)const{
    double a=this->TinhKhoangCach(d1);
    double b= d1.TinhKhoangCach(d2);
    double c= d2.TinhKhoangCach(*this);
    string chuoikq ="";
    if(!KiemTraTamGiacHopLe(d1,d2)){
        chuoikq="Tam giac khong hop le!\n";
    }
    else if (a==b&&b==c) chuoikq="Tam giac deu.\n";
    else if (a==b||b==c||a==c){
        if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(c*c+b*b-a*a)<=epsilon)
            chuoikq="Tam giac vuong can.";
        else chuoikq="Tam giac can.";
    }
    else if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(c*c+b*b-a*a)<=epsilon)
        chuoikq="Tam giac vuong.";
    else chuoikq="Tam giac thuong.";
    return chuoikq;
}


