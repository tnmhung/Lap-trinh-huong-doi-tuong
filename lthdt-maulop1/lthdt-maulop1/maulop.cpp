#include<iostream>
//#include<stdio.h>

using namespace std;

//khai bao mau lop doi tuong ngan xep luu tru ke tiep
template<class Type>
class Stack
{
private:
	enum {size = 32};
	Type S[size];
	int T;

public:
	Stack();
	void push(Type x);
	Type pop();
	bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
	//tao doi tuong ngan xep chua phan tu la so nguyen
	Stack<int> s1;

	//tao doi tuong ngan xep chua phan tu la ki tu
	Stack<char> s2;

	//khai bao bien
	unsigned int n, thuong, du;

	cout << "Nhap vao 1 so nguyen duong: "; cin >> n;

	//chuyen sang nhi phan
	thuong = n;
	while (thuong)
	{
		du = thuong % 2;
		thuong /= 2;
		s1.push(du);
	}

	//chuyen ra ma hex
	thuong = n;
	while (thuong)
	{
		du = thuong % 16;
		thuong /= 16;

		//chuyen so du thanh chu so he hex r day vao ngan xep s2
		if (du < 10) s2.push(du + 48);
		else s2.push(du + 55);
	}

	//dua ra ket qua
	cout << "\nSo nhi phan cua " << n << " la: ";
	while (!s1.isEmpty()) cout << s1.pop();

	cout << "\nSo hex phan cua " << n << " la: ";
	while (!s2.isEmpty()) cout << s2.pop();


	cout << endl;
	return 0;
}
//===dinh nghia ham===
template<class Type>
Stack<Type>::Stack() :T(-1)
{

}

template<class Type>
void Stack<Type>::push(Type x)
{
	//1. kiem tra ngan xep day
	if (T == size - 1)
	{
		cout << "Ngan xep day!" << endl;
		return;
	}


	//2-3. tang T len 1 va dua X vao vi tri T
	S[++T] = x;
}

template<class Type>
Type Stack<Type>::pop()
{
	//1.kiem tra ngan xep rong
	if (T == -1)
	{
		Type tg;
		cout << "Ngan xep da rong!" << endl;
		return tg;
	}

	//2-3-4.tra ve phan tu dinh va giam T
	return S[T--];
}

template<class Type>
bool Stack<Type>::isEmpty()
{
	return T == -1;
}

