/*
Bài thi NMLT 2019 (final)
Câu 1
Người viết : Nguyễn Bảo Trấn
MSSV: 19110301
Ngày viết : 02/01/2020 9:58 AM
*/

//Ko xoa
#include <iostream> // Một số thư viện thường dùng
#include <conio.h> //_getch,...
#include <stdlib.h>
#include <math.h> //sqrt,...
#include <time.h> 
#include <string.h> // Xử lí chuỗi
#include <iomanip>


using namespace std;

int main()
{
	// Khai bao bien
	int n, t;
	int tong = 0;

	do {
		//Tat ca cac lenh dat o day
		cout << "Nhap so n: ";
		do {
			cin >> n;
			if (n < 0)
				cout << "So ban nhap khong thoa man dieu kien, moi nhap lai so n: ";
		} while (n < 0 || n> pow(10,9));
		tong = 0;
		while (n >= 0) {
			t = n % 10;
			n = n / 10;
			if (t == 0)
				tong += 6;
			else if (t == 1)
				tong += 2;
			else if (t == 2)
				tong += 5;
			else if (t == 3)
				tong += 5;
			else if (t == 4)
				tong += 4;
			else if (t == 5)
				tong += 5;
			else if (t == 6)
				tong += 6;
			else if (t == 7)
				tong += 3;
			else if (t == 8)
				tong += 7;
			else if (t == 9)
				tong += 6;
		}
		cout << tong << endl;

		cout << "Nhan phim ESC de thoat" << endl;
	} while (_getch() != 27);
	return 0;
}
