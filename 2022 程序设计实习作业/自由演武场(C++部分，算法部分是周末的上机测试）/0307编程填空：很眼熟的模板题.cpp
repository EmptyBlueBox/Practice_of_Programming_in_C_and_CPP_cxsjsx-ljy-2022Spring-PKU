#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// 在此处补充你的代码
template<class T, int size>
class A {
	public:
		T* p;
		A(T* _p) :p(_p) {}
		template<class Tf>
		Tf sum(int a, int b, Tf (*f)(T)) {//重要！
			Tf ans = f(p[a]);
			for (int i = a + 1; i <= b; i++)
				ans = ans+ f(p[i]);
			return ans;
		}
};
// 在此处补充你的代码
string int2string(int x) {
	return to_string(x);
}
int int2squareint(int x) {
	return x * x;
}

int string2int(string str) {
	int res = 0;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
		res += *iter;
	return res;
}
string string2longerstring(string str) {
	return str + str;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		int b1[10];
		for (int i = 0; i < 10; ++i)

			cin >> b1[i];
		A<int, 10> a1 = b1;
		cout << a1.sum(2, 6, int2squareint) << endl;
		cout << a1.sum(2, 6, int2string) << endl;

		string b2[4];
		for (int i = 0; i < 4; ++i)
			cin >> b2[i];

		A<string, 4> a2 = b2;
		cout << a2.sum(0, 3, string2int) << endl;
		cout << a2.sum(0, 3, string2longerstring) << endl;
	}
	return 0;
}