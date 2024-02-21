#include "phanso.h"
using namespace std;
int main()
{
    PhanSo d1, d2, re;
    int tmp1, tmp2;
    int select;
    cout << "*** CHUONG TRINH XU LY PHAN SO *** \n";
    cout <<"(Chuong trinh khoi tao gia tri 2 phan so ban dau deu bang 1)\n";
    cout << "1. Nhap 2 phan so.\n";
    cout << "2. Xuat 2 phan so.\n";
    cout << "3. Tong 2 phan so.\n";
    cout << "4. Hieu 2 phan so.\n";
    cout << "5. Tich 2 phan so.\n";
    cout << "6. Thuong 2 phan so.\n";
    cout << "7. So sanh 2 phan so.\n";
    cout << "8. Thiet lap lai tu so cua 2 phan so.\n";
    cout << "9. Thiet lap lai mau so cua 2 phan so.\n";
    cout << "0. Thoat chuong trinh \n";
    do{
        cout<<"------------------------------------------------\n";
        cout<<"Moi ban chon phuong thuc thuc hien: ";
        cin>>select;
    switch(select){
        case 0:
            cout<<"Tam biet!";
            break;
        case 1:
            cout<<"Moi ban nhap phan so A: \n";
            cin>>d1;
            cout<<"Moi ban nhap phan so B: \n";
            cin>>d2;
            break;
        case 2:
            cout<<"2 phan so: "<<d1<<" va "<<d2<<endl;
            break;
        case 3:
            re=d1+d2;
            cout<<"Tong 2 phan so: A + B: = "<<re<<endl;
            break;
        case 4:
            re=d1-d2;
            cout<<"Hieu 2 phan so: A - B: = "<<re<<endl;
            break;
        case 5:
            re=d1*d2;
            cout<<"Tich 2 phan so: A.B: = "<<re<<endl;
            break;
        case 6:
            if(d2!=0){
                re=d1/d2;
                cout<<"Thuong 2 phan so: A/B: = "<<re<<endl;
            }
            else cout<<"Mau bang 0 khong the chia\n";
            break;
        case 7:
            if(d1 == d2)
	          cout << "Phan so " << d1 << " = " << d2 << endl;
	        else
	          cout << "Phan so " << d1 << " != " << d2 << endl;
	        if(d1 > d2)
	          cout << "Phan so " << d1 << " > " << d2 << endl;
	        else if(d1 >= d2)
	          cout << "Phan so " << d1 << " >= " << d2 << endl;
	        else if(d1 < d2)
	          cout << "Phan so " << d1 << " < " << d2 << endl;
	        else if(d1 <= d2)
	          cout << "Phan so " << d1 << " <= " << d2 << endl;
            break;
        case 8:
            cout<<"Tu so cua 2 phan so A, B: ";
			cin>>tmp1>>tmp2;
			d1.SetTs(tmp1); d2.SetTs(tmp2);
			cout << "Phan so A moi: "; cout << d1 << endl;
			cout << "Phan so B moi: "; cout << d2 << endl;
	        break;
	    case 9:
	        cout<<"Mau so cua 2 phan so A, B: ";
	        cin>>tmp1>>tmp2;
			d1.SetMs(tmp1); d2.SetMs(tmp2);
			cout << "Phan so A moi: "; cout << d1 << endl;
			cout << "Phan so B moi: "; cout << d2 << endl;
	        break;
		default:
			cout << "Ban chon sai. Vui long chon lai." << endl;
			break;
        }
    }while(select!=0);
    return 0;
}
