// mang 1 chieu.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
1. Tác giả: Nguyễn Hoàng Vũ
2. Ngày viết: 13/12/2019
3. Ngày cập nhật:
*/

#include <iostream>				//một số thư viện thường dùng
#include <conio.h>				//_getch...
#include <math.h>				//sqrt,...
#include <time.h>
#include <stdlib.h>				//random,...
#include <string.h>				//xử lý chuỗi
using namespace std;

void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu #" << i << ": ";
		cin >> a[i];
	}
}

void inmang(int a[], int n)
{
	cout << "Mang vua nhap la:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void incacsochan(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) cout << a[i] << " ";
	cout << endl;
}

void tongptu(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++) tong += a[i];
	cout << "Tong cac phan tu cua mang = " << tong << endl;
}

bool ktsochinhphuong(int x)
{
	if (sqrt(x) == int(sqrt(x))) return true;
	return false;
}

void tongcp(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		if (ktsochinhphuong(a[i])) tong += a[i];
	cout << "Tong cac so chinh phuong trong mang = " << tong << endl;
}

bool ktnguyento(int x)
{
	if (x < 2) return false;
	else if (x > 2)
	{
		if (x % 2 == 0) return false;
		else
		{
			for (int i = 3; i < x; i++)
				if (x % i == 0) return false;
		}
	}
	return true;
}

void tongnguyento(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		if (ktnguyento(a[i])) tong += a[i];
	cout << "Tong cac so nguyen to trong mang = " << tong << endl;
}

void demsoam(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0) dem++;
	cout << "So luong so am co trong mang = " << dem << endl;
}

void timmax(int a[], int n)
{
	int vt = 0;
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
		{
			max = a[i];
			vt = i;
		}
	cout << "MAX = " << max << " va nam o vi tri #" << vt << endl;
}

void timmin(int a[], int n)
{
	int vt = 0;
	int min = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < min)
		{
			min = a[i];
			vt = i;
		}
	cout << "MIN = " << min << " va nam o vi tri #" << vt << endl;
}

void maxchan(int a[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			max = a[i];
			for (int j = 0; j < n; j++)
				if (a[j] > max&& a[j] % 2 == 0) max = a[j];
		}
	}
	if (max == 0) cout << "Mang ko co so chan\n";
	else cout << "Max chan = " << max << endl;
}

void mincp(int a[], int n)
{
	int min = 0;
	for (int i = 0; i < n; i++)
		if (ktsochinhphuong(a[i]))
		{
			min = a[i];
			for (int j = 0; j < n; j++)
				if (ktsochinhphuong(a[j]) && a[j] < min) min = a[j];
		}
	if (min == 0) cout << "Mang ko co so chinh phuong\n";
	cout << "Min so chinh phuong = " << min << endl;
}

int tongchuso(int x)
{
	int dem = 0;
	while (x > 0)
	{
		int t = x % 10;
		dem += t;
		x = x / 10;
	}
	return dem;
}

void tongchusomax(int a[], int n)
{
	int vt = 0;
	int max = tongchuso(a[0]);
	for (int i = 0; i < n; i++)
		if (tongchuso(a[i] > max))
		{
			max = tongchuso(a[i]);
			vt = i;
		}
	cout << "So co tong cac chu so lon nhat la: " << max << " va o vi tri #" << vt << endl;
}

bool ktmangtangdan(int a[], int n)
{

	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1]) return false;
	return true;
}

bool ktmanggiamdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] < a[i + 1]) return false;
	return true;
}

bool ktmangdoixung(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
		if (a[i] != a[n - 1 - i]) return false;
	return true;
}

bool ktchantangdan(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 == 0 && a[j] < a[i]) return false;
	return true;
}

bool ktchanlexenke(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 == 0 && a[i + 1] % 2 == 0 || a[i] % 2 != 0 && a[i + 1] % 2 != 0)
			return false;
	return true;
}

bool ktamduongxenke(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == 0) return false;
		else if (a[i] > 0 && a[i + 1] > 0 || a[i] < 0 && a[i + 1] < 0) return false;
	}
	return true;
}

bool ktcapsocong(int a[], int n)
{
	for (int i = 0; i < n - 2; i++)
		if (a[i + 1] - a[i] != a[i + 2] - a[i + 1]) return false;
	return true;
}

void sxmangtangdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	cout << "Mang sau khi sap xep tang dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void sxmanggiamdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	cout << "Mang sau khi sap xep giam dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void sxchantanglegiam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 == 0)
			for (int j = i + 1; j < n; j++)
				if (a[i] > a[j] && a[j] % 2 == 0)
				{
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 != 0)
			for (int j = i + 1; j < n; j++)
				if (a[i] < a[j] && a[j] % 2 != 0)
				{
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}

	cout << "Mang sau khi sap xep chan tang dan, le giam dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void sxchandautanglesaugiam(int a[], int n)
{
	int k, min, j, t;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
		{
			k = i;
			for (j = 0; j < n; j++)
			{
				t = a[k];
				a[k] = a[j];
				a[j] = t;
			}
			i--;
		}

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			min = i;
			for (j = i + 1; j < n; j++)
				if (a[min] > a[j] && a[j] % 2 == 0) min = j;
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
		else
		{
			min = i;
			for (j = i + 1; j < n; j++)
				if (a[min] < a[j] && a[j] % 2 != 0) min = j;
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
	cout << "Mang chan ve dau mang tang dan va le ve sau mang giam dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void xoapt(int a[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
		a[i - 1] = a[i];
	a[n - 1] = 0;
	n--;
}

void xoapttaivtk(int a[], int n, int k)
{
	for (int i = k + 1; i < n; i++)
		a[i - 1] = a[i];
	n--;
	cout << "Mang sau khi xoa phan tu tai vi tri #" << k << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void xoatatcacacgtx(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			for (int j = i + 1; j < n; j++)
			{
				a[j - 1] = a[j];
			}
			a[n - 1] = 0;
			n--;
		}
	}

	cout << "Mang sau khi xoa cac phan tu = " << x << " khoi mang\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void xoatatcasongto(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ktnguyento(a[i]))
		{
			xoapt(a, n, i);
			i--;
		}
	}

	cout << "Mang sau khi xoa cac so nguyen to\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void xoatatcaccacpttrungnhau(int a[], int& n)
{

	int dem;
	for (int i = 0; i < n - 1; i++)                                                //vòng lặp duyệt từng phần tử của mảng a[i], để n-1 vì phần tử cuối cùng chắc chắn đã phân biệt, không cần kiểm tra
	{
		dem = 0;
		for (int j = i + 1; j < n; j++)                                        //vòng lặp duyệt các phần tử đứng sau a[i]
		{
			if (a[j] == a[i])                                                     //trường hợp có phần tử a[j] trùng với a[i] thì xóa phần tử tại vị trí j
			{
				xoapt(a, n, j);
				j--;
				dem = 1;
			}
		}
		if (dem == 1) xoapt(a, n, i);

	}

	cout << "Mang sau khi xoa cac pt trung nhau\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

}

void xoacacpttrungnhauchualai1pt(int a[], int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				xoapt(a, n, j);
				i--;
			}
		}
	}

	cout << "Mang sau khi xoa cac pt trung nhau chi chua lai 1 pt lam dai dien\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void chengtxvaovtk(int a[], int& n, int x, int k)
{
	for (int i = n; i >= k; i--)
		a[i] = a[i - 1];
	a[k] = x;
	n++;
	cout << "Mang sau khi chen gia tri " << x << " tai vi tri #" << k << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void chengtxvasapxepgiamdan(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < x)
		{
			for (int j = n; j > i; j--)
				a[j] = a[j - 1];
			a[i] = x;
			break;
		}
		else a[n] = x;
	}
	cout << "Mang sau khi chen gia tri " << x << " va sap xep giam dan\n";
	for (int i = 0; i < n + 1; i++)
		cout << a[i] << " ";
	cout << endl;

}

void tachmangchanle(int a[], int n)
{
	int chan[100], le[100];
	int m = 0;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			chan[m] = a[i];
			m++;
		}
		else
		{
			le[p] = a[i];
			p++;
		}
	}
	cout << "Mang chan la: ";
	for (int i = 0; i < m; i++)
		cout << chan[i] << " ";
	cout << endl;
	cout << "Mang le la: ";
	for (int j = 0; j < p; j++)
		cout << le[j] << " ";
	cout << endl;
}

void taomangcp(int a[], int n)
{
	int cp[100];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (ktsochinhphuong(a[i]))
		{
			cp[k] = a[i];
			k++;
		}
	}
	cout << "Mang gom cac so chinh phuong la: ";
	for (int i = 0; i < k; i++)
		cout << cp[i] << " ";
	cout << endl;
}

void gopmang(int a[], int n, int b[], int m, int c[], int& p)
{
	p = n + m;
	for (int i = 0; i < p; i++)
	{
		if (i < n) c[i] = a[i];
		else c[i] = b[i - n];
	}
}




int main()
{
	int a[100];
	int n;
	int k1, x1;
	int k2, x2;
	int x;
	do
	{
		cout << "Nhap so phan tu cua mang (n>0): "; cin >> n;
		nhapmang(a, n);
		inmang(a, n);
		/*

		// in các số chẵn ra màn hình:
		cout << "Cac so chan trong mang la: ";
		incacsochan(a, n);

		// tính tổng các ptử:
		tongptu(a, n);

		// tính tổng các số chính phương (nếu có):
		tongcp(a, n);

		// tính tổng các số nguyên tố có trong mảng (nếu có):
		tongnguyento(a, n);

		// đếm số lượng số âm có trong mảng (nếu có):
		demsoam(a, n);

		// tìm max, min và vị trí của nó:
		timmax(a, n);
		timmin(a, n);

		// tìm số chẵn lớn nhất (nếu có):
		maxchan(a, n);

		// tìm số chính phương nhỏ nhất (nếu có):
		mincp(a, n);

		// tìm số có tổng các chữ số lớn nhất và vị trị của nó:
		tongchusomax(a, n);

		// kiểm tra xem mảng có tăng dần/ giảm dần hay ko:
		if (ktmangtangdan(a, n)) cout << "Mang tang dan\n";
		else cout << "Mang ko tang dan\n";
		if (ktmanggiamdan(a, n)) cout << "Mang giam dan\n";
		else cout << "Mang ko giam dan\n";

		// kiểm tra xem mảng có đối xứng hay ko:
		if (ktmangdoixung(a, n)) cout << "Mang doi xung\n";
		else cout << "Mang ko doi xung\n";

		// kiểm tra các số chẵn trong mảng có tăng dần hay ko:
		if (ktchantangdan(a, n)) cout << "Mang co cac so chan tang dan\n";
		else cout << "Cac so chan trong mang ko tang dan\n";

		// kiểm tra tính chất chẵn lẻ xen kẽ:
		if (ktchanlexenke(a, n)) cout << "Mang co tinh chat chan le xen ke\n";
		else cout << "Mang ko co tinh chat chan le xen ke\n";

		// kiểm tra tính chất âm dương xen kẽ
		if (ktamduongxenke(a, n)) cout << "Mang co tinh chat am duong xen ke\n";
		else cout << "Mang ko co tinh chat am duong xen ke\n";
		
		// kiểm tra xem mảng có lập thành cấp số cộng ko:
		if (ktcapsocong(a, n)) cout << "Mang la cap so cong\n";
		else cout << "Mang ko lap dc thanh cap so cong\n";
		
		// sắp xếp mảng tăng dần/ giảm dần:
		sxmangtangdan(a, n);
		sxmanggiamdan(a, n);

		// sắp xếp chẵn tăng dần, lẻ giảm dần:
		sxchantanglegiam(a, n);

		// sắp xếp mảng sao cho các số chẵn về đầu mảng tăng dần, các số lẻ về cuối giảm dần:
		sxchandautanglesaugiam(a, n);

		// xoá phần tử tại vị trí k:
		cout << "Nhap vi tri k ban muon xoa = "; cin >> k1;
		xoapttaivtk(a, n, k1);
		
		// xoá tất cả các giá trị x ra khỏi mảng:
		cout << "Nhap gia tri x ma ban muon xoa khoi mang = "; cin >> x1;
		xoatatcacacgtx(a, n, x1);
		
		// xoá tất cả số nguyên tố ra khỏi mảng:
		xoatatcasongto(a, n);

		// xoá tất cả các phần tử trùng nhau:
		xoatatcaccacpttrungnhau(a, n);

		// xoá tất cả các ptử trùng chỉ chừa lại 1 ptử làm đại diện:
		xoacacpttrungnhauchualai1pt(a, n);

		// chèn giá trị x vào vị trí k trong mảng:
		cout << "Nhap gia tri x ban muon chen = "; cin >> x2;
		cout << "Nhap vi tri k ma ban muon chen gia tri x vao = "; cin >> k2;
		chengtxvaovtk(a, n, x2, k2);

		// chèn x vảo mảng có thứ tự giảm dần sao cho kq cũng có thứ tự giảm dần:
		cout << "Nhap gia tri x can chen = "; cin >> x;
		chengtxvasapxepgiamdan(a, n, x);

		// tách mảng thành 2 mảng gốm 1 mảng chẵn và 1 mảng lẽ:
		tachmangchanle(a, n);

		// tạo mảng gồm các số chính phương có trong mảng ban đầu:
		taomangcp(a, n);

		// trộn 2 mảng (a,m) và (b,n) có thứ tự tăng để tạo mảng (c,m+n) cũng có thứ tự tăng dần
		{
			int a[100];
			int b[100];
			int c[200];
			int m, n;
			int k;
			cout << "Nhap so phan tu cua mang (a, n) = "; cin >> n;
			nhapmang(a, n);
			inmang(a, n);
			cout << "Nhap so phan tu cua mang (b, m) = "; cin >> m;
			nhapmang(b, m);
			inmang(b, m);
			gopmang(a, n, b, m, c, k);
			sxmangtangdan(c, k);

		}*/
		
		

		cout << "Nhan ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}

