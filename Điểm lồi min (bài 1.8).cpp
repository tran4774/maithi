//Người viết: Nguyễn Phước Đăng
//MSSV: 19110189
//Câu 1.8 BT chương 2
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
using namespace std;
struct Data {
    int value;
    int x;
    int y;
};
void Nhapmang(int a[][MAX], int& d, int& c);
void checkdiemloi(int a[][MAX], int& d, int& c);
int main()
{
    int a[MAX][MAX], d, c;
    do
    {
        do
        {
            cin >> d; cin >> c;
            if (!((0 < d) && (0 < c) && (d < 100) && (c < 100)))
                cout << "Sai DK (0<dong,cot<100)!\n";
        } while (!((0 < d) && (0 < c) && (d < 100) && (c < 100)));
        Nhapmang(a, d, c);
        checkdiemloi(a, d, c);
    }
    while (_getch() != 27);
}
void Nhapmang(int a[][MAX], int& d, int& c)
{
    for (int i = 0; i < d+2; i++)
    {
        for (int j = 0; j < c+2; j++)
        {
           a[i][j] = 0;
        }
    }
    for (int i = 1; i < d + 1; i++)
    {
        for (int j = 1; j < c + 1; j++)
            cin >> a[i][j];
    }
    cout << "Mang vua nhap la: \n";
    for (int i = 1; i < d + 1; i++)
    {
        for (int j = 1; j < c + 1; j++)
        {
            cout.width(5);                         
            cout << a[i][j];
        }
        cout << endl;
    }
}

void checkdiemloi(int a[][MAX], int& d, int& c)
{
    Data arr[MAX * MAX];
    int n = -1;
    for (int j = 1; j < c + 1; j++)
        for (int i = 1; i < d + 1; i++)
            if ((a[i][j] > a[i][j - 1]) &&
                (a[i][j] > a[i][j + 1]) &&
                (a[i][j] > a[i - 1][j]) &&
                (a[i][j] > a[i + 1][j])) {
                n++;
                arr[n].value = a[i][j];
                arr[n].x = i - 1;
                arr[n].y = j - 1;
            }
    if (n == -1)
        cout << -1 << endl;
    else {
        int min = arr[0].value;
        int vt = 0;
        for (int i = 0; i <= n; i++)
        {
            if (arr[i].value < min)
            {
                min = arr[i].value;
                vt = i;
            }
        }
        cout << arr[vt].x << " " << arr[vt].y << endl;
    }
}

