#include "mau.h"
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
