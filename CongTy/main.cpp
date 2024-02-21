#include "congty.h"
int main(){
    CONGTY A;
    int se;
    cout<< "----------CHUONG TRINH QUAN LY NHAN VIEN CUA CONG TY-------------\n";
    cout<< "0. Thoat CT.\n";
    cout<< "1. Nhap d/s.\n";
    cout<< "2. Xuat d/s.\n";
    cout<< "3. Liet ke cac nhan vien bien che co he so luong tu 3.5 tro len. \n";
    cout<< "4. Dem so luong nhan vien hop dong co so ngay cong la 26. \n";
    cout<< "5. Tinh tong tien luong da tra cho cac nhan vien phong 'Ke toan'.\n";
    cout<< "6. Tinh tien luong trung binh cua cac nhan vien bien che.\n";
    cout<< "7. Kiem tra cong ty co nhan vien hop dong khong di lam ngay nao khong?\n";
    cout<< "8. Tim cac nhan vien bien che co he so luong cao nhat.\n";
    cout<< "9. Sap xep danh sach nhan vien tang dan theo ma so.\n";
    cout<< "10. Them 1 nhan vien moi.\n";
    cout<< "11. Xoa 1 nhan vien co ma so do nguoi dung nhap vao.\n";
    do{
        cout<< "-----------------------------------------------------------------\n";
        cout<< "Ban chon: ";
        cin>>se;
        switch(se){
            case 0: cout<< "Tam biet!\n"; break;
            case 1: A.Nhap(); break;
            case 2: A.Xuat(); break;
            case 3: A.LietKeNVBCCoHSLuongTu3cham5TroLen(); break;
            case 4: if(A.DemSoLuongNVHDCoSoNgayCongla26()==0) cout<< "Khong co nhan vien hop dong nao co so ngay cong la 26.\n";
            else cout<< "Co "<<A.DemSoLuongNVHDCoSoNgayCongla26()<< "nhan vien hop dong co so ngay cong la 26.\n";
             break;
            case 5: if(A.TongTienLuongDaTraChoCacNVPhongKeToan()!=0) cout<<A.TongTienLuongDaTraChoCacNVPhongKeToan()<<endl;
                else  cout<< "Khong co nhan vien phong ke toan.\n";
            break;
            case 6: if(A.TinhTienLuongTBCuaCacNVBC()!=0) cout<< A.TinhTienLuongTBCuaCacNVBC()<<endl;
                else cout<< "Khong co nhan vien bien che.\n";
            break;
            case 7: if(A.KiemTraCTyCoNVHDKhongDiLamNgayNaoKhong()) cout<< "Cong ty co nhan vien hop dong khong di lam ngay nao do.\n";
                else cout<< "Cong ty co nhan vien hop dong di lam day du.\n";
                break;
            case 8: A.TimCacNVBCCoHSLuongCaoNhat(); break;
            case 9: A.SXDSNVTangDanTheoMaSo(); A.Xuat(); break;
            case 10:
                {
                int vt;
                do{
                    cout<< "Nhap vi tri can them: ";
                    cin>>vt;
                }while(vt<0||vt>A.getSL());
                A.Them(A.Nhap1(),vt);
                cout<< "D/s nhan vien sau khi them:\n ";
                A.Xuat();
                }
                break;
            case 11: {
                string maso;
                cout<< "Nhap ma so nhan vien can xoa: ";
                cin>>maso;
                A.Xoa(maso);

                A.Xuat();
                }
                break;
            default: {
                "Chon sai moi chon lai.\n";
                break;
            }
        }
    }while(se!=0);
    return 0;
}
