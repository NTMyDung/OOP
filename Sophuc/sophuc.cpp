#include "sophuc.h"
#include <cmath>
SoPhuc::SoPhuc(double thuc, double ao){
  this->thuc = thuc;
  this->ao = ao;
}
istream& operator>>(istream &is, SoPhuc &ps){
  cout << "Nhap gia tri thuc, ao: ";
  is >> ps.thuc >> ps.ao;
  return is;
}
void SoPhuc::Xuat(){
    if(ao<0){
        cout<<thuc<<" - ";
        if(ao==-1) cout<<"i";
        else cout<<abs(ao)<<"i";
    }
    else if(ao>0){
        cout<<thuc<<" + ";
        if(ao==1) cout<<"i";
        else cout<<ao<<"i";
    }
    else cout<<thuc;
}
ostream& operator<<(ostream &os, SoPhuc ps){
  ps.Xuat();
  return os;
}
double SoPhuc::GetThuc(){
  return thuc;
}
double SoPhuc::GetAo(){
  return ao;
}
void SoPhuc::SetThuc(){
  double thuc;
  cout << "Nhap gia tri thuc: "; cin >> thuc;
  this->thuc = thuc;
}
void SoPhuc::SetAo(){
  double ao;
    cout << "Nhap gia tri ao: "; cin >> ao;
  this->ao = ao;
}
void SoPhuc::SetSoPhuc(){
  SetThuc();
  SetAo();
}
SoPhuc operator+(SoPhuc A, SoPhuc B){
  return SoPhuc(A.thuc + B.thuc, A.ao + B.ao);
}
SoPhuc operator-(SoPhuc A, SoPhuc B){
  return SoPhuc(A.thuc - B.thuc, A.ao - B.ao);
}
SoPhuc operator*(SoPhuc A, SoPhuc B){
  return SoPhuc(A.thuc * B.thuc - A.ao * B.ao, A.thuc * B.ao + A.ao * B.thuc);
}
SoPhuc operator/(SoPhuc A, SoPhuc B){
  double thuc = (A.thuc * B.thuc - A.thuc * B.ao)/(pow(B.thuc, 2) + pow(B.ao, 2));
  double ao = (B.thuc * A.ao - A.thuc * B.ao)/(pow(B.thuc, 2) + pow(B.ao, 2));
  return SoPhuc(thuc, ao);
}
bool operator==(SoPhuc A, SoPhuc B){
  return sqrt(pow(A.thuc, 2) + pow(A.ao, 2)) == sqrt(pow(B.thuc, 2) + pow(B.ao, 2));
}
bool operator!=(SoPhuc A, SoPhuc B){
  return sqrt(pow(A.thuc, 2) + pow(A.ao, 2)) != sqrt(pow(B.thuc, 2) + pow(B.ao, 2));
}
bool operator>(SoPhuc A, SoPhuc B){
  return sqrt(pow(A.thuc, 2) + pow(A.ao, 2)) > sqrt(pow(B.thuc, 2) + pow(B.ao, 2));
}
bool operator>=(SoPhuc A, SoPhuc B){
  return sqrt(pow(A.thuc, 2) + pow(A.ao, 2)) >= sqrt(pow(B.thuc, 2) + pow(B.ao, 2));
}
bool operator<(SoPhuc A, SoPhuc B){
  return sqrt(pow(A.thuc, 2) + pow(A.ao, 2)) < sqrt(pow(B.thuc, 2) + pow(B.ao, 2));
}
bool operator<=(SoPhuc A, SoPhuc B){
  return sqrt(pow(A.thuc, 2) + pow(A.ao, 2)) <= sqrt(pow(B.thuc, 2) + pow(B.ao, 2));
}
