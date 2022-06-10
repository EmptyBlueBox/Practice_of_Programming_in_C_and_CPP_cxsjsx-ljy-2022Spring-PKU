#include <iostream>
using namespace std;
// 在此处补充你的代码
class A {
	public:
		int a;
		A() {}
		A(int _a) :a(_a) {}
		operator int() {
			return a;
		}
		int get_value() {
			return a;
		}
		A operator+(A* p) {//实现A+A*
			return A(a + p->a);
		}
		A* operator->() {
			return this;
		}
};
class C :public A {
	public:
		C(int _a) :A(_a) {}
};
class B:public A {
	public:
		B(int _a) :A(_a) {}
};
// 在此处补充你的代码
int main() {
	int t;
	cin >> t;
	while (t--) {
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		A a(aa);
		B b(bb);
		C c(cc);
		A* x = &a;
		A* y = &b;
		A* z = &c;
		cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
		cout << ((*x) + y + z)->get_value() << endl;
	}
	return 0;
}