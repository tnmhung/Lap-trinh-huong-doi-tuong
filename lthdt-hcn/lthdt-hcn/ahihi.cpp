/*
	tính chu vi diện tich hình chữ nhật theo hướng đối tượng
*/

#include<iostream>

using namespace std;

//Khai bao lop hinh chu nhat
class HinhCN
{
	private:
		int a, b;

	public:
		void nhap();
		int tinhCV();
		int tinhDT();
};

//===Chuong trinh chin=
int main() 
{
	system("color 8");
	//tao doi tuong hinh chu nhat
	HinhCN hcn;

	//thao tac
	hcn.nhap();

	cout << "Chu vi hinh chu nhat la:" << hcn.tinhCV()<<endl;
	cout << "Dien tich hinh chu nhat la: " << hcn.tinhDT();

	cout << endl;
	return 0;
}
//===Dinh nghia ham
void HinhCN::nhap()
{
	cout << "Nhap thong tin 2 canh a va b:" << endl;
	cout << "\tNhap canh a: ";	cin >> a;
	cout << "\tNhap canh b: ";	cin >> b;
}

int HinhCN::tinhCV()
{
	return (a + b) * 2;
}

int HinhCN::tinhDT()
{
	return (a * b);
}
