#include <iostream>

using namespace std;

    long long UCLN ( long long a, long long b){
        if(b==0) return a;
        return UCLN(b, a%b);
    }

    int tongChuSo ( long long x){
        int tong(0);
        while(x>0){
            tong+=x%10;
            x=x/10;
        }
        return tong;
    }
    int soDao(int x){
        int a=0;
        while(x>0){
            a=a*10+ x%10;
            x=x/10;
        }
        return a;
    }
    bool soNT ( long long x){
        if(x<=1) return false;
        if(x==2) return true;
        for( long long i=2; i<x; i++){
            if(x%i==0) return false;
        }
        return true;
    }
int main()
{
    long long a,b;
    cin>>a>>b;
    if(soNT(soDao(tongChuSo(UCLN(a,b))))) cout<<"CO";
        else cout<<"KHONG";
    return 0;
}
