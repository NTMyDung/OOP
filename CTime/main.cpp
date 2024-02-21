#include "ctime.h"
using namespace std;

int main(){
  CTIME A, tmp;
  int time;
  int select;
    cout << "------------ CHUONG TRINH CTIME---------------------\n";
    cout << "(Chuong trinh khoi tao thoi diem luc 0h0p0s)\n";
    cout << "1. Nhap thoi diem.\n";
    cout << "2. Xuat thoi diem.\n";
    cout << "3. Thoi diem sau t giay.\n";
    cout << "4. Thoi diem truoc t giay.\n";
    cout << "5. Thoi diem sau 1 giay.\n";
    cout << "6. Thoi diem truoc 1 giay.\n";
    cout << "7. Thiet lap lai gia tri cua gio.\n";
    cout << "8. Thiet lap lai gia tri cua phut.\n";
    cout << "9. Thiet lap lai gia tri cua giay.\n";
    cout << "0. Thoat chuong trinh \n";
  do {
    cout << "-----------------------------------------------------" << endl;
    cout << "BAN CHON: ";
    cin >> select;
    switch(select){
	    case 0: cout << "Thoat CT! Tam biet!"; break;
	    case 1:
	        cout << "Nhap thoi diem:" << endl;
	        cin >> A;
	        break;
	    case 2:
	        cout << "Thoi diem vua nhap: " << A << endl;
	        break;
	    case 3:
	        cout<<"Nhap thoi gian t can dich ve sau: ";
	        cin>>time;
	        tmp = A+time;
	        cout<<"Thoi diem sau "<<time<<" giay la: "<<tmp;
	        break;
	    case 4:
	        cout<<"Nhap thoi gian t can dich ve truoc: ";
	        cin>>time;
	        tmp = A - time;
	        cout<<"Thoi diem truoc "<<time<<" giay la: "<<tmp;
            break;
	    case 5:
	        tmp=++A;
	        cout<<"Sau khi tang 1s, thoi diem la: "<<tmp;
	        break;
	    case 6:
	        tmp=--A;
	        cout<<"Sau khi giam 1s, thoi diem la: "<<tmp;
	        break;
	    case 7:
	        A.setH();
	        cout<<"Thoi diem moi la: "<<A<<endl;
	        break;
	    case 8:
			A.setM();
			cout<<"Thoi diem moi la: "<<A;
	        break;
	    case 9:
            A.setS();
			cout<<"Thoi diem moi la: "<<A;
	        break;
		default:
			cout << "Ban chon sai. Vui long chon lai." << endl;
			break;
    }
  cout << "\n";
  } while(select != 0);
  return 0;
}
