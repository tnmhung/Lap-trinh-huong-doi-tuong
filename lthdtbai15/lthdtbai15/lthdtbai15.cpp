//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*
Bài 15(lthdtbai15.cpp): Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c. Ba cạnh a,b,c có thể nhập vào
  từ bàn phím hoặc từ tệp văn bản.
*/
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<math.h>

using namespace std;

//Khai bao lop doi tuong hinh tam giac
class HinhTG
{
	private:
		float a, b, c;

	public:
		void nhap();
		void docTep(const char* tenTep);
		float tinhDT();
		float tinhCV();
};

//===chuong trinh chinh===
int main()
{
	//Tao 1 doi tuong hinh tam giac
	HinhTG htg;

	//khai bao bien
	int type;

	do
	{
		
		//Hoi muon nhap theo cach nao
		cout << "Muon nhap theo cach nao (1.Nhap tu ban phim, 2.Doc tep): ";
		cin >> type;

		switch (type)
		{
			case 1:
				htg.nhap();
				break;
			case 2:
				htg.docTep("D:\\file text\\hinhtamgiac.txt");
			default:
				break;
		}
	} 
	while (type>=3);

	printf("Dien tich tam giac la: %0.1f", htg.tinhDT());
	printf("\nChu vi tam giac la: %0.1f", htg.tinhCV());

	cout << endl;
	return 0;
}
//===dinh nghia ham===
void HinhTG::nhap()
{
	do
	{
		cout << "Nhap vao 3 canh tam giac: ";
		cin >> a >> b >> c;

		if (a + b <= c || a + c <= b || b + c <= a)
			cout << "3 canh vua nhap khong phai canh cua tam giac. Nhap lai!\n";
	} while (a + b <= c || a + c <= b || b + c <= a);
}

void HinhTG::docTep(const char* tenTep)
{
	//Khai bao tep doc vao
	ifstream fin(tenTep);

	//Doc 3 canh tam giac
	fin >> a >> b >> c;

	//Neu 3 canh khong phai canh tam giac
	if (a + b <= c || a + c <= b || b + c <= a) 
		a = b = c = 0;
}

float HinhTG::tinhDT()
{
	//Neu 3 gia tri a b c khong phai 3 canh tam gia
	if (a + b <= c || a + c <= b || b + c <= a) return 0;

	//Neu la 3 canh tam giac
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

float HinhTG::tinhCV()
{
	return a + b + c;
}


