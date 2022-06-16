#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int main() {
	int m, n, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	while (cin >> n >> m && m) {
		char map[22][22];
		bool vis[22][22] = { {0} };
		queue<pii> q;
		int ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') q.push({ i,j }), vis[i][j] = true, ans++;
			}
		while (!q.empty()) {
			pii nn = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = nn.first + dx[i], yy = nn.second + dy[i];
				if (map[xx][yy] == '#' || vis[xx][yy] || xx<1 || xx>m || yy<1 || yy>n)
					continue;
				vis[xx][yy] = true, ans++;
				q.push({ xx,yy });
			}
		}
		cout << ans << endl;
	}
}