#pragma once
#include "phanso.h"
PhanSo::PhanSo(double ts, double ms){
    this->ts=ts;;
    this->ms=ms;
}
void PhanSo:: SetTs ( int ts){
    this->ts=ts;
}
void PhanSo::SetMs ( int ms){
    this->ms=ms;
}
int PhanSo::getTs (){
    return ts;
}
int PhanSo::getMs (){
    return ms;
}
void PhanSo::Nhap(){
    cout<<"Tu so: ";
    cin>>ts;
    do{
    cout<<"Mau so (khac 0): ";
    cin>>ms;
    }while(ms==0);
}
int PhanSo::UCLN (int t, int m){
    if (m==0) return t;
    else return UCLN(m, t % m);
}
void PhanSo:: rutGonVaXuat(){
    int k=UCLN(ts, ms);
    ts=ts/k;
    ms=ms/k;
    if (ms <-1) cout<<-ts<<"/"<<-ms;
    else if (ms==-1) cout<<-ts;
    else if (ms==0) cout<<"Khong chia cho so 0";
    else if (ms==1) cout<<ts;
    else cout<<ts<<"/"<<ms;
}
PhanSo operator+(PhanSo x, PhanSo y){
    return  PhanSo( x.ts*y.ms+y.ts*x.ms, x.ms*y.ms);
}
PhanSo operator-(PhanSo x, PhanSo y){
    return  PhanSo( x.ts*y.ms-y.ts*x.ms, x.ms*y.ms);
}
PhanSo operator*(PhanSo x, PhanSo y){
    return PhanSo(x.ts*y.ts, x.ms*y.ms);
}
PhanSo operator/(PhanSo x, PhanSo y){
    return PhanSo(x.ts*y.ms, x.ms*y.ts);
}
bool operator==(PhanSo x, PhanSo y){
    return x.ts*y.ms==y.ts*x.ms;
}
bool operator!=(PhanSo x, PhanSo y){
    return x.ts*y.ms!=y.ts*x.ms;
}
bool operator>(PhanSo x, PhanSo y){
    return x.ts*y.ms>y.ts*x.ms;
}
bool operator>=(PhanSo x, PhanSo y){
    return x.ts*y.ms>=y.ts*x.ms;
}
bool operator<(PhanSo x, PhanSo y){
    return x.ts*y.ms<y.ts*x.ms;
}
bool operator<=(PhanSo x, PhanSo y){
    return x.ts*y.ms<=y.ts*x.ms;
}
istream& operator>>(istream &is, PhanSo &ps){
    ps.Nhap();
    return is;
}
ostream& operator<<(ostream& os, PhanSo&x){
    x.rutGonVaXuat();
    return os;
}
