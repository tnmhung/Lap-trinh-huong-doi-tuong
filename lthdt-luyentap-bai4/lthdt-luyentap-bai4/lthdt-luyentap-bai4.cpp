//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 25(ktltbai25.cpp): Nhập vào danh sách n sinh viên, mỗi sinh viên có thông tin về mã sinh viên, họ tên, ngày sinh,
giới tính, lớp. Tìm sinh viên có tuổi cao nhất tính đến thời điểm hiện tại. Yêu cầu trong chương trình có sử dụng mảng động
để chứa danh sách sinh viên.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong Nguoi
class Nguoi
{
	private:
		char kt;
		char hoTen[50];
		int ngay, thang, nam;
		char gioiTinh[5];

	public:
		void nhap();
		void hien();
		int tinhTuoi();
};

//Khai bao lop doi tuong sinh vien
class SinhVien: public Nguoi
{
	private:
		int MaSV;
		char lop[10];

	public:
		void nhap();
		void hien();
		int tinhTuoi();
};

//===chuong trinh chinh===
int main()
{
	//Khai bao bien
	int n;
	int MAX = -1;
	int maxAge = -1;

	//Nhap so luong sinh vien va tao n doi tuong dong
	cout << "Nhap so luong sinh vien: "; cin >> n;
	SinhVien* sv = new SinhVien[n];

	//Nhap vao n doi tuong 
	printf("Nhap vao %d sinh vien: ", n);
	for (int i = 0; i < n; i++)
	{
		printf("\nSinh vien thu %d:\n", i + 1);
		sv[i].nhap();
		sv[i].tinhTuoi();
	}

	cout << "\n\nDanh sach sinh vien vua nhap la:";
	for (int i = 0; i < n; i++)
	{
		printf("\n\n\tSinh vien thu %d: ", i + 1);
		sv[i].hien();

		int currentAge = sv[i].tinhTuoi();
		if (currentAge > MAX)
		{
			MAX = currentAge;
			maxAge = i;
		}
	}

	// Kiểm tra xem có sinh viên nào có tuổi hay không
	if (maxAge != -1)
	{
		cout << "\n\nSinh vien co tuoi cao nhat la:";
		printf("\n\n\tSinh vien thu %d: ", maxAge + 1);
		sv[maxAge].hien();
	}
	else
	{
		cout << "\nKhong co sin vien nao duoc nhap!" << endl;
	}

	delete[]sv;
	cout << endl;
	return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop Nguoi
void Nguoi::nhap()
{
	cout << "Nhap ho ten: ";
	cin.ignore(); cin.getline(hoTen, sizeof(hoTen));
	cout << "Nhap ngay sinh(dd/mm/yyyy): ";
	cin >> ngay >> kt >> thang >> kt >> nam;
	cout << "Nhap gioi tinh: ";
	cin.ignore(); cin.getline(gioiTinh, sizeof(gioiTinh));
}

void Nguoi::hien()
{
	cout << "\n\tHo ten: " << hoTen;
	cout << "\n\tNgay sinh: " << ngay << kt << thang << kt << nam;
	cout << "\n\tGioi tinh: " << gioiTinh;
}

int Nguoi::tinhTuoi()
{
	return 2024 - nam;
}

//Ham thanh vien lop sinh vien
void SinhVien::nhap()
{
	cout << "Nhap ma sinh vien: ";
	cin >> MaSV;
	Nguoi::nhap();
	cout << "Nhap lop: ";
	cin.ignore(); cin.getline(lop, sizeof(lop));
}

void SinhVien::hien()
{
	cout << "\n\tMa sinh vien: " << MaSV;
	Nguoi::hien();
	cout << "\n\tLop: " << lop;
}

int SinhVien::tinhTuoi()
{
	return Nguoi::tinhTuoi();
}