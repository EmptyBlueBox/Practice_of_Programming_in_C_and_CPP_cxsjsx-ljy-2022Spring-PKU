#include <iostream>
using namespace std;

bool f(int m, int n) {
	if (n > m) swap(m, n);
	if (n == 0)
		return false;
	else if (m * 1. / n >= 2)
		return true;
	else return !f(m - n, n);
}
int main() {
	int m, n;
	while (cin >> m >> n && m)
		cout << (f(m, n) ? "win\n" : "lose\n");//注意要求输出的不是YES OR NO！！！
}