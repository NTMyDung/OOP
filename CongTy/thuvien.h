#pragma once
#ifndef THUVIEN_H
#include <iostream>
using namespace std;
class NHANVIEN{
protected:
    string ms, ten, phong;
public:
    NHANVIEN(string="", string="", string="");
    ~NHANVIEN();
    void setTen(string);
    void setPhong(string);
    string getMS();
    string getTen();
    string getPhong();
    virtual void setHSLuong(double);
    virtual void setHSPCCV(double);
    virtual void setTienCong(int);
    virtual void setSoNgayCong(int);
    virtual void setHSVuotGio(double);
    virtual double getHSLuong();
    virtual double getHSPCCV();
    virtual int getTienCong();
    virtual int getSoNgayCong();
    virtual double getHSVuotGio();
    virtual void Nhap();
    virtual void Xuat();
    virtual long TienLuong()=0;
    virtual string getLoai()=0;
};

class HOPDONG: public NHANVIEN{
protected:
    int TienCong;
    int SoNgayCong;
    double HSVuotGio;
public:
    HOPDONG(string="", string="", string="",int=0, int=0, double=0);
    ~HOPDONG();
    void setTienCong(int);
    void setSoNgayCong(int);
    void setHSVuotGio(double);
    int getSoNgayCong();
    int getTienCong();
    double getHSVuotGio();
    void Nhap();
    void Xuat();
    long TienLuong();
    string getLoai();
};
class BIENCHE: public NHANVIEN{
protected:
    double HSLuong;
    double HSPCCV;
public:
    BIENCHE(string="", string="", string="",double=0, double=0);
    ~BIENCHE();
    void setHSLuong(double);
    void setHSPCCV(double);
    double getHSLuong();
    double getHSPCCV();
    void Nhap();
    void Xuat();
    long TienLuong();
    string getLoai();
};
#endif // THUVIEN_H
