/*
Bài thi NMLT 2019 (final)
Câu 4
Người viết : Nguyễn Bảo Trấn
MSSV: 19110301
Ngày viết : 02/01/2020 10:34 AM
*/

//Ko xoa
#include <iostream> // Một số thư viện thường dùng
#include <conio.h> //_getch,...
#include <stdlib.h>
#include <math.h> //sqrt,...
#include <time.h> 
#include <string.h> // Xử lí chuỗi


using namespace std;

//1. Hàm đếm số kí từ có tận cùng là 1 kí tự số thập lục phân //Lop 12A2 se LA so 1
int demthapluc(char str[]) {
	int dem = 0;
	int length = strlen(str);
	int i = length - 1;
	for (i = 0; i <= length; i++) {
		if (str[i] == ' '|| str[i] == '\0') {
			if ((str[i - 1] >= '0' && str[i - 1] <= '9') || (str[i - 1] >= 'A' && str[i - 1] <= 'F')) {
				dem++;
			}
		}
	}
	return dem;
}

int main()
{
	// Khai bao bien
	char ch[256];
	do {

		//Tat ca cac lenh dat o day
		cout << "Nhap mot chuoi: ";
		cin.getline(ch, 256);
		cout << "Chuoi vua nhap: " << ch << endl;

		cout << "So tu co tan cung la ki tu thap luc phan la: " << demthapluc(ch) << endl;
		cout << "Nhan phim ESC de thoat" << endl;
	} while (_getch() != 27);
	return 0;
}