#include "hcn.h"

int HCN::dem=0;
HCN::~HCN(){
    cout<<"Da huy 1 HCN => Con "<<--dem<<" HCN\n";
}
HCN::HCN():A(1,0),B(0,1){
    dem++;
}
HCN::HCN(const DIEMM& A, const DIEMM& B): A(A), B(B){
    if(!KiemTraHopLe()) Nhap();
    dem++;
}

HCN::HCN(double xA, double yA,double xB,double yB): A(xA, yA), B(xB, yB){
    if(!KiemTraHopLe()) Nhap();
    dem++;
}
DIEMM HCN::GetA() const{
    return A;
}
DIEMM HCN::GetB() const{
    return B;
}
int HCN::GetDem(){
    return dem;
}
void HCN::SetA(const DIEMM& A){
    this->A=A;
    while(!KiemTraHopLe()){
        cout<<"Nhap toa do dinh A:\n";
        this->A.Nhap();
    }
}
void HCN::SetB(const DIEMM& B){
    this->B=B;
    while(!KiemTraHopLe()){
        cout<<"Nhap toa do dinh B:\n";
        this->B.Nhap();
    }
}
void HCN::SetAB(const DIEMM& A, const DIEMM& B){
    SetA(A);
    SetB(B);
}
void HCN::Nhap(){
    do{
        cout<<"Nhap toa do 2 dinh duong cheo cua HCN:\n";
        A.Nhap();
        B.Nhap();
    }while(!KiemTraHopLe());
}
void HCN::Xuat() const{
    cout<<"HCN co duong cheo AB voi ";
    cout<<"A(";A.Xuat();cout<<") ";
    cout<<"B(";B.Xuat();cout<<") ";
    cout<<"\tDien tich: "<<TinhDienTich();
    cout<<"\tChu vi: "<<TinhChuVi()<<endl;
}
HCN HCN::DiChuyen( double dx, double dy){
    A.DiChuyen(dx, dy);
    B.DiChuyen(dx, dy);
}
bool HCN::KiemTraHopLe() const{
    return A.GetX()!=B.GetX()||A.GetY()!=B.GetY();
}

double HCN::TinhChuVi() const{
    if (A.GetX()!=B.GetX()&& A.GetY()!=B.GetY()) return 2*(abs(A.GetX()-B.GetX())+abs(A.GetY()-B.GetY()));
    else return 4*(A.TinhKhoangCach (B)/sqrt(2));
}
double HCN::TinhDienTich() const{
    if (A.GetX()!=B.GetX()&& A.GetY()!=B.GetY()) return abs(A.GetX()-B.GetX())*abs(A.GetY()-B.GetY());
    else return pow(A.TinhKhoangCach(B),2)/2;
}
istream& operator>>(istream& is, HCN& x){
    x.Nhap();
    return is;
}
ostream& operator<<(ostream& os, HCN& x){
    x.Xuat();
    return os;
}
