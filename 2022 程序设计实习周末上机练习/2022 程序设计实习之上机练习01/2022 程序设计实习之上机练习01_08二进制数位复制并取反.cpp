#include <iostream>
using namespace std;

int f(int n, int m, int i) {//将m第i位的反赋值给n的第i位
	return (m >> i & 1) == 0 ? n | (1 << i) : n & (~(1 << i));
}

int main() {
	int a, b, i, j;
	cin >> a >> b >> i >> j;
	for (int k = i; k <= j; k++) {
		a = f(a, b, k);
	}
	cout << a;
}