//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Viết chương trình C++ để hiển thị thông tin n sinh viên: id, điểm thi hai môn, điểm thể chất, tổng điểm, và điểm trung bình.
kế thừa nhiều mức
Khai báo lớp sinhvien
Khai báo và định nghĩa hàm get() để lấy thông tin sinh viên.
Khai báo lớp gdthechat
Khai báo và định nghĩa hàm nhapdiemgdtc() để đọc điểm thể chất.
Tạo lớp thongtinsv được kế thừa từ hai lớp là sinhvien và gdthechat
Khai báo và định nghĩa hàm display() để tìm tổng điểm và điểm trung bình
Khai báo đối tượng obj của lớp kế thừa, gọi hàm nhapdiemkiemtra(), nhapdiemgdtc() và display().
*/
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop doi tuong sinh vien
class SinhVien
{
	private:
		int MaSV;
		float diemkt1, diemkt2;

	public:
		SinhVien();
		SinhVien(int MaSV, float diemkt1, float diemkt2);
		void nhap();
		void hien();
};

//Khai bao lop doi tuong giao duc the chat
class GDTC
{
	private:
		float diemgdtc;//diem giao duc the chat

	public:
		GDTC();
		GDTC(float diemgdtc);
		void nhap();
		void hien();
};

class thongTinSV:public SinhVien,public GDTC
{
	private:
		float tongDiem, diemTB;

	public:
		thongTinSV();
		thongTinSV(float tongDiem, float diemTB, float diemgdtc, int MaSV, float diemkt1, float diemkt2);
		void nhap();
		void hien();
};

//===chuong trinh chinh===
int main()
{
	
	cout << endl;
	return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop sinh vien
SinhVien::SinhVien():MaSV(0),diemkt1(0),diemkt2(0)
{

}

SinhVien::SinhVien(int MaSV, float diemkt1, float diemkt2):MaSV(MaSV),diemkt1(diemkt1),diemkt2(diemkt2)
{

}

void SinhVien::nhap()
{
	cout << "Nhap vao ma sinh vien: "; cin >> MaSV;
	cout << "Nhap vao diem kiem tra 1: "; cin >> diemkt1;
	cout << "Nhap vao diem kiem tra 2: "; cin >> diemkt2;
}

void SinhVien::hien()
{
	cout << "\nMa sinh vien: " << MaSV;
}

//Ham thanh vien lop GDTC
GDTC::GDTC():diemgdtc(0)
{

}

GDTC::GDTC(float diemgdtc):diemgdtc(diemgdtc)
{

}

void GDTC::nhap()
{
	cout << "Nhap diem giao duc the chat: "; cin >> diemgdtc;
}

void GDTC::hien()
{

}

//Ham thanh vien lop thong tin sv
thongTinSV::thongTinSV():SinhVien(),GDTC()
{

}

thongTinSV::thongTinSV(float tongDiem, float diemTB, float diemgdtc, int MaSV, float diemkt1, float diemkt2)
{

}

void thongTinSV::nhap()
{

}

void thongTinSV::hien()
{
	
}