//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Xây dựng lớp Vemaybay gồm:

Thuộc tính: tenchuyen, ngaybay, giave
Phương thức:
Cấu tử
Hủy
Nhap
Xuat
getgiave() : hàm trả về giá vé
Xây dựng lớp Nguoi gồm:

Thuộc tính: hoten, gioitinh, tuoi
Phương thức:
Cấu tử
Hủy
Nhập
Xuất
Xây dựng lớp Hanhkhach (mỗi hành khách được mua nhiều vé) kế thừa lớp Nguoi bổ
sung thêm:

Thuộc tính: Vemaybay *ve; int soluong;
Phương thức:
Cấu tử
Hủy
Nhập
Xuất
tongtien(): trả về Tổng số tiền phải trả của hành khách
Chương trình chính: Nhập vào 1 danh sách n hành khách (n nhập từ bàn phím).
Hiển thị danh sách hành khách và số tiền phải trả tương ứng của mỗi khách hàng.
Sắp xếp danh sách hành khách theo chiều giảm dần của Tổng tiền.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong Ve may bay
class VeMayBay
{
	private:
		char kt;
		char tenChuyen[30];
		int ngay, thang, nam;
		float giaVe;

	public:
		VeMayBay();
		~VeMayBay();
		void nhap();
		void hien();
		float getGV();//gia ve
};

//Khai bao lop doi tuong nguoi
class Nguoi
{
	private:
		char hoTen[31];
		char gioiTinh[5];
		unsigned int tuoi;

	public:
		Nguoi();
		~Nguoi();
		void nhap();
		void hien();
};

//Khai bao lop doi tuong Hanh Khach
class HanhKhach:public Nguoi
{
	private:
		int soLuong;
		VeMayBay *ve;
		float donGia;

	public:
		HanhKhach();
		~HanhKhach();
		void nhap();
		void hien();

		bool operator<(HanhKhach& hk);
};

//Khai bao ham thong thuong
void swap(HanhKhach& x, HanhKhach& y);
void bubbleSort(HanhKhach a[], int n);

//===chuong trinh chinh===
int main()
{
	//Khai bao n doi tuong khach hang
	int n;

	//Nhap so luong khach va tao n doi tuong khach
	cout << "Nhap so luong hanh khach: ";
	cin >> n;
	HanhKhach* ds = new HanhKhach[n];
	
	cout << "Nhap thong tin hanh khach:";
	for (int i = 0; i < n; i++)
	{
		printf("\nHanh khach thu %d:\n", i + 1);
		ds[i].nhap();
	}

	cout << "\n\t\t---------------------\n\n";
	cout << "Thong tin khach hang:\n";
	for (int i = 0; i < n; i++)
	{
		ds[i].hien();
		cout << "\n=============\n";
	}

	//Sap xep
	bubbleSort(ds, n);

	cout << "\n\t\t---------------------\n\n";
	cout << "Danh sach sau khi sap xep:\n";
	for (int i = 0; i < n; i++)
	{
		ds[i].hien();
		cout << "\n=============\n";
	}

	cout << endl;
	return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop Ve may bay
VeMayBay::VeMayBay():tenChuyen(),giaVe(0)
{

}

VeMayBay::~VeMayBay()
{

}

void VeMayBay::nhap()
{
	cout << "Nhap ten chuyen: ";
	cin.ignore(); cin.getline(tenChuyen, sizeof(tenChuyen));
	cout << "Nhap ngay bay(dd/mm/yyyy): "; 
	cin.ignore();
	cin >> ngay >> kt >> thang >> kt >> nam;
	cout << "Nhap gia ve: "; cin >> giaVe;
}

void VeMayBay::hien()
{
	cout << "\n\tTen chuyen: " << tenChuyen;
	cout << "\n\tNgay bay: " << ngay << kt << thang << kt << nam;
	cout << "\n\tGia ve: " << giaVe;
}

float VeMayBay::getGV()
{
	return giaVe;
}

//Ham thanh vien lop nguoi
Nguoi::Nguoi() :hoTen(), gioiTinh(), tuoi(0)
{

}

Nguoi::~Nguoi()
{

}

void Nguoi::nhap()
{
	cout << "Nhap ho ten: ";
	cin.ignore(); cin.getline(hoTen, sizeof(hoTen));
	cout << "Nhap gioi tinh: ";
	cin.ignore();  cin >> gioiTinh;
	cout << "Nhap tuoi: "; cin >> tuoi;
}

void Nguoi::hien()
{
	cout << "\n\tHo ten: " << hoTen;
	cout << "\n\tGioi tinh: " << gioiTinh;
	cout << "\n\tTuoi: " << tuoi;
}

//Ham thanh vien lop Hanh khach
HanhKhach::HanhKhach() :soLuong(0), ve(nullptr), donGia(0)
{
	cout << "Nhap so luong ve da mua: ";
	cin >> soLuong;
	ve = new VeMayBay[soLuong];
}

HanhKhach::~HanhKhach()
{
	delete[]ve;
}

void HanhKhach::nhap()
{
	Nguoi::nhap();
	cout << "Nhap so luong ve da mua: ";
	cin >> soLuong;
	
	for (int i = 0; i < soLuong; ++i)
	{
		ve[i].nhap();
		donGia += ve[i].getGV();
	}

}

void HanhKhach::hien()
{
	cout << "\n\t - Thong tin khach hang:\n";
	Nguoi::hien();
	cout << "\n\t - Thong tin chuyen bay:\n";
	for (int i = 0; i < soLuong; ++i)
	{
		ve->hien();
		cout << endl;
	}
	cout << "\n\t==> Tong tien: " << donGia << endl;
}


bool HanhKhach::operator<(HanhKhach& hk)
{
	if (donGia < hk.donGia) return true;
	else return false;
}

//Ham thong thuong
void swap(HanhKhach& x, HanhKhach& y)
{
	HanhKhach tg = x;
	x = y;
	y = tg;
}

void bubbleSort(HanhKhach a[], int n) 
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
}

