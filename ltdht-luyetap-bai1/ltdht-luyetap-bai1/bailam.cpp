//Ho ten: Tran Nguyen Minh Hung
//MaSV: 671501
//Lop: K67CNPMC
//De:
/*Xây dựng lớp Person gồm các thông tin: Họ và tên, Ngày sinh, Quê quán. Sau đó, xây dựng lớp dẫn xuất “Kỹ sư” ngoài các thông tin của lớp Person, 
lớp kỹ sư còn có các thông tin về: Ngành học, Năm tốt nghiệp (int) và các phương thức: 
Phương thức nhập: nhập các thông tin của kỹ sư. 
Phương thức xuất: xuất các thông tin lên màn hình. Xây dựng chương trình chính nhập vào một danh sách các kỹ sư. 
In danh sách của các kỹ sư lên màn hình và thông tin của các kỹ sư tốt nghiệp gần đây nhất (năm tốt nghiệp lớn nhất). 
*/
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

//Khai bao lop doi tuong person
class Person
{
    private:
        char hoTen[30];
        char ngaySinh[11];
        char queQuan[30];

    public:
        void nhap();
        void hien();
};

//Khai bao lop doi tuong ky su
class KySu : public Person
{

    private:
        char nganhHoc[30];
        int namTotNghiep;

        //Bien tinh
        static int maxNamTotNghiep;
        static int indexMax;

    public:
        void nhap();
        void hien();
        
        //Ham tinh
        static void findMax();
};

// Khởi tạo giá trị cho thuộc tính tạm thời
int KySu::maxNamTotNghiep = 0;
int KySu::indexMax = -1;

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n;

    //Nhap so ki su
    cout << "Nhap so ki su can nhap: ";
    cin >> n;

    //Tao n doi tuong ky su
    KySu* ks = new KySu[n];

    //Nhap thong tin
    cout << "Nhap vao thong tin ky su:";
    for (int i = 0; i < n; i++)
    {
        printf("\nKy su thu %d la:\n", i + 1);
        ks[i].nhap();
    }

    //Xuat thong tin
    printf("\nThong tin %d ky su vua nhap la:\n", n);
    for (int i = 0; i < n; i++)
    {
        ks[i].hien();
        cout << endl;
    }
  
    KySu::findMax();
    cout << "\nThong tin ky su tot nghiep gan day nhat la:\n";
    ks[KySu::indexMax].hien();

    cout << endl;
    delete[] ks; // Giải phóng bộ nhớ đã cấp phát
    return 0;
}

//===dinh nghia ham===
//Ham thanh vien lop person
void Person::nhap()
{
    cout << "Nhap ho ten: ";
    cin.ignore();
    cin.getline(hoTen, sizeof(hoTen));
    
    cout << "Nhap ngay sinh(dd/mm/yyyy): ";
    cin >> ngaySinh;

    cout << "Nhap que quan: ";
    cin.ignore(); // Clear the newline character left in the buffer
    cin.getline(queQuan, sizeof(queQuan));
}

void Person::hien()
{
    cout << "\n\tHo ten: " << hoTen;
    cout << "\n\tNgay sinh: " << ngaySinh;
    cout << "\n\tQue quan: " << queQuan;
}

//Ham thanh vien lop ky su
void KySu::nhap()
{
    //ke thua lop person
    Person::nhap();

    cout << "Nhap nganh hoc: ";
    cin.ignore();
    cin.get(nganhHoc, sizeof(nganhHoc));
    cout << "Nhap nam tot nghiep: ";
    cin >> namTotNghiep;

    if (namTotNghiep > maxNamTotNghiep)
    {
        maxNamTotNghiep = namTotNghiep;
        indexMax = -1; // Reset chỉ số khi có kỹ sư có năm tốt nghiệp mới lớn nhất
    }
}

void KySu::hien()
{
    //ke thua lop person
    Person::hien();

    cout << "\n\tNganh hoc: " << nganhHoc;
    cout << "\n\tNam tot nghiep: " << namTotNghiep;
}

void KySu::findMax()
{
    for (int i = 0; i < 3; i++)
    {
        if (maxNamTotNghiep == ks[i].namTotNghiep)
        {
            indexMax = i;
            break;
        }
    }
}
