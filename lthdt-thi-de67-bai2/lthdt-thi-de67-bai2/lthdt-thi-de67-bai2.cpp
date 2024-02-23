//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De: 67
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong nhan su
class NhanSu
{
	private:
		char hoTen[31];
		char ngaySinh[11];

	public:
		virtual void nhap() = 0;
		virtual void hien() = 0;
};

//Khai bao lop doi tuong nhan vien
class NhanVien :public NhanSu
{
	private:
		char MaNV[10];
		float heSoLuong;

	public:	
		void nhap();
		void hien();
};

//khai bao lop doi tuong can bo quan ly
class CanBo:public NhanVien
{
	private:
		char chucVu[31];
		
	public:
		void nhap();
		void hien();
};

class GiaoVien:public NhanVien
{
	private:
		char Mon[31];

	public:
		void nhap();
		void hien();
};

//===chuong trinh chinh===
int main()
{
	//Khai bao bien
	int n;

	//Nhap so luong nhan su
	cout << "Nhap so luong nhan su: ";
	cin >> n;
	
	//tao 3 doi tuong 
	NhanVien** NV = new NhanVien*[n];
	CanBo** CB = new CanBo*[n];
	GiaoVien** GV = new GiaoVien*[n];

	// Vòng lặp nhập thông tin cho từng nhân viên, cán bộ hoặc giáo viên
	for (int i = 0; i < n; ++i) {
		int type;
		cout << "Chon doi tuong can nhap (1.NV, 2.CB, 3.GV): ";
		cin >> type;

		if (type == 1) {
			NV[i] = new NhanVien;
			NV[i]->nhap();
		}
		else if (type == 2) {
			CB[i] = new CanBo;
			CB[i]->nhap();
		}
		else if (type == 3) {
			GV[i] = new GiaoVien;
			GV[i]->nhap();
		}
		else {
			cout << "Loai nhan su khong hop le!" << endl;
			--i;
		}
	}

	// Vòng lặp hiển thị thông tin của từng nhân viên, cán bộ và giáo viên
	for (int i = 0; i < n; ++i) {
		if (NV[i]) {
			cout << "\nThong tin nhan vien " << i + 1 << ":";
			NV[i]->hien();
		}
		if (CB[i]) {
			cout << "\nThong tin can bo " << i + 1 << ":";
			CB[i]->hien();
		}
		if (GV[i]) {
			cout << "\nThong tin giao vien " << i + 1 << ":";
			GV[i]->hien();
		}
	}


	cout << endl;
	return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop nhan su
void NhanSu::nhap()
{
	cout << "Nhap vao ho ten: ";
	cin.getline(hoTen, sizeof(hoTen));
	cout << "Nhap vao ngay sinh(dd/mm/yyyy): ";
	cin >> ngaySinh;
}

void NhanSu::hien()
{
	cout << "\nHo ten: " << hoTen;
	cout << "\nNgay sinh: " << ngaySinh;
}

//Ham thanh vien lop nhan vien
void NhanVien::nhap()
{
	cout << "Nhap ma nhan vien: ";
	cin >> MaNV;
	NhanSu::nhap();
	cout << "Nhap he so luong: ";
	cin >> heSoLuong;
}

void NhanVien::hien()
{
	cout << "\nMa nhan vien: " << MaNV;
	NhanSu::hien();
	cout << "\nHe so luong: " << heSoLuong;
}

//Ham thanh vien lop can bo
void CanBo::nhap()
{
	NhanVien::nhap();
	cout << "Nhap chuc vu: ";
	cin.getline(chucVu, sizeof(chucVu));
}

void CanBo::hien()
{
	NhanVien::hien();
	cout << "\nChuc vu: " << chucVu;
}

//Ham thanh vien lop giao vien
void GiaoVien::nhap()
{
	NhanVien::nhap();
	cout << "Nhap mon giang day: ";
	cin.getline(Mon, sizeof(Mon));
}

void GiaoVien::hien()
{
	NhanVien::hien();
	cout << "\nMon giang day: " << Mon;
}
