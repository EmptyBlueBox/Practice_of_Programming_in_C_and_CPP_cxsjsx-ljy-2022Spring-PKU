#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{
	int order, n;
	string tmp;
	multiset<int> a;
	set<int>vis;
	cin >> order;
	for (int i = 0; i < order; i++)
	{
		cin >> tmp;
		if (tmp == "add")
		{
			cin >> n;
			a.insert(n);
			vis.insert(n);
			cout << a.count(n) << endl;
		}
		else if (tmp == "del")
		{
			cin >> n;
			cout << a.count(n) << endl;
			a.erase(n);
		}
		else if (tmp == "ask")
		{
			cin >> n;
			if (vis.find(n) != vis.end())
			{
				cout << 1 << " ";
			}
			else
			{
				cout << 0 << " ";
			}
			cout << a.count(n) << endl;
		}
	}
}
