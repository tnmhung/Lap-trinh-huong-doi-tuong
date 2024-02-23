//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 31(lthdtbai31.cpp): Đọc vào một dãy số nguyên từ tệp văn bản, trong đó có cả số dương và số âm.
  Sử dụng hàng đợi lưu trữ phan tan theo kiểu quay vòng để tách, đưa ra màn hình đồng thời
  ghi ra tệp văn bản dãy các số dương và dãy các số âm.
*/
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao lop doi tuong hang doi luu tru phan tan
class Queue
{
	private:
		struct node
		{
			int infor;
			node *link;
		}*F, *R;

	public:
		Queue();
		~Queue();
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
Queue::Queue() :F(NULL), R(NULL)
{

}

Queue::~Queue()
{
	while (F)
	{
		node* P = F;
		F = F->link;
		delete P;
	}
}

void Queue::insert(int x)
{
	//1.Tao nut moi
	node* N = new node;
	N->infor = x;
	N->link = NULL;

	//2.Noi nut moi vao sau R
	if (F == NULL) F = R = N;
	else R->link = N;

	//3.Cho R tro toi nut moi
	R = N;
}

int Queue::remove()
{
	//1.Kiem tra rong
	if (F == NULL)
	{
		cout << "Hang doi rong!";
		return 1;
	}

	//2.Giu lai nut loi truoc(nut dau hang)
	int tg = F->infor;
	node *P = F;

	//3.Cho F tro toi nut dung sau
	if (F == R) F = R = NULL;
	else F = F->link;

	//4.Huy nut va tra ve phan tu du lieu
	delete P;
	return tg;
}

bool Queue::isEmpty()
{
	return F == NULL;
}

