#pragma once
#ifndef CACGIASUC_H
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class GIASUC{
public:
    GIASUC();
    ~GIASUC();
    virtual string getTen()=0;
    virtual string getKeu()=0;
    virtual long getSL();
    virtual long tongSua();
    virtual void sinhConSau1lua();
    virtual void Nhap();
} ;
class BO: public GIASUC{
protected:
    long sl;
public:
    BO(long=0);
    ~BO();
    string getTen();
    string getKeu();
    long getSL();
    long tongSua();
    void sinhConSau1lua();
    void Nhap();
};
class CUU: public GIASUC{
protected:
    long sl;
public:
    CUU( long=0);
    ~CUU();
    string getTen();
    string getKeu();
    long getSL();
    long tongSua();
    void sinhConSau1lua();
    void Nhap();
};
class DE: public GIASUC{
protected:
    long sl;
public:
    DE(long=0);
    ~DE();
    string getTen();
    string getKeu();
    long getSL();
    long tongSua();
    void sinhConSau1lua();
    void Nhap();
};
#endif // CACGIASUC_H
