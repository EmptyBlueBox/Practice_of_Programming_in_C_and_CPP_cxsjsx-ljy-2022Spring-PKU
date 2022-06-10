#include <iostream> 
using namespace std;
class MyInt
{
	int nVal;
public:
	MyInt(int n) { nVal = n; }
	// 在此处补充你的代码

	MyInt& operator-(int m)
	{
		nVal -= m;
		return *this;
	}
	friend int Inc(MyInt a)//friend可将class内函数变为全局函数
	{
		return a.nVal + 1;
	}

	// 在此处补充你的代码
};
int Inc(int n) {
	return n + 1;
}
int main() {
	int n;
	while (cin >> n) {
		MyInt objInt(n);
		objInt - 2 - 1 - 3;
		cout << Inc(objInt);
		cout << ",";
		objInt - 2 - 1;
		cout << Inc(objInt) << endl;
	}
	return 0;
}
