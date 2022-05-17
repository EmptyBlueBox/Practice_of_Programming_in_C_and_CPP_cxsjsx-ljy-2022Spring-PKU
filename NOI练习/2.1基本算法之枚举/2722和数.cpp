#include <iostream>
#include <set>
#include <unordered_map>//第一次使用unordered_map
using namespace std;

int main() {
	multiset<int> a;
	unordered_map<int, bool> vis;
	int n, tmp, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.insert(tmp);
		vis[tmp] = false;
	}
	for (auto i : a)
		for (auto j : a) {
			if ((i == j && a.count(i) == 1) || vis[i + j])
				continue;
			if (a.find(i + j) != a.end())
				cnt++, vis[i + j] = true;
		}
	cout << cnt << endl;
}