#include <iostream>

using namespace std;

class GiaiPTBac1{
private:
    float a;
    float b;
public:
    //Khởi tạo 2 hệ số a, b đều = 0
    GiaiPTBac1(){
        a=b=0;
    }
    //Khởi tao hệ số a=0, b tùy ý
    GiaiPTBac1 (float b){
        a = 0;
        this->b = b;
    }
    //Khởi tạo hệ số a, b tùy ý
    GiaiPTBac1( float a, float b){
        this->a = a;
        this->b = b;
    }
    //Nhập 2 hệ số a, b
    void Nhap (){
        cout<<"Nhap a: ";
        cin>>a;
        cout<<"Nhap b: ";
        cin>>b;
    }
    void SetA ( double a){
        this->a=a;
    }
    void SetB (double b){
        this->b=b;
    }
    void SetAB (double a, double b){
        this->a=a;
        this->b=b;
    }
    float getA (){
        return a;
    }
    float getB (){
        return b;
    }
    //Giải phương trình
    void giaiPhuongTrinh (){
        if(a==0 && b==0) cout<<"Phuong trinh vo so nghiem";
        else if(a==0 && b!=0) cout<<"Phuong trinh vo nghiem";
        else cout<<" Phuong trinh co nghiem x = "<<-b/a;
    }
    //Xuất phương trình
    void XuatPhuongTrinh (){
        cout<<a<<" + "<<b<<"x = 0"
    }
};

int main()
{
    GiaiPTBac1 d1 (2,3);
    //d1.SetAB(2, 3);
    d1.giaiPhuongTrinh();
    cout<<endl;
    d1.XuatPhuongTrinh();
    cout<<endl;
    d1.getA();
    cout<<endl;
    d1.getB();

    return 0;
}
