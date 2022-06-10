#include <iostream>
using namespace std;
class CMyClassA {
		int val;
	public:
		CMyClassA(int);
		void virtual print();
};
CMyClassA::CMyClassA(int arg) {
	val = arg;
	printf("A:%d\n", val);
}
void CMyClassA::print() {
	printf("%d\n", val);
	return;
}
// 在此处补充你的代码
class CMyClassB:public CMyClassA {
	public:
		int val;
		CMyClassB(int _val):CMyClassA(3*_val) {//乘三即可
			val=_val;
			printf("B:%d\n", val);
		}
		void virtual print() {
			printf("%d\n", val);
		}
};
// 在此处补充你的代码
//A:3
//A:15
//B:5
//3
//15
//5
int main(int argc, char** argv) {
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a;
	ptr->print();
	a = b;
	a.print();
	ptr = &b;
	ptr->print();
	return 0;
}