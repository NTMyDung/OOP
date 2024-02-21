#pragma once
#ifndef _SoPhuc
#define _SoPhuc
#include <iostream>
using namespace std;
class SoPhuc {
private:
  double thuc, ao;
public:
  SoPhuc(double = 0, double = 0);
  void Nhap();
  void Xuat();
  double GetThuc();
  double GetAo();
  void SetThuc();
  void SetAo();
  void SetSoPhuc();
  friend SoPhuc operator+(SoPhuc, SoPhuc);
  friend SoPhuc operator-(SoPhuc, SoPhuc);
  friend SoPhuc operator*(SoPhuc, SoPhuc);
  friend SoPhuc operator/(SoPhuc, SoPhuc);
  friend bool operator==(SoPhuc, SoPhuc);
  friend bool operator!=(SoPhuc, SoPhuc);
  friend bool operator>(SoPhuc, SoPhuc);
  friend bool operator>=(SoPhuc, SoPhuc);
  friend bool operator<(SoPhuc, SoPhuc);
  friend bool operator<=(SoPhuc, SoPhuc);
  friend istream& operator>>(istream&, SoPhuc&);
  friend ostream& operator<<(ostream&, SoPhuc);
};
#endif
