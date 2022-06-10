#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main()
{
	int N, n;
	cin >> N;
	for (int k = 1; k <= N; k++)
	{
		cin >> n;
		string man, p, tmp;
		map<string, queue<string> >a;
		map<string, set<string> >c;
		for (int i = 0; i < n; i++)
		{
			char order;
			cin >> order;
			if (order == 'C')
			{
				cin >> man >> p;
				a[man].push(p);
				if (a[man].size() == 7)
				{
					tmp = a[man].front();//普通队列是front，优先队列是top
					a[man].pop();
					c[man].insert(tmp);
				}
			}
			else if (order == 'T')
			{
				cin >> man >> p;
				set<string>::iterator pp = c[man].find(p);
				if (pp != c[man].end())
				{
					cout << "Success\n";
					tmp = *pp;
					c[man].erase(tmp);
					a[man].push(tmp);
					if (a[man].size() == 7)
					{
						tmp = a[man].front();
						a[man].pop();
						c[man].insert(tmp);
					}
				}
				else
					cout << "Failed\n";
			}
		}
	}
}
