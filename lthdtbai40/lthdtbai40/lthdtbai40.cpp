//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
 Bài 40(lthdtbai40.cpp): Một nhân sự nói chung có họ tên và ngày sinh. Nhân viên trong
  một công ty là một loại nhân sự có thêm mã nhân viên và hệ số lương. Cán bộ quản lý
  trong công ty là một loại nhân viên có thêm chức vụ. Nhập vào danh sách n cán bộ quản lý.
  Đưa ra danh sách cán bộ quản lý đã nhập.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong nhan su
class NhanSu
{
	private:
		char hoTen[31];
		char ngaySinh[10];

	public:
		void nhap();
		void hien();
};

//Khai bao lop doi tuong nhan vien
class NhanVien:public NhanSu
{
	private:
		char MaNV[10];
		float heSoLuong;

	public:
		void nhap();
		void hien();
};

//Khai bao lop doi tuong can bo quan ly
class CanBo:public NhanVien
{
	private:
		char chucVu[30];

	public:
		void nhap();
		void hien();
};



//===chuong trinh chinh===
int main()
{
	//Khai bao bien
	int n;

	//Nhap n
	cout << "Nhap vao so luong can bo quan ly: ";
	cin >> n;

	//Tao n doi tuong can bo quan ly
	CanBo* cb = new CanBo[n];

	cout << "Nhap thong tin can bo:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap can bo thu " << i + 1 << ":\n";
		cb[i].nhap();
	}

	//Hien thi danh sach
	cout << "Danh sach can bo vua nhap la: " << endl;
	for (int i = 0; i < n; i++)
	{
		printf("\nCan bo thu %d:\n", i + 1);
		cb[i].hien();
		cout << endl;
	}

	cout << endl;
	return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop nhan su
void NhanSu::nhap()
{
	cout << "Nhap ho va ten: ";
	fflush(stdin); cin.get(hoTen, sizeof(hoTen));
	cout << "Nhap vao ngay sinh: ";
	cin >> ngaySinh;
}

void NhanSu::hien()
{
	cout << "Ho ten: " << hoTen;
	cout << "\nNgay sinh: " << ngaySinh;
}

//Ham thanh vien lop nhan vien
void NhanVien::nhap()
{
	NhanSu::nhap();
	cout << "Nhap vao ma nhan vien: ";
	cin >> MaNV;
	cout << "Nhap vao he so luong: ";
	cin >> heSoLuong;
}

void NhanVien::hien()
{
	cout << "Ma nhan vien: " << MaNV;
	NhanSu::hien();
	cout << "He so luong: " << heSoLuong;
}

//ham thanh vien lop can bo quan ly
void CanBo::nhap()
{
	NhanVien::nhap();
	cout << "Nhap vao chuc vu: ";
	fflush(stdin); cin.get(chucVu, sizeof(chucVu));
}

void CanBo::hien()
{
	NhanVien::hien();
	cout << "Chuc vu: " << chucVu;
}
