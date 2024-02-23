/*
Tính tổng 2 số phức. Yêu cầu:
1)Sử dụng toán tử cộng + để cộng 2 số phức
2)Sử dụng toán tử nhập >> để nhập vào số phức
3)Sử dụng toán tử xuất << để đưa ra số phức
4)Viết hàm tạo không đối số tự động khởi tạo phần thực và ảo bằng 0;
5)Viết hàm tạo 1 đối số để khởi tạo phần thực bằng đối số và phần ảo bằng 0;
6)Viết hàm tạo 2 đối số để khởi tạo phần thực và phần ảo bằng đối số;
7)Viết hàm tạo sao chép;
8)Viết hàm hủy
Trong thân các hàm tạo, hàm hủy đều có lệnh cout để đưa ra thông báo hàm nào đã thực hiện.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong so phuc
class SoPhuc
{
private:
    float a, b;

public:
    SoPhuc(); //Ham tao khong doi so
    SoPhuc(float a); //Ham tao 1 doi so
    SoPhuc(float a, float b); //Ham tao 2 doi so
    SoPhuc(SoPhuc& p); //Ham tao sao chep
    ~SoPhuc(); //Ham huy

    SoPhuc operator+(SoPhuc p2);

    //Ham ban
    friend istream& operator>>(istream& cin, SoPhuc& p);
    friend ostream& operator<<(ostream& cout, SoPhuc& p);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong so phuc
    SoPhuc p1(2), p2(3, 7), tong;

    //Nhap 2 so phuc
    cout << "\nNhap vao so phuc p1:\n";
    cin >> p1;//Uoc gi co the cin>>p1;
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
SoPhuc::SoPhuc() :a(0), b(0)
{
    cout << "\nHam tao khong doi so da thuc hien.";
}

SoPhuc::SoPhuc(float a) :a(a), b(0)
{
    cout << "\nHam tao 1 doi so da thuc hien.";
}

SoPhuc::SoPhuc(float a, float b) :a(a), b(b)
{
    cout << "\nHam tao 2 doi so da thuc hien.";
}

SoPhuc::SoPhuc(SoPhuc& p) :a(p.a), b(p.b)
{
    cout << "\nHam tao sao chep da thuc hien.";
}

SoPhuc::~SoPhuc()
{
    cout << "\nHam huy da thuc hien.";
}

SoPhuc SoPhuc::operator+(SoPhuc p2)
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