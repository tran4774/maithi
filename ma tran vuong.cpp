// ma tran vuong.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
1. Tác giả: Nguyễn Hoàng Vũ
2. Ngày viết: 21/12/2019
3. Ngày cập nhật:
*/

#include <iostream>				//một số thư viện thường dùng
#include <conio.h>				//_getch...
#include <math.h>				//sqrt,...
#include <time.h>
#include <stdlib.h>				//random,...
#include <string.h>				//xử lý chuỗi
using namespace std;
#define SIZE 20

void nhapmatran(int a[][SIZE], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Nhap phan tu [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void inmatran(int a[][SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}

bool ktmatrandonvi(int a[][SIZE], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				if (a[i][j] != 1) return false;
			}
			else
			{
				if (a[i][j] != 0) return false;
			}
		}

	return true;
}

bool ktmatrantamgiactren(int a[][SIZE], int n)
{
	int dem = 0;
	int check = 0;

//	for (int i = 0; i < n; i++)
//		check += i;
	
	for (int i = 1; i < n-1; i++)
		for (int j = i-1; j <= i; j++)
			if (a[i][j] != 0) return false;
		
//	if (dem == check) 
	return true;
//	else return false;
}

bool ktmatrantamgiacduoi(int a[][SIZE], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j][i] != 0) return false;
	
	return true;
}

bool ktmatrandoixung(int a[][SIZE], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] != a[j][i]) return false;

	return true;
}

int timmaxcheochinh(int a[][SIZE], int n)
{
	int max = a[0][0];
	for (int i = 0; i < n; i++)
		if (a[i][i] > max) max = a[i][i];
	return max;
}

int timmincheochinh(int a[][SIZE], int n)
{
	int min = a[0][0];
	for (int i = 0; i < n; i++)
		if (a[i][i] < min) min = a[i][i];
	return min;
}

int timmaxcheophu(int a[][SIZE], int n)
{
	int max = a[0][n - 1];
	for (int i = 0; i < n; i++)
		if (a[i][n - 1 - i] > max) max = a[i][n - 1 - i];
	return max;
}

int timmincheophu(int a[][SIZE], int n)
{
	int min = a[n - 1][n - 1];
	for (int i = 0; i < n; i++)
		if (a[i][n - 1 - i] < min) min = a[i][n - 1 - i];
	return min;
}

void nhanmatran(int a[][SIZE], int b[][SIZE], int x[][SIZE], int n, int k)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			x[i][j] = a[i][j];

	for (int stt = 1; stt < k; stt++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				b[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int c = 0; c < n; c++) 
					b[i][j] += a[i][c] * x[c][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				x[i][j] = b[i][j];
	}

	cout << "Ma tran M^" << k << ":\n";
	inmatran(x, n);
}

void taomatranxoanoc(int a[][SIZE], int n)
{
	int d = 0;
	int gt = 1;
	int hang = n - 1;
	int cot = n - 1;
	int i;
	while (d <= n / 2)
	{
		for (i = d; i <= cot; i++) a[d][i] = gt++;
		for (i = d + 1; i <= hang; i++) a[i][cot] = gt++;
		for (i = cot - 1; i >= d; i--) a[hang][i] = gt++;
		for (i = hang - 1; i > d; i--) a[i][d] = gt++;
		d++; hang--; cot--;
	}

	cout << "Ma tran xoan oc:\n";
	inmatran(a, n);
}




int main()
{
	int m[SIZE][SIZE];
	int n;

	do
	{
		cout << "Nhap cap cua ma tran vuong = "; cin >> n;
		/*nhapmatran(m, n);
		cout << "Ma tran vuong cap " << n << " vua nhap la:\n";
		inmatran(m, n);*/
		/*
		// ktra ma trận đơn vị
		if (ktmatrandonvi(m, n)) cout << "Day la ma tran don vi\n";
		else cout << "Day ko phai la ma tran don vi\n";

		// ktra ma trận tam giác trên/ dưới
		if (ktmatrantamgiactren(m, n)) cout << "Day la ma tran tam giac tren\n";
		else cout << "Day ko phai la ma tran tam giac tren\n";
		if (ktmatrantamgiacduoi(m, n)) cout << "Day la ma tran tam giac duoi\n";
		else cout << "Day ko phai la ma tran tam giac duoi\n";

		// ktra ma trận đối xứng
		if (ktmatrandoixung(m, n)) cout << "Day la ma tran doi xung\n";
		else cout << "Day ko phai la ma tran doi xung\n";

		// tìm max/min đường chéo chính chéo phụ
		cout << "Max duong cheo chinh = " << timmaxcheochinh(m, n) << endl;
		cout << "Min duong cheo chinh = " << timmincheochinh(m, n) << endl;
		cout << "Max duong cheo phu = " << timmaxcheophu(m, n) << endl;
		cout << "Min duong cheo phu = " << timmincheophu(m, n) << endl;

		// tính M^k
		int b[SIZE][SIZE];
		int x[SIZE][SIZE];
		int k;
		cout << "Nhap so mu cua ma tran = "; cin >> k;
		nhanmatran(m, b, x, n, k);*/

		// tạo ma trận xoắn ốc cấp n
		int a[SIZE][SIZE];
		taomatranxoanoc(a, n);

		// tìm ma trận nghịch đảo M^(-1)



		cout << "Nhan ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

