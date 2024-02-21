#include "congty.h"
#include "thuvien.h"
CONGTY::CONGTY(){
    pNV=NULL;
    sl=0;
}
CONGTY::~CONGTY(){
    for( int i=0; i<sl; i++){
        delete[] pNV[i];
    }
    delete[] pNV;
    pNV=NULL;
    sl=0;
}
int CONGTY::getSL(){
    return sl;
}
void CONGTY::Nhap(){
    int loai;
    do{
        cout<< "Nhap so luong nhan vien: ";
        cin>>sl;
    }while(sl<1);
    pNV= new NHANVIEN*[sl];
    for( int i=0; i<sl; i++){
        cout<< "-----------------------\n";
        cout<< "Nhap thong tin nhan vien thu "<<i+1<< ":\n";
        do{
            cout<< "Nhap loai( 1_Nhan vien hop dong, 2_Nhan vien bien che): ";
            cin>>loai;
        }while(loai!=1 &&loai!=2);
        if(loai==1) pNV[i] = new HOPDONG;
        else pNV[i]=new BIENCHE;
        pNV[i]->Nhap();
    }
}
void CONGTY::Xuat(){
for( int i=0; i<sl; i++){
    pNV[i]->Xuat();
    cout<<endl;
    }
}
NHANVIEN* CONGTY::Nhap1(){
    int loai;
    NHANVIEN* x;
    do{
    cout<< "Nhap loai nhan vien( 1_Nhan vien hop dong, 2_Nhan vien bien che): ";
    cin>>loai;
    }while(loai!=1&&loai!=2);
    if(loai==1)  x=new HOPDONG;
    else x=new BIENCHE;
    x->Nhap();
    return x;
}
void CONGTY::LietKeNVBCCoHSLuongTu3cham5TroLen(){
    int dem=0;
    for( int i=0; i<sl; i++)
        if(pNV[i]->getLoai()=="Nhan vien bien che"&&pNV[i]->getHSLuong()>=3.5){
            pNV[i]->Xuat();
            dem++;
        }
    if(dem==0) cout<< "Khong co nhan vien bien che nao co he so luong tu 3.5 tro len.\n";
}
int CONGTY::DemSoLuongNVHDCoSoNgayCongla26(){
    int dem=0;
     for( int i=0; i<sl; i++){
        if(pNV[i]->getLoai()=="Nhan vien hop dong" && pNV[i]->getSoNgayCong()==26) dem++;
    }
       // cout<< "Khong co nhan vien hop dong nao co so ngay cong la 26.\n";
   return dem;
}
long CONGTY::TongTienLuongDaTraChoCacNVPhongKeToan(){
    long tienLuong=0;
     for( int i=0; i<sl; i++)
        if(DoiChuoiInHoa(pNV[i]->getPhong())=="KE TOAN") tienLuong+=pNV[i]->TienLuong();
    return tienLuong;
}
double CONGTY::TinhTienLuongTBCuaCacNVBC(){
    int dem=0;
    long tien=0;
    for( int i=0; i<sl; i++){
        if(pNV[i]->getLoai()=="Nhan vien bien che") {
            dem++;
            tien+=pNV[i]->TienLuong();
        }
    }
    return dem>0 ? (double)tien/(double)dem : 0;
}
bool CONGTY::KiemTraCTyCoNVHDKhongDiLamNgayNaoKhong(){
    for( int i=0; i<sl; i++){
        if(pNV[i]->getLoai()=="Nhan vien hop dong" && pNV[i]->getSoNgayCong()<30) return true;
    }
    return false;
}
void CONGTY::TimCacNVBCCoHSLuongCaoNhat(){
    double hsmax;
    int dem=0;
    for( int i=1; i<sl; i++){
        if(pNV[i]->getLoai()=="Nhan vien bien che"){
            hsmax=pNV[i]->getHSLuong();
            dem++;
            break;
        }
    }
    if(dem!=0){
        for( int i=1; i<sl; i++){
            if(pNV[i]->getLoai()=="Nhan vien bien che" && pNV[i]->getHSLuong()>hsmax) hsmax=pNV[i]->getHSLuong();
        }
        for( int i=1; i<sl; i++){
            if(pNV[i]->getLoai()=="Nhan vien bien che" && pNV[i]->getHSLuong()==hsmax) pNV[i]->Xuat();
        }
    }
    else cout<< "Cong ty khong co nhan vien bien che.\n";
}
string CONGTY::DoiChuoiInHoa(string s){
    for( int i=0; i<s.length(); i++){
        s[i]=toupper(s[i]);
    }
    return s;
}
string CONGTY::DoiChuoiInThuong(string s){
    for( int i=0; i<s.length(); i++){
        s[i]=tolower(s[i]);
    }
    return s;
}
void CONGTY::SXDSNVTangDanTheoMaSo(){
    for( int i=0; i<sl; i++){
        for( int j=i+1; j<sl; j++){
            if(pNV[i]->getMS()>pNV[j]->getMS()) swap(pNV[i], pNV[j]);
        }
    }
}
void CONGTY::Them(NHANVIEN* x,int vt){
    NHANVIEN** pnew= new NHANVIEN*[sl+1];
    for( int i=0; i<vt-1; i++){
        pnew[i]=pNV[i];
    }
    pnew[vt-1]= x;
    for(int i=vt; i<sl+1; i++){
        pnew[i]=pNV[i-1];
    }
    delete[] pNV;
    pNV=pnew;
    sl++;
}
void CONGTY::Xoa(string maso){
    int vt=-1;
    for( int i=0; i<sl; i++){
        if(DoiChuoiInHoa(pNV[i]->getMS())==DoiChuoiInHoa(maso)){
            vt=i;
            break;
        }
    }
    if(vt==-1) {cout << "Khong tim thay "<<maso<<endl;}
    else{
    NHANVIEN** pnew= new NHANVIEN*[sl-1];
    for( int i=0; i<vt; i++){
        pnew[i]=pNV[i];
    }
    for( int i=vt; i<sl-1; i++){
        pnew[i]=pNV[i+1];
    }
    delete[] pNV;
    pNV=pnew;
    sl--;
    }
}
void CONGTY::TimKiemNVTheoMS(string maso){
    int dem=0;
    for( int i=0; i<sl; i++){
        if(DoiChuoiInHoa(pNV[i]->getMS())==DoiChuoiInHoa(maso)){
            dem++;
            pNV[i]->Xuat();
            break;
        }
    }
    if(dem==0) cout << "Khong tim thay "<<maso<<endl;
}
