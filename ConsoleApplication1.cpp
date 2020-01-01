// Mảng hai chiều.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Thao tác: Kiểm tra xem ma trận a có tăng dần từ trái sang phải từ trên xuống dưới hay không.
=> Quy về bài toán kiểm tra xem mảng 1 chiều (arr,n) có theo thứ tự tăng dần hay không.
=> Bài toán quy các phần tử của mảng hai chiều đứng thành 1 hàng trong mảng 1 chiều rồi xét lần lượt từ trái sang phải.
=> Quy từ ma trận a về mảng 1 chiều (arr,n); kiểm tra xem mảng 1 chiều (arr,n) có theo thứ tự tăng dần hay không.
*/
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;
#define MAX 20                                         //hằng số chỉ kích thước của ma trận

int main()
{
    //Khai báo biến cục bộ (mảng 2 chiều) 
    int a[MAX][MAX];                                    //ma trận kích thước MAX x MAX
    int d;                                              //số hàng thực tế sử dụng
    int c;                                              //số cột thực tế sử dụng
    int i, j;                                           //i,j là các biến chạy
    do
    {
        //B1.Nhập kích thước thực tế của ma trận
        cout << "Nhap so dong:= ";
        cin >> d;
        cout << "Nhap so cot:= ";
        cin >> c;
        //Thao tác 1: Nhập ma trận
        //Lần lượt duyệt qua hết tất cả các ô của ma trận đó 
        for (int i = 0; i < d; i++)             //Hai vòng lặp nằm lồng vào nhau; chỉ có 1 vòng lặp này nằm trong 1 vòng lặp kia nên ko cần dùng dấu ngoặc
            for (int j = 0; j < c; j++)
            {
                cout << "a[" << i << "][" << j << "] = ";                     // câu nhắc để xác định đang nhập tới cột bao nhiêu, dòng bao nhiêu
                cin >> a[i][j];
            }
        //Thao tác 2: Xuất ma trận
        cout << "Ma tran vua nhap la: \n";
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout.width(5);                         //đặt kích thước tối thiểu = 5
                cout << a[i][j];
            }

            cout << endl;
        }
        //B1: Nối các dòng của mảng hai chiều (ma trận a) thành 1 dòng để tạo mảng 1 chiều arr có kích thước dxc
        int arr[MAX * MAX];
        int n = 0;                                           //n là tổng số phần tử của mảng 1 chiều sau khi nối, có giá trị lúc đầu =0
        for (int i = 0; i < d; i++)
            for (int j = 0; j < c; j++)
                arr[n++] = a[i][j];                          //lưu ý: ta phải để n++ để tăng số lượng phần tử của mảng lên, vì lúc đầu chưa xác định được số lượng cụ thể nên phải để giá trị ban đầu =0 rồi cứ thế tăng dần lên
         //B2: Kiểm tra xem các phần tử có tăng dần hay không
        int check = 1;                                       //biến cờ hiệu để kiểm tra
        for (int i = 0; i < n - 1; i++)                              //xét tới vị trí kế cuối, không xét vị trí cuối
            if (arr[i] > arr[i + 1])
            {
                check = 0;                                   //ghi nhận vi phạm
                break;
            }
        if (check) cout << "Ma tran tang dan tu trai sang phai, tu tren xuong duoi \n";
        else cout << "Ma tran khong thoa yeu cau de bai \n";



    } while (_getch() != 27);
    return 0;
}

