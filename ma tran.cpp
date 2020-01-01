// on tap chieu t5.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
1. Tác giả: Nguyễn Hoàng Vũ
2. Ngày viết: 12/12/2019
3. Ngày cập nhật:



*/

#include <iostream>				//một số thư viện thường dùng
#include <conio.h>				//_getch...
#include <math.h>				//sqrt,...
#include <time.h>
#include <stdlib.h>				//random,...
#include <string.h>				//xử lý chuỗi
using namespace std;
#define MAX 20

void NhapMaTran(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap phan tu a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
}

void InMaTran(int a[][MAX], int d, int c)
{
	cout << "Ma tran da nhap la:\n";
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}
int tinhtongcotle(int a[][MAX], int d, int c)
{
	int dem = 0;
	for (int i = 0; i < d; i++)
		if (a[i][c] % 2 != 0) dem += a[i][c];
	return dem;
}
void tinhmaxcotle(int a[][MAX], int d, int c)
{
	int max = tinhtongcotle(a, d, 0);
	for (int j = 1; j < c; j++)
		if (tinhtongcotle(a, d, j) > max) max = tinhtongcotle(a, d, j);
	cout << max << endl;
}



int main()
{
	int M[MAX][MAX];
	int d, c;

	do
	{
		cout << "Nhap so dong cua ma tran (0<d): "; cin >> d;
		cout << "Nhap so cot cua ma tran (c<100): "; cin >> c;
		NhapMaTran(M, d, c);
		InMaTran(M, d, c);
		tinhmaxcotle(M, d, c);












		cout << "Nhan ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

