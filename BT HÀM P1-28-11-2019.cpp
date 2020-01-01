// BT HÀM P1-28-11-2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//1. Nhập mảng
void NhapMang(int a[], int n);
//2.Xuất mảng
void XuatMang(int a[], int n);
//3.Tính tổng các số nguyên tố trong mảng
int TongSNT(int a[], int n);
//4. Kiểm tra xem các số chẵn trong mảng có tăng dần không
void KTratongmang(int a[], int n);
//5. Sắp xếp mảng sao cho các số chẵn tăng dần, số lẻ giảm dần
void sapxepchantangdan(int a[], int n);
void sapxeplegiamdan(int a[], int n);
//6. Xóa phần tử tại vị trí k trong mảng
void xoak(int c[], int &n);
//7. Xóa tất cả các số nguyên tố ra khỏi mảng
void xoanguyento(int d[], int& n);
//8.Xóa tất cả các phần tử trùng nhau
void xoaphantutrungnhau(int e[], int& n);



int main()
{
	int a[100]; int n; int c[100]; int d[100]; int e[100];
	do
	{
		cout << "Moi nhap so phan tu cua mang: "; cin >> n;
		NhapMang(a, n);
		XuatMang(a, n);
		TongSNT(a, n);
		KTratongmang(a, n);
		memcpy(c, a, n * sizeof(int));
		memcpy(d, a, n * sizeof(int));
		memcpy(e, a, n * sizeof(int));
		sapxepchantangdan(a,n);
		sapxeplegiamdan(a, n);
		xoak(c, n);
		xoanguyento(d, n);
		xoaphantutrungnhau(e,n);


	} while (_getch() != 27);
	return 0;
}



//1. Nhập mảng
void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Moi nhap phan tu thu #" << i << ":" << " ";
		cin >> a[i];
	}
}
//2.Xuất mảng
void XuatMang(int a[], int n)
{
	cout << "Mang vua nhap: \n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//3.Tính tổng các số nguyên tố trong mảng
bool CheckSNT(int x)
{
	if (x < 2) return false;
	else if (x > 2)
	{
		if ((x % 2) == 0) return false;
		for (int i = 3; i < x; i += 2)
		{
			if ((x % i) == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int TongSNT(int a[], int n)
{
	int TongSNT = 0;
	cout << "Tong cac so nguyen to trong mang la:= ";
	for (int i = 0; i < n; i++)
	{
		if (CheckSNT(a[i]))
		{
			TongSNT = TongSNT + a[i];
		}
	}
	cout << TongSNT << endl;
	return TongSNT;
}
//4. Kiểm tra xem các số chẵn trong mảng có tăng dần không
void KTratongmang(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((a[j] % 2 == 0) && (a[i] > a[j]))
				{
					dem = dem++;
				}
			}
		}
	}
	if (dem > 0) cout << "Cac so chan trong KHONG mang tang dan \n";
	else cout << "Cac so chan trong mang tang dan \n";
}
//5. Sắp xếp mảng sao cho các số chẵn tăng dần, số lẻ giảm dần
void sapxepchantangdan(int a[], int n)
{
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i] % 2 == 0) && (a[i] > a[j]))
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	cout << "Mang sau khi sap xep cac so chan tang dan la: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void sapxeplegiamdan(int a[], int n)
{
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((a[i] % 2 != 0) && (a[i] < a[j]))
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	cout << "Mang sau khi sap xep cac so le giam dan la: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

//6. Xóa phần tử tại vị trí k trong mảng
void xoak(int c[], int& n)
{

	int k;
	cout << "Moi nhap so K:= "; cin >> k;
	for (int i = k + 1; i < n; i++)
	{
		c[i - 1] = c[i];
	}
	n--;
	cout << "Mang sau khi xoa phan tu tai vi tri k trong mang la: ";
	for (int i = 0; i < n; i++)
		cout << c[i] << " ";
	cout << endl;
}
//7. Xóa tất cả các số nguyên tố ra khỏi mảng
void xoanguyento(int d[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (CheckSNT(d[i]))
		{
			for (int j = i + 1; j < n; j++)
				d[j - 1] = d[j];
			n--;
			i--;
		}
	}
	cout << "Mang sau khi xoa cac so nguyen to ra khoi mang la: ";
	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
	cout << endl;
}
void xoaphantu(int e[], int &n, int k)                                     //k là vị trí bất kì cần xóa 
{
	for (int i = k + 1; i < n; i++)
		e[i - 1] = e[i];
	n--;
}             
//8.Xóa tất cả các phần tử trùng nhau
void xoaphantutrungnhau(int e[], int &n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (e[j] == e[i])
			{
				xoaphantu(e, n, j);
				i--;
			}
		}
	}
	cout << "Mang sau khi xoa cac phan tu trung nhau la: ";
	for (int i = 0; i < n; i++)
		cout << e[i] << " ";
	cout << endl;
}