#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
	// 在此处补充你的代码
	T*p1,T*p2)
{
	p2--;
	T* ans = p1;//无法初始化就用第一个初始化
	for (T* i = ++p1; i <= p2; i++)
		*ans += *i;
	return *ans;
	// 在此处补充你的代码
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John" };
	cout << SumArray(array, array + 4) << endl;
	int a[4] = { 1, 2, 3, 4 };  //提示：1+2+3+4 = 10
	cout << SumArray(a, a + 4) << endl;
	return 0;
}
