#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	map<int, int>a;
	map<int, int>::iterator p1, p2;
	a[1000000000] = 1;
	int n, i, tmpno, tmp;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> tmpno >> tmp;
		cout << tmpno << " ";
		p1 = a.upper_bound(tmp);
		p2 = a.upper_bound(tmp);
		if (p1 == a.begin())
			goto flag2;
		p1--;
		if (p2 == a.end())
			goto flag1;
		if (p1->first + p2->first >= 2 * tmp)
		{
		flag1:;
			cout << p1->second << endl;
		}
		else
		{
		flag2:;
			cout << p2->second << endl;
		}
		a[tmp] = tmpno;
	}
}
