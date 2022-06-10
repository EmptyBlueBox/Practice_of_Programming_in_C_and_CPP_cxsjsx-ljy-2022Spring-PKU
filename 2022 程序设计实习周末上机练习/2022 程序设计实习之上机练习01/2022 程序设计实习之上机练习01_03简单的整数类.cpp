#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum {
	public:
		char C;
		MyNum(char c='0'): C(c) {}
		// 在此处补充你的代码
		MyNum(int c) : C(c + '0') {}//类似巧妙使用类型转换构造函数，也可以巧妙使用类型转换构造函数
		operator int() {
			return C - '0';
		}
		// 在此处补充你的代码
};

int main() {
	char m,n;
	cin >> m >>  n;
	MyNum n1(m), n2(n);
	MyNum n3;
	n3 = n1*n2;
	cout << int(n3) << endl;
	return 0;
}