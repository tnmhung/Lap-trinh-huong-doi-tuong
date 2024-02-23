//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Sinh viên hãy lập trình hướng đối tượng bằng C++ thực hiện các việc sau: 
- Xây dựng lớp PhuongTienGiaoThong (phương tiện giao thông): 
+) Thuộc tính: Hãng sản xuất (chuỗi ký tự), Tên phương tiện (chuỗi ký tự), Năm sản xuất (số nguyên), Vận tốc tối đa (float). 
+) Phương thức: Hàm thiết lập,  hàm nhập, hàm xuất. 
- Xây dựng lớp OTo (ô tô) kế thừa lớp PhuongTienGiaoThong bổ sung thêm: Thuộc tính: Số chỗ ngồi (int), Kiểu động cơ (chuỗi ký tự). 
Phương thức:  
- Hàm thiết lập, hàm huỷ bỏ, hàm nhập, hàm xuất.   
- Vận tốc cơ sở: được tính bằng vận tốc tối đa chia cho số chỗ.  
- Nạp chồng toán tử < (phương tiện giao thông có <Vận tốc cơ sở= nhỏ hơn thì nhỏ hơn). 

Chương trình chính: 
1) (3 điểm) Nhập từ bàn phím thông tin của một phương tiện giao thông PhuongTienGiaoThong. 
2) (2 điểm) Hiển thị thông tin của phương tiện giao thông vừa nhập ra màn hình.  
3) (2 điểm) Nhập thông tin cho n đối tượng OTO bao gồm: Hãng sản xuất, Tên phương tiện, Năm sản xuất, Vận tốc tối đa, số chỗ ngồi, kiểu động cơ.
4) (1 điểm) In ra màn hình thông tin của n đối tượng OTO cùng với vận tốc cơ sở.
5) (2 điểm) Sắp xếp danh sách các đối tượng OTO theo thứ tự giảm dần của vận tốc cơ sở.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop doi tuong phương tiện
class PhuongTien
{
	private:
		enum { size = 30 };
		char hangSX[size];
		char tenPT[size];
		int namSX;
		float vanTocMax;

	public:
		void nhap();
		void hien();
		float VanTocToiDa();
};

//Khai bao lop doi tuong oto
class OTO:public PhuongTien
{
	private:
		int soCho;
		char kieuDongCo[30];

	public:
		OTO();
		~OTO();
		void nhap();
		void hien();
		float VanTocCS();
		
		bool operator<(OTO& oto);
};

//===chuong trinh chinh===
int main()
{
	//Tao 1 doi tuong phuong tien giao thong
	PhuongTien pt;

	//Nhap thong tin phuong tien va dua ra man hinh
	cout << "Nhap thong tin phuong tien\n";
	pt.nhap();
	pt.hien();


	cout << "\n\n====================\n\n";
	//Khai bao bien
	int n;
	
	//Nhap vao so luong oto va tao n doi tuong oto
	cout << "Nhap so luong oto: "; cin >> n;
	OTO *oto = new OTO[n];

	//Nhap thong tin
	cout << "Nhap thong tin oto:";
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap thong tin xe thu %d:\n", i + 1);
		oto[i].nhap();
	}

	cout << "\n\n====================\n\n";
	cout << "Thong tin " << n << " oto vua nhap la:";
	for (int i = 0; i < n; i++)
	{
		printf("\n\n\tXe thu %d:", i + 1);
		oto[i].hien();
		cout << "\n\tVan toc co so: " << oto[i].VanTocCS();
	}

	cout << endl;
	return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop PhuongTien
void PhuongTien::nhap()
{
	cout << "Nhap hang san xuat: ";
	scanf_s(" "); cin.getline(hangSX, sizeof(hangSX));
	cout << "Nhap ten phuong tien: ";
	fflush(stdin);	cin.getline(tenPT, sizeof(tenPT));
	cout << "Nhap nam san xuat: "; cin >> namSX;
	cout << "Nhap van toc toi da: "; cin >> vanTocMax;
}

void PhuongTien::hien()
{
	cout << "\n\tHang san xuat: " << hangSX;
	cout << "\n\tTen phuong tien: " << tenPT;
	cout << "\n\tNam san xuat: " << namSX;
	cout << "\n\tVan toc toi da: " << vanTocMax;
}

float PhuongTien::VanTocToiDa()
{
	return vanTocMax;
}

//Ham thanh vien lop oto
OTO::OTO():soCho(0),kieuDongCo()
{

}

OTO::~OTO()
{

}

void OTO::nhap()
{
	PhuongTien::nhap();

	cout << "Nhap so cho: "; cin >> soCho;
	cout << "Nhap kieu dong co: ";
	cin.ignore(); cin.getline(kieuDongCo, sizeof(kieuDongCo));
}

void OTO::hien()
{
	PhuongTien::hien();

	cout << "\n\tSo cho: " << soCho;
	cout << "\n\tKieu dong co: " << kieuDongCo;
}

float OTO::VanTocCS()
{
	return VanTocToiDa() / soCho;
}

bool OTO::operator<(OTO& oto)
{
	return VanTocCS() < oto.VanTocCS();
}

