/*Câu 1: (2.5 điểm) 
Viết chương trình thực hiện việc nhập vào một số nguyên dương N (0 < N < 1.000.000). Tìm và in ra màn hình số nguyên tố gần N nhất. Trong trường hợp có 2 số có khoảng cách tới N bằng nhau thì in ra số lớn hơn.
Dữ liệu vào: Một số nguyên N duy nhất.
Dữ liệu ra: Một số nguyên duy nhất cho biết kết quả tìm được. 
Ví dụ:	Dữ liệu vào	Dữ liệu vào
	12	25
	Dữ liệu ra	Dữ liệu ra
	13	23
*/


#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <iomanip>
using namespace std;
bool ktsongto(int x)
{
	if (x < 2) return false;
	else if (x > 2)
	{
		if (x % 2 == 0) return false;
		else
			for (int i = 3; i < x; i += 2)
				if (x % i == 0) return false;
	}
	return true;
}
int main()
{
	unsigned n;

	int i, j;
	do {
		do {
			cout << "nhap so nguyen N: ";
			cin >> n;
			if (!(n > 0 && n < 1000000))
			{
				cout << "dieu kien khong thoa, nhap lai !!! \n";
			}
		} while (!(n > 0 && n < 1000000));

		i = n + 1;
		j = n - 1;

		while (i < 1000000)
		{
			if (ktsongto(i)) break;
			else i++;
		}


		while (j > 0)
		{
			if (ktsongto(j)) break;
			else j--;
		}

		if (i - n > n - j) cout << j << endl;
		else if (i - n < n - j) cout << i << endl;
		else cout << i << endl;


		cout << endl;
		cout << "Nhan phim ESC de thoat...\n" << "Hoac la nhan bat ki phim nao de chay lai chuong trinh...\n";
	} while (_getch() != 27);
	return 0;
}
