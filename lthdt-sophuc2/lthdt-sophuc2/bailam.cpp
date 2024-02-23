/*
	Tính tổng 2 số phức. Yêu cầu:
	1)Sử dụng toán tử cộng + để cộng 2 số phức
	2)Sử dụng toán tử nhập >> để nhập vào số phức
	3)Sử dụng toán tử xuất << để đưa ra số phức
*/
#include<iostream>


using namespace std;

//khai bao lop doi tuong so phuc
class SoPhuc
{
	private:
		float a, b;

	public:
		SoPhuc operator+(SoPhuc &p2);

		//ham ban
		friend istream& operator>>(istream& cin, SoPhuc& p);
		friend ostream& operator<<(ostream& cout, SoPhuc& p);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong so phuc
    SoPhuc p1, p2, tong;

    //Nhap 2 so phuc
    cout << "Nhap vao so phuc p1:\n";
    cin >> p1; //Uoc gi co the cin>>p1;
    cout << "Nhap vao so phuc p2:\n";
    cin >> p2;

    //Tinh tong 2 so phuc
    tong = p1 + p2; //Uoc gi p1 + p2

    //Dua cac so phuc ra man hinh
    cout << "\nSo phuc p1 = " << p1;
    cout << "\nSo phuc p2 = " << p2;
    cout << "\nSo phuc p1 + p2 = " << tong;

    cout << endl;
    return 0;
}
//===dinh nghia ham===
SoPhuc SoPhuc::operator+(SoPhuc& p2)
{
    SoPhuc tg;

    tg.a = a + p2.a;
    tg.b = b + p2.b;

    return tg;
}

//Ham ban, ham thuong thuong
istream& operator>>(istream& cin, SoPhuc& p)
{
    cout << "Nhap vao phan thuc: "; cin >> p.a;
    cout << "Nhap vao phan ao: "; cin >> p.b;

    return cin;
}

ostream& operator<<(ostream& cout, SoPhuc& p)
{
    if (p.b >= 0) cout << p.a << " + j" << p.b;
    else cout << p.a << " - j" << -p.b;

    return cout;
}
