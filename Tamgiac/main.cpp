#include "DIEM.h"
#include "tamgiac.h"
#include <iostream>
int main()
{
    cout<< "Co "<<DIEM::GetDem()<< " diem\n";
    cout<< "Co "<<TAMGIAC::GetDem()<<" TG\n";
    DIEM A, B(3), C(0,4);
    TAMGIAC tg1, tg2(A,B,C), tg3(0,4,-3,0,3,0);
    cout<<"Co "<<DIEM::GetDem()<<" diem\n";
    cout<<"Co "<<TAMGIAC::GetDem()<<" TG\n";
    tg1.Xuat();
    tg2.Xuat();
    tg3.Xuat();

    return 0;
}
