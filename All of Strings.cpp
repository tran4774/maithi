#include <iostream>				//một số thư viện thường dùng
#include <conio.h>				//_getch...
#include <math.h>				//sqrt,...
#include <time.h>
#include <stdlib.h>				//random,...
#include <string.h>				//xử lý chuỗi
#include <iomanip>
using namespace std;
//9. Đếm số lần xuất hiện chuỗi con trong chuỗi mẹ
int demchuoicon(char str[], char str2[]) {
	int i = 0;
	int dem = 0;
	int len1 = strlen(str);
	int len2 = strlen(str2);
	for (i = 0; i < len1; i++)
	{
		if (str[i] != str2[0])
			continue;
		else
		{
			bool check = true;
			for (int j = 0; j < len2; j++)
			{
				if (str[i + j] != str2[j])
				{
					check = false;
					break;
				}
			}
			if (check == true)
				dem++;
		}
	}
	return dem;
}
//10.Đếm số lần xuất hiện của 1 ký tự ch trong chuỗi
unsigned Demkt(char s[], char ch)
{
	int len = strlen(s);
	int dem = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ch) dem++;
	}
	return dem;
}

//11. Đếm số từ có trong 1 chuỗi chuẩn
unsigned DemTuChuoiChuan(char s[])
{
	if (s[0] == NULL) return 0;
	int dem = Demkt(s, ' ');
	return dem + 1;
}

//12. Đếm số lượng kí tự số có trong chuỗi (nếu có)
unsigned DemKyTuSo(char s[])
{
	int len = strlen(s);
	int dem = 0;
	for (int i = 0; i < len; i++)
		if ('0' <= s[i] && s[i] <= '9') dem++;					// '0' = 48 và '9' = 57
	return dem;
}

//13.Kiểm tra 1 chuỗi có phải là chuỗi chuẩn hay ko
//Chuỗi chuẩn là chuỗi ko có khoảng trắng thừa
//Khoảng trắng thừa là kí tự trắng nằm ở đầu , cuối hoặc ngay sau 1 kí tự trắng khác
bool KiemTraChuoiChuan(char s[])
{
	int len = strlen(s);
	if (s[0] == NULL) return false;
	if (s[0] == ' ') return false;
	if (s[len - 1] == ' ') return false;
	for (int i = 0; i < len; i++)
		if (s[i] == ' ' && s[i + 1] == ' ') return false;
	return true;
}

//14. Đếm số từ trong chuỗi bất kỳ
unsigned DemTu(char s[])
{
	int sotu = 0;
	if (s[0] == NULL) return 0;
	if (s[0] != ' ') sotu++;
	int len = strlen(s);
	for (int i = 1; i < len; i++)
		if (s[i] != ' ' && s[i - 1] == ' ') sotu++;
	return sotu;
}

//15. Hàm đếm số lượng các kí tự nguyên âm có trong chuỗi
// Các nguyên âm bao gồm (A,E,I,O,U,Y,a,e,i,o,u,y)
//cach1
int demnguyenam1(char s[])
{
	int dem = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
			s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ||
			s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
			s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
			dem++;
	}
	return dem;
}

//cach 2 ,dùng toupper/tolower
int demnguyenam2(char s[])
{
	int dem = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		char ch = toupper(s[i]);// chữ hoa tương ứng của kí tự đang xét
		if (ch == 'A' || ch == 'E' || ch == 'I' ||
			ch == 'O' || ch == 'U' || ch == 'Y')
			dem++;
	}
	return dem;
}


//16. Hàm viết hoa ký tự đầu mỗi từ, viết thường các ký tự
// còn lại. dùng hàm toupper(ch) và tolower(ch) nếu cần 
void hoadautu(char  s[])
{
	_strlwr_s(s, 50); // đổi toàn bô chuỗi thành chữ thường
	s[0] = toupper(s[0]); // đổi kí tự đầu chuổi thành chữ hoa
	int len = strlen(s);
	for (int i = 1; i < len; i++)
		if ((s[i] == 32) && (s[i + 1] != 32)) // đầu từ 
			s[i+1] = toupper(s[i+1]);
	cout << s << endl;
}

//17. Hàm đảo ngược các thứ tự các từ trong chuỗi
void daonguoctu(char str[]) {
	int len = strlen(str);
	int i = 0;
	_strrev(str);		//Hàm đảo ngược nguyên chuỗi
	while (i < len) {
		int oldi = i;
		while (i < len && str[i] != ' ') i++;
		for (int j = 0; j <= int((i - oldi) / 2) - 1; j++) {
			int tam = str[j + oldi];
			str[j + oldi] = str[i - j - 1];
			str[i - j - 1] = tam;
		}
		i++;
	}
	cout << str << endl;
}

//18. Hàm đếm từ có 2 nguyên âm liền trong chuỗi 
void demtu2na(char str[]) {
	char na[] = "AEIOUYaeiouy";
	int sotu01 = 0; int dem2 = 0;
	int len = strlen(str);
	if (len > 0)                                                //len > 0 tức là ko cần biết có bao nhiêu ký tự phải, chắc chắn là có 1 từ bất kỳ vì vậy sotu=1
	{
		for (int i = 0; i < len; i++)
		{
			if ((strchr(na, str[i]) != NULL) && (strchr(na, str[i + 1]) != NULL))
				sotu01++;
		}
		int dem = 0;
		for (int i = 0; i < len; i++)
			if ((strchr(na, str[i]) != NULL) && (strchr(na, str[i + 1]) != NULL) && (strchr(na, str[i + 1 + 1]) != NULL))
				dem++;
		dem2 = sotu01 - dem;
	}
	cout << "So tu co chua it nhat hai nguyen am dung canh nhau trong mang la: " << dem2 << endl;
}

int main()
{
	char str[50];			//chuỗi kí tự
	int len;				//chiều dài thực sự của chuỗi
	char str2[50];

	do
	{
		//1.Nhập chuỗi
		cout << "1. Nhap 1 chuoi ki tu: ";
		cin.getline(str, 50);			//gets(...)

		//2.Xuất chuỗi
		cout << "2. Chuoi vua nhap la:  ";
		cout << str << endl;

		//3.Sao chép 1 chuỗi
		strcpy_s(str2, str);
		cout << "3. Chuoi ki tu sau khi copy la: " << str2 << endl;

		//4.Nối chuỗi
		strcat_s(str2, " xin chao");
		cout << "4. Chuoi sau khi noi la: " << str2 << endl;

		//5.Tính chiều dài chuỗi
		len = strlen(str);
		cout << "5. Chieu dai cua chuoi = " << len << endl;
		
		//6.Đổi hoa/ thường
		_strupr_s(str);		//in hoa Full chuỗi
		cout << "6. Chuoi sau khi doi hoa la: " << str << endl;
		_strlwr_s(str);		//in thường Full chuỗi
		cout << "6. Chuoi sau khi in thuong la: " << str << endl;

		//7.So sánh 2 chuỗi
		strcpy_s(str, "an");
		strcpy_s(str2, "An");
		if (_stricmp(str2, str) == 0) cout << "7. 2 chuoi bang nhau\n";			//_stricmp: so sánh không phân biệt hoa thường
		else cout << "7. 2 chuoi ko bang nhau\n";								//strcmp: so sánh phân biệt hoa thường.

		//8.Tìm kí tự trong chuỗi
		strcpy_s(str, "Con ga me tcon ga con");
		if (strchr(str, 't') == NULL) cout << "8. Chuoi ki tu ko chua t" << endl;		//strchr == NULL là k có kí tự t, nếu có thì trả về 1 con trỏ tới kí tự t.
		else cout <<"8. "<<strchr(str, 't') << endl;		//strchr trỏ tới chữ t và in ra dãy sau nó
		

		//9.Đếm chuỗi con trong chuỗi mẹ
		char strcon[20];
		cout << "Nhap chuoi con can dem: ";
		cin.getline(strcon, 20);
		if (demchuoicon(str, strcon) == 0)
			cout << "Chuoi con khong xuat hien trong chuoi me" << endl;
		else
			cout << "Chuoi con xuat hien trong chuoi me " << demchuoicon(str, strcon) << " lan" << endl;

		//10.Đếm số lần xuất hiện của kí tự ch trong chuỗi 
		cout << "10. So lan xuat hien cua ki tu ch trong chuoi la " << Demkt(str, 'ch') << " lan" << endl;

		//11.Đếm số từ có trong 1 chuỗi chuẩn
		if (KiemTraChuoiChuan(str)) 
			cout << "11. So tu trong chuoi chuan = " << DemTuChuoiChuan(str) << endl;
		else 
			cout << "Day ko phai la chuoi chuan\n";
		
		//12.Đếm số lượng kí tự số có trong chuỗi (nếu có)
		cout << "12. So luong ki tu so co trong chuoi = " << DemKyTuSo(str) << endl;

		//13.Kiểm tra chuỗi chuẩn
		if (KiemTraChuoiChuan(str)) cout << "Day la chuoi chuan\n";
		else cout << "13. Day ko phai la chuoi chuan\n";

		//14.Đếm số từ trong chuỗi bất kỳ
		cout << "14. So tu co trong chuoi bat ky = " << DemTu(str) << endl;

		//15. Đếm số lượng kí tự nguyên âm trong chuỗi bất kỳ
		cout << "15. So luong ki tu nguyen am co trong chuoi bat ky = " << demnguyenam2(str) << endl; //demnguyenam 1 hay 2 đều dùng được hết
		
		//16. hàm viết hoa ký tự đầu mỗi từ, viết thường các ký tự'
		cout << "16. Chuoi sau khi viet hoa dau tu la: ";
		hoadautu(str);
		
		//17. Hàm đảo ngược các thứ tự các từ trong chuỗi
		cout << "17. Chuoi sau khi dao nguoc cac tu la: ";
		daonguoctu(str);
		
		//18. Hàm đếm từ có 2 nguyên âm liền trong chuỗi 
		demtu2na(str);

		//19.Hàm strcat: ghép chuỗi nguồn vào sau chuỗi đích.
		char* strcat(char* dich, char* nguon);

		//20. Hàm strncpy: sao chép n kí tự đầu tiên của chuỗi nguồn vào chuỗi đích.
		char* strncpy(char* dich, char* nguon, int n);

		//21. Hàm strstr: trả về địa chỉ vị trí xuất hiện đầu tiên của chuỗi s1 trong chuỗi s và sẽ trả về giá trị NULL trong trường hợp không tìm thấy.
		char* strstr(char* s, char* s1);

		//22. Hàm strrchr:  trả về địa chỉ vị trí xuất hiện cuối cùng của kí tự ch trong chuỗi s.Nếu không tìm thấy hàm sẽ trả về giá trị NULL
		char* strrchr(char* s, char ch);

		

		cout << "Nhan ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}
