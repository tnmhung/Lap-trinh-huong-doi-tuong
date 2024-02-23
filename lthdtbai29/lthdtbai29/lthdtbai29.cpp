//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 29(lthdtbai29.cpp): Nhập vào một số nguyên dương, đưa ra số hex tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang hex.
Ngăn xếp sử dụng cấu trúc lưu trữ phân tán với phần tử là ký tự.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong ngan xep
class Stack
{
	private:
		struct node
		{
			char infor;
			node* link;
		}*T;

	public:
		Stack();
		~Stack();
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
Stack::Stack():T(NULL)
{

}

Stack::~Stack()
{
	while (T)
	{
		node* P = T;
		T = T->link;
		delete P;
	}
}

void Stack::push(char x)
{
	//1.Tao nut moi
	node* N = new node;
	N->infor = x;
	N->link = NULL;

	//2.Cho noi nut moi vao ten T
	N->link = T;

	//3.Cho T tro toi nut moi
	T = N;
}

char Stack::pop()
{
	//1.Kiem tra rong
	if (T == NULL)
	{
		cout << "Ngan xep da rong!" << endl;
		return 1;
	}

	//2.Giu lai phan tu dinh
	char tg = T->infor;
	node* P = T;

	//3.Cho T tro toi nut ben duoi
	T = T->link;

	//4.Huy nut va tra ve phan tu dinh
	delete P;
	return tg;
}

bool Stack::isEmpty()
{
	return T == NULL;
}
