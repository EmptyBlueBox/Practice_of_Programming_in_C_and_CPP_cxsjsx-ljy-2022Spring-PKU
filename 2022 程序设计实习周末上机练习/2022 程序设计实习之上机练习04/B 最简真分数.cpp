#include <iostream>
#include <vector>
#include <set>
using namespace std;

inline int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	int n, tmp, cnt = 0;
	set<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.insert(tmp);
	}
	for (auto i : a)
		for (auto j : a) {
			if (i >= j)
				continue;
			if (gcd(i, j) == 1)
				cnt++;
		}
	cout << cnt << endl;
}