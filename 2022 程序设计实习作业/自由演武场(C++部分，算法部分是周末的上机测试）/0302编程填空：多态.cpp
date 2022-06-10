#include <iostream>
using namespace std;

class Base {
	public:
		virtual Base& fun() {
			cout << "base fun" << endl;
			return *this;
		}
		virtual Base& foo() {
			cout << "base foo" << endl;
			return *this;
		}
};

class Derived: public Base {
	public:
		Base& fun() {
			cout << "derived fun" << endl;
			return *this;
		}
		Base& foo() {
			cout << "derived foo" << endl;
			return *this;
		}
};

Base& foo();
Base& fun();
// 在此处补充你的代码
Base& foo() {
	cout << "derived foo" << endl;
	Derived* p=new Derived;
	return *p;
}
Base& fun() {
	cout << "base fun" << endl;
	Base* p=new Base;
	return *p;
}
// 在此处补充你的代码
int main() {
	foo().fun().foo();
	fun().foo().fun();
	return 0;
}