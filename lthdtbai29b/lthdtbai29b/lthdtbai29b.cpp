//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 29(lthdtbai29.cpp): Nhập vào một số nguyên dương, đưa ra số hex tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang hex.
Ngăn xếp sử dụng cấu trúc lưu trữ kế tiếp với phần tử là ký tự.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong ngan xep
class Stack
{
	private:
		enum {size = 32};
		int S[size];
		int T;

	public:
		Stack();
		void push(char x);
		char pop();
		bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
	//Tao doi tuong ngan xep
	Stack s;

	//Khai bao bien
	int n, thuong, du;

	//Nhap n
	cout << "Nhap vao 1 so nguyen duong: ";
	cin >> n;

	//Chuyen sang he Hex
	thuong = n;
	while (thuong)
	{
		du = thuong % 16;
		thuong /= 16;

		if (du < 10) s.push(du + 48);
		else s.push(du + 55);
	}

	//Dua ket qua ra man hinh
	cout << "Ma hex tuong ung cua " << n << " la: ";
	while (!s.isEmpty()) cout << s.pop();

	cout << endl;
	return 0;
}
//===dinh nghia ham
Stack::Stack():T(-1)
{

}

void Stack::push(char x)
{
	//1.Kiem tra ngan xep day
	if (T == size - 1)
	{
		cout << "Ngan xep da day!";
		return;
	}

	//2-3.Tang T len 1 vao dua x vao vi tri T
	S[++T] = x;
}

char Stack::pop()
{
	//1.Kiem tra rong
	if (T == -1)
	{
		cout << "Ngan xep rong!";
		return 1;
	}

	//2-3-4.Tra ve phan tu dinh va giam T
	return S[T--];
}

bool Stack::isEmpty()
{
	return T == -1;
}
