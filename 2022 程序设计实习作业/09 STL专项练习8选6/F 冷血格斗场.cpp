#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct info
{
	int id, power;
};
struct cmp
{
	bool operator()(const info& a, const info& b)const
	{
		if (a.power != b.power)
			return a.power < b.power;
		else
			return a.id < b.id;
	}
};
int main()
{
	set<info, cmp>a;
	set<info, cmp>::iterator p1, p2;
	a.insert({ 1,1000000000 });
	int n, i, tmpid, tmp;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> tmpid >> tmp;
		cout << tmpid << " ";
		p2 = a.upper_bound({ tmpid,tmp });
		p1 = a.lower_bound({ tmpid,tmp });
		//特判
		if (p1 == a.begin())
		{
			cout << p1->id << endl;
			a.insert({ tmpid,tmp });
			continue;
		}
		if (p2 == a.end())
		{
			p1--;
			p1 = a.upper_bound({ 0,p1->power });
			cout << p1->id << endl;
			a.insert({ tmpid,tmp });
			continue;
		}

		p1--;
		p1 = a.upper_bound({ 0,p1->power }); 
		p2 = a.upper_bound({ 0,p2->power });
		if (p1->power + p2->power > 2 * tmp)
			cout << p1->id << endl;
		else if (p1->power + p2->power == 2 * tmp)
		{
			if (p1->id < p2->id)
				cout << p1->id << endl;
			else
				cout << p2->id << endl;
		}
		else
			cout << p2->id << endl;
		a.insert({ tmpid,tmp });
	}
	return 0;
}
