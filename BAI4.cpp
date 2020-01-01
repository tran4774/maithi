#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
using namespace std;
int main()
{
    char str[50];
    
    do
    {
        cout << "Moi nhap chuoi: ";
        cin.getline(str, 50);
        cout << "Chuoi vua nhap la: ";
        cout << str << endl;
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
    while (_getch() != 27);
}


