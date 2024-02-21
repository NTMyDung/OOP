#ifndef CTIME_H
#pragma once
#include <iostream>
using namespace std;
class CTIME{
private:
    int hour;
    int minute;
    int second;
public:
    CTIME(int=0, int=0, int=0);
    ~CTIME();
    void setH();
    void setM();
    void setS();
    void setAll();
    int getH();
    int getM();
    int getS();
    bool checkH();
    bool checkM();
    bool checkS();
    bool checkAll();
    void ChuyenVaXuat();
    friend CTIME operator+(CTIME, int);
    friend CTIME operator-(CTIME, int);
    friend CTIME operator++(CTIME);
    friend CTIME operator--(CTIME);
    friend istream& operator>>(istream&, CTIME&);
    friend ostream& operator<<(ostream&, CTIME&);
};
#endif // CTIME_H
