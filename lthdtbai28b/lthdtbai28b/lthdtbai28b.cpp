//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 28(lthdtbai28.cpp): Nhập vào một số nguyên dương, đưa ra số nhị phân tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang nhị phân.
Ngăn xếp sử dụng cấu trúc lưu trữ kế tiếp với phần tử là ký tự.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong ngan xep luu tru ke tiep
class Stack
{
	private:
		enum {size=32};
		int S[size];
		int T;

	public:
		Stack();
		void push(int x);
		int pop();
		bool isEmpty();
};

//===chuong trinh chinh===
int main()
{

	//Tao 1 doi tuong ngan xep
	Stack s;

	//Khai bao bien
	int n, thuong, du;

	//Nhap n
	cout << "Nhap vao 1 so nguyen duong: ";
	cin >> n;

	//Chuyen sang nhi phan
	thuong = n;
	while (thuong)
	{
		du = thuong % 2;
		thuong /= 2;
		s.push(du);
	}

	//Dua ket qua ra man hinh
	cout << "So nhi phan tuong ung cua " << n << " la: ";
	while (!s.isEmpty()) cout << s.pop();

	cout << endl;
	return 0;
}
//===dinh nghia ham===
Stack::Stack() :T(-1)
{

}

void Stack::push(int x)
{
	//1.Kiem tra day
	if (T == size - 1)
	{
		cout << "Ngan xep day!";
		return;
	}

	//2-3.Tang T len 1 va dua x vao ngan xep tai vi tri T
	S[++T] = x;
}

int Stack::pop()
{
	//1.Kiem tra rong
	if (T == -1)
	{
		cout << "Ngan xep rong!";
		return 1;
	}

	//2-3-4.Tra ve phan tu dinh va giam di T
	return S[T--];

}

bool Stack::isEmpty()
{
	return T == -1;
}
