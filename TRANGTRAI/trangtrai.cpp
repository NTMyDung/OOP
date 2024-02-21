#include "trangtrai.h"
TRANGTRAI::TRANGTRAI(){
    p=NULL;
}
TRANGTRAI::~TRANGTRAI(){
    if(p!=NULL) {
        for(int i=0; i<3; i++)
        delete[]p[i];
        p=NULL;
    }
}
void TRANGTRAI::Nhap(){
    p=new GIASUC*[3];
    p[0]= new BO; p[0]->Nhap();
    p[1]= new CUU; p[1]->Nhap();
    p[2]= new DE; p[2]->Nhap();
}
void TRANGTRAI::XuatKeu(){
    for( int i=0; i<3; i++){
        for( int j=0; j<p[i]->getSL(); j++){
            cout<<p[i]->getKeu()<< "\t";
        }
    }
    cout<<endl;
}
void TRANGTRAI::ThongKe(){
    cout<< "Thong ke thong tin nguoi chu mong muon sau khi de 1 lua: \n";
    for( int i=0; i<3; i++){
        p[i]->sinhConSau1lua();
         cout<< "Loai: "<<p[i]->getTen()<< "\tSL: "<<p[i]->getSL()<< "\t So lit sua: "<<p[i]->tongSua()<<endl;
    }
}
