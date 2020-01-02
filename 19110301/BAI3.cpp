/*
Bài thi NMLT 2019 (final)
Câu 3
Người viết : Nguyễn Bảo Trấn
MSSV: 19110301
Ngày viết : 02/01/2020 : AM
*/

//Ko xoa
#include <iostream> // Một số thư viện thường dùng
#include <conio.h> //_getch,...
#include <stdlib.h>
#include <math.h> //sqrt,...
#include <time.h> 
#include <string.h> // Xử lí chuỗi
#include <iomanip>

using namespace std;
#define SOA 105			//Size of Array
//1. Hàm nhập mảng 2 chiều (ma trận)
void nhapmang2d(int a[][SOA], int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap phan tu [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}
//2. Hàm xuất mảng 2 chiều (ma trận)
void inmang2d(int a[][SOA], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout.width(7);
			cout << a[i][j];
		}
		cout << endl;
	}
}
//3. Hàm tính tổng cột
int tinhtongcot(int a[][SOA], int d, int c)
{
	int tong= 0;
	for (int i = 0; i < d; i++)
		tong += a[i][c];
	return tong;
}
//4. Hàm đếm số lượng cột có tổng thuộc [A;B]
int demsocot(int a[][SOA], int d, int c, int A, int B) {
	int i, dem = 0;
	for (i = 0; i < d; i++) {
		int tam = tinhtongcot(a, d, i);
		if (tam >= A && tam <= B)
			dem++;
	}
	return dem;
}
int main()
{
	// Khai bao bien
	int arr2d[105][105], d, c;
	int A, B;
	do {

		//Tat ca cac lenh dat o day
		cout << "Nhap so hang cua ma tran: ";
		do {
			cin >> d;
			if (d <= 0 || d >= 100)
				cout << "So hang phai lon hon 0, moi ban nhap lai: ";
		} while (d <= 0 || d >=100);

		cout << "Nhap so cot cua ma tran: ";
		do {
			cin >> c;
			if (c <= 0 || c >= 100)
				cout << "So cot phai lon hon 0, moi ban nhap lai: ";
		} while (c <= 0 || c >= 100);

		cout << "Nhap A: ";
		cin >> A;
		cout << "Nhap B: ";
		cin >> B;

		nhapmang2d(arr2d, d, c);
		cout << "\nMang 2 chieu vua nhap: " << endl;
		inmang2d(arr2d, d, c);
		cout << "So cot co tong nam trong doan [" << A << ";" << B << "] la: " << demsocot(arr2d, d, c, A, B) << endl;

		cout << "Nhan phim ESC de thoat" << endl;
	} while (_getch() != 27);
	return 0;
}
