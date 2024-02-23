//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De: 66
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao lop doi tuong phan so
class PhanSo
{
	private:
		float a, b;
		char kt;

	public:
		PhanSo();
		PhanSo operator-(PhanSo ps2);
		void rutGon();

		//ham ban
		friend ifstream& operator>>(ifstream &fin, PhanSo &ps);
		friend ostream& operator<<(ostream &cout, PhanSo &ps);
};

//===chuong trinh chinh===
int main()
{
	//Tao 2 doi tuong phan so
	PhanSo ps1, ps2;

	//Tao 2 doi tuong tep doc vao
	ifstream finA("D:\\file text\\phanso1");
	ifstream finB("D:\\file text\\phanso2");


	cout << endl;
	return 0;
}
//===dinh nghia ham===
PhanSo::PhanSo():a(0),b(1)
{

}

PhanSo PhanSo::operator-(PhanSo ps2)
{
	PhanSo tg;
	
	tg.a = a * ps2.b - ps2.a * b;
	tg.b = b * ps2.b;

	return tg;
}

void PhanSo::rutGon()
{
	// Tìm ước số chung lớn nhất
	int tempA = a;
	int tempB = b;
	int r;

	while (tempB != 0) {
		r = tempA % tempB;
		tempA = tempB;
		tempB = r;
	}

	// Rút gọn
	a /= tempA;
	b /= tempA;
}

//Ham ban, ham thong thuong
ifstream& operator>>(ifstream& fin, PhanSo& ps)
{
	cout << "Doc vao phan so: ";
	fin >> ps.a >> ps.kt >> ps.b;

	return fin;
}

ostream& operator<<(ostream& cout, PhanSo& ps)
{
	cout << ps.a << "/" << ps.b;
	return cout;
}
