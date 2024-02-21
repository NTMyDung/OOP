#include "tamgiac.h"
#include <iostream>
using namespace std;
int TAMGIAC::dem=0;
TAMGIAC::~TAMGIAC(){
    cout<<"Da huy 1 TG => Con "<<--dem<<" TG\n";
}
TAMGIAC::TAMGIAC():A(0,0),B(1,0), C(0,1){
    dem++;
}
TAMGIAC::TAMGIAC(const DIEM& A, const DIEM& B, const DIEM& C): A(A), B(B), C(C){
    if(!KiemTraHopLe()) Nhap();
    dem++;
}

TAMGIAC::TAMGIAC(double xA, double yA,double xB,double yB,double xC,double yC): A(xA, yA), B(xB, yB), C(xC, yC){
    if(!KiemTraHopLe()) Nhap();
    dem++;
}
DIEM TAMGIAC::GetA() const{
    return A;
}
DIEM TAMGIAC::GetB() const{
    return B;
}
DIEM TAMGIAC::GetC() const{
    return C;
}
int TAMGIAC::GetDem(){
    return dem;
}
void TAMGIAC::SetA(const DIEM& A){
    this->A=A;
    while(!KiemTraHopLe()){
        cout<<"Nhap toa do dinh A:\n";
        this->A.Nhap();
    }
}
void TAMGIAC::SetB(const DIEM& B){
    this->B=B;
    while(!KiemTraHopLe()){
        cout<<"Nhap toa do dinh B:\n";
        this->B.Nhap();
    }
}
void TAMGIAC::SetC(const DIEM& C){
    this->C=C;
    while(!KiemTraHopLe()){
        cout<<"Nhap toa do dinh C:\n";
        this->C.Nhap();
    }
}
void TAMGIAC::SetABC(const DIEM& A, const DIEM& B, const DIEM& C){
    SetA(A);
    SetB(B);
    SetC(C);
}
void TAMGIAC::Nhap(){
    do{
        cout<<"Nhap toa do 3 dinh tam giac:\n";
        A.Nhap();
        B.Nhap();
        C.Nhap();
    }while(!KiemTraHopLe());
}
void TAMGIAC::Xuat() const{
    cout<<"TG qua 3 diem ";
    cout<<"A(";A.Xuat();cout<<") ";
    cout<<"B(";B.Xuat();cout<<") ";
    cout<<"C(";C.Xuat();cout<<") ";
    //cout<<"=> Phan loai: "<<PhanLoai();
    cout<<"\tDien tich: "<<TinhDienTich();
    cout<<"\tChu vi: "<<TinhChuVi()<<endl;
}
bool TAMGIAC::KiemTraHopLe() const{
    return A.KiemTraTamGiacHopLe(B, C);
}
/*
string TAMGIAC::PhanLoai() const{
    return A.PhanLoaiTamGiac(B, C);
}
*/
double TAMGIAC::TinhChuVi() const{
    return A.TinhChuViTamGiac(B,C);
}
double TAMGIAC::TinhDienTich() const{
    return A.TinhDienTichTamGiac(B, C);
}

