#include <cstdio>
#include <iostream>
using namespace std;

class f {
		// 在此处补充你的代码
	public:
		int a, b, ans;
		f(int _a) :a(_a) {}
		f(int _a, int _b) :a(_a), b(_b) {
			ans = a * b;
		}
		f operator()(int _b) {
			b = _b;
			ans = b - a;
			return *this;
		}
		operator int() {
			return ans;
		}
		// 在此处补充你的代码
};

int main() {
	cout << f(3)(5) << endl;
	cout << f(4)(10) << endl;
	cout << f(114)(514) << endl;
	cout << f(9,7) << endl;
	cout << f(2,3) << endl;
	cout << f(2,5) << endl;
}