#include "ctime.h"
#include <iostream>
#include <cmath>
using namespace std;
CTIME::CTIME(int hour, int minute, int second){
    this->hour=hour;
    this->minute=minute;
    this->second=second;
}
CTIME::~CTIME(){}
void CTIME:: setH(){
    int hour;
    do{
        cout<<"Nhap gio: "; cin>>hour;
        this->hour=hour;
    }while(!checkH());
}
void CTIME::setM(){
    int minute;
    do{
        cout<<"Nhap phut: ";cin>>minute;
        this->minute=minute;
    }while(!checkM());
}
void CTIME::setS(){
    int second;
    do{
        cout<<"Nhap giay: "; cin>>second;
        this->second=second;
    }while(!checkS());
}
void CTIME::setAll(){
    setH();
    setM();
    setS();
}
int CTIME::getH(){
    return hour;
}
int CTIME::getM(){
    return minute;
}
int CTIME::getS(){
    return second;
}
bool CTIME::checkH(){
    return hour<=24&&hour>=0;
}
bool CTIME::checkM(){
    return minute<=60 && minute>=0;
}
bool CTIME::checkS(){
    return second<=60 && second>=0;
}
bool CTIME::checkAll(){
    return checkH() && checkM() && checkS();
}
void CTIME::ChuyenVaXuat(){
    if(second==60){
        second=0; minute++;
    }
    else if(second>60){
        minute+=second/60;
        second-=(second/60)*60;
    }
    else if(second<0){
        int tmp=abs(second)/60;
        second=60-(abs(second)-tmp*60);
        minute-=tmp;
    }
    if(minute==60){
        minute=0; hour++;
    }
    else if(minute>60){
        hour+=minute/60;
        minute-=(minute/60)*60;
    }
    else if(minute<0){
        int tmp=abs(minute)/60;
        minute=60-(abs(minute)-tmp*60);
        hour-=tmp+1;
    }
    if(hour==24) hour=0;
    else if(hour>24) {
        hour-=(hour/24)*24;
    }
    else if(hour<0){
        hour=24-abs(hour);
    }
    cout<<hour<<"h"<<minute<<"p"<<second<<"s";
}

CTIME operator+(CTIME t, int x){
    return CTIME(t.getH(), t.getM(), t.getS()+x);
}
CTIME operator-(CTIME t, int x){
    return CTIME(t.getH(), t.getM(), t.getS()-x);
}
CTIME operator++(CTIME t){
    return CTIME(t.getH(), t.getM(), t.getS()+1);
}
CTIME operator--(CTIME t){
    return CTIME(t.getH(), t.getM(), t.getS()-1);
}
istream& operator>>(istream& is, CTIME&t){
    t.setAll();
    return is;
}
ostream& operator<<(ostream& os, CTIME&t){
    t.ChuyenVaXuat();
    return os;
}
