#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> a;
	int n, cnt = 0;
	while (cin >> n && n != 0)
		a.insert(n);
	set<int>::iterator itr = a.begin();
	while (itr != a.end()) {
		if (a.find(2 * *itr) != a.end())
			cnt++;
		itr++;
	}
	cout << cnt << endl;
}