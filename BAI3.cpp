/*
Đề NMLT 2018-19 câu 2
Bài 3: (2 điểm) Cho M là một mảng 2 chiều các số nguyên dương có kích thước dxc (d dòng và c cột).
Yêu cầu: Tính tổng các số lẻ của mỗi cột và cho biết cột có tổng các số lẻ lớn nhất bằng bao nhiêu?
Dữ liệu vào có cấu trúc như sau:
-	Dòng đầu tiên lần lượt là hai nguyên d, c (0<d, c<100).
-	d dòng tiếp theo, mỗi dòng là c số nguyên dương nhỏ hơn 100 (mỗi số cách nhau ít nhất một khoảng trắng) lần lượt là c phần tử của từng dòng tương ứng của ma trận.
Dữ liệu ra: Một số nguyên duy nhất cho biết giá trị tổng lớn nhất tìm được.
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

        do
        {
            cout << "Nhap so dong(0<d<100):= ";
            cin >> d;
            if (!((0 < d) && (d < 100))) cout << "Sai dieu kien !!! \n";
        } while (!((0 < d) && (d < 100)));
        do
        {
            cout << "Nhap so dong(0<c<100):= ";
            cin >> c;
            if (!((0 < c) && (c < 100))) cout << "Sai dieu kien !!! \n";
        } while (!((0 < c) && (c < 100)));
        //Thao tác 1: Nhập ma trận
        //Lần lượt duyệt qua hết tất cả các ô của ma trận đó 
        for (int i = 0; i < d; i++)             //Hai vòng lặp nằm lồng vào nhau; chỉ có 1 vòng lặp này nằm trong 1 vòng lặp kia nên ko cần dùng dấu ngoặc
            for (int j = 0; j < c; j++)
            {
                cout << "a[" << i << "][" << j << "] = ";                     // câu nhắc để xác định đang nhập tới cột bao nhiêu, dòng bao nhiêu
                cin >> a[i][j];
            }
        //Thao tác 2: Xuất ma trận
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout.width(5);                         //đặt kích thước tối thiểu = 5
                cout << a[i][j];
            }

            cout << endl;
        }
        //Tính tổng cột đầu                                                                //Tương tự với câu tìm cột có tổng lớn nhất trong mảng và in ra tổng đó nằm trong chuyên đề mảng 2 chiều phần
        int tongle = 0;           //tổng lẻ của 1 cột bất kỳ                               //1 số thao tác của mảng hai chiều
        int tong1;
        int cmax = 0;
        for (int i = 0; i < d; i++)
        {
            if ((a[i][0]) % 2 != 0)
                tongle += a[i][0];
            tong1 = tongle;       //ghi nhớ lại giá trị tổng lẻ của cột đầu tiên
        }
        cout << "Tổng lẻ của cột đầu tiên:= " << tongle << endl;
        //Duyệt các cột kế tiếp
        for (int j = 0; j < c; j++)
        {
            tongle = 0;           //do hiện tại giá trị tongle đang ghi nhớ giá trị tổng lẻ của cột đầu tiên nên 
            //để so sánh các cột tiếp theo, ta phải trả tongle về giá trị 0
            for (int i = 0; i < d; i++)
            //xét từng phần tử của mỗi cột
                if (a[i][j] % 2 != 0)
                    tongle += a[i][j];
            //sau khi đã tính được tổng lẻ của cột này xong, ta cần phải so sánh tổng lẻ đó với tổng lẻ của cột trước nó 
            //bằng cách so sánh tổng lẻ vừa mới tính với tổng lẻ đã ghi nhớ ở biến tong1 trước đó, nếu cái mới thỏa điều kiện
            //hơn cái cũ thì cập nhật lại
            if (tongle > tong1)
            {
                tong1 = tongle;
                //đồng thời cập nhật lại vị trí ngay tại cột đó
                cmax = j;
            }
        }
        cout << "Tong le lon nhat trong mang:= " << tong1 << endl; cout << "Cot cua tong le max la:= " << cmax << endl;
    } while (_getch() != 27);
    return 0;
}

