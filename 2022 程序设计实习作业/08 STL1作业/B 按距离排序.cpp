#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
template <class T1, class T2>
struct Closer {
	// 在此处补充你的代码
	T1 n;
	T2 f;//T2是函数指针 int (*)(int, int)
	Closer(T1 n0, T2 f0) :n(n0), f(f0) {};
	bool operator()(T1 x, T1 y)
	{
		int d1 = f(x, n), d2 = f(y, n);
		if (d1 == d2)
			return x < y;
		else
			return d1 < d2;
	}
	// 在此处补充你的代码
};

int Distance1(int n1, int n2) {
	return abs(n1 - n2);
}
int Distance2(const string& s1, const string& s2)
{
	return abs((int)s1.length() - (int)s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15 };
string b[6] = { "American","Jack","To","Peking","abcdefghijklmnop","123456789" };
int main()
{
	int n; string s;
	while (cin >> n >> s) {
		sort(a, a + 10, Closer<int, int (*)(int, int)>(n, Distance1));//比较函数是一个Closer对象，想要让这个对象跟函数一样能接受两个参数，可以重载括号
		for (int i = 0; i < 10; ++i)
			cout << a[i] << ",";
		cout << endl;
		sort(b, b + 6, Closer<string, int (*)(const string&, const string&)>(s, Distance2));
		for (int i = 0; i < 6; ++i)
			cout << b[i] << ",";
		cout << endl;
	}
	return 0;
}
