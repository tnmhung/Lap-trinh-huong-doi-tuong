//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 25(lthdtbai25.cpp): Viết chương trình nhập vào một thời gian có giờ và phút.
  Tính và đưa ra màn hình thời gian sau n phút nhập vào từ bàn phím.
  Yêu cầu thêm:
  1) Sử dụng toán tử nhập >> để nhập thời gian từ bàn phím theo dạng h:m
  2) Sử dụng toán tử xuất << để đưa thời gian ra màn hình theo định dạng h:mm
  3) Sử dụng toán tử + để cộng thời gian với số phút n
  4) Tự động khởi tạo thời gian có giờ, phút bằng 0
  5) Có thể khởi thời gian với giờ, phút xác định trước.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong thoi gian
class ThoiGian
{
	private:
		int gio, phut;

	public:
		ThoiGian();
		ThoiGian(int gio, int phut);
		ThoiGian operator+(int n);

		//Ham ban
		friend istream& operator>>(istream& cin, ThoiGian& tg);
		friend ostream& operator<<(ostream& cout, ThoiGian& tg);
};

//===chuong trinh chinh===
int main()
{
	//Tao 2 doi tuong thoi gian
	ThoiGian bd, tong;
	int n;

	//Nhap so lieu
	cout << "Nhap vao thoi gian bat dau: " << endl;
	cin >> bd;
	cout << "Nhap vao so phut: ";
	cin >> n;

	//Tinh thoi gian bat dau voi n phut
	tong = bd + n;

	cout << "\nThoi gian sau " << n << " phut la: " << tong;

	cout << endl;
	return 0;
}
//===dinh nghia ham===
ThoiGian::ThoiGian():gio(0),phut(0)
{

}

ThoiGian::ThoiGian(int gio, int phut):gio(gio),phut(phut)
{

}

ThoiGian ThoiGian::operator+(int n)
{
	ThoiGian tg;
	
	tg.gio = gio;
	tg.phut = phut + n;

	//Hieu chinh thoi gian ve dang 24 gio, 0<=gio<=23 0<=phut<=59
	tg.gio += tg.phut / 60;
	tg.gio = tg.gio % 24;
	tg.phut = tg.phut % 60;

	//tra ve thoi gian sau khi cong n phut
	return tg;
}

//Ham ban
istream& operator>>(istream& cin, ThoiGian& tg)
{
	char kt;

	do
	{
		cout << "Nhap vao thoi gian (h:m): ";
		cin >> tg.gio >> kt >> tg.phut;
	} while (tg.gio < 0 || tg.gio>23 || tg.phut < 0 || tg.phut > 59);

	return cin;
}

ostream& operator<<(ostream& cout, ThoiGian& tg)
{
	printf("%d:%02d", tg.gio, tg.phut);

	return cout;
}

