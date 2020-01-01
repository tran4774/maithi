#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <iomanip>
using namespace std;

int main()
{
	int a[100][100];
	int d, n, i, j;
	int tongtren = 0;
	int tongduoi = 0;
	int tongtrai = 0;
	int tongphai = 0;
	int tongtoanbo;
		do {
		cout << "Nhap kich thuoc cua mt vuong: ";
		cin >> n;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << "[" << i << "]" << "[" << j << "]" << "=";
				cin >> a[i][j];
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout.width(5);
				cout << a[i][j];
			}
			cout << endl;
		}


		for (j = 0; j < n; j++)
		{
			if (a[0][j] % 2 == 0)
			{
				tongtren += a[0][j];
			}
			if (a[n - 1][j] % 2 == 0)
			{
				tongduoi += a[n - 1][j];
			}
		}
		
		for (i = 1; i < n - 1; i++)
		{
			if (a[i][0] % 2 == 0)
			{
				tongtrai += a[i][0];
			}
			if (a[i][n - 1] % 2 == 0)
			{
				tongphai += a[i][n - 1];
			}
		}

		
		tongtoanbo = tongtren + tongduoi + tongtrai + tongphai;		
		cout << tongtoanbo;

		cout << endl;
		cout << "Nhan phim ESC de thoat...\n" << "Hoac la nhan bat ki phim nao de chay lai chuong trinh...\n";
	} while (_getch() != 27);
	return 0;
}
