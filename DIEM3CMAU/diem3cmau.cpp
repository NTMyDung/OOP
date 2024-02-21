#include "diem3cmau.h"
#define epsilon 0.0000000001
DIEMM::~DIEMM(){

}
DIEMM::DIEMM(double x, double y):x(x), y(y){

}
DIEMM::DIEMM(const DIEMM& d): x(d.x), y(d.y){
}
double DIEMM::GetX() const{
    return x;
}
double DIEMM::GetY() const{
    return y;
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
    cout<<"Toa do: ("<<x<<","<<y<<")";
}
void DIEMM::DiChuyen(double dx, double dy){
    x+=dx;
    y+=dy;
}
bool DIEMM::KtraTrung(const DIEMM &d)const{
    return this->x==d.x&&this->y==d.y;
}
double DIEMM::TinhKhoangCach(const DIEMM &d)const{
    return sqrt(pow(x-d.x,2)+pow( y-d.y,2));
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
istream& operator>> (istream&is, DIEMM& x){
    x.Nhap();
    return is;
}
ostream& operator<< (ostream& os, DIEMM& x){
    x.Xuat();
    return os;
}
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
bool DIEM3C::KtraTrung(const DIEM3C& B){
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
    cout<< "("<<x<< ","<<y<< ","<<z<< ")";
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
MAU::MAU(int r, int g, int b): Red(r), Green(g), Blue(b){
    if(r<0||r>255){
        cout<< "Chi so khong hop le!\n";
        setRed();
    }
    if(g<0||g>255){
        cout<< "Chi so khong hop le!\n";
        setGreen();
    }
    if(b<0||b>255){
        cout<< "Chi so khong hop le!\n";
        setBlue();
    }
}
MAU::~MAU(){}
MAU::MAU(const MAU& x){
    Red=x.Red;
    Green=x.Green;
    Blue=x.Blue;
}
void MAU::setRed(){
    int m;
    do{
        cout<< "Nhap chi so cua Red (tu 0->255): ";
        cin>>m;
    }while(m<0||m>255);
    Red=m;
}
void MAU::setGreen(){
    int m;
    do{
        cout<< "Nhap chi so cua Green (tu 0->255): ";
        cin>>m;
    }while(m<0||m>255);
    Green=m;
}
void MAU::setBlue(){
    int m;
    do{
        cout<< "Nhap chi so cua Blue (tu 0->255): ";
        cin>>m;
    }while(m<0||m>255);
    Blue=m;
}
void MAU::setRGB(){
    setRed();
    setGreen();
    setBlue();
}
int MAU::getRed(){
    return Red;
}
int MAU::getGreen(){
    return Green;
}
int MAU::getBlue(){
    return Blue;
}
bool MAU::KtraTrung(const MAU& x){
    return Red==x.Red &&Green==x.Green &&Blue==x.Blue;

}
void MAU::Nhap(){
    setRGB();
}
void MAU::Xuat(){
    cout<< ", Mau R-G-B: "<< "("<<Red<< ","<<Green<< ","<<Blue<< ")";
}
istream& operator>> (istream&is, MAU& x){
    x.Nhap();
    return is;
}
ostream& operator<< (ostream& os, MAU& x){
    x.Xuat();
    return os;
}
DIEM3CMAU::DIEM3CMAU(double a, double b, double c, int r, int g, int bl):DIEM3C(a,b,c),MAU(r, g, bl){
}
DIEM3CMAU::~DIEM3CMAU(){}
DIEM3CMAU::DIEM3CMAU(const DIEM3CMAU& d){
    x=d.x;
    y=d.y;
    z=d.z;
    Red=d.Red;
    Green=d.Green;
    Blue=d.Blue;
}
void DIEM3CMAU::Nhap(){
    DIEM3C::Nhap();
    MAU::Nhap();
}
void DIEM3CMAU::Xuat(){
    DIEM3C::Xuat();
    MAU::Xuat();
}
istream& operator>>(istream& is, DIEM3CMAU& x){
    x.Nhap();
    return is;
}
ostream& operator<<(ostream& os, DIEM3CMAU& x){
    x.Xuat();
    return os;

}


