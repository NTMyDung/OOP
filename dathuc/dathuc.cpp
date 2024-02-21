#include "dathuc.h"

DATHUC::DATHUC(double a, double b, double c){
   double x=a;
   while(x==0){
    cout<< "Da thuc bac 2, he so x^2 khong the bang 0. Moi ban nhap lai.\n";
    cin>>x;
   }while(x==0);
   this->a=x;
   this->b=b;
   this->c=c;
}
DATHUC::~DATHUC(){
}
DATHUC::DATHUC(const DATHUC& x): a(x.a), b(x.b), c(x.c){
}
void DATHUC::setB2(double a){
    this->a=a;
}
void DATHUC::setB1(double b){
    this->b=b;
}
void DATHUC::setB0(double c){
    this->c=c;
}
double DATHUC::getB2(){
    return a;
}
double DATHUC::getB1(){
    return b;
}
double DATHUC::getB0(){
    return c;
}
void DATHUC:: Nhap(){
    double x;
    do{
        cout<< "Nhap he so x^2 (khac 0): ";
        cin>>x;
    }while(x==0);
    this->a=x;
    cout<< "Nhap he so x^1: "; cin>>b;
    cout<< "Nhap he so tu do: "; cin>>c;
}
void DATHUC::NhapAuto(){
    srand(time(NULL));
    a=rand()%100+1;
    b=rand()%100;
    c=rand()%100;
}
void DATHUC::Xuat(){
    if(a!=0){
        if(a==1) cout<< "x^2";
        else if(a==-1) cout<< "-x^2";
        else cout<<a<< "x^2";
    }
    if(b!=0){
        if(b>0&&a!=0) cout<< "+";
        if(b==1) cout<< "x";
        else if(b==-1) cout<< "-x";
        else cout<<b<< "x";
    }
    if(c!=0){
        if(c>0&&b!=0) cout<< "+";
        cout<<c;
    }
}
float DATHUC::GTTaiDiem(float x){
   return (float)a*x*x+b*x+c;
}
void DATHUC::GiaiPT(){
    float delta=b*b-4*a*c;
    if(delta<0) cout<< "Phuong trinh vo nghiem.\n";
    else if(delta>0) cout<< "Phuong trinh co 2 nghiem phan biet: x1 = "<<(-b+sqrt(delta))/(2.0*a)<< "\tx2 = "<<(-b-sqrt(delta))/(2.*a)<<endl;
    else cout<< "Phuong trinh co nghiem kep x1 = x2 = "<<-b/(2.0*a)<<endl;
}
DATHUC operator+(DATHUC x, DATHUC y){
    DATHUC re;
    re.setB2(x.getB2()+y.getB2());
    re.setB1(x.getB1()+y.getB1());
    re.setB0(x.getB0()+y.getB0());
    return re;
}

istream& operator>>(istream& is, DATHUC& x){
    x.Nhap();
    return is;
}
ostream& operator<<(ostream& os, DATHUC& x){
    x.Xuat();
    return os;
}
