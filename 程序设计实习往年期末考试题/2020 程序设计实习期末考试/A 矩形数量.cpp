#include <iostream>
#include <set>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, a, b, ans = 0;
		cin >> n;
		set<pair<int, int>> p;
		for (int i = 0; i < n; i++)
			cin >> a >> b, p.insert({ a,b });
		n = p.size();
		for (auto i : p)
			for (auto j : p) {
				if (i >= j || i.first != j.first)//按顺序枚举上边
					continue;
				for (auto k : p) {
					if (j >= k || j.second != k.second)//按顺序枚举右边
						continue;
					for (auto l : p) {
						if (l.second == i.second && l.first == k.first)
							ans++;
					}
				}
			}
		cout << ans << endl;
	}
}