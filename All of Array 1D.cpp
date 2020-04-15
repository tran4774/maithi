#include <iostream>				//một số thư viện thường dùng
#include <conio.h>				//_getch...
#include <math.h>				//sqrt,...
#include <time.h>
#include <stdlib.h>				//random,...
#include <string.h>				//xử lý chuỗi
using namespace std;

//1. Hàm nhập mảng 1D
void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu #" << i << ": ";
		cin >> a[i];
	}
}

//2. Hàm in mảng 1D
void inmang(int a[], int n)
{
	cout << "Mang vua nhap la:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

//3. In các số chẵn ra màn hình:
void incacsochan(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) cout << a[i] << " ";
	cout << endl;
}
//4. Tính tổng các ptử:
void tongptu(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++) tong += a[i];
	cout << "Tong cac phan tu cua mang = " << tong << endl;
}
//Kiểm tra số chính phương (scp)
bool ktsochinhphuong(int x)
{
	if (sqrt(x) == int(sqrt(x))) return true;
	return false;
}
//5. Tính tổng các số chính phương (nếu có):
void tongcp(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		if (ktsochinhphuong(a[i])) tong += a[i];
	cout << "Tong cac so chinh phuong trong mang = " << tong << endl;
}
//Hàm kiểm tra số nguyên tố
bool checkPrime(int x) {
	if (x < 2) return false;
	else if (x > 2) {
		if (x % 2 == 0) 
			return false;
		else {
			int t = sqrt(x);
			for (int i = 3; i <= t; i+=2)
				if (x % i == 0) 
					return false;
		}
	}
	return true;
}
//6. Tính tổng các số nguyên tố có trong mảng (nếu có):
void tongnguyento(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
		if (ktnguyento(a[i])) tong += a[i];
	cout << "Tong cac so nguyen to trong mang = " << tong << endl;
}
//7. Đếm số lượng số âm có trong mảng (nếu có):
void demsoam(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0) dem++;
	cout << "So luong so am co trong mang = " << dem << endl;
}
//8. Tìm max, min và vị trí của nó:
//Tìm max
void timmax(int a[], int n)
{
	int vt = 0;
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
		{
			max = a[i];
			vt = i;
		}
	cout << "MAX = " << max << " va nam o vi tri #" << vt << endl;
}
//Tìm min
void timmin(int a[], int n)
{
	int vt = 0;
	int min = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < min)
		{
			min = a[i];
			vt = i;
		}
	cout << "MIN = " << min << " va nam o vi tri #" << vt << endl;
}
//9. Tìm số chẵn lớn nhất (nếu có):
void maxchan(int a[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			max = a[i];
			for (int j = 0; j < n; j++)
				if (a[j] > max&& a[j] % 2 == 0) max = a[j];
		}
	}
	if (max == 0) cout << "Mang ko co so chan\n";
	else cout << "Max chan = " << max << endl;
}
//10. Tìm số chính phương nhỏ nhất (nếu có):
void mincp(int a[], int n)
{
	int min = 0;
	for (int i = 0; i < n; i++)
		if (ktsochinhphuong(a[i]))
		{
			min = a[i];
			for (int j = 0; j < n; j++)
				if (ktsochinhphuong(a[j]) && a[j] < min) min = a[j];
		}
	if (min == 0) cout << "Mang ko co so chinh phuong\n";
	cout << "Min so chinh phuong = " << min << endl;
}
//11. Tìm số có tổng các chữ số lớn nhất và vị trị của nó:
//Hàm tìm tổng chữ số
int tongchuso(int x)
{
	int dem = 0;
	while (x > 0)
	{
		int t = x % 10;
		dem += t;
		x = x / 10;
	}
	return dem;
}
//Hàm tính số có tổng chữ số max
void tongchusomax(int a[], int n)
{
	int vt = 0;
	int max = tongchuso(a[0]);
	for (int i = 0; i < n; i++)
		if (tongchuso(a[i] > max))
		{
			max = tongchuso(a[i]);
			vt = i;
		}
	cout << "So co tong cac chu so lon nhat la: " << max << " va o vi tri #" << vt << endl;
}
//12. Kiểm tra xem mảng có tăng dần/ giảm dần hay ko:
bool ktmangtangdan(int a[], int n)
{

	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1]) 
			return false;
	return true;
}

bool ktmanggiamdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] < a[i + 1]) 
			return false;
	return true;
}
//13. Kiểm tra xem mảng có đối xứng hay ko:
bool ktmangdoixung(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
		if (a[i] != a[n - 1 - i]) 
			return false;
	return true;
}
//14. Kiểm tra các số chẵn trong mảng có tăng dần hay ko:
bool ktchantangdan(int a[], int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
			for (int j = i + 1; j < n; j++)
				if (a[j] % 2 == 0 && a[j] < a[i]) 
					return false;
	return true;
}
//15. Kiểm tra tính chất chẵn lẻ xen kẽ:
bool ktchanlexenke(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 == 0 && a[i + 1] % 2 == 0 || a[i] % 2 != 0 && a[i + 1] % 2 != 0)
			return false;
	return true;
}
//16. Kiểm tra tính chất âm dương xen kẽ
bool ktamduongxenke(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == 0) return false;
		else if (a[i] > 0 && a[i + 1] > 0 || a[i] < 0 && a[i + 1] < 0) return false;
	}
	return true;
}
//17. Kiểm tra xem mảng có lập thành cấp số cộng ko:
bool ktcapsocong(int a[], int n)
{
	for (int i = 0; i < n - 2; i++)
		if (a[i + 1] - a[i] != a[i + 2] - a[i + 1]) return false;
	return true;
}
//18. Sắp xếp mảng tăng dần/ giảm dần:
void sxmangtangdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	cout << "Mang sau khi sap xep tang dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void sxmanggiamdan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	cout << "Mang sau khi sap xep giam dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//19. Sắp xếp chẵn tăng dần, lẻ giảm dần:
void sxchantanglegiam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 == 0)
			for (int j = i + 1; j < n; j++)
				if (a[i] > a[j] && a[j] % 2 == 0)
				{
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
	for (int i = 0; i < n - 1; i++)
		if (a[i] % 2 != 0)
			for (int j = i + 1; j < n; j++)
				if (a[i] < a[j] && a[j] % 2 != 0)
				{
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}

	cout << "Mang sau khi sap xep chan tang dan, le giam dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//20. Sắp xếp mảng sao cho các số chẵn về đầu mảng tăng dần, các số lẻ về cuối giảm dần :
void sxchandautanglesaugiam(int a[], int n)
{
	int k, min, j, t;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
		{
			k = i;
			for (j = 0; j < n; j++)
			{
				t = a[k];
				a[k] = a[j];
				a[j] = t;
			}
			i--;
		}

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			min = i;
			for (j = i + 1; j < n; j++)
				if (a[min] > a[j] && a[j] % 2 == 0) min = j;
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
		else
		{
			min = i;
			for (j = i + 1; j < n; j++)
				if (a[min] < a[j] && a[j] % 2 != 0) min = j;
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
	cout << "Mang chan ve dau mang tang dan va le ve sau mang giam dan\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//21. Xoá phần tử tại vị trí k:
//Xoá phần tử
void xoapt(int a[], int& n, int vt)
{
	for (int i = vt + 1; i < n; i++)
		a[i - 1] = a[i];
	a[n - 1] = 0;
	n--;
}
//Xoá phần tử tại vị trí k
void xoapttaivtk(int a[], int n, int k)
{
	for (int i = k + 1; i < n; i++)
		a[i - 1] = a[i];
	n--;
	cout << "Mang sau khi xoa phan tu tai vi tri #" << k << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//22. Xoá tất cả các giá trị x ra khỏi mảng:
void xoatatcacacgtx(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			for (int j = i + 1; j < n; j++)
			{
				a[j - 1] = a[j];
			}
			a[n - 1] = 0;
			n--;
		}
	}

	cout << "Mang sau khi xoa cac phan tu = " << x << " khoi mang\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//23. Xoá tất cả số nguyên tố ra khỏi mảng:
void xoatatcasongto(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (ktnguyento(a[i]))
		{
			xoapt(a, n, i);
			i--;
		}
	}

	cout << "Mang sau khi xoa cac so nguyen to\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//24. Xoá tất cả các phần tử trùng nhau:
void xoatatcaccacpttrungnhau(int a[], int& n)
{

	int dem;
	for (int i = 0; i < n - 1; i++)                                                //vòng lặp duyệt từng phần tử của mảng a[i], để n-1 vì phần tử cuối cùng chắc chắn đã phân biệt, không cần kiểm tra
	{
		dem = 0;
		for (int j = i + 1; j < n; j++)                                        //vòng lặp duyệt các phần tử đứng sau a[i]
		{
			if (a[j] == a[i])                                                     //trường hợp có phần tử a[j] trùng với a[i] thì xóa phần tử tại vị trí j
			{
				xoapt(a, n, j);
				j--;
				dem = 1;
			}
		}
		if (dem == 1) xoapt(a, n, i);

	}

	cout << "Mang sau khi xoa cac pt trung nhau\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

}
//25. Xoá tất cả các ptử trùng chỉ chừa lại 1 ptử làm đại diện:
void xoacacpttrungnhauchualai1pt(int a[], int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				xoapt(a, n, j);
				i--;
			}
		}
	}

	cout << "Mang sau khi xoa cac pt trung nhau chi chua lai 1 pt lam dai dien\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//26. Chèn giá trị x vào vị trí k trong mảng:
void chengtxvaovtk(int a[], int& n, int x, int k)
{
	for (int i = n; i >= k; i--)
		a[i] = a[i - 1];
	a[k] = x;
	n++;
	cout << "Mang sau khi chen gia tri " << x << " tai vi tri #" << k << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//27. Chèn x vảo mảng có thứ tự giảm dần sao cho kq cũng có thứ tự giảm dần:
void chengtxvasapxepgiamdan(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < x)
		{
			for (int j = n; j > i; j--)
				a[j] = a[j - 1];
			a[i] = x;
			break;
		}
		else a[n] = x;
	}
	cout << "Mang sau khi chen gia tri " << x << " va sap xep giam dan\n";
	for (int i = 0; i < n + 1; i++)
		cout << a[i] << " ";
	cout << endl;

}
//28. Tách mảng thành 2 mảng gốm 1 mảng chẵn và 1 mảng lẽ:
void tachmangchanle(int a[], int n)
{
	int chan[100], le[100];
	int m = 0;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			chan[m] = a[i];
			m++;
		}
		else
		{
			le[p] = a[i];
			p++;
		}
	}
	cout << "Mang chan la: ";
	for (int i = 0; i < m; i++)
		cout << chan[i] << " ";
	cout << endl;
	cout << "Mang le la: ";
	for (int j = 0; j < p; j++)
		cout << le[j] << " ";
	cout << endl;
}
//29. Tạo mảng gồm các số chính phương có trong mảng ban đầu:
void taomangcp(int a[], int n)
{
	int cp[100];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (ktsochinhphuong(a[i]))
		{
			cp[k] = a[i];
			k++;
		}
	}
	cout << "Mang gom cac so chinh phuong la: ";
	for (int i = 0; i < k; i++)
		cout << cp[i] << " ";
	cout << endl;
}
//30. Trộn 2 mảng (a,m) và (b,n) có thứ tự tăng để tạo mảng (c,m+n) cũng có thứ tự tăng dần
void gopmang(int a[], int n, int b[], int m, int c[], int& p)
{
	p = n + m;
	for (int i = 0; i < p; i++)
	{
		if (i < n) c[i] = a[i];
		else c[i] = b[i - n];
	}
}
//31. Hàm kiểm tra số Fibonacci
//Mảng chứa các số Fibonacci
unsigned long long int fibonacci[100];
void fibo() {
	fibonacci[0] = 1;
	fibonacci[1] = 1;
	for (int i = 2; i < 100; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
}
//Hàm kiểm tra 1 số có nằm trong dãy Fibonacci hay không
bool checkfibo(int n) {
	fibo();
	int i = 0;
	while (fibonacci[i] <= n) {
		i++;
		if (fibonacci[i] == n)
			return true;
	}
	return false;
}
//32.
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
			dem01 = 0;
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
					xoatatcacacgtx(a, n, a[i]);
					//j-- tức là số lượng các phần tử giảm dần đi mỗi lần xóa
					j--;
					//dem phải =0 để sau khi xóa một tổ hợp các phần tử trùng nhau trong mảng, phòng trường hợp có một tổ hợp khác cũng cùng trùng nhau vs 1 giá trị khác nữa, thao tác được lặp lại
					dem = 0;
				}
			}
		}
	}
	inmang(a, n);
}
//33. Hàm kiểm tra số hoàn hảo (số hoàn thiện)
bool check(int n) {
	int sum = 0;//khai bao biem sum
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0)
			sum += i;
	}
	if (sum == n) return true; // tra ve true
	return false;
}


int main()
{
	int a[100];
	int n;
	int k1, x1;
	int k2, x2;
	int x;
	do
	{
		cout << "Nhap so phan tu cua mang (n>0): "; cin >> n;
		nhapmang(a, n);
		inmang(a, n);
		/*
		// in các số chẵn ra màn hình:
		cout << "Cac so chan trong mang la: ";
		incacsochan(a, n);
		// tính tổng các ptử:
		tongptu(a, n);
		// tính tổng các số chính phương (nếu có):
		tongcp(a, n);
		// tính tổng các số nguyên tố có trong mảng (nếu có):
		tongnguyento(a, n);
		// đếm số lượng số âm có trong mảng (nếu có):
		demsoam(a, n);
		// tìm max, min và vị trí của nó:
		timmax(a, n);
		timmin(a, n);
		// tìm số chẵn lớn nhất (nếu có):
		maxchan(a, n);
		// tìm số chính phương nhỏ nhất (nếu có):
		mincp(a, n);
		// tìm số có tổng các chữ số lớn nhất và vị trị của nó:
		tongchusomax(a, n);
		// kiểm tra xem mảng có tăng dần/ giảm dần hay ko:
		if (ktmangtangdan(a, n)) cout << "Mang tang dan\n";
		else cout << "Mang ko tang dan\n";
		if (ktmanggiamdan(a, n)) cout << "Mang giam dan\n";
		else cout << "Mang ko giam dan\n";
		// kiểm tra xem mảng có đối xứng hay ko:
		if (ktmangdoixung(a, n)) cout << "Mang doi xung\n";
		else cout << "Mang ko doi xung\n";
		// kiểm tra các số chẵn trong mảng có tăng dần hay ko:
		if (ktchantangdan(a, n)) cout << "Mang co cac so chan tang dan\n";
		else cout << "Cac so chan trong mang ko tang dan\n";
		// kiểm tra tính chất chẵn lẻ xen kẽ:
		if (ktchanlexenke(a, n)) cout << "Mang co tinh chat chan le xen ke\n";
		else cout << "Mang ko co tinh chat chan le xen ke\n";
		// kiểm tra tính chất âm dương xen kẽ
		if (ktamduongxenke(a, n)) cout << "Mang co tinh chat am duong xen ke\n";
		else cout << "Mang ko co tinh chat am duong xen ke\n";

		// kiểm tra xem mảng có lập thành cấp số cộng ko:
		if (ktcapsocong(a, n)) cout << "Mang la cap so cong\n";
		else cout << "Mang ko lap dc thanh cap so cong\n";

		// sắp xếp mảng tăng dần/ giảm dần:
		sxmangtangdan(a, n);
		sxmanggiamdan(a, n);
		// sắp xếp chẵn tăng dần, lẻ giảm dần:
		sxchantanglegiam(a, n);
		// sắp xếp mảng sao cho các số chẵn về đầu mảng tăng dần, các số lẻ về cuối giảm dần:
		sxchandautanglesaugiam(a, n);
		// xoá phần tử tại vị trí k:
		cout << "Nhap vi tri k ban muon xoa = "; cin >> k1;
		xoapttaivtk(a, n, k1);

		// xoá tất cả các giá trị x ra khỏi mảng:
		cout << "Nhap gia tri x ma ban muon xoa khoi mang = "; cin >> x1;
		xoatatcacacgtx(a, n, x1);

		// xoá tất cả số nguyên tố ra khỏi mảng:
		xoatatcasongto(a, n);
		// xoá tất cả các phần tử trùng nhau:
		xoatatcaccacpttrungnhau(a, n);
		// xoá tất cả các ptử trùng chỉ chừa lại 1 ptử làm đại diện:
		xoacacpttrungnhauchualai1pt(a, n);
		// chèn giá trị x vào vị trí k trong mảng:
		cout << "Nhap gia tri x ban muon chen = "; cin >> x2;
		cout << "Nhap vi tri k ma ban muon chen gia tri x vao = "; cin >> k2;
		chengtxvaovtk(a, n, x2, k2);
		// chèn x vảo mảng có thứ tự giảm dần sao cho kq cũng có thứ tự giảm dần:
		cout << "Nhap gia tri x can chen = "; cin >> x;
		chengtxvasapxepgiamdan(a, n, x);
		// tách mảng thành 2 mảng gốm 1 mảng chẵn và 1 mảng lẽ:
		tachmangchanle(a, n);
		// tạo mảng gồm các số chính phương có trong mảng ban đầu:
		taomangcp(a, n);
		// trộn 2 mảng (a,m) và (b,n) có thứ tự tăng để tạo mảng (c,m+n) cũng có thứ tự tăng dần
		{
			int a[100];
			int b[100];
			int c[200];
			int m, n;
			int k;
			cout << "Nhap so phan tu cua mang (a, n) = "; cin >> n;
			nhapmang(a, n);
			inmang(a, n);
			cout << "Nhap so phan tu cua mang (b, m) = "; cin >> m;
			nhapmang(b, m);
			inmang(b, m);
			gopmang(a, n, b, m, c, k);
			sxmangtangdan(c, k);
		}*/



		cout << "Nhan ESC de thoat...\n";
	} while (_getch() != 27);
	return 0;
}