#include "diem3cmau.h"

int main()
{
    DIEM3CMAU d(-2.3, 8.9, 10, 56, -117, 200);
    double a,b,c;
    int select;
    cout<< "-----------CHUONG TRINH XU LY DIEM 3 CHIEU CO MAU----------\n";
    cout<< "0. Thoat CT.\n";
    cout<< "1. Nhap diem.\n";
    cout<< "2. Xuat diem.\n";
    cout<< "3. Di chuyen diem.\n";
    cout<< "4. Tim diem doi xung.\n";
    cout<< "5. Kiem tra trung.\n";
    cout<< "6. Cap nhat lai hoanh do.\n";
    cout<< "7. Cap nhat lai tung do.\n";
    cout<< "8. Cap nhat lai cao do.\n";
    cout<< "9. Cap nhat lai hoanh do, tung do, cao do.\n";
    cout<< "10. Xem hoanh do.\n";
    cout<< "11. Xem tung do.\n";
    cout<< "12. Xem cao do.\n";
    cout<< "13. Chu vi va dien tich tam giac qua 3 diem.\n";
    cout<< "14. Cap nhat lai mau Red.\n";
    cout<< "15. Cap nhat lai mau Green.\n";
    cout<< "16. Cap nhat lai mau Blue.\n";
    cout<< "17. Cap nhat lai mau R-G-B.\n";
    cout<< "18. Xem mau Red.\n";
    cout<< "19. Xem mau Green.\n";
    cout<< "20. Xem mau Blue.\n";
    do{
       cout<< "-------------------------------------------------------\n";
       cout<< "Ban chon: ";
       cin>>select;
       switch(select){
        case 0: cout<< "Tam biet!\n";
        break;
        case 1: cin>>d;
        break;
        case 2: cout<<d<<endl;
        break;
        case 3: cout<< "Nhap khoang cach dx, dy, dz can di chuyen: "; cin>>a>>b>>c;
            d.DiChuyen(a,b,c);
            cout<< "Diem sau khi di chuyen: "<<d<<endl;
            break;
        case 4:
            {
            DIEM3C tmp=d.DoiXung();
            DIEM3C tmp2=(DIEM3C)d;
            cout<< "Diem doi xung cua "<<tmp2<< " la "<<tmp<<endl;
            }
            break;
        case 5:
            {
            cout<< "Nhap diem de kiem tra co trung voi diem ban dau khong.\n";
            DIEM3CMAU tmp;
            cin>>tmp;
            if(DIEM3C(d).KtraTrung(DIEM3C(tmp))) cout<< "Diem vua nhap "<<tmp<< " trung toa do voi diem ban dau "<<d<<".\n";
                else cout<< "Diem vua nhap "<<tmp<< " khong trung toa do voi diem ban dau "<<d<<".\n";
            if(MAU(d).KtraTrung(MAU(tmp))) cout<< "Diem vua nhap "<<tmp<< " trung mau voi diem ban dau "<<d<<".\n";
            else cout<< "Diem vua nhap "<<tmp<< " khong trung mau voi diem ban dau "<<d<<".\n";
            }
        break;
        case 6: cout<< "Nhap hoanh do can cap nhat: "; cin>>a;
            d.SetX(a);
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
            break;
        case 7: cout<< "Nhap tung do can cap nhat: "; cin>>b;
            d.SetY(b);
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
            break;
        case 8: cout<< "Nhap cao do can cap nhat: "; cin>>c;
            d.setZ(c);
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
            break;
        case 9: {
            cout<<"Nhap hoanh do: "; cin>>a;
            cout<<"Nhap tung do: "; cin>>b;
            cout<<"Nhap cao do: "; cin>>c;
            d.setXYZ(a,b,c);
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
        }
        break;
        case 10: cout<< "Hoanh do: "<<d.GetX()<<endl;
            break;
        case 11: cout<< "Tung do: "<<d.GetY()<<endl;
            break;
        case 12: cout<< "Cao do: "<<d.getZ()<<endl;
            break;
        case 13:
            {
            DIEM3C tmp=(DIEM3C)d;
            cout<< "Nhap them 2 diem de tao voi diem ban dau "<<tmp<< " thanh 1 tam giac.\n";
            cout<< "Diem thu nhat: \n";
            DIEM3C d1;
            cin>>d1;
            cout<< "Diem thu hai: \n";
            DIEM3C d2;
            cin>>d2;
            if(d.KTTamGiacHopLe(d1, d2)){
                cout<< "Tam giac co 3 dinh "<<tmp<<", "<<d1<< ", "<<d2<<endl;
                cout<< "Chu vi tam giac: "<<d.ChuViTamGiac(d1,d2)<<endl;
                cout<< "Dien tich tam giac: "<<d.DienTichTamGiac(d1,d2)<<endl;
                }
            else cout<< "3 diem "<<tmp<<", "<<d1<< ", "<<d2<< "khong the tao thanh tam giac.\n";
            }
        break;
        case 14:
            d.setRed();
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
            break;
        case 15:
            d.setGreen();
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
            break;
        case 16:
            d.setBlue();
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
            break;
        case 17:
            d.setRGB();
            cout<< "Diem sau khi cap nhat: "<<d<<endl;
            break;
        case 18:
            cout<<d.getRed()<<endl;
            break;
        case 19:
            cout<<d.getGreen()<<endl;
            break;
        case 20:
            cout<<d.getBlue()<<endl;
            break;
        default: {
            cout<< "Chon sai moi chon lai (0->6).\n";
            break;
        }
       }
    }while(select!=0);
    return 0;
}
