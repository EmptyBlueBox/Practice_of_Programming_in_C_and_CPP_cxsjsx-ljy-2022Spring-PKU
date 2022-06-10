#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	int  a[100];
	cin >> t;
	while (t--) {
		for (int i = 0; i < 12; ++i)
			cin >> a[i];
		// 在此处补充你的代码
		//iterator末尾是or不是er
		ostream_iterator<int> c(cout, " ");
		set<int>b;
		for (int i = 0; i < 12; i++)
			b.insert(a[i]);
		// 在此处补充你的代码
		std::copy(b.begin(), b.end(), c);
		cout << endl;
	}
	return 0;
}