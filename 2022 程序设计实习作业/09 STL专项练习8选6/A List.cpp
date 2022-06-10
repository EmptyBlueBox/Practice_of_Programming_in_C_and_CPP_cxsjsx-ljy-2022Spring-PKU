#include <iostream>
#include <list>
#include <map>
#include <iterator>//ostream_iterator
using namespace std;

int main()
{
	int order;
	string tmp;
	map<int, list<int> > a;
	cin >> order;
	for (int i = 0; i < order; i++)
	{
		cin >> tmp;
		if (tmp == "new")
		{
			int _id;
			cin >> _id;
			a[_id] = list<int>();//添加新元素要写{}、无变量名的临时对象要写（）否则只有类型名不可以
		}
		else if (tmp == "add")
		{
			int _id, _n;
			cin >> _id >> _n;
			a[_id].push_back(_n);
		}
		else if (tmp == "merge")
		{
			int _id1, _id2;
			cin >> _id1 >> _id2;
			a[_id1].merge(a[_id2]);
		}
		else if (tmp == "unique")
		{
			int _id;
			cin >> _id;
			a[_id].sort();
			a[_id].unique();
		}
		else if (tmp == "out")
		{
			int _id;
			cin >> _id;
			a[_id].sort();
			ostream_iterator<int> output(cout, " ");
			copy(a[_id].begin(), a[_id].end(), output);
			cout << endl;
		}
	}
}
