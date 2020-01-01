// chuoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
1. Tác giả: Nguyễn Hoàng Vũ
2. Ngày viết: 30/12/2019
3. Ngày cập nhật:
*/

#include <iostream>				//một số thư viện thường dùng
#include <conio.h>				//_getch...
#include <math.h>				//sqrt,...
#include <time.h>
#include <stdlib.h>				//random,...
#include <string.h>				//xử lý chuỗi
using namespace std;

void nhapchuoi(char str[])
{
	cout << "Nhap chuoi: ";
	cin.getline(str, 100);
}

bool ktchuoichuan(char str[])
{
	int len = strlen(str);
	if (strlen(str) > 0)
	{
		if (str[0] == ' ') return false;		//kí tự trắng đầu chuỗi
		else if (len - 1 == ' ') return false;	//kí tự trắng cuối chuỗi
		else 
		{
			for (int i = 0; i < len - 1; i++)
				if (str[i] == ' ' && str[i + 1] == ' ')		//2 kí tự trắng kề nhau
					return false;
		}
	}

	return true;
}

void chuanhoachuoi(char str[])
{
	int len = strlen(str);
	if (len > 0)
	{
		while (str[0] == ' ')								 //xoá ký tự trắng ở đầu chuỗi
		{
			for (int i = 0; i < len; i++)
				str[i] = str[i + 1];
			str[len - 1] = 0;
			len--;
		}

		while (str[strlen(str) - 1] == ' ')					//xoá ký tự trắng cuối chuỗi
		{
			for (int i = len - 1; i < len; i++)
				str[i] = str[i + 1];
			str[strlen(str) - 1] = 0;
			len--;
		}

		for (int i = 0; i < len - 1; i++)					//xoá ký tự trắng thừa giữa chuỗi
		{
			if (str[i] == ' ' && str[i + 1] == ' ')
			{
				for (int j = i; j < len; j++)
				{
					str[j] = str[j + 1];
				}
				len--;
				i--;
			}
		}

	}
	
	cout << "Mang sau khi chuan hoa: " << str << endl;
}
// đếm số lần xuất hiện của ký tự
int demlanxuathien(char s[], char x)
{
	int dem = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == x) dem++;
	}
	return dem;
}

int demsotu(char s[])
{
	int sotu = 0;
	if (strlen(s) > 0) 
	{
		if (s[0] != ' ') sotu++;
		for (int i = 0; i < strlen(s); i++)
			if (s[i] == ' ' && s[i + 1] != ' ') sotu++;
	}
	return sotu;
}
// in hoa chữ đầu mỗi từ và in thường các chữ còn lại
void inhoachudauinthuongcacchuconlai(char s[])
{

	int i;
	if (strlen(s) > 0)
	{
		if (s[0] != ' ')
		{
			if (isdigit(s[0])) s[0] = s[0];
			else s[0] = s[0] - 32;

			for (i = 1; i < strlen(s); i++)
			{
				if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
				{
					s[i + 1] = s[i + 1] - 32;
				}
			}
		}
		else
		{
			for (i = 0; i < strlen(s); i++)
			{
				if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
				{
					s[i + 1] = s[i + 1] - 32;
				}
			}
		}
	}

	cout << s << endl;
}

int demnguyenam(char s[])
{
	int dem = 0;

	for (int i = 0; i < strlen(s); i++)
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
			dem++;

	return dem;
}
// đếm nguyên âm phân biệt
int demnguyenamphanbiet(char s[])
{
	int dem = 0;		
	if (demlanxuathien(s, 'a') >= 1) dem++;
	if (demlanxuathien(s, 'e') >= 1) dem++;
	if (demlanxuathien(s, 'i') >= 1) dem++;
	if (demlanxuathien(s, 'o') >= 1) dem++;
	if (demlanxuathien(s, 'u') >= 1) dem++;
	if (demlanxuathien(s, 'y') >= 1) dem++;
	return dem;
}

int demsotubatdaunguyenam(char s[])
{
	int sotu = 0;
	if (strlen(s) > 0)
	{
		if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'y')
			sotu++;

		for (int i = 0; i < strlen(s); i++)
			if (s[i] == ' ' && (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u' || s[i + 1] == 'y'))
				sotu++;
	}
	return sotu;
}

bool checkchuoitoanso(char s[])
{
	if (strlen(s) == 0) return false;
	else if (strlen(s) > 0)
	{
		for (int i = 0; i < strlen(s); i++)
			if (!(isdigit(s[i]))) return false;
	}
	return true;
}
// kiểm tra xem chuỗi có biểu diễn cho hệ thập lục phân hay ko
bool ktthaplucphan(char s[])
{
	if (strlen(s) == 0) return false;
	else if (strlen(s) > 0)
	{
		if (s[0] == '0') return false;

		for (int i = 1; i < strlen(s); i++)
			if (!('0' <= s[i] && s[i] <= '9' || 'a' <= s[i] && s[i] <= 'f'))
				return false;
	}
	return true;
}

bool checkchuoitoanchu(char s[])
{

	if (strlen(s) == 0) return false;
	else if (strlen(s) > 0)
	{
		for (int i = 0; i < strlen(s); i++)
			if (!('a' <= s[i] && s[i] <= 'z')) return false;
	}

	return true;
}

bool checkchuoitoankhoangtrang(char s[])
{

	if (strlen(s) == 0) return false;
	else if (strlen(s) > 0)
	{
		for (int i = 0; i < strlen(s); i++)
			if (!(s[i] == ' ')) return false;
	}
		return true;
}

int tinhtongkytuso(char str[])
{
	int i = 0, j, tong = 0, n;
	while (i <= strlen(str) - 1)
	{
		 if (str[i] <= '9' && str[i] >= '0')
		 {
			j = i;
			n = 0;
			while (j <= strlen(str) - 1 && (str[j] <= '9' && str[j] >= '0'))
			{
				 n = 10 * n + (int)str[j] - 48;
				j++;
			}
 
			tong += n;
			 i = j;
		 }

		 else i++;

	}

	return tong;
}

int timmaxsoduong(char s[])
{
	int i = 0;
	int max = 0;
	while (i < strlen(s))
	{
		if (isdigit(s[i]))
		{
			int j = i;
			int n = 0;
			while (j < strlen(s) && isdigit(s[j]))
			{
				n = 10 * n + (int)s[j] - 48;
				j++;
			}
			if (n > max) max = n;
			i = j;
		}
		else i++;
	}
	return max;
}

int timvitrixuathiendautiencuachuoicon(char s[], char s1[])
{
	int count = 0;
	for (int i = 0; i <= strlen(s) - strlen(s1); i++)
	{
		bool Check = true;
		for (int j = 0; j < strlen(s1); j++)
			if (s[i + j] != s1[j]) Check = false;
		if (Check)
		{
			count = i;
			break;
		}
		
	}
	return count;
}


int demsolanxuathiencuachuoicon(char s[], char s1[])
{
	int i, j;
	int count = 0;
	for (i = 0; i <= strlen(s) - strlen(s1); i++)
	{
		bool Check = true;
		for (j = 0; j < strlen(s1); j++)
			if (s[i + j] != s1[j]) Check = false;
		if (Check) count++;
	}
	return count;
}



// tìm và in ra từ dài nhất chuỗi
void TuDaiNhat(char s[]) 
{
	int i;
	int maxx = 0, maxi = 0;
	int len = strlen(s);
	if (s[0] == ' ') 
	{
		for (i = 0; i < len - 1; i++)
		{
			if ((s[i] == ' ') && (s[i + 1] != ' '))
			{
				int j = i + 1;
				int dem = 0;
				while ((s[j] != ' ') && (s[j] != '\0')) 
				{
					dem++;
					j++;
				}
				if (dem > maxx)
				{
					maxx = dem;
					maxi = i + 1;
				}
				i = j - 1;
			}
		}
	}
	else {
		i = 0;
		int dem = 0;
		while ((s[i] != ' ') && (s[i] != '\0')) 
		{
			dem++;
			i++;
		}
		if (dem > maxx) 
		{
			maxx = dem;
			maxi = 0;
		}
		for (i = maxx - 1; i < len - 1; i++)
		{
			if ((s[i] == ' ') && (s[i + 1] != ' '))
			{
				int j = i + 1;
				int de = 0;
				while ((s[j] != ' ') && (s[j] != '\0'))
				{
					de++;
					j++;
				}
				if (de > maxx) 
				{
					maxx = de;
					maxi = i + 1;
				}
				i = j - 1;
			}
		}
	}

	int k;
	for (k = maxi; k < (maxi + maxx); k++)
		cout << s[k];
}

void thaythekitu(char s[], char x, char y)
{
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == x) s[i] = y;
	
	puts(s);
}





int main()
{
	char str[100];
	int len;

	do
	{
		
		nhapchuoi(str);
		
		/*
		// check chuỗi chuẩn
		if (ktchuoichuan(str)) cout << "Day la chuoi chuan\n";
		else cout << "Day ko phai la chuoi chuan\n";

		// chuẩn hoá chuỗi
		chuanhoachuoi(str);	
		
		// đếm số lần xuất hiện của ký tự ch trong chuỗi
		cout <<"So lan xuat hien cua ky tu ch trong chuoi = " << demlanxuathien(str, 'ch');
		cout << endl;

		// đếm số từ
		cout << "So tu co trong chuoi = " << demsotu(str) << endl;
		
		// viết hoa ký tự đầu mỗi từ, viết thuờng các kí tự còn lại
		cout << "Mang sau khi in hoa chu da, in thuong cac chu con lai: ";
		inhoachudauinthuongcacchuconlai(str);
		
		// đếm số lượng ký tự nguyên âm
		cout << "So luong ky tu nguyen am trong chuoi = ";
		cout << demnguyenam(str) << endl;

		// đếm số lượng ký tự nguyên âm (phân biệt)
		_strlwr_s(str);
		cout << "So luong ky tu nguyen am (phan biet) trong chuoi = ";
		cout << demnguyenamphanbiet(str) << endl;

		// đếm số từ bắt đầu = 1 nguyên âm trong chuỗi
		_strlwr_s(str);
		cout << "So tu bat dau = nguyen am trong chuoi = " << demsotubatdaunguyenam(str) << endl;

		// kiểm tra xem chuỗi có chứa toàn toàn chữ số hay ko
		if (checkchuoitoanso(str)) cout << "Chuoi toan chu so\n";
		else cout << "Chuoi con co ki tu khac ngoai so\n";

		// kiểm tra xem chuỗi có phải là biểu diễn của 1 số thập lục phân hay ko
		_strlwr_s(str);
		if (ktthaplucphan(str)) cout << "Chuoi la bieu dien thap luc phan\n";
		else cout << "Chuoi ko la thap luc phan\n";

		// kiểm tra xem chuỗi có chứa toàn chữ cái/ ký tự trắng
		_strlwr_s(str);
		if (checkchuoitoanchu(str)) cout << "Chuoi toan chu cai\n";
		else cout << "Chuoi con ky tu khac ngoai chu\n";

		if (checkchuoitoankhoangtrang(str)) cout << "Chuoi toan khoang trang\n";
		else cout << "Chuoi con ky tu khac ngoai khoang trang\n";

		// tính tổng các ký tự số có trong chuỗi
		cout << "Tong cac ky tu so = " << tinhtongkytuso(str) << endl;
		
		// tìm max số nguyên dương. Nếu ko có thì trả về 0
		cout << "Max = " << timmaxsoduong(str) << endl;
		
		// tìm vị trí xuất hiện đầu tiên của chuỗi con trong chuỗi lớn (nếu có)
		char str1[100];
		cout << "Nhap chuoi thu 2: "; cin.getline(str1, 100);
		cout << "Vi tri = ";
		cout << timvitrixuathiendautiencuachuoicon(str, str1) << endl;
		
		
		// đếm số lần xuất hiện của chuỗi con trong chuỗi lớn
		char str1[100];
		cout << "Nhap chuoi thu 2: "; cin.getline(str1, 100);
		cout << demsolanxuathiencuachuoicon(str, str1) << endl;
		*/
		// tìm và in ra từ dài nhất có trong chuỗi
		cout << "Tu dai nhat chuoi la: ";
		TuDaiNhat(str);
		cout << endl;

		// thay thế kí tự oldc = newc
		thaythekitu(str, 'oldc', 'newc');
		cout << endl;

		//Thay thế toàn bộ các chuỗi con olds trong chuỗi bằng chuỗi news
		//VD: s = “em noi em yeu anh ma em khong yeu”
		//olds = “yeu”
		//news = “ghet”
		//Kết quả : “em noi em ghet anh ma em khong ghet”





		cout << "Nhan ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}
