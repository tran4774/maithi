/* Xóa các phần tử trùng nhau từ 3 lần trở lên ra khỏi mảng, 2 lần giữ nguyên.
 Ngày viết: 30/12/2019
 Ngày cập nhật: 30/12/2019
 Phương pháp xử lý:
 Dùng 1 hàm xóa vị trí cần xóa
 Dùng 1 hàm xóa một giá trị cần xóa 
 Dùng 1 hàm để kiểm tra trường hợp trùng nhau 3 lần trở lên có xuất hiện
 Dùng 1 hàm xóa phần tử trùng nhau 3 lần trở lên bằng cách thực hiện thao tác đếm số lần trùng nhau rồi xóa chính giá trị tại vị trí đó nếu số lần trùng nhau 
 vượt quá giới hạn cho phép
 VD: 1 1 1 2 2 3 3 3, biến đếm đếm có 3 lần trùng nhau vs 1 1 1 do đó thực hiện thao tác xóa các vị trí nào miễn có giá trị bằng với 1 (nguyên nhân chính dẫn
 đến việc phải viết hai hàm xóa tại vị trí cần xóa và giá trị cần xóa riêng biệt); 2 2 thì số lần trùng nhau chưa vượt quá giới hạn cho phép; 3 3 3 thì giống như
 thao tác với 1 1 1 miễn có vị trí nào trong mảng bằng 3 thì xóa 
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;
void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Moi nhap phan tu thu #" << i << ":" << " ";
        cin >> a[i];
    }
}
void XuatMang(int a[], int n)
{
    cout << "Mang vua nhap la: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
//Xóa phần tử tại vị trí k

void xoaphantutaivitrik(int a[], int& n, int k)
{
    //k là vị trí bất kỳ cần xóa
    for (int i = k; i < n; i++)
        a[i] = a[i + 1];
    n--;
}

void xoaphantux(int a[], int& n, int x)
{
    //x là phần tử cần xóa trong mảng, muốn xóa x thì phải xóa vị trí tại x đó chính là i nếu giá trị a[i] = x
    for (int i = 0; i < n;)
        if (a[i] == x)
        {
            xoaphantutaivitrik(a, n, i);
        }
        else i++;
}
//Hàm để kiểm tra xem có bao nhiêu phần tử trùng nhau 3 lần trở lên trong mảng
int sophantutrungnhau3lan(int a[], int n)                         
{
    //biến đếm dem01 được dùng để đếm nếu có phần tử trùng nhau trong mảng
    int dem01 = 0; 
    //biến đếm dem02 được dùng để đếm nếu dem01 lớn hơn hoặc bằng hai tức là có hơn 2 cặp số trùng nhau đồng nghĩa với có 3 số trùng nhau (so sánh 3 số thì có hai cặp)
    int dem02 = 0;                                                             
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if (a[i] == a[j]) 
                dem01++;
        if (dem01 >= 2)
        {
            dem02++;
            dem01=0;
            //lý do dem01 phải trả về giá trị 0 để nếu có trường hợp tiếp túc trùng nhau thì có thể xử lý được nữa
        }
    }
    return dem02;
}
void xoatrungnhau3lan(int a[], int& n)
{
    int i, j;
    int dem = 0;
    //Xử lý cho đến khi nào không còn phát hiện trường hợp trùng nhau từ 3 lần trở lên nữa
    while (sophantutrungnhau3lan(a, n) != 0)
    {
        for (i = 0; i < n; i++)
        {
           for (j = i + 1; j < n; j++)
           {
                if (a[i] == a[j])
                {
                    dem++;
                }
                //Nếu đã phát hiện được 2 cặp số trùng nhau trở lên , tức là 3 số trùng nhau ở lên dù chúng nằm liền kề hay không liền kề, thì thực hiện tiếp thao tác xóa
                if (dem >= 2)
                {
                    //Xóa các vị trí trùng nhau phát hiện được
                    xoaphantux(a, n, a[i]);
                    //j-- tức là số lượng các phần tử giảm dần đi mỗi lần xóa
                    j--;
                    //dem phải =0 để sau khi xóa một tổ hợp các phần tử trùng nhau trong mảng, phòng trường hợp có một tổ hợp khác cũng cùng trùng nhau vs 1 giá trị khác nữa, thao tác được lặp lại
                    dem = 0;
                }
            }
        }
    }
    XuatMang(a, n);
}
int main()
{
    int n; int a[100];
    do
    {
        cout << "Moi nhap so phan tu cua mang:= "; cin >> n;
        NhapMang(a, n);
        XuatMang(a, n);
        cout << "Mang sau khi xoa cac phan tu trung nhau la: ";
        xoatrungnhau3lan(a, n);
    } 
    while (_getch() != 27);
    return 0;
}

