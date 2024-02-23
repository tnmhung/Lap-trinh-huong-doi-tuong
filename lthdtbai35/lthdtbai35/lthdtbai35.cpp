//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
  Bài 35(lthdtbai35.cpp): Đọc danh sách n mặt hàng từ tệp văn bản "mathang.txt", lưu vào
  danh sách liên kết kép (DSLKK), mỗi mặt hàng có thông tin về mã hàng, tên hàng, số lượng, đơn giá.
  Đưa danh sách mặt hàng ra màn hình kèm theo số tiền của từng mặt hàng. Tính tổng số tiền của tất cả mặt hàng.
  Xóa mặt hàng có mã nhập vào từ bàn phím.
*/
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao kieu phan tu du lieu DSLKK
struct MatHang
{
	int MaMH;
	char tenHang[31];
	int soLuong;
	float donGia;
};

//Khai bao lop doi tuong DSLKK
class Dlist
{
	private:
		struct node
		{
			MatHang infor;
			node* left, * right;
		} *L,*R;

	public:
		Dlist();
		~Dlist();
		void lastInsert(MatHang x);
		void display();
		float getSum();
		bool remove(int MaMH);
};

//===chuong trinh chinh===
int main()
{
	//Tao 1 doi tuong DLSKK
	Dlist ds;

	//Tao doi tuong tep doc vao
	ifstream fin("D:\\file text\\mathang.txt");

	//Khai bao bien
	int n;
	MatHang x;
	char tg[2];

	//Doc so luong mat hang tu tep
	fin >> n;

	cout << endl;
	return 0;
}
//===dinh nghia ham===
Dlist::Dlist():L(NULL),R(NULL)
{

}

Dlist::~Dlist()
{
	while (L)
	{
		node* P = L;
		L = L->right;
		delete P;
	}
}

void Dlist::lastInsert(MatHang x)
{
	//tao nut moi chua x
	node* N = new node;
	N->infor = x;
	N->left = N->right = NULL;

	//Noi nut moi vao cuoi DSLKK(sau nut R)
	if (R == NULL) L = R = N;
	else
	{
		R->right = N;
		N->left = R;
		R = N;
	}
}

void Dlist::display()
{
	node* P = L;
	while (P)
	{
		//Dua ra mat hang tron nut P
		cout << "\n\tMa mat hang: " << P->infor.MaMH;
		cout << "\n\tTen hang: " << P->infor.tenHang;
		cout << "\n\tSo luong: " << P->infor.soLuong;
		cout << "\n\tDon gia: " << P->infor.donGia;
		printf("\n\tThanh tien: %0.1f", P->infor.soLuong * P->infor.donGia);

		//Cho P tro toi nut tiep theo
		P = P->right;
	}
}

float Dlist::getSum()
{
	float sum = 0.0;
	node* P = L;
	while (P)
	{
		sum += P->infor.soLuong * P->infor.donGia;
		P = P->right;
	}
	return sum;
}

bool Dlist::remove(int MaMH)
{
	node* P = L;

	while (P)
	{
		if (P->infor.MaMH == MaMH)
		{
			if (P == L && P == R) // Trường hợp danh sách chỉ có một phần tử
			{
				delete P;
				L = R = NULL;
			}
			else if (P == L) // Trường hợp xóa phần tử đầu danh sách
			{
				L = L->right;
				delete P;
				L->left = NULL;
			}
			else if (P == R) // Trường hợp xóa phần tử cuối danh sách
			{
				R = R->left;
				delete P;
				R->right = NULL;
			}
			else // Trường hợp xóa phần tử ở giữa danh sách
			{
				P->left->right = P->right;
				P->right->left = P->left;
				delete P;
			}
			return true; // Phần tử được xóa thành công
		}
		P = P->right;
	}
	return false; // Không tìm thấy phần tử cần xóa
}
