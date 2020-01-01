/*
Sắp xếp
2. Ngày viết: 27/12/2019
3. Ngày cập nhật: 27/12/2019
//Thao tác 21: Sắp xếp mảng tăng dần
*/

#include <iostream>				//một số thư viện thường dùng
#include <conio.h>				//_getch...
#include <math.h>				//sqrt,...
#include <time.h>
#include <stdlib.h>				//random,...
#include <string.h>				//xử lý chuỗi
using namespace std;
int main()
{
	int a[100];
	int n;
	int i;

	do
	{
		//Nhập mảng
		cout << "Nhap so phan tu cua mang: "; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap so phan thu thu # " << i << ": ";
			cin >> a[i];
		}
		//Xuất mảng
		cout << "Mang vua nhap la: ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		//Thao tác 21: Sắp xếp mảng tăng dần
		//Đầu tiên, tìm số nhỏ nhất trong mảng, đưa về đứng ở đầu mảng, các phần tử còn lại giữ nguyên
		//Sau đó, ko xét tới phần tử đầu tiên nữa, thực hiện lại thao tác tìm và đẩy về đứng kế ptử đầu tiên đối với CHỈ các phần tử còn lại
		//Tiếp tục giữ nguyên hai phần tử vừa sắp xếp, ko xét tới nữa, thực hiện lại thao tác tìm và đẩy về đối với CHỈ các phần tử còn lại
		//Cứ thực hiện thao tác đó đến cuối mảng, sau (n-1) bước ta đã đẩy được (n-1) phần tử đứng về phía trước
		//Vì vậy, chỉ còn lại phần tử cuối thực chất không cần thiết xét nữa vì ở bước thứ (n-1) ta đã phải so sánh phần tử kế cuối và phần tử cuối 
		//Vì thế, sau (n-1) bước mảng đã được sắp xếp đúng thứ tự (LƯU Ý HẾT SỨC QUAN TRỌNG !!!)
		for (int i = 0; i < n - 1; i++)
		{
			//tìm min từ a[i] đến a[n-1]
			int min = a[i];
			int vtmin = i;
			//j là phần tử đứng sau phần tử i, duyệt j từ đầu đến cuối để không một bỏ sót một giá trị nào bé hơn giá trị đứng trước nó
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] < min)
				{
					// cập nhật lại giá trị nhỏ nhất và vị trí của giá trị đó
					min = a[j];
					vtmin = j;
				}
			}
			//đổi chỗ a[i] vs min
			//dùng t là biến tạm để lưu nhớ giá trị a[i] ban đầu, lúc sau a[i] (ptử đứng trước) sẽ được cập nhật thành a[vtmin] còn a[vtmin]
			//cũng được cập nhật thành a[i] ban đầu thông qua biến lưu nhớ t 
			int t = a[i];
			a[i] = a[vtmin];
			a[vtmin] = t;
		}
		cout << "Ket qua cua cach 1: \n";
		cout << "Mang vua sap xep theo thu tu tang dan la: ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		//Cách khác (Sử dụng phương pháp nghịch thế)
		//So sánh 1 phần tử đầu tiên bất kì với các phần tử đứng sau nó, nếu có phần tử nào bé hơn thì đổi lại ngay
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)                                 //xét các phần tử đứng đằng sau
				if (a[i] > a[j])                                    //Phát hiện nghịch thế
				{
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
		cout << "Ket qua cua cach 2 (su dung phuong phap nghich the): \n";
		cout << "Mang vua sap xep theo thu tu tang dan la: ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	} while (_getch() != 27);
	return 0;
}

