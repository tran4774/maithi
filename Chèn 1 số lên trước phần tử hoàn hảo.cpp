#include <iostream>
#include <math.h> // sqrt,...
#include <stdlib.h> // random
#include <conio.h> // _getch,...
#include <string.h>  // xử lý chuỗi
#include <time.h> //
using namespace std;
bool kthoanhao(int x);
bool ktngto(int x);
void chenmang(int a[], int& n, int tg, int vt);
void inmang(int a[], int n);
#define MAX 200
int main()
{
	do {
		int a[MAX];
		int n; cout << " Nhap so phan tu cua mang: ";
		cin >> n; cout << endl;
		int x; cout << " Nhap vao so nguyen X: "; cin >> x; cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << " Nhap phan tu thu [" << i << "] "; cin >> a[i]; cout << endl;
		}

		int vt = 0;
		int dem = 0;
		for (int i = 0; i < n; i++)
			if (kthoanhao(a[i]))
			{
				vt = i; dem = 1;
				break;
			}
		if (dem == 1)
		{
			chenmang(a, n, x, vt);
			inmang(a, n);
		}
		if (dem == 0)
		{
			n++; a[n - 1] = x;
			inmang(a, n);
		}


		cout << "Nhan phim ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}
bool kthoanhao(int x)
{
	int tong = 0;
	for (int i = 1; i < x; i++)
		if (x % i == 0) tong += i;
	if (tong == x) return true;
	else return false;
}
void chenmang(int a[], int& n, int tg, int vt)
{
	for (int i = n; i >= vt; i--)
		a[i] = a[i - 1];
	a[vt] = tg;
	n++;
}
void inmang(int a[], int n)
{
	cout << " Mang vua nhap la: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";

}