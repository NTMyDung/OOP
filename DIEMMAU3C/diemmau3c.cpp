#include "diemmau3c.h"
DIEMMAU3C::DIEMMAU3C(double a, double b, double c, int r, int g, int bl): DIEM3C(a,b,c), Red(r),Green(g), Blue(bl){
    if(r<0||r>255){
        cout<< "Chi so khong hop le!\n";
        setRed();
    }
    if(g<0||g>255){
        cout<< "Chi so khong hop le!\n";
        setGreen();
    }
    if(bl<0||bl>255){
        cout<< "Chi so khong hop le!\n";
        setBlue();
    }
}
DIEMMAU3C::~DIEMMAU3C(){}
DIEMMAU3C::DIEMMAU3C(const DIEMMAU3C& x){
    DIEM3C(DIEM3C(x));
    Red=x.Red;
    Green=x.Green;
    Blue=x.Blue;
}
void DIEMMAU3C::setRed(){
    int m;
    do{
        cout<< "Nhap chi so cua Red (tu 0->255): ";
        cin>>m;
    }while(m<0||m>255);
    Red=m;
}
void DIEMMAU3C::setGreen(){
    int m;
    do{
        cout<< "Nhap chi so cua Green (tu 0->255): ";
        cin>>m;
    }while(m<0||m>255);
    Green=m;
}
void DIEMMAU3C::setBlue(){
    int m;
    do{
        cout<< "Nhap chi so cua Blue (tu 0->255): ";
        cin>>m;
    }while(m<0||m>255);
    Blue=m;
}
void DIEMMAU3C::setRGB(){
    setRed();
    setGreen();
    setBlue();
}
int DIEMMAU3C::getRed(){
    return Red;
}
int DIEMMAU3C::getGreen(){
    return Green;
}
int DIEMMAU3C::getBlue(){
    return Blue;
}
bool DIEMMAU3C::KtraTrung(const DIEMMAU3C& x){
    return DIEM3C::KtraTrung(DIEM3C(x)) && Red==x.Red &&Green==x.Green &&Blue==x.Blue;
}
void DIEMMAU3C::Nhap(){
    DIEM3C::Nhap();
    setRed();
    setGreen();
    setBlue();
}
void DIEMMAU3C::Xuat(){
    DIEM3C::Xuat();
    cout<< ", Mau R-G-B: "<< "("<<Red<< ","<<Green<< ","<<Blue<< ")";
}
istream& operator>> (istream& is, DIEMMAU3C& x){
    x.Nhap();
    return is;
}
ostream& operator<< (ostream& os, DIEMMAU3C& x){
    x.Xuat();
    return os;
}
