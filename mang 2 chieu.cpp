// mang 2 chieu.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
1. Tác giả: Nguyễn Hoàng Vũ
2. Ngày viết: 19/12/2019
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

void nhapmatran(int a[][SIZE], int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap phan tu [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void inmatran(int a[][SIZE], int d, int c)
{
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

int tongle(int a[][SIZE], int d, int c)
{
	int tong = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] % 2 != 0) tong += a[i][j];
	return tong;
}

void timmax(int a[][SIZE], int d, int c)
{
	int max = a[0][0];
	int vt1 = 0;
	int vt2 = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] > max)
			{
				max = a[i][j];
				vt1 = i;
				vt2 = j;
			}
	cout << "MAX = " << max << " vi tri dong " << vt1 + 1 << " cot " << vt2 + 1 << endl;
}

void timmin(int a[][SIZE], int d, int c)
{
	int min = a[0][0];
	int vt1 = 0;
	int vt2 = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			if (a[i][j] < min)
			{
				min = a[i][j];
				vt1 = i;
				vt2 = j;
			}
	cout << "MIN = " << min << " vi tri dong " << vt1 + 1 << " cot " << vt2 + 1 << endl;
}

int maxchan(int a[][SIZE], int m, int n)
{
	int i, j, max;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			max = 0;
			if (a[i][j] % 2 == 0)
			{

				max = a[i][j];

				for (i = 0; i < m; i++)
					for (j = 0; j < n; j++)
						if (a[i][j] % 2 == 0 && a[i][j] > max)
							max = a[i][j];
			}

		}

	if (max == 0) return -1; //ko co so chan trong mang

	return max;
}

int minle(int a[][SIZE], int m, int n)
{
	int i, j, min;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			min = 0;
			if (a[i][j] % 2 != 0)
			{

				min = a[i][j];

				for (i = 0; i < m; i++)
					for (j = 0; j < n; j++)
						if (a[i][j] % 2 != 0 && a[i][j] < min)
							min = a[i][j];
			}
		}

	if (min == 0) return -1; //ko co so le trong mang

	return min;
}

int tongdong(int a[][SIZE], int c, int k)
{
	int tong = 0;
	for (int j = 0; j < c; j++)
		tong += a[k - 1][j];

	return tong;
}

int tongcot(int a[][SIZE], int d, int k)
{
	int tong = 0;
	for (int i = 0; i < d; i++)
		tong += a[i][k - 1];

	return tong;
}

int timdongcotonglonnhat(int a[][SIZE], int d, int c)
{
	int max = tongdong(a, c, 1);
	int vtmax = 1;

	for (int i = d; i > 0; i--)
		for (int j = c; j > 0; j--)
			if (tongdong(a, j, i) > max)
			{
				max = tongdong(a, j, i);
				vtmax = i;
			}

	return vtmax;
}

int timcotcotonglonnhat(int a[][SIZE], int d, int c)
{
	int max = tongcot(a, 1, d);
	int vtmax = 1;

	for (int i = d; i > 0; i--)
		for (int j = c; j > 0; j--)
			if (tongcot(a, i, j) > max)
			{
				max = tongcot(a, i, j);
				vtmax = i;
			}

	return vtmax;
}

void sxdongtangdan(int a[][SIZE], int d, int c, int k)
{
	for (int j = 0; j < c; j++)
		for (int p = j + 1; p < c; p++)
			if (a[k - 1][j] > a[k - 1][p])
			{
				int t = a[k - 1][j];
				a[k - 1][j] = a[k - 1][p];
				a[k - 1][p] = t;
			}
	cout << "Ma tran sau khi sx dong #" << k << " tang dan la:\n";
	inmatran(a, d, c);
}

void sxcottangdan(int a[][SIZE], int d, int c, int k)
{
	for (int i = 0; i < d; i++)
		for (int p = i + 1; p < d; p++)
			if (a[i][k - 1] > a[p][k - 1])
			{
				int t = a[i][k - 1];
				a[i][k - 1] = a[p][k - 1];
				a[p][k - 1] = t;
			}
	cout << "Ma tran sau khi sx cot #" << k << " tang dan la:\n";
	inmatran(a, d, c);
}

void sxmttang(int a[][SIZE], int d, int c)     // bài này sai r nha :v
{
	int i, j;
	for (i = 0; i < d; i++)
		for (j = 0; j < c; j++)
			for (int p = j + 1; p < c; p++)
				if (a[i][j] > a[i][p])
				{
					int t = a[i][j];
					a[i][j] = a[i][p];
					a[i][p] = t;
				}

	for (i = 0; i < d; i++)
		for (j = 0; j < c; j++)
			for (int p = i + 1; p < d; p++)
				if (a[i][j] > a[p][j])
				{
					int t = a[i][j];
					a[i][j] = a[p][j];
					a[p][j] = t;
				}


	cout << "Ma tran sau khi sap xep tang dan\n";
	inmatran(a, d, c);

}
//. sắp xếp ma trận tăng dần từ trái sang phải từ trên xuống dưới
void sapxepmt(int a[][MAX], int d, int c)
{
	int t;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			for (int k = j + 1; k < c; k++)
			if (a[i][j] > a[i][k]) {		
				t = a[i][j];
				a[i][j]= a[i][k];
				a[i][k] = t;
			}
	for (int j = 0; j < c; j++)
		for (int i = 0; i < d; i++)
			for (int k = i + 1; k < d; k++)
			if (a[i][j] > a[k][j]) {
				t = a[i][j];
				a[i][j] = a[k][j];
				a[k][j] = t;
			}
}
void cong2matran(int a[][SIZE], int b[][SIZE], int x[][SIZE], int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];


	cout << "Tong cua 2 ma tran ban vua nhap:\n";
	inmatran(x, d, c);
}

void nhan2matran(int a[][SIZE], int b[][SIZE], int x[][SIZE], int d, int c, int k)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < k; j++)
		{
			x[i][j] = 0;
			for (int y = 0; y < c; y++)
				x[i][j] += a[i][y] * b[y][j];

		}

	cout << "Tich cua 2 ma tran tren = \n";
	inmatran(x, c, k);
}

void matranchuyenvi(int a[][SIZE], int d, int c)
{
	
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cout.width(5);
			cout << a[j][i];
		}
		cout << endl;
	}
}

int tinhtongcacptubien(int a[][SIZE], int d, int c)
{
	int s = 0;
	for (int i = 0; i < d; i++)
	{
		s += a[i][0] + a[i][c - 1];
	}
	for (int j = 1; j < c - 1; j++)
	{
		s += a[0][j] + a[d - 1][j];
	}

	return s;
}
//. kiểm tra ma trận đơn vị
bool check(int a[][MAX], int d, int c)
{
	int dem = 1;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			if ((i != j && a[i][j] != 0) || (i == j && a[i][j] != 1))
			{
				dem = 0;
				i = d;
				break;
			}
		}
	}
	if (dem == 0)
		return false;
	return true;
}
//. Kiểm tra ma trận có phải tam giác trên không
bool ktratgtren(int a[][MAX], int d, int c)
{
	int check = 1;
	for (int i = 0; i < d; i++) 
		for (int j = 0; j < c; j++) 
			if (i > j && a[i][j] != 0)
			{
				check = 0;
				i = d;
				break;
			}
	if (check == 0)
		return false;
	return true;
}
//. Kiểm tra ma trận đối xứng
bool ktradoixung(int a[][MAX])
{
	int n;
	cout << "Nhap cap ma tran: ";
	cin >> n;
	Nhap(a, n, n);
	int b[MAX][MAX];
	int check = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[j][i] = a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (b[i][j] != b[j][i])
			{
				check = 0;
				i = n;
				break;
			}
	if (check == 0)
		return false;
	return true;
}
int main()
{
	int m[SIZE][SIZE];
	int d, c;
	int k1, k2;
	int k3, k4;

	do
	{
		cout << "Nhap so dong cua ma tran = "; cin >> d;
		cout << "Nhap so cot cua ma tran = "; cin >> c;
		nhapmatran(m, d, c);
		cout << "Ma tran da nhap la:\n";
		inmatran(m, d, c);

		/*
		// tính tổng các số lẻ của ma trận:
		cout << "Tong cac so le cua ma tran = " << tongle(m, d, c) << endl;

		// tìm max/ min và vị trí của nó:
		timmax(m, d, c);
		timmin(m, d, c);

		// tìm max chẵn/ min lẻ và vị trí của nó (nếu có):
		cout << "Max chan = " << maxchan(m, d, c) << endl;
		cout << "Min le = " << minle(m, d, c) << endl;

		// tính tổng dòng/cột thứ k của ma trận:
		cout << "Nhap dong thu k ban muon tinh tong = "; cin >> k1;
		cout << "Tong dong thu " << k1 << " = " << tongdong(m, c, k1) << endl;
		cout << "Nhap cot thu k ban muon tinh tong = "; cin >> k2;
		cout << "Tong cot thu " << k2 << " = " << tongcot(m, d, k2) << endl;

		// tìm dòng/ cột có tổng lớn nhất:
		cout << "Dong co tong lon nhat la dong #" << timdongcotonglonnhat(m, d, c) << endl;
		cout << "Cot co tong lon nhat la cot #" << timcotcotonglonnhat(m, d, c) << endl;

		//sắp xếp dòng/ cột thứ k tăng dần:
		cout << "Nhap dong thu k ban muon sap xep tang dan: "; cin >> k3;
		sxdongtangdan(m, d, c, k3);
		cout << "Nhap cot thu k ban muon sap xep tang dan: "; cin >> k4;
		sxcottangdan(m, d, c, k4);

		// sắp xếp ma trận tăng từ trái qua phải từ trên xuống dưới:
		sxmttang(m, d, c);

		// cộng 2 ma trận
		{
			int n[SIZE][SIZE];
			int p[SIZE][SIZE];
			cout << "Nhap ma tran thu 2:\n";
			nhapmatran(n, d, c);
			cout << "Ma tran thu 2 vua nhap la:\n";
			inmatran(n, d, c);
			cong2matran(m, n, p, d, c);
		}
		
		// nhân 2 ma trận
		{
			int n[SIZE][SIZE];
			int p[SIZE][SIZE];
			int k;
			cout << "So dong cua ma tran thu 2 luon luon = so cot cua ma tran dau = " << d << endl;
			cout << "Nhap so cot cua ma tran thu 2 = "; cin >> k;
			cout << "Nhap ma tran thu 2:\n";
			nhapmatran(n, c, k);
			cout << "Ma tran thu 2 vua nhap la:\n";
			inmatran(n, c, k);
			nhan2matran(m, n, p, d, c, k);
		}
		*/
		// tạo ma trận chuyển vị
		cout << "Ma tran chuyen vi:\n";
		matranchuyenvi(m, d, c);

		// tính tổng các phần tử nằm trên 4 biên của ma trận
		//cout << "Tong cac phan nam tren 4 bien = " << tinhtongcacptubien(m, d, c) << endl;
		






		cout << "Nhan ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}



