#include <iostream>
using namespace std;
class A {
public:
	int val;
//
	A(int x = 123)
	{
		val = x;
	}
	A& GetObj()
	{
		return *this;
	}
  //
};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}
