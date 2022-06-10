#include <iostream>
using namespace std;

class A {
	public:
		// 在此处补充你的代码
		int n;
		A(int _n) :n(_n) {}
		int& getValue() {
			return n;
		}
		operator int() {
			return n;
		}
		A operator+=(A tmp) {
			n += tmp.n;
			return *this;
		}
		A operator-=(int tmp) {
			n -= tmp;
			return *this;
		}
		// 在此处补充你的代码
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, k;
		cin >> m >> n >> k;
		A a(m);
		A b = a;
		cout << b << endl;
		cout << (a += b -= n) << endl;
		cout << a.getValue() << endl;
		a.getValue() = k;
		cout << a << endl;
	}
	return 0;
}