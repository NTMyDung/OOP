#include<iostream>
#include<string>

using namespace std;

class Sach
{
protected:
	string ms;
	string ten;
	string nxb;
	int sl;
	long gia;

public:
	enum Loai{SGK, STK};
	Loai pl;
	Sach()
	{
	}
	~Sach()
	{
	}
	virtual void Nhap()
	{
		cout << "Nhap ma so sach: ";
		cin.ignore();
		getline(cin, ms);
		cout << "Nhap ten sach: ";
		getline(cin, ten);
		cout << "Nhap nha xuat ban cua sach: ";
		getline(cin, nxb);
		cout << "Nhap so luong sach: ";
		cin >> sl;
		cout << "Nhap don gia cua sach: ";
		cin >> gia;
	}
	virtual void Xuat()
	{
		cout << "Ma so: " << ms << endl;
		cout << "Ten: " << ten << endl;
		cout << "Nha xuat ban: " << nxb << endl;
		cout << "So luong: " << sl << endl;
		cout << "Gia 1 sach: " << gia << endl;
	}
	virtual double thanhtien() = 0;
	int phanloai()
	{
		if (this->pl == SGK)
			return 1;
		else
			return 2;
	}
	virtual double get() = 0;
	string getnxb()
	{
		return nxb;
	}
};

class Sachgk :public Sach
{
public:
	int tinhtrang;
	Sachgk()
	{
		pl = SGK;
	}
	~Sachgk()
	{
	}
	void Nhap()
	{
		Sach::Nhap();
		cout << "Chon tinh trang sach: "<<endl;
		cout << "0. Sach cu." << endl;
		cout << "1. Sach moi." << endl;
		do
		{
			cout << "Chon: ";
			cin >> tinhtrang;
			if (tinhtrang != 1 && tinhtrang != 0)
				cout << "Chon lai" << endl;
		} while (tinhtrang != 1 && tinhtrang != 0);
	}
	void Xuat()
	{
		Sach::Xuat();
		cout << "Tinh trang sach: ";
		if (tinhtrang == 0)
			cout << "cu." << endl;
		else
			cout << "moi." << endl;
	}
	double thanhtien()
	{
		if (tinhtrang == 1)
			return sl * gia;
		else
			return sl * gia * 0.5;
	}
	double get()
	{
		return tinhtrang;
	}
};

class Sachtk :public Sach
{
public:
	double thue;
	Sachtk()
	{
		pl = STK;
	}
	~Sachtk()
	{

	}
	void Nhap()
	{
		Sach::Nhap();
		cout << "Nhap tien thue: ";
		cin >> thue;
	}
	void Xuat()
	{
		Sach::Xuat();
		cout << "Thue: " << thue << endl;
	}
	double thanhtien()
	{
		return sl * gia + thue;
	}
	double get()
	{
		return thue;
	}
};

class ThuVien
{
private:
    int n;
	Sach** ds;
public:
	ThuVien()
	{
		n = 0;
		ds = new Sach*;
	}
	~ThuVien()
	{
		delete[]ds;
	}
	void nhap()
	{
		int s;
		for (int i = 0;; i++)
		{
			cout << "Cho loai sach: " << endl;
			cout << "1. Sach giao khoa." << endl;
			cout << "2. Sach tham khao." << endl;
			cout << "0.Ngung nhap." << endl;
			do
			{
				cout << "Chon :";
				cin >> s;
				if (s != 1 && s != 2 && s!= 0)
					cout << "Chon lai." << endl;
			} while (s != 1 && s != 2 && s != 0);
			if (s == 0)
			{
				return ;
			}
			if (s == 1)
			{
				n++;
				ds[i] = new Sachgk;
			}
			if (s == 2)
			{
				n++;
				ds[i] = new Sachtk;
			}
			ds[i]->Nhap();
		}
	}
	void xuat()
	{
		for (int i = 0; i < n; i++)
		{
			if (ds[i]->phanloai() == 1)
				cout << "Sach Giao Khoa." << endl;
			else
				cout << "Sach Tham Khao." << endl;
			ds[i]->Xuat();
		}
	}
	double tiensgk()
	{
		double tsgk = 0;
		for (int i = 0; i < n; i++)
		{
			if (ds[i]->phanloai() == 1)
				tsgk += ds[i]->thanhtien();
		}
		return tsgk;
	}
	double tienstk()
	{
		double tstk = 0;
		for (int i = 0; i < n; i++)
		{
			if (ds[i]->phanloai() == 2)
				tstk += ds[i]->thanhtien();
		}
		return tstk;
	}
	void tongtien()
	{
		cout << "Thanh tien sach giao khoa: " << tiensgk() << endl;
		cout << "Thanh tien sach tham khao: " << tienstk() << endl;
	}
	void thueit()
	{
		int min = 0;
		for (int i = 0; i < n; i++)
		{
			min = ds[i]->get();
			if (ds[i]->phanloai() == 2)
			{
				for (int j = 1; j < n; j++)
				{
					if(ds[j]->phanloai() == 2)
					if (ds[j]->get() < min)
						min = ds[j]->get();
				}
			}
			break;
		}
		for (int i = 0; i < n; i++)
		{
			if (ds[i]->phanloai() == 2 && ds[i]->get() == min)
			{
				ds[i]->Xuat();
			}
		}
	}
	int timkiem(string a)
	{
		for (int i = 0; i < n; i++)
		{
			if (ds[i]->phanloai() == 1)
			{
				if (ds[i]->getnxb() == a)
				{
					ds[i]->Xuat();
					return 1;
				}
			}
		}
		return 0;
	}
};

int main()
{
	ThuVien x;
	int chon;
	do
	{
		cout << "\n____________________________________________" << endl;
		cout << "Chon chuc nang thuc hien: " << endl;
		cout << "1. Nhap danh sach." << endl;
		cout << "2. Xuat danh sach." << endl;
		cout << "3. Xuat thanh tien ma thu vien phai tra." << endl;
		cout << "4. Xuat danh sach sach tham khao it thue nhat." << endl;
		cout << "5. Tim kiem sach gia khoa theo nha san xuat." << endl;
		cout << "0. Thoat." << endl;
		cout << "__________________________________________" << endl;
		cout << "Chon ";
		cin >> chon;
		switch (chon)
		{
		case 0:
			break;
		case 1:
			x.nhap();
		case 2:
			cout << "			DANH SACH SACH TRONG THU VIEN" << endl;
			x.xuat();
			break;
		case 3:
			cout << "			THANH TIEN THU VIEN PHAI TRA" << endl;
			x.tongtien();
			break;
		case 4:
			cout << "			DANH SACH SACH THAM KHAO IT THUE NHAT" << endl;
			x.thueit();
			break;
		case 5:
			string a;
			int c;
			cout << "Tim Kiem Sach: " << endl;
			cout << "Chon " << endl << "1: Tim sach" << endl << "0.Thoat" << endl;
			cout << "Chon: ";
			cin >> c;
			switch (c)
			{
			case 0:
				break;
			case 1:
				if (c == 1)
				{
					cout << "Nhap ten nha xuat ban cua sach muon tim kiem: ";
					cin.ignore();
					getline(cin, a);
					if (x.timkiem(a) == 1)
					{
						cout << "Da tim thay " << endl;
					}
					else
					{
						cout << "Khong tim thay sach" << endl;
					}
				}
				break;
			}
			break;

		}
	} while (chon != 0);
    return 0;
}
