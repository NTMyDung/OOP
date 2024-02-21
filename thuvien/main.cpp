#include <iostream>
using namespace std;
class SACH{
protected:
    string ms, ten, nxb;
    int sl;
    int gia;
public:
    SACH(string ="", string= "", string="", int=0, int =0);
    ~SACH();
    string getMS();
    string getTen();
    string getNXB();
    int getSL();
    int getGia();
    virtual void Nhap();
    virtual void Xuat();
    virtual string getLoai()=0;
    virtual double ThanhTien()=0;
};
class GIAOKHOA:public SACH{
private:
    string tinhTrang;
public:
    GIAOKHOA(string ="", string= "", string="", int=0, int =0, string="");
    ~GIAOKHOA();
    string getTT();
    void Nhap();
    void Xuat();
    string getLoai();
    double ThanhTien();
};
class THAMKHAO: public SACH{
protected:
    double thue;
public:
    THAMKHAO(string ="", string= "", string="", int=0, int =0, double=0);
    ~THAMKHAO();
    double getThue();
    void Nhap();
    void Xuat();
    string getLoai();
    double ThanhTien();
};
class THUVIEN{
private:
    SACH** p;
    long sl;
public:
    THUVIEN();
    ~THUVIEN();
    void Nhap();
    void Xuat();
    long getSL();
    string DoiInHoa(string);
    void TienThuVienPhaiTraChoTungLoaiSach();
    void ThongTinSachCoThanhTienItNhat();
    void TimSGKCuaNXBCoTenDoNguoiDungNhapVao(string);
};
THUVIEN::THUVIEN(){
    p=NULL;
    sl=0;
}
THUVIEN::~THUVIEN(){}
void THUVIEN::Nhap(){
    cout<< "Nhap so luong sach: ";
    cin>>sl;
    for( int i=0; i<sl; i++){
        cout<< "Nhap thong tin sach thu "<<i+1<< ": \n";
        int x;
        do{
            cout<< "Nhap loai sach (1_Sach giao khoa, 2_Sach tham khao): ";
            cin>>x;
        }while(x!=1 && x!=2);
        if(x==1) p[i]= new GIAOKHOA;
        else p[i]=new THAMKHAO;
        p[i]->Nhap();
    }
}
void THUVIEN::Xuat(){
    for( int i=0; i<sl; i++){
        p[i]->Xuat();
        cout<<endl;
    }
}
long THUVIEN::getSL(){
    return sl;
}
string THUVIEN::DoiInHoa(string s){
    for (int i=0; i<s.length(); i++){
        s[i]=tolower(s[i]);
    }
    return s;
}
void THUVIEN::TienThuVienPhaiTraChoTungLoaiSach(){
     double TienSachGiaoKhoa=0, TienSachThamKhao=0;
    for(int i=0; i<sl; i++){
        if(p[i]->getLoai()== "Sach giao khoa") TienSachGiaoKhoa+=p[i]->ThanhTien();
        else TienSachThamKhao+=p[i]->ThanhTien();
    }
    cout<< "Tien thu vien phai tra cho sach giao khoa: "<<TienSachGiaoKhoa<<endl;
    cout<< "Tien thu vien phai tra cho sach tham khao: "<<TienSachThamKhao<<endl;
 }
void THUVIEN::ThongTinSachCoThanhTienItNhat(){
     double minn=p[0]->ThanhTien();
    for( int i=1; i<sl; i++){
        if(p[i]->ThanhTien()<minn) minn=p[i]->ThanhTien();
    }
    cout<< "Nhung sach co thanh tien it nhat: \n";
    for( int i=0; i<sl; i++){
        if(p[i]->ThanhTien()==minn) p[i]->Xuat();
    }
}
void THUVIEN::TimSGKCuaNXBCoTenDoNguoiDungNhapVao(string s){
    int dem=0;
    for( int i=0; i<sl; i++){
        if(DoiInHoa(p[i]->getNXB())== DoiInHoa(s) && p[i]->getLoai()=="GK"){
            p[i]->Xuat();
            dem++;
        }
    }
    if(dem==0) cout<< "Khong co sach giao khoa cua nha xuat ban "<<s<<endl;
}
SACH::SACH(string ms, string ten, string nxb, int sl, int gia): ms(ms), ten(ten), nxb(nxb), sl(sl), gia(gia){}
    SACH::~SACH(){}
    string SACH::getMS(){return ms;}
    string SACH::getTen(){return ten;}
    string SACH::getNXB(){return nxb;}
    int SACH::getSL(){return sl;}
    int SACH::getGia(){return gia;}
    void SACH::Nhap(){
    cin.ignore();
    cout<< "Nhap ma so sach: "; getline(cin, ms);
    cout<< "Nhap ten sach: "; getline(cin, ten);
    cout<< "Nhap ten NXB: "; getline(cin, nxb);
    cout<< "Nhap so luong: "; cin>>sl;
    cout<< "Nhap gia: "; cin>>gia;
    }
    void SACH::Xuat(){
        cout<<ms<<"\tTen: "<<ten<< "\tNXB: "<<nxb<< "\tSL: "<<sl<< "\tGia: "<<gia;
    }
GIAOKHOA::GIAOKHOA(string ms, string ten, string nxb, int sl, int gia, string tinhTrang): SACH(ms, ten, nxb, sl, gia), tinhTrang(tinhTrang){};
GIAOKHOA::~GIAOKHOA(){}
string GIAOKHOA::getTT(){return tinhTrang;}
void GIAOKHOA::Nhap(){
    SACH::Nhap();
    int tt;
    do{
    cout<< " Tinh trang sach ( 0_Sach cu, 1_Sach moi): ";
    cin>>tt;
    }while( tt!=0 && tt!=1);
    if(tt==1) tinhTrang= "Sach moi";
    else tinhTrang= "Sach cu";
}
void GIAOKHOA::Xuat(){
    SACH::Xuat();
    cout<< "\tTinh trang: "<<tinhTrang<<endl;
}
string GIAOKHOA::getLoai(){
    return "GK";
}
double GIAOKHOA::ThanhTien(){
    if(tinhTrang== "Sach moi") return sl*gia;
    else return  (double) sl*gia*0.5;
}
THAMKHAO::THAMKHAO(string ms, string ten, string nxb, int sl, int gia, double thue): SACH(ms, ten, nxb, sl, gia), thue(thue){};
THAMKHAO::~THAMKHAO(){};
double THAMKHAO::getThue(){return thue;}
void THAMKHAO::Nhap(){
    SACH::Nhap();
    do{
    cout<< "Nhap thue (0->1): ";cin>>thue;
    }while(thue<0 || thue>1);
}
void THAMKHAO::Xuat(){
    SACH::Xuat();
    cout<< "\tThue: "<<thue<<endl;
}
string THAMKHAO::getLoai(){
    return "TK";
}
double THAMKHAO::ThanhTien(){
    return (double) sl*gia +thue;
}
int main()
{
    THUVIEN UIT;
    int se;
    cout<< "------------THU VIEN NEKKKK---------------\n";
    cout<< "1. Nhap thong tin sach trong thu vien.\n";
    cout<< "2. Xuat thong tin sach trong thu vien.\n";
    cout<< "3. Tien ma truong phai tra cho tung loai sach.\n";
    cout<< "4. Thong tin chi tiet nhung sach co thanh tien phai tra it nhat.\n";
    cout<< "5. Tim thong tin cac SGK co ten tac gia do nguoi dung nhap vao.\n";
    cout<< "0. Thoat CT.\n";
    do{
        cout<< "-----------------------------------------------------\n";
        cout<< "BAN CHON: "; cin>>se;
        switch(se){
            case 0: cout<< "SAY GOODBYE!\n";
                break;
            case 1:
                UIT.Nhap();
                break;
            case 2:
                UIT.Xuat();
                break;
            case 3:
                UIT.TienThuVienPhaiTraChoTungLoaiSach();
                break;
            case 4:
                UIT.ThongTinSachCoThanhTienItNhat();
                break;
            case 5:{
                string tg;
                getline(cin, tg);
                UIT.TimSGKCuaNXBCoTenDoNguoiDungNhapVao(tg);
                break;
            }
            default: {
                cout<< "Ban chon sai. Moi chon lai.\n";
                break;
            }
        }
    }while( se!=0);
    return 0;
}
