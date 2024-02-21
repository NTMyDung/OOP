#include "trangtrai.h"

int main()
{
    TRANGTRAI t;
    int se;
    cout<< "----------CHUONG TRINH QUAN LY NHAN VIEN CUA CONG TY-------------\n";
    cout<< "0. Thoat CT.\n";
    cout<< "1. Nhap tt.\n";
    cout<< "2. Tat ca tieng keu trong trang trai khi chu di vang.\n";
    cout<< "3. Thong ke thong tin nguoi chu mong muon.\n";
    do{
        cout<< "------------------------------------------------------------------\n";
        cout<< "Ban chon: ";
        cin>>se;
        switch(se){
            case 0: cout<< "Tam biet!\n"; break;
            case 1: t.Nhap(); break;
            case 2: t.XuatKeu(); break;
            case 3: t.ThongKe(); break;
            default: {
                "Chon sai moi chon lai.\n";
                break;
            }
        }
    }while(se!=0);
    return 0;
}
