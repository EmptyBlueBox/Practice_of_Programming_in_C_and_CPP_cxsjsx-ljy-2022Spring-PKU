#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//在此处补充你的代码
template<class T, class Pred>
void MyForeach(T* p1, T* p2, Pred* pf)//函数指针要用另一个类模板，如sort(,,,_Pr _Pred),_Pr为新的template
{
	for (T* i = p1; i < p2; i++)
		pf(*i);
}
// 在此处补充你的代码
void Print(string s)
{
	cout << s;
}
void Inc(int& n)
{
	++n;
}
int a[100];
int main() {
	string array[100];
	int m, n;
	while (cin >> m >> n) {
		for (int i = 0; i < m; ++i)
			cin >> array[i];
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(array, array + m, Print);
		cout << endl;
		MyForeach(a, a + n, Inc);
		for (int i = 0; i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}
