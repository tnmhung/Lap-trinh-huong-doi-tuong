//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 28(lthdtbai28.cpp): Nhập vào một số nguyên dương, đưa ra số nhị phân tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang nhị phân.
Ngăn xếp sử dụng cấu trúc lưu trữ phân tán với phần tử là ký tự.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong ngan xep luu tru phan tan
class Stack
{
	private:
		struct node
		{
			int infor;
			node* link;
		}*T;

	public:
		Stack();
		~Stack();
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

void Stack::push(int x)
{
	//1.Tao nut moi
	node* N = new node;
	N->infor = x;
	N->link = NULL;

	//2.Noi nut moi vao tren T
	N->link = T;

	//3.Cho T tro toi nut moi
	T = N;
}

int Stack::pop()
{
	//1.Kiem tra rong
	if (T == NULL)
	{
		cout << "Ngan xep rong!";
		return 1;
	}

	//2.Giu lai phan tu dinh
	int tg = T->infor;
	node* P = T;

	//3.Cho T tro toi nut duoi
	T = T->link;

	//4.Huy nut va tra ve phan tu 
	delete P;
	return tg;
}

bool Stack::isEmpty()
{
	return T == NULL;
}
