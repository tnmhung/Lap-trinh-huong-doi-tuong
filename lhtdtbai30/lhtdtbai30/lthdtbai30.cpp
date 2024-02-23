//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 30(lthdtbai30.cpp): Đọc vào một dãy số nguyên từ tệp văn bản, trong đó có cả số dương và số âm.
  Sử dụng hàng đợi lưu trữ kế tiếp theo kiểu quay vòng để tách, đưa ra màn hình đồng thời
  ghi ra tệp văn bản dãy các số dương và dãy các số âm.
*/
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao lop doi tuong hang doi luu tru ke tiep
class Queue
{
	private:
		enum { size = 100 };
		int Q[size];
		int F, R;

	public:
		Queue();
		void insert(int x);
		int remove();
		bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
	//Tao 2 doi tuong hang doi, Q1 chua so duong, Q2 chua so am
	Queue Q1, Q2;

	//Khai bao tep doc vao
	ifstream fin("D:\\file text\\daysonguyen-bai30.txt");

	//Khai bao bien
	int x;

	//doc vao phan tu
	cout << "Day so doc duoc tu tep la:\n";
	while (fin >> x)
	{
		cout << x << " ";
		
		if (x > 0) Q1.insert(x);
		else Q2.insert(x);
	}

	//Dua ket qua ra man hinh
	cout << "\n\nDay so duong la: ";
	while (!Q1.isEmpty()) cout << Q1.remove() << " ";

	cout << "\nDay so am la: ";
	while (!Q2.isEmpty()) cout << Q2.remove() << " ";

	cout << endl;
	return 0;
}
//===dinh nghia ham===
Queue::Queue():F(-1),R(-1)
{

}

void Queue::insert(int x)
{
	//1.Kiem tra day
	if (F == 0 && R == size - 1 || R + 1 == F)
	{
		cout << "Hang doi da day!";
		return;
	}

	//2.Tang R len 1
	if (R == -1) F = R = 0;
	else if (R == size - 1) R = 0;
	else R++;

	//3.Dua x vao vi tri r
	Q[R] = x;
}

int Queue::remove()
{
	//1.Kiem tra hang doi rong 
	if (F == -1) 
	{
		cout << "Hang doi rong!";
		return 1;
	}

	//2.Giu lai phan tu dung truoc
	int tg = Q[F];

	//3.Tang F len 1
	if (F == R)F = R = -1;
	else if (F == size - 1) F = 0;
	else F++;

	//tra ve phan tu da loai bo
	return tg;
}

bool Queue::isEmpty()
{
	return F == -1;
}
