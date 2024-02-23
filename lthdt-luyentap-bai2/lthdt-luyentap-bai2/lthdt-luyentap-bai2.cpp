//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
 Xây dựng lớp vận động viên VanDongVien gồm:

Thuộc tính: hoten (chuỗi ký tự), tuoi (số nguyên), monthidau (chuỗi ký tự), cannang (số thực), chieucao (số thực).

Phương thức:

Thiết lập không tham số.
Hủy bỏ
Nạp chồng toán tử nhập >>
Nạp chồng toán tử xuất <<
Nạp chồng toán tử so sánh > (một vận động viên là lớn hơn nếu chiều cao lớn hơn, trong trường hợp chiều cao bằng nhau thì xét cân nặng lớn hơn)
Xây dựng chương trình chính:

Nhập vào một mảng gồm n vận động viên.
Hiển thị danh sách đã nhập ra màn hình.
Sắp xếp mảng đã nhập theo thứ tự tăng dần, hiển thị danh sách đã sắp ra màn hình.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong van dong vien
class VanDongVien
{
	private:
		char hoTen[30];
		int tuoi;
		char monTD[30];
		float canNang;
		float chieuCao;

	public:
		VanDongVien();
		~VanDongVien();		

		bool operator>(const VanDongVien& vdv);

		//Ham  ban, ham thong thuong
		friend istream& operator>>(istream& cin, VanDongVien& vdv);
		friend ostream& operator<<(ostream& cout, VanDongVien& vdv);
};

//Khai bao ham
void swap(VanDongVien &x, VanDongVien &y);
void bubbleSort(VanDongVien a[], int n);

//===chuong trinh chinh===
int main()
{
	//Khai bao bien
	int n;

	//Nhap so luong
	cout << "Nhap so luong van dong vien: ";
	cin >> n;

	//Tao n doi tuong van dong vien
	VanDongVien* vdv = new VanDongVien[n];

	//Nhap thong tin n van dong vien
	cout << "\nNhap thong tin cac van dong vien:\n";
	for (int i = 0; i < n; i++)
	{
		printf("\nVan dong vien thu %d:\n", i + 1);
		cin >> vdv[i];
	}

	cout << "\nThong tin cac van dong vien vua nhap la:";
	for (int i = 0; i < n; i++)
	{
		printf("\n\n\tVan dong vien thu %d:", i + 1);
		cout << vdv[i];
	}

	//sap xep theo chieu cao va can nag
	bubbleSort(vdv, n);

	cout << "\nDanh sach sau khi sap xep la:";
	for (int i = 0; i < n; i++)
	{
		printf("\n\n\tVan dong vien thu %d:", i + 1);
		cout << vdv[i];
	}

	//Giai phong bo nho
	delete[]vdv;
	cout << endl;
	return 0;
}
//===dinh nghia ham===
VanDongVien::VanDongVien() :hoTen(), tuoi(0), monTD(), canNang(0.0), chieuCao(0.0)
{

}

VanDongVien::~VanDongVien()
{

}

bool VanDongVien::operator>(const VanDongVien& vdv)
{
	if (chieuCao > vdv.chieuCao) return true;
	else if (chieuCao == vdv.chieuCao && canNang > vdv.canNang) return true;
	else return false;
}

//Ham  ban, ham thong thuong
istream& operator>>(istream& cin, VanDongVien& vdv)
{
	cout << "Nhap ho ten: ";
	cin.ignore();
	cin.getline(vdv.hoTen, sizeof(vdv.hoTen));

	cout << "Nhap tuoi: ";
	cin >> vdv.tuoi;

	cout << "Nhap mon thi dau: ";
	cin.ignore();
	cin.getline(vdv.monTD, sizeof(vdv.monTD));

	cout << "Nhap can nang: ";
	cin >> vdv.canNang;
	cout << "Nhap chieu cao: ";
	cin >> vdv.chieuCao;

	return cin;
}

ostream& operator<<(ostream& cout, VanDongVien& vdv)
{
	cout << "\n\tHo ten:" << vdv.hoTen;
	cout << "\n\tTuoi: " << vdv.tuoi;
	cout << "\n\tMon thi dau: " << vdv.monTD;
	cout << "\n\tCan nang: " << vdv.canNang;
	cout << "\n\tChieu cao: " << vdv.chieuCao;

	return cout;
}

void swap(VanDongVien& x, VanDongVien& y)
{
	VanDongVien tg = x;
	x = y;
	y = tg;
}

void bubbleSort(VanDongVien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

