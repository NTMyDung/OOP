#include "thuvien.h"

NHANVIEN::NHANVIEN(string ms, string ten, string phong):ms(ms), ten(ten), phong(phong){}
NHANVIEN:: ~NHANVIEN(){}
void NHANVIEN::setTen(string ten){ this->ten=ten;}
void NHANVIEN::setPhong(string phong){this->phong=phong;}
string NHANVIEN::getMS(){return ms;}
string NHANVIEN::getTen(){return ten;}
string NHANVIEN::getPhong(){return phong;}
void NHANVIEN::setHSLuong(double l){return;}
void NHANVIEN::setHSPCCV(double pccv){return;}
void NHANVIEN::setTienCong(int TienCong){return;}
void NHANVIEN::setSoNgayCong(int SoNgayCong){return;}
void NHANVIEN::setHSVuotGio(double HSVuotGio){return;}
double NHANVIEN::getHSLuong(){return -1;}
double NHANVIEN::getHSPCCV(){return -1;}
int NHANVIEN::getTienCong(){return -1;}
int NHANVIEN::getSoNgayCong(){return -1;}
double NHANVIEN::getHSVuotGio(){return -1;}
void NHANVIEN::Nhap(){
    cin.ignore();
    cout<< "Nhap ma so: "; getline(cin, ms);
    cout<< "Nhap ho va ten: "; getline(cin, ten);
    cout<< "Nhap phong ban: "; getline(cin, phong);
}
void NHANVIEN::Xuat(){
    cout<< "Ma So: "<<ms<<endl;
    cout<< "Ho va ten: "<<ten<<endl;
    cout<< "Phong: "<<phong<<endl;
}
HOPDONG::HOPDONG(string ms, string ten, string phong, int TienCong, int SoNgayCong, double HSVuotGio):NHANVIEN(ms, ten, phong), SoNgayCong(SoNgayCong), HSVuotGio(HSVuotGio){}
HOPDONG::~HOPDONG(){}
void HOPDONG::setTienCong(int TC){
   while(TC<0){
    cout<< "Nhap tien cong: "; cin>>TC;
   }
   TienCong=TC;
}
void HOPDONG::setSoNgayCong(int SNC){
    while(SNC<0){
        cout<< "Nhap so ngay cong: "; cin>>SNC;
    }
    SoNgayCong=SNC;
}
void HOPDONG::setHSVuotGio(double HSVg){
    while(HSVg<0){
        cout<< "Nhap he so vuot gio: "; cin>>HSVg;
    }
    HSVuotGio=HSVg;
}
int HOPDONG::getSoNgayCong(){ return SoNgayCong;}
int HOPDONG::getTienCong(){return TienCong;}
double HOPDONG::getHSVuotGio(){ return HSVuotGio;}
void HOPDONG::Nhap(){
    NHANVIEN::Nhap();
    do{
    cout<< "Tien cong: "; cin>>TienCong;
    }while(TienCong<0);
    do{
    cout<< "So Ngay Cong: "; cin>>SoNgayCong;
    }while(SoNgayCong<0);
    do{
    cout<< "He so vuot gio: "; cin>>HSVuotGio;
    }while(HSVuotGio<0);
}
void HOPDONG::Xuat(){
    NHANVIEN::Xuat();
    cout<< "Tien cong: "<<TienCong<<endl;
    cout<< "SoNgayCong: "<<SoNgayCong<<endl;
    cout<< "He so vuot gio: "<<HSVuotGio<<endl;
    cout<< "Tien luong: "<<TienLuong()<<endl;
}
long HOPDONG::TienLuong(){
    return TienCong*SoNgayCong*(1+HSVuotGio);
}
string HOPDONG::getLoai(){ return "Nhan vien hop dong";}
BIENCHE::BIENCHE(string ms, string ten, string phong,double HSLuong, double HSPCCV): NHANVIEN(ms, ten, phong), HSLuong(HSLuong), HSPCCV(HSPCCV){}
BIENCHE::~BIENCHE(){}
void BIENCHE::setHSLuong(double l){
    while(l<0){
        cout<< "Nhap he so Luong: ";
        cin>>l;
    }
    HSLuong=l;
}
void BIENCHE::setHSPCCV(double pc){
    while(pc<0){
        cout<< "Nhap he so phu cap chuc vu: "; cin>>pc;
    }
    HSPCCV= pc;
}
double BIENCHE::getHSLuong(){return HSLuong;}
double BIENCHE::getHSPCCV(){ return HSPCCV;}
void BIENCHE::Nhap(){
    NHANVIEN::Nhap();
    do{
        cout<< "Nhap he so Luong: ";
        cin>>HSLuong;
    }while(HSLuong<0);
    do{
        cout<< "Nhap he so phu cap chuc vu: ";
        cin>>HSPCCV;
    }while(HSPCCV<0);
}
void BIENCHE::Xuat(){
    NHANVIEN::Xuat();
    cout<< "He so luong: "<<HSLuong<<endl;
    cout<< "He so phu cap chuc vu: "<<HSPCCV<<endl;
    cout<< "Tien luong: "<<TienLuong()<<endl;
}
long BIENCHE::TienLuong(){
        return (1+HSLuong+HSPCCV)*1000;
}
string BIENCHE::getLoai(){ return "Nhan vien bien che";}

