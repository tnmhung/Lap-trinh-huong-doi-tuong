//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:66
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong hinh
class Hinh
{
	private:

	public:
		virtual void nhap() = 0;
		virtual float tinhDT() = 0;
};

//Khai bao lop doi tuong hinh chu nhat
class HinhCN:public Hinh
{
	private:
		float a, b;

	public:
		void nhap();
		float tinhDT();
};

//Khai bao lop doi tuong hinh tron
class HinhTron :public Hinh
{
	private:
		float r;

	public:
		void nhap();
		float tinhDT();
};

//Khai bao lop doi tuong hinh hop chu nhat
class HinhHCN :public Hinh
{
	private:
		float a, b;
		float h;

	public:
		void nhap();
		float tinhDTXQ();//ham tinh dien tich xung quanh
		float tinhDT();
};

//===chuong trinh chinh===
int main()
{
	//Khai bao bien
	int n;

	//Nhap vao so luong hinh
	cout << "Nhap vao so luong hinh can tinh: ";
	cin >> n;

	//Tao n doi tuong hinh
	Hinh** ds = new Hinh*[n];

	//nhap vao cac hinh
	for (int i = 0; i < n; i++)
	{
		int type;
		cout << "Nhap vao so hinh can tinh(1-HinhCN,2-HinhTron,3-HinhHCN): ";
		cin >> type;

		switch (type)
		{
			case 1:
				HinhCN hcn;
				hcn.nhap();
				break;
			case 2:
				HinhTron ht;
				ht.nhap();
				break;
			case 3:
				HinhHCN hhcn;
				hhcn.nhap();
				break;
			default:
				cout << "Lua chon khong hop le!" << endl;
				return 1;
		}
	}

	//Dua ra ket qua
	cout << "\nDien tich cac hinh vua nhap la: " << endl;
	for (int i = 0; i < n; i++)
	{
		printf("Hinh thu %d: %0.2f", i + 1, ds[i]->tinhDT());
		cout << endl;
	}

	cout << endl;
	return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop hinh chu nhat
void HinhCN::nhap()
{
	cout << "Nhap vao 2 canh a va b: ";
	cin >> a >> b;
}

float HinhCN::tinhDT()
{
	return a * b;
}

//Ham thanh vien lop hinh tron
void HinhTron::nhap()
{
	cout << "Nhap vao ban kinh hinh tron: ";
	cin >> r;
}

float HinhTron::tinhDT()
{
	return 3.14 * r * r;
}

//Ham thanh vien lop hinh hop chu nhat
void HinhHCN::nhap()
{
	cout << "Nhap vao 2 canh a va b: ";
	cin >> a >> b;
	cout << "Nhap vao chieu cao: ";
	cin >> h;
}

float HinhHCN::tinhDTXQ()
{
	return (a + b) * h * 2;
}

float HinhHCN::tinhDT()
{
	return tinhDTXQ() + 2 * a * b;
}

