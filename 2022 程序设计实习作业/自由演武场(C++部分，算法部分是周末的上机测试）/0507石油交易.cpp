#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	int n;
	string cmd;
	multimap<int, int> a;//可能有钱一样的输入
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "SELL") {
			int x, y;
			cin >> x >> y;
			a.insert(make_pair(y, x));
		} else {
			int cnt, ans = 0;
			cin >> cnt;
			while (cnt--) {
				if (!a.empty()) {
					ans += a.begin()->first;
					a.begin()->second--;
					if (a.begin()->second <= 0)
						a.erase(a.begin());
				} else
					ans += 40;
			}
			cout << ans << endl;
		}
	}
}