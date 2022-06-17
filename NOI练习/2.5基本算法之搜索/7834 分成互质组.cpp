#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, info[11], ans = 0x3f3f3f3f;
bool p[11][11];
vector<int> g[11];
void f(int k,int group) {
	if (k == n + 1) {
		ans = min(ans, group);
		return;
	}
	for (int i = 1; i <= group; i++) {
		for (int j = 0; j < g[i].size(); j++)
			if (!p[g[i][j]][k])
				goto nextGroup;
		g[i].push_back(k);
		f(k + 1, group);
		g[i].pop_back();
nextGroup:
		;
	}
	g[group + 1].push_back(k);
	f(k + 1, group + 1);
	g[group + 1].pop_back();
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> info[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			p[i][j] = p[j][i] = (__gcd(info[i], info[j]) == 1);
	f(1, 1);
	cout << ans << endl;
}