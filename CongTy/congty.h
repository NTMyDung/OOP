#pragma once
#ifndef CONGTY_H
#include "thuvien.h"
class CONGTY{
private:
    NHANVIEN** pNV;
    int sl;
public:
    CONGTY();
    ~CONGTY();
    int getSL();
    void Nhap();
    void Xuat();
    NHANVIEN* Nhap1();
    void LietKeNVBCCoHSLuongTu3cham5TroLen();
    int DemSoLuongNVHDCoSoNgayCongla26();
    long TongTienLuongDaTraChoCacNVPhongKeToan();
    double TinhTienLuongTBCuaCacNVBC();
    bool KiemTraCTyCoNVHDKhongDiLamNgayNaoKhong();
    void TimCacNVBCCoHSLuongCaoNhat();
    string DoiChuoiInHoa(string);
    string DoiChuoiInThuong(string);
    void SXDSNVTangDanTheoMaSo();
    void Them(NHANVIEN*,int);
    void Xoa(string);
    void TimKiemNVTheoMS(string);
};
#endif // CONGTY_H
