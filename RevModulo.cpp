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



int revmodulo(int n, int m);
int main() {
	int n, m;
	cout << "Nhap n: ";
	cin >> n;
	//cout << "Nhap m: ";
	//cin >> m;
	int start = clock();
	cout << revmodulo(n, 1000000007) << endl;
	cout << clock() - start << " ms" << endl;
	return 0;
}
int revmodulo(int k, int m) {
	if (k == 1)
		return k;
	vector<int> x = { k, m };
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
	return *(a.end() - 1);
}