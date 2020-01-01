// BT HÀM P1-28-11-2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//.1 Nhập mảng
void NhapMang(int a[], int n);
//.2 Xuất mảng
void XuatMang(int a[], int n);
//.3 Tính tổng các số nguyên tố trong mảng
int TongSNT(int a[], int n);
//.4 Kiểm tra xem các số chẵn trong mảng có tăng dần không
void KTratongmang(int a[], int n);
//.5 Sắp xếp mảng sao cho các số chẵn về đầu mảng, các số lẻ ở cuối mảng
void Sapxepchanle(int a[], int n);
//.6 Sắp xếp mảng sao cho các số chẵn tăng dần, số lẻ giảm dần
void sapxepchantangdan(int a[], int n);
void sapxeplegiamdan(int a[], int n);
//.7 Xóa phần tử đầu tiên bằng x trong mảng 
void Xoapt(int a[], int& n)
//.8 Xóa phần tử tại vị trí k trong mảng
void xoak(int c[], int &n);
//.9 Xóa tất cả các số nguyên tố ra khỏi mảng
void xoanguyento(int d[], int& n);
//.10 Xóa tất cả các phần tử trùng nhau
void xoaphantutrungnhau(int e[], int& n);
//.11 Hàm xóa tất cả các phần tử có giá trị thuộc đoạn [x,y] cho trước. Hàm trả về số phần tử bị xóa
int xoadoan(int a[], int& n, int x, int y);
//.12 Hàm chèn 1 số nguyên x vào vị trí k trong mảng k cho trước (0<=k<=n)
void chen1sok(int a[], int n);
//.13 Hàm chèn giá trị x vào mảng tăng dần, sao cho mảng có kết quả vẫn có thứ tự tăng
void chenx(int a[], int& n, int x);
//.14 Hàm tách mảng a thành 2 mảng con mc và ml. Mảng mc chứa số chẵn, mảng ml chứa số lẻ
void tach(int a[], int n);
//.15 Hàm trộn 2 mảng a, b có thứ tự tăng thành mảng c cũng có thứ tự tăng
void Tron(int a[], int n, int b[], int m);
//.16 Hàm kiểm tra giá trị có trùng hay không, nếu có thì nhập lại đến khi nào không trùng nữa mới thôi
bool kiemtra(int a[], int n, int gtri);
void nhap(int a[], int& n);



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
//5. Sắp xếp mảng sao cho các số chẵn về đầu mảng, các số lẻ ở cuối mảng
void Sapxepchanle(int a[], int n)
{
		for (int i = 0; i < n - 1; i++)		//bước i: so sánh vị trí i với các vị trí sau nó
			for (int j = i + 1; j < n; j++)	//j là những vị trí sau i
				if (a[i] % 2 != 0 && a[j] % 2 == 0) //nếu có nghịch thế  3 6 8 5 4 7
				{
					int t = a[i];	//thì đổi chỗ
					a[i] = a[j];
					a[j] = t;
				}
}
//6. Sắp xếp mảng sao cho các số chẵn tăng dần, số lẻ giảm dần
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
//.7 Xóa phần tử đầu tiên bằng x trong mảng 
void Xoapt(int a[], int& n)
{
	int x;
	cout << "\nNhap 1 so nguyen: "; cin >> x;		//số cần xóa
	int k = 0;
	while (k < n && a[k] != x) k++;
	if (k < n)
	{
		for (int i = k + 1; i < n; i++)		//dồn các vị trí sau k lên 1
			a[i - 1] = a[i];
		n--;
	}
}	
//8. Xóa phần tử tại vị trí k trong mảng
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
//9. Xóa tất cả các số nguyên tố ra khỏi mảng
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
//10.Xóa tất cả các phần tử trùng nhau
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
//11. Hàm xóa tất cả các phần tử có giá trị thuộc đoạn [x,y] cho trước. Hàm trả về số phần tử bị xóa
int xoadoan(int a[], int& n, int x, int y)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x && a[i] <= y)
		{
			Xoa(a, n, i);
			i--;
			dem++;
		}
	}
	return dem;
}
//12. Hàm chèn 1 số nguyên x vào vị trí k trong mảng k cho trước (0<=k<=n)
void chen1sok(int a[], int n)
{
	int k, x;
	cout << "nhap vi tri can chen k:";
		cin >> k;
		cout << " nhap so can chen:"; cin >> x;
	int i;
	for (i = n; i > k; i--) {
		a[i] = a[i - 1];
	}
	a[k] = x;
}
//13. Hàm chèn giá trị x vào mảng tăng dần, sao cho mảng có kết quả vẫn có thứ tự tăng
void chenx(int a[], int& n, int x)
{
	int i = 0;
	int j;
	while (i < n && !(x > a[i] && x < a[i + 1]))	// 2 4 6 8 
		i++;										// 2 4 6 6 8
	if (i < n)
	{
		n++;
		for (j = n; j > i; j--)
			a[j] = a[j - 1];
		a[j + 1] = x;
	}
}
//14. Hàm tách mảng a thành 2 mảng con mc và ml. Mảng mc chứa số chẵn, mảng ml chứa số lẻ
void tach(int a[], int n)
{
	int i, c = 0, l = 0;
	int mc[100], ml[100];
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) 
		{
			mc[c] = a[i];
			c++;
		}
		else 
		{
			ml[l] = a[i];
			l++;
		}
	}
}
//15. Hàm trộn 2 mảng a, b có thứ tự tăng thành mảng c cũng có thứ tự tăng
void Tron(int a[], int n, int b[], int m)
{
	int c[100], k = 0;
	for (int i = 0; i < n; i++)
	{
		c[k] = a[i];
		k++;
	}
	for (int i = 0; i < m; i++)
	{
		c[k] = b[i];
		k++;
	}
}
//16. Hàm kiểm tra giá trị có trùng hay không, nếu có thì nhập lại đến khi nào không trùng nữa mới thôi
bool kiemtra(int a[], int n, int gtri)
{
	int i;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == gtri)
		{
			return true;
		}
	}
	return false;
}
void nhap(int a[], int& n)
{
	cout << "Nhap so luong phan tu:  ";
	cin >> n;
	int gtri1, i = 0;
	for (i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu #" << i << " : ";		//0 1 2 3 4
		cin >> gtri1;
	}
		if (kiemtra(a, i, gtri1) == true)
		{
				cout << "Gia tri bi trung vui long nhap lai" << endl;
				i--;
		}
		else
		{
				a[i] = gtri1;
		}
}
