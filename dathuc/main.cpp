#include "dathuc.h"

int main()
{
    DATHUC f;
    int i;
    float k;
    int select;
    cout << "------------------DA THUC----------------------\n";
    cout <<"(Chuong trinh khoi tao DA THUC f(x)=x^2)\n";
    cout << "1. Nhap da thuc thu cong.\n";
    cout << "2. Nhap da thuc tu dong.\n";
    cout << "3. Xuat da thuc f(x).\n";
    cout << "4. Gia tri cua da thuc tai x0: f(x0).\n";
    cout << "5. Cong 2 da thuc: f(x) + g(x).\n";
    cout << "6. Neu f(x) la da thuc bac 2 giai pt f(x)=0.\n";
    cout << "7. Cap nhat lai he so cua x^i.\n";
    cout << "8. Xem he so cua x^i.\n";
    cout << "0. Thoat chuong trinh \n";
    do{
        cout<<"------------------------------------------------\n";
        cout<<"Moi ban chon phuong thuc thuc hien: ";
        cin>>select;
    switch(select){
        case 0:
            cout<<"Tam biet!\n";
            break;
        case 1:
            cout<<"Nhap da thuc f(x).\n";
            cin>>f;
            break;
        case 2:
            cout<<"Nhap da thuc f(x).\n";
            f.NhapAuto();
            cout<<"f(x) = "<<f<<endl;
            break;
        case 3:
            cout<<"f(x) = "<<f<<endl;
            break;
        case 4:
            cout<<"Nhap gia tri x0: ";
            cin>>k;
            cout<<"f("<<k<<") = "<<f.GTTaiDiem(k)<<endl;
            break;
        case 5:
            {
            DATHUC g;
            cout<<"Nhap da thuc g(x).\n";
            cin>>g;
            DATHUC tmp = f + g ;
            cout<<"f(x) + g(x) = "<<tmp<<endl;
            }
            break;
        case 6:
            f.GiaiPT();
            break;
        case 7:
           do {
                cout<< "Nhap don thuc bac i(0->2) can cap nhat he so: ";
                cin>>i;
            }while(i>2||i<0);
            do{
                cout<< "Nhap gia tri he so can cap nhat: ";
                cin>>k;
            }while(i==2&&k==0);
            if(i==2) f.setB2(k);
            else if(i==1) f.setB1(k);
            else f.setB0(k);
            cout<< "Da thuc moi: "<<f<<endl;
            break;
        case 8:
            do {
                cout<< "Ban muon xem he so cua don thuc bac(0->2): ";
                cin>>i;
            }while(i>2||i<0);
            if(i==0)cout<<f.getB0()<<endl;
            else if(i==1) cout<<f.getB1()<<endl;
            else cout<<f.getB2()<<endl;
            break;
		default:
			cout << "Ban chon sai. Vui long chon lai." << endl;
			break;
        }
    }while(select!=0);
    return 0;
}
