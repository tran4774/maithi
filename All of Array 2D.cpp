/*
All hàm trong mảng 2 chiều (ma trận)
*/
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;
#define MAX 100                                         //hằng số chỉ kích thước của ma trận

//1. Hàm nhập mảng 2D (ma trận)
void nhapmatran(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap phan tu [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}
//2. Hàm xuất mảng 2D (ma trận)
void inmatran(int a[][MAX], int d, int c)
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
//3. Hàm tính tổng lẻ trong cột lớn nhất và in ra vị trí cột đó
void tonglemax(int a[][MAX], int d, int c) {
	int tongle = 0;
	int tong1;
	int cmax = 0;
	for (int i = 0; i < d; i++) {
		if ((a[i][0]) % 2 != 0)
			tongle += a[i][0];
		tong1 = tongle;
	}
	cout << "Tong le cot dau tien: " << tongle << endl;
	for (int j = 0; j < c; j++) {
		tongle = 0;
		for (int i = 0; i < d; i++)
			if (a[i][j] % 2 != 0)
				tongle += a[i][j];
		if (tongle > tong1)
		{
			tong1 = tongle;
			cmax = j;
		}
	}
	cout << "Tong le lon nhat trong mang la " << tong1 << endl; cout << "Cot cua tong le max la:= " << cmax << endl;
}
//4. Hàm check ma trận đơn vị
bool ktmatrandonvi(int a[][MAX], int n)
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
//5. Hàm kiểm tra ma trận tam giác trên
bool ktmatrantamgiactren(int a[][MAX], int n)
{
	for (int i = 1; i < n - 1; i++)
		for (int j = i - 1; j <= i; j++)
			if (a[i][j] != 0) return false;

	return true;

}
//6. Hàm kiểm tra ma trận tam giác dưới
bool ktmatrantamgiacduoi(int a[][MAX], int n)
{
	int dem = 0;
	int check = 0;
	int temp = 0;

	for (int i = 0; i < n; i++)
		check += i;

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			if (a[i][i] == 0) return false;
			if (a[i][j] != 0) dem++;
			if (a[j][i] == 0) temp++;
		}
	if (dem > 0 && temp == check) return true;
	else return false;
}
//7. Hàm kiểm tra ma trận đối xứng
bool ktmatrandoixung(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] != a[j][i]) return false;

	return true;
}
//8. Hàm tìm phần tử lớn nhất trên đường chéo chính
int timmaxcheochinh(int a[][MAX], int n)
{
	int max = a[0][0];
	for (int i = 0; i < n; i++)
		if (a[i][i] > max) max = a[i][i];
	return max;
}
//9. Hàm tìm phần tử nhỏ nhất trên đường chéo chính
int timmincheochinh(int a[][MAX], int n)
{
	int min = a[0][0];
	for (int i = 0; i < n; i++)
		if (a[i][i] < min) min = a[i][i];
	return min;
}
//10. Hàm tìm phần tử lớn nhất trên đường chéo phụ
int timmaxcheophu(int a[][MAX], int n)
{
	int max = a[0][n - 1];
	for (int i = 0; i < n; i++)
		if (a[i][n - 1 - i] > max) max = a[i][n - 1 - i];
	return max;
}
//11. Hàm tìm phần tử nhỏ nhất trên đường chéo phụ
int timmincheophu(int a[][MAX], int n)
{
	int min = a[n - 1][n - 1];
	for (int i = 0; i < n; i++)
		if (a[i][n - 1 - i] < min) min = a[i][n - 1 - i];
	return min;
}
//12. Hàm tính ma trận A^k
void tinhAmuK(int a[][MAX], int b[][MAX], int x[][MAX], int n, int k)
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
	inmatran(x, n, n);
}
//13. Hàm in ma trận xoắn ốc
void taomatranxoanoc(int a[][MAX], int n)
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
	inmatran(a, n, n);
}
//14. Hàm tính tổng các phần tử biên của HAI DỤ
int tinhtongcacptubien(int a[][MAX], int d, int c)
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
//15. Hàm tính tổng các phần tử biên chẵn của HAI DỤ
int tinhtongcacptuchanbien(int a[][MAX], int n) 
{
	int s = 0;

	for (int i = 0; i < n; i++)                        // tính hàng đầu
		if (a[0][i] % 2 == 0) s += a[0][i];
	for (int i = 1; i < n - 1; i++)                    // tính cột đầu loại bỏ a[0][0] vừa tính ở trên
		if (a[i][0] % 2 == 0) s += a[i][0];
	for (int i = 1; i < n; i++)                        // tính cột cuối loại bỏ các giá trị a[n-1][n-1] và a[0][n-1]
		if (a[i][n - 1] % 2 == 0) s += a[i][n - 1];
	for (int i = 0; i < n - 1; i++)                    // tính hàng cuối loại bỏ các giá trị a[n-1][0] và a[n-1][n-1]
		if (a[n - 1][i] % 2 == 0) s += a[n - 1][i];
	return s;
}
//16. Hàm tính tổng các phần tử biên (chẵn, lẻ, không điều kiện) Lô Độ
int sumbienclkdk(int a[][MAX], int d, int c) {
	int i, j;
	int tongtren = 0;
	int tongduoi = 0;
	int tongtrai = 0;
	int tongphai = 0;
	int tongtoanbo;
	//Tính tổng cạnh trên và cạnh dưới của ma trận vuông
	for (j = 0; j < c; j++)
	{
		if (a[0][j] % 2 == 0)
		{
			tongtren += a[0][j];
		}
		if (a[c - 1][j] % 2 == 0)
		{
			tongduoi += a[c - 1][j];
		}
	}

	//Tính tổng cạnh trái và cạnh phải của ma trận vuông (i chạy từ 1->n-1 để tránh cộng 4 góc 2 lần) 
	for (i = 1; i < d - 1; i++)
	{
		if (a[i][0] % 2 == 0)
		{
			tongtrai += a[i][0];
		}
		if (a[i][d - 1] % 2 == 0)
		{
			tongphai += a[i][d - 1];
		}
	}
	tongtoanbo = tongtren + tongduoi + tongtrai + tongphai;
	cout << tongtoanbo;
}
//17. Hàm sắp xếp ma trận 
void sapxepmatrix(int a[][MAX], int d, int c) {
	int b[MAX * MAX];
	int k = 0;                            //k là số phần tử của mảng 1 chiều 
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			b[k++] = a[i][j];             //số lượng phần tử của mảng 1 chiều tăng dần lên mỗi khi có thêm phần tử từ ma trận được nối vào
	//Sắp xếp lại mảng 1 chiều vừa nối theo thứ tự tăng dần
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (b[i] > b[j])
			{
				int t = b[i];
				b[i] = b[j];
				b[j] = t;
			}
	//Xuất mảng 1 chiều vừa được sắp xếp ra để tiện theo dõi
	cout << "Mang 1 chieu sau khi da duoc noi va sap xep lai la: \n";
	for (int i = 0; i < k; i++)
		cout << b[i] << " ";
	cout << endl;
	//Đưa mảng 1 chiều vừa sắp xếp xong trở lại dạng mảng 2 chiều theo thứ tự từ trên xuống dưới và trái sag phải

	k = 0;
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < d; i++)
		{
			a[i][j] = b[k++];
		}

	}
	//Lưu ý liên hệ: Nếu đề bài yêu cầu sắp xếp từ trái sang phải rồi mới từ trên xuống dưới thì chỉ việc đổi thứ tự hai dòng for i và for lại vs nhau
	cout << "Ma tran vuong vua sap xep lai theo thu tu tren xuong duoi va trai sang phai la: \n";
	inmatran(a, d, c);
}
//18. Tính tổng các phần tử lẻ trong cột
int tinhtongcotle(int a[][MAX], int d, int c)
{
	int dem = 0;
	for (int i = 0; i < d; i++)
		if (a[i][c] % 2 != 0) dem += a[i][c];
	return dem;
}
//19. Tìm cột có tổng là các phần tử lẻ lớn nhất
void timmaxcotle(int a[][MAX], int d, int c)
{
	int max = tinhtongcotle(a, d, 0);
	for (int j = 1; j < c; j++)
		if (tinhtongcotle(a, d, j) > max) max = tinhtongcotle(a, d, j);
	cout << max << endl;
}
//20. Nhân 2 ma trận
void nhan2matran(int a[][MAX], int b[][MAX], int x[][MAX], int d, int c, int k)
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
//21. Tổng 2 ma trận
void cong2matran(int a[][MAX], int b[][MAX], int x[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];


	cout << "Tong cua 2 ma tran ban vua nhap:\n";
	inmatran(x, d, c);
}
//22. Phan ra A = LU
void PhanRaLU(float A[MAX][MAX], float L[MAX][MAX], float U[MAX][MAX], int n) {
	for (int k = 0; k < n; k++) {
		U[k][k] = A[k][k];
		L[k][k] = 1;
		for (int i = k + 1; i < n; i++) {
			L[i][k] = A[i][k] / U[k][k];
			U[k][i] = A[k][i];
			U[i][k] = 0;
			L[k][i] = 0;
		}
		for (int i = k + 1; i < n; i++)
			for (int j = k + 1; j < n; j++)
				A[i][j] = A[i][j] - L[i][k] * U[k][j];
	}
}
//23. Dinh thuc ma tran tam giac
float DinhThucMaTranTamGiac(float A[MAX][MAX], int n) {
	float temp = 1;
	for (int i = 0; i < n; i++)
		temp *= A[i][i];
	if (temp == -0 || temp == 0)
		return 0;
	return temp;
}
//24. Copy ma trận và chuyển vị
void copymtvacv(float A[MAX][MAX], float copy[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy[i][j] = A[j][i];
		}
	}
}
int main()
{
	//Khai báo biến cục bộ
	int a[MAX][MAX];
	int d;                                              
	int c;
	int i, j;
	do
	{
		do
		{
			cout << "Nhap so dong(0<d<100): ";
			cin >> d;
			if (!((0 < d) && (d < 100))) cout << "Sai dieu kien !!! \n";
		} while (!((0 < d) && (d < 100)));
		do
		{
			cout << "Nhap so dong(0<c<100): ";
			cin >> c;
			if (!((0 < c) && (c < 100))) cout << "Sai dieu kien !!! \n";
		} while (!((0 < c) && (c < 100)));

		nhapmatran(a, d, c);
		inmatran(a, d, c);
		tonglemax(a, d, c);

	} while (_getch() != 27);
	return 0;
}

