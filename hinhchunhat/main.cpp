#include <iostream>
#include "hcn.h"
using namespace std;

int main()
{
    HCN hcn, tmp;
    DIEMM d1, d2;
    double tmp1, tmp2, dx, dy;
    int select;
    cout<<"------------------CHUONG TRINH XU LI HCN------------------\n\n";
    cout<<"Chuong trinh cung cap cho ban: HCN duong cheo A(1,0), B(0,1) \n\n";
    cout<<"1. XUAT thong tin cua HCN.\n";
    cout<<"2. KHOI TAO gia tri cho HCN.\n";
    cout<<"3. DI CHUYEN HCN.\n";
    cout<<"4. Hoanh do X cua A.\n";
    cout<<"5. Tung do Y cua A.\n";
    cout<<"6. Hoanh do X cua B.\n";
    cout<<"7. Tung do Y cua B.\n";
    cout<<"8. Toa do cua A.\n";
    cout<<"9. Toa do cua B.\n";
    cout<<"10. Cap nhat hoanh do X  cua A.\n";
    cout<<"11. Cap nhat tung do Y  cua A.\n";
    cout<<"12. Cap nhat hoanh do X  cua B.\n";
    cout<<"13. Cap nhat tung do Y  cua B.\n";
    cout<<"14. Cap nhat Toa do cua A.\n";
    cout<<"15. Cap nhat Toa do cua B.\n";
    cout<<"0. THOAT.\n";
    do{
    cout<<"------------------------------------------------------------------\n";
    cout<<"BAN CHON: ";
    cin>>select;
    switch(select)
    {
        case 0: cout<<"Ket thuc! Tam biet!"; break;
        case 1: cout<<"Thong tin hinh chu nhat:  "<<hcn<<endl; break;
        case 2: cin>>hcn; d1=hcn.GetA(); d2=hcn.GetB(); break;
        case 3: cout<<"Nhap dx: "; cin>>dx; cout<<"Nhap dy: "; cin>>dy; hcn.DiChuyen(dx,dy);
                cout<<"Hcn sau khi di chuyen dx = "<<dx<<", dy = "<<dy<<" :\n"<<hcn<<endl; break;
        case 4: cout<<"Hoanh do cua A la: "<<hcn.GetA().GetX()<<endl; break;
        case 5: cout<<"Tung do cua A la: "<<hcn.GetA().GetY()<<endl; break;
        case 6: cout<<"Hoanh do cua B la: "<<hcn.GetB().GetX()<<endl; break;
        case 7: cout<<"Tung do cua B la: "<<hcn.GetB().GetY()<<endl; break;
        case 8: cout<<"A("<<hcn.GetA().GetX()<<","<<hcn.GetA().GetY()<<")"<<endl; break;
        case 9: cout<<"B("<<hcn.GetB().GetX()<<","<<hcn.GetB().GetY()<<")"<<endl; break;
        case 10: cout<<"Nhap x: "; cin>>tmp1; d1.SetX(tmp1); hcn.SetA(d1); cout<<hcn; break;
        case 11: cout<<"Nhap y: "; cin>>tmp2; d1.SetY(tmp2); hcn.SetA(d1); cout<<hcn; break;
        case 12: cout<<"Nhap x: "; cin>>tmp1; d2.SetX(tmp1); hcn.SetB(d2);  cout<<hcn;break;
        case 13: cout<<"Nhap y: "; cin>>tmp2; d2.SetY(tmp2); hcn.SetB(d2);  cout<<hcn;break;
        case 14: cout<<"Nhap x: "; cin>>tmp1; cout<<"Nhap y: "; cin>>tmp2; d1.SetXY(tmp1,tmp2);hcn.SetA(d1); cout<<hcn;break;
        case 15: cout<<"Nhap x: "; cin>>tmp1; cout<<"Nhap y: "; cin>>tmp2; d2.SetXY(tmp1,tmp2);hcn.SetA(d2); cout<<hcn;break;
        default:
            break;
    }
    }while(select!=0);
    return 0;
}

