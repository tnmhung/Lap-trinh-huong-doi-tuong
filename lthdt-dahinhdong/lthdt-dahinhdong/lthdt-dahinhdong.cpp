/*
	 Tính diện tích các hình: Hình tam
giác biết 3 cạnh a,b,c; hình chữ nhật biết 2
cạnh a,b; hình tròn biết bán kính r; hình trụ
biết bán kính r và chiều cao h. Biết rằng
hình trụ là một loại hình tròn có bán kính r
được kéo dài với chiều cao h. Nhập vào
một số hình tùy theo yêu cầu, trong đó cả
cả hình tam giác, chữ nhật, tròn, trụ. Đưa
ra diện tích các hình đã nhập. Yêu cầu cài
đặt đa hình động.
*/
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop doi tuong hinh
class Hinh
{
	private:

	public:
		virtual void nhap() = 0;
		virtual float tinhDT() = 0;
};

//Khai bao lop doi tuong hinh tam giac
class HinhTG:public Hinh
{
	private:
		float a, b, c;

	public:
		void nhap();
		float tinhDT();
};

//Khai bao lop doi tuong hinh chu nhat
class HinhCN :public Hinh
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


//Khai bao lop doi tuong hinh tru
class HinhTru :public HinhTron
{
private:
	float h;

public:
	void nhap();
	float tinhDT();
};

//===chuong trinh chinh===
int main()
{


	cout << endl;
	return 0;
}
//===dinh nghia ham===

