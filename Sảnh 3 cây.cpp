/*Câu 1: (3 điểm) Hãy viết chương trình thực hiện các công việc sau:
a)	(1.5đ) Nhập từ bàn phím 3 số nguyên a, b, c thỏa điều kiện 1 ≤ a, b, c ≤ 13. Nếu không thỏa thì yêu cầu nhập lại cho đến khi thỏa mới thôi.
b)	(1.5đ) Kiểm tra xem 3 số đã nhập có lập thành 1 “sảnh” 3 cây của bài tiến lên hay không. Chú thích: 1 = A, 11 = J, 12 = Q, 13 = K. Sảnh 3 gồm (345, 456, 567, 678, 789, 8910, 910J, 10JQ, JQK, QKA)
*/
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

int main()
{
	int a, b, c;
	int t1, t2, t3;
	do {
		//câu a
		do {
			cout << "nhap so nguyen a: ";
			cin >> a;
			if (!(a >= 1 && a <= 13))
			{
				cout << "dieu kien khong thoa, nhap lai !!! \n";
			}
		} while (!(a >= 1 && a <= 13));


		do {
			cout << "nhap so nguyen b: ";
			cin >> b;
			if (!(b >= 1 && b <= 13))
			{
				cout << "dieu kien khong thoa, nhap lai !!! \n";
			}
		} while (!(b >= 1 && b <= 13));


		do {
			cout << "nhap so nguyen c: ";
			cin >> c;
			if (!(c >= 1 && c <= 13))
			{
				cout << "dieu kien khong thoa, nhap lai !!! \n";
			}
		} while (!(c >= 1 && c <= 13));

		//câu b
		if (a > b && a > c)
		{
			t1 = a;
			if (b > c)
			{
				t2 = b;
				t3 = c;
			}
			else
			{
				t2 = c;
				t3 = b;
			}

		}
		else if ((a > b && a < c) || (a < b && a > c))
		{
			t2 = a;
			if (b > c)
			{
				t1 = b;
				t3 = c;
			}
			else
			{
				t1 = c;
				t3 = b;
			}

		}
		else
		{
			t3 = a;
			if (b > c)
			{
				t1 = b;
				t2 = c;
			}
			else
			{
				t1 = c;
				t2 = b;
			}

		}


		if ((t1 - t2 == 1) && (t1 - t3 == 2))
		{
			cout << t3 << " - " << t2 << " - " << t1 << " la mot sanh" << endl;
		}
		else
		{
			cout << t3 << " - " << t2 << " - " << t1 << " khong la mot sanh" << endl;
		}

		cout << endl;
		cout << "Nhan phim ESC de thoat...\n" << "Hoac la nhan bat ki phim nao de chay lai chuong trinh...\n";
	} while (_getch() != 27);
	return 0;
}