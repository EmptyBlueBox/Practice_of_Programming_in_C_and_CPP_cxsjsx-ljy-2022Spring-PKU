#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[1001][1001], vis[1001];//某种物品得到的时候有过多少钱
int main() {
	int m, n, r, s, t, ans = 0xc0c0c0c0;
	cin >> m >> n;
	memset(a, 0xc0, sizeof(a));
	memset(vis, 0xc0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		cin >> r >> s >> t, a[r][s] = t;
	queue<pair<int, int>> q;
	q.push({ 1,0 }), vis[1] = 0;
	while (!q.empty()) {
		pair<int, int> nn = q.front();
		q.pop();
		for (int i = 1; i <= m; i++) {
			if (a[nn.first][i] == 0xc0c0c0c0 || vis[i] >= nn.second + a[nn.first][i])
				continue;
			vis[i] = max(vis[i], nn.second + a[nn.first][i]);
			ans = max(ans, vis[i]);
			if (ans > 400000) {
				cout << "1000000000\n";
				return 0;
			}
			q.push({ i,nn.second + a[nn.first][i] });
		}
	}
	cout << ans << endl;
}