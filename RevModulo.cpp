#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;
#include <math.h>
#include <stdio.h>
#include <ctype.h>



int revmodulo(long long n, int m);
int main() {
	long long n;
	int m;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap m: ";
	cin >> m;
	int start = clock();
	int mod = revmodulo(n, m);
	cout << mod << endl;
	cout << clock() - start << " ms" << endl;
	return 0;
}
int revmodulo(long long k, int m) {
	if (k % m == 1)
		return 1;
	long long  k2 = k, m2 = m;
	int a1 = 1, a2 = 0, a3;
	int r = k2 % m2;
	while (r > 1) {
		a3 = a1 - (a2 * int(k2 / m2));
		r = k2 % m2;
		k2 = m2;
		m2 = r;
		a1 = a2;
		a2 = a3;
	}
	if (r != 1)
		return -1;
	while (a2 < 0) 
		a2 += m;
	return a2;
	/*vector<long long> x = { k, m };
	vector<int> a = { 1, 0 };
	vector<int> b = { 0, 1 };
	vector<int> y = { 0 };
	int i = 1;
	while (x[i] > 1) {
		y.push_back(x[i - 1] / x[i]);
		i++;
		x.push_back(x[i - 2] % x[i - 1]);
		a.push_back(a[i - 2] - (a[i - 1] * y[i - 1]));
		b.push_back(b[i - 2] - (b[i - 1] * y[i - 1]));
	}
	while (*(a.end() - 1) < 0) *(a.end() - 1) += m;
	return *(a.end() - 1);*/
}