#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <class T>
class container {
	public:
		T a;
		container(T _a) :a(_a) {}
		T operator+(container<T> n) {
			return a + n.a + n.a;
		}
		T operator+(T n) {
			return a + n;
		}
};
// 在此处补充你的代码
int main() {
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
	container <int> a = n;
	container <int> b = m;
	cout<<a+b<<endl;
	cout<<a+m<<endl;
	container <string> sa = string(s1);
	container <string> sb = string(s2);
	cout<<sa+sb<<endl;
	cout<< sa + s2<<endl;
}