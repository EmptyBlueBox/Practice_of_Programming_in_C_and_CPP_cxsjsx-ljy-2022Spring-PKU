#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int m, n;
	cin >> n >> m;//注意n还是m！！！
	map<string, pair<int, int> >a;
	for (int i = 1; i <= m; i++) {
		string tmp;
		int pri, num;
		cin >> tmp >> pri >> num;
		a.insert(make_pair(tmp, make_pair(pri, num)));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		string o[4];
		cin >> o[1] >> o[2] >> o[3];
		for (int j = 1; j <= 3; j++) {
			if (a.find(o[j]) != a.end() && a[o[j]].second > 0) {
				ans += a[o[j]].first;
				a[o[j]].second--;
			}
		}
	}
	cout << ans;
}