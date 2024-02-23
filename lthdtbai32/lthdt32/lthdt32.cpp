//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
 Bài 32(lthdtbai32.cpp): Cho tệp văn bản "daysonguyen-bai32.txt" chứa dãy số nguyên,
  trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản, lưu dãy số trong
  danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
  Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.
*/
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao lop doi tuong DSLKD
class Slist
{
	private:
		struct node
		{
			int infor;
			node* link;
		}*F;

	public:	
		Slist();
		~Slist();
		void postInsert(int x);
		void display();
		bool search(int x);
		bool remove(int x);
};



//===chuong trinh chinh===
int main()
{
	//Tao doi tuong tep doc vao
	ifstream fin("D:\\file text\\daysonguyen-bai32.txt");

	//Tao doi tuong DSLKD
	Slist ds;

	//Khai bao bien
	int x;

	//Doc day so tu tep vao DSLKD
	while (fin >> x) ds.postInsert(x);

	//Dua day so ra man hinh
	cout << "Day so trong DSLKD la: ";
	ds.display();

	//Tim va xoa phan tu x
	cout << "\n\nNhap vao x can xoa: ";
	cin >> x;

	if (ds.search(x))
	{
		//xoa phan tu x
		ds.remove(x);

		//dua ra
		cout << "\nDay so trong DSLKD sau khi xoa phan tu " << x << " la: ";
		ds.display();
	}
	else cout << "\nTrong DSLKD khong co phan tu nao bang " << x;

	cout << endl;
	return 0;
}
//===dinh nghia ham===
Slist::Slist():F(NULL)
{

}

Slist::~Slist()
{
	while (F)
	{
		node* P = F;
		F = F->link;
		delete P;
	}
}

void Slist::postInsert(int x)
{
	//1.Tao nut moi
	node *N = new node;
	N->infor = x;
	N->link = NULL;

	//2.Noi nut moi vao cuoi danh sach
	if (F == NULL) F = N;
	else
	{
		//Tim nut cuoi DSLKD
		node *P = F;
		while (P->link) P = P->link;

		//Noi nut moi vao sau nut cuoi
		P->link = N;
	}
}

void Slist::display()
{
	node* P = F;

	while (P)
	{
		cout << P->infor << " ";
		P = P->link;
	}
}

bool Slist::search(int x)
{
	node* P = F;

	//Tim x
	while (P)
	{
		if (P->infor == x) return 1;
		else P = P->link;
	}

	//Khong tim thay phan tu x
	return 0;
}

bool Slist::remove(int x)
{
	//Tim nut M co phan tu bang x va nut P truoc nut M
	node* M = F, *P = NULL;
	while (M)
	{
		if (M->infor == x) break;
		else
		{
			P = M;
			M = M->link;
		}
	}

	//Truong hop khong thay phan tu bang x
	if (M == NULL) return 0;

	//Noi nut truoc M voi nut sau M
	P->link = M->link;

	//Huy nut M
	delete M;

	//Da xoa
	return 1;

}

