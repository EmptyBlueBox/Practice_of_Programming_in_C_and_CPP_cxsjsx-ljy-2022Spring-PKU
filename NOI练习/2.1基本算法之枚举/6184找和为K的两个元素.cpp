#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m, tmp;
	multiset<int> a;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.insert(tmp);
	}
	for (int i = 0; i <= m / 2; i++) {
		if (a.find(i) != a.end() && a.find(m - i) != a.end()) {
			if (i * 2 == m && a.count(i) == 1)
				continue;
			cout << "yes" << endl;
			return 0;
		}
	}
	cout << "no" << endl;
}