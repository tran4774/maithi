/*
Ngày viết: 29/12/2019
Ngày cập nhật: 29/12/2019
Nội dung: Thực hiện các thao tác sau:
Thao tác 1: Nhập mảng
Thao tác 2: Xuất mảng
Thao tác 3: In mảng được sắp xếp tăng dần của từng hàng
Thao tác 4: In ma trận chuyển vị
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
using namespace std;
void NhapMaTran(int a[][MAX], int& d, int& c)
{

	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			cout << "a[" << i << "][" << j << "]" << ":" << " ";
			cin >> a[i][j];
		}
}

void XuatMaTran(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++) {
			cout.width(5);
			cout << a[i][j];
		}
		cout << endl;
	}

}

//Thao tác 3: In mảng được sắp xếp tăng dần của từng hàng

void Sapxep03(int a[MAX][MAX], int d, int c)
{
	for (int k = 0; k < d; k++)                               //k là biến chạy dùng để so sánh
		for (int i = 0; i < c - 1; i++)
			for (int j = c - 1; j >= i; j--)
				if (a[k][j] < a[k][j - 1])
				{
					int temp = a[k][j];
					a[k][j] = a[k][j - 1];
					a[k][j - 1] = temp;
				}
}
//Thao tác 4: Ma trận chuyển vị

void Matranchuyenvi(int a[MAX][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++) {
			cout.width(5);
			cout << a[j][i];
		}
		cout << endl;
	}

}
int main()
{
	do
	{
		int a[MAX][MAX], d, c;
		cout << "Moi nhap so dong:= "; cin >> d;
		cout << "Moi nhap so cot:= "; cin >> c;
		NhapMaTran(a, d, c);
		cout << "Ma tran A vua nhap\n";
		XuatMaTran(a, d, c);
		cout << "Mang sau khi duoc sap xep tang cua tung hang: \n";
		Sapxep03(a, d, c);
		XuatMaTran(a, d, c);
		cout << "Ma tran chuyen vi: \n";
		Matranchuyenvi(a, d, c);
	} while (_getch() != 27);
	return 0;
}