#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
using namespace std;
//Hàm tính tổng (hoặc trung bình cộng) các số nguyên trong CHUỖI
double tongtrongchuoi(char str[]) {
	int len = strlen(str);
	int i = len - 1;
	int tong = 0, num = 0, dem = 0;
	while (i >= 0) {
		while (i >= 0 && !isdigit(str[i])) i--;
		num = 0;
		int hang = 1;
		while (i >= 0 && isdigit(str[i])) {
			num += hang * (str[i] - 48);
			hang *= 10;
			i--;
		}
		tong += num;
		dem++;                              //Tính tổng thì bỏ dòng này
	}
	return (double)tong / (double)dem;      //Tính tổng thỉ return tong;
}
//Hàm đếm từ có 2 nguyên âm liền trong chuỗi 
void demtu2na(char str[]) {
        char na[] = "AEIOUYaeiouy";
        int sotu01 = 0; int dem2 = 0;
        int len = strlen(str);
        if (len > 0)                                                //len > 0 tức là ko cần biết có bao nhiêu ký tự phải, chắc chắn là có 1 từ bất kỳ vì vậy sotu=1
        {
           for (int i = 0; i < len; i++)
            {
                if ((strchr(na, str[i]) != NULL) && (strchr(na, str[i+1]) != NULL))
                    sotu01++;
            }
           int dem = 0; 
           for (int i = 0; i < len; i++)
               if ((strchr(na, str[i]) != NULL) && (strchr(na, str[i + 1]) != NULL)&& (strchr(na, str[i + 1+1]) != NULL))
                   dem++;
           dem2 = sotu01 - dem;
        }
        cout << "So tu co chua it nhat hai nguyen am dung canh nhau trong mang la: "<<dem2 << endl;
}
int main()
{
    char str[50];
    
    do
    {
        cout << "Moi nhap chuoi: ";
        cin.getline(str, 50);
        cout << "Chuoi vua nhap la: ";
        cout << str << endl;

    } 
    while (_getch() != 27);
}


