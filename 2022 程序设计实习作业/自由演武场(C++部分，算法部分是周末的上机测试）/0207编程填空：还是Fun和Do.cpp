#include <iostream>
using namespace std;

class A {
	public:
		virtual void Fun() {
			cout << "A::Fun" << endl;
		};
		virtual void Do() {
			cout << "A::Do" << endl;
		}
};
// 在此处补充你的代码
class B :public A {
	public://不用B::Fun就不会输出B::Fun了
		/*void Fun() {
			cout << "B::Fun" << endl;
		};*/
		void Do() {
			cout << "B::Do" << endl;
		}
};
class C :public B {
	public:
		virtual void Fun() {
			cout << "C::Fun" << endl;
		};
		virtual void Do() {
			cout << "C::Do" << endl;
		}
};
void Call1(B& p)//多态除了使用基类指针，也可以用基类引用触发
// 在此处补充你的代码
{
	p.Fun();
	p.Do();
}

void Call2(B p) {
	p.Fun();
	p.Do();
}



int main() {
	C c;
	B b;
	Call1(b);
	Call1(c);
	Call2(c);
	return 0;
}