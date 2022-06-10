#include <iostream>
using namespace std;

class A {
	public:
		int n;
		A(int m):n(m) {}
		virtual void Do() {
			cout <<"A::Do()" << n << endl;
			Fun();
		}
// 在此处补充你的代码
		virtual void Fun() {
			cout<<"A::Fun()"<<++n<<endl;
		}
// 在此处补充你的代码
		void CallFun() {
			Fun();
		}
};

class B: public A {
	public:
		B(int n):A(n) { }
		void Do() {
			cout <<"B::Do()" << ++n << endl;
			CallFun();
		}
		void Fun() {
			cout <<"B::Fun()" << ++n << endl;
		}
};

int main() {
	B bb(1);
	A aa = bb;
	aa.Do();
	A *bp = &bb;
	bp->Do();
	return 0;
}