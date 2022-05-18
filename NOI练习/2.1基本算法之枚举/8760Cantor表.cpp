#include <iostream>
using namespace std;

int main() {
	int n, p, q;
	cin >> n;
	for (int i = 1;; i++) {
		if (i * (i + 1) / 2 >= n && i * (i - 1) / 2 < n) { //找第n个分数在第几个对角线
			if (i % 2 == 0) {
				p = n - i * (i - 1) / 2;
				q = i + 1 - p;
			} else {
				q = n - i * (i - 1) / 2;
				p = i + 1 - q;
			}
			cout << p << '/' << q << endl;
			return 0;
		}
	}
}