#include "sophuc.h"
using namespace std;

int main(){
  SoPhuc A, B;
  int select;
  cout << "*** CHUONG TRINH XU LY SO PHUC *** \n";
    cout << "1. Nhap 2 so phuc.\n";
    cout << "2. Xuat 2 so phuc.\n";
    cout << "3. Tong 2 so phuc.\n";
    cout << "4. Hieu 2 so phuc.\n";
    cout << "5. Tich 2 so phuc.\n";
    cout << "6. Thuong 2 so phuc.\n";
    cout << "7. So sanh 2 so phuc.\n";
    cout << "8. Thiet lap lai gia tri thuc cua 2 so phuc.\n";
    cout << "9. Thiet lap lai gia tri ao cua 2 so phuc.\n";
    cout << "10. Thiet lap lai 2 so phuc.\n";
    cout << "0. Thoat chuong trinh \n";
  do {
    cout << "-----------------------------------------------------" << endl;
    cout << "BAN CHON: ";
    cin >> select;
    switch(select){
	    case 0: cout << "Thoat CT! Tam biet!"; break;
	    case 1:
	        cout << "Nhap 2 so phuc:" << endl;
	        cin >> A >> B;
	        break;
	    case 2:
	        cout << "Hai so phuc vua nhap: " << A << ", " << B << endl;
	        break;
	    case 3:
	        cout << "Tong 2 so phuc: " << A << " + " << B << " = " << A + B;
	        break;
	    case 4:
	        cout << "Hieu 2 so phuc: " << A << " - (" << B << ") = " << A - B;
            break;
	    case 5:
	        cout << "Tich 2 so phuc: (" << A << ") * (" << B << ") = " << A * B;
	        break;
	    case 6:
	        cout << "Thuong 2 so phuc: (" << A << ") / (" << B << ") = " << A / B;
	        break;
	    case 7:
	        if(A == B)
	          cout << "So phuc " << A << " = " << B << endl;
	        else
	          cout << "So phuc " << A << " != " << B << endl;
	        if(A > B)
	          cout << "So phuc " << A << " > " << B << endl;
	        else if(A >= B)
	          cout << "So phuc " << A << " >= " << B << endl;
	        else if(A < B)
	          cout << "So phuc " << A << " < " << B << endl;
	        else if(A <= B)
	          cout << "So phuc " << A << " < " << B << endl;
	        break;
	    case 8:
			A.SetThuc(); A.GetThuc(); B.SetThuc(); B.GetThuc();
			cout << "So phuc A moi: "; cout << A << endl;
			cout << "So phuc B moi: "; cout << B << endl;
	        break;
	    case 9:
	        cout << "Nhap 2 gia tri ao moi:" << endl;
	        A.SetAo(); A.GetAo(); B.SetAo(); B.GetAo();
			cout << "So phuc A moi: "; cout << A << endl;
			cout << "So phuc B moi: "; cout << B << endl;
	        break;
	    case 10:
			A.SetSoPhuc(); A.GetThuc(); A.GetAo();
			B.SetSoPhuc(); B.GetThuc(); B.GetAo();
			cout << "So phuc A moi: "; cout << A << endl;
			cout << "So phuc B moi: "; cout << B << endl;
	        break;
		default:
			cout << "Ban chon sai. Vui long chon lai." << endl;
			break;
    }
  cout << "\n";
  } while(select != 0);
  return 0;
}
