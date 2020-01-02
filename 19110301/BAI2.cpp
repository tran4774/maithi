/*
Bài thi NMLT 2019 (final)
Câu 2
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

using namespace std;

void nhapmang(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu #" << i << ": ";
		do {
			cin >> a[i];
			if (a[i] <= -100 || a[i] >= 100)
				cout << "So khong hop le, moi nhap lai phan tu #" << i <<": ";
		} while (a[i] <= -100 || a[i] >= 100);
		
	}
}

//2. Hàm in mảng 1D
void inmang(double a[], int n)
{
	cout << "Mang vua nhap la:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//3. Hàm đếm số phần tử bất thường
int batthuong(double a[], int n, int k) {
	int i;
	int dem = 0;
	for (i = 1; i < n-1; i++) {
		if (((a[i] - a[i - 1] >= k) && (a[i] - a[i + 1] >= k)) 
		 || ((a[i - 1] - a[i] >= k) && (a[i + 1] - a[i] >= k)))
			dem++;
	}
	return dem;
}

int main()
{
	// Khai bao bien
	double arr[100];
	int n, k;
	do {

		//Tat ca cac lenh dat o day
		cout << "Nhap so phan tu cua mang 1 chieu: ";
		do {
			cin >> n;
			if (n < 0)
				cout << "So phan tu khong duoc nho hon 0, moi ban nhap lai so phan tu: ";
		} while (n < 0);
		cout << "Nhap so k: ";
		cin >> k;

		nhapmang(arr, n);
		inmang(arr, n);

		cout << "So phan tu bat thuong trong mang la: " << batthuong(arr, n, k) << endl;
		cout << "Nhan phim ESC de thoat" << endl;
	} while (_getch() != 27);
	return 0;
}