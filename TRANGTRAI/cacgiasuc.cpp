#include "cacgiasuc.h"
GIASUC::GIASUC(){}
GIASUC::~GIASUC(){}
string GIASUC::getTen(){}
string GIASUC::getKeu(){}
long GIASUC::getSL(){return -1;}
long GIASUC::tongSua(){ return -1;}
void GIASUC::sinhConSau1lua(){return;}
void GIASUC::Nhap(){}
BO::BO(long sl): sl(sl){}
BO::~BO(){}
string BO::getTen(){
    return "Bo";
}
string BO::getKeu(){
    return "UHM BOOOO~~~~";
}
long BO::getSL(){
    return sl;
}
long BO::tongSua(){
    long re=0;
    for( int i=0; i<sl; i++){
        re+=rand()%20;
    }
    return re;
}
void BO::sinhConSau1lua(){
    long con=0;
    srand(time(0));
    for( int i=0; i<sl; i++){
        con+=rand()%10;
    }
    sl+=con;
}
void BO::Nhap(){
    do{
        cout<< "Nhap so luong bo: ";
        cin>>sl;
    }while(sl<1);
}
CUU::CUU(long sl): sl(sl){}
CUU::~CUU(){}
string CUU::getTen(){
    return "Cuu";
}
string CUU::getKeu(){
    return "BAAAA~~~";
}
long CUU::getSL(){
    return sl;
}
long CUU::tongSua(){
    long re=0;
    srand(time(0));
    for( int i=0; i<sl; i++){
        re+= rand()%5;
    }
    return re;
}
void CUU::sinhConSau1lua(){
    long con=0;
    srand(time(0));
    for( int i=0; i<sl; i++){
        con+=rand()%10;
    }
    sl+=con;
}
void CUU::Nhap(){
    do{
        cout<< "Nhap so luong cuu: ";
        cin>>sl;
    }while(sl<1);
}
DE::DE(long sl): sl(sl){}
DE::~DE(){}
string DE::getTen(){
    return "De";
}
string DE::getKeu(){
    return "BEEE BEEEE~~~";
}
long DE::getSL(){
    return sl;
}
long DE::tongSua(){
    long re=0;
    srand(time(0));
    for( int i=0; i<sl; i++){
        re+= rand()%10;
    }
    return re;
}
void DE::sinhConSau1lua(){
    long con=0;
    srand(time(0));
    for( int i=0; i<sl; i++){
        con+=rand()%10;
    }
    sl+=con;
}
void DE::Nhap(){
    do{
        cout<< "Nhap so luong de: ";
        cin>>sl;
    }while(sl<1);
}
