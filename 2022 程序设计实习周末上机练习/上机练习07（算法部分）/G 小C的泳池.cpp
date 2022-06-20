#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, map[302][302], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool vis[302][302] = { {0} };
bool bfs(int h) {
	if (h < map[1][1] || h < map[n][n])
		return false;
	queue<pair<int, int>> q;
	memset(vis, 0, sizeof(vis));
	vis[1][1] = true;
	q.push({ 1,1 });
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = p.first + dx[i], yy = p.second + dy[i];
			if (map[xx][yy] > h || vis[xx][yy] || xx<1 || xx>n || yy<1 || yy>n)
				continue;
			else if (xx == n && yy == n)
				return true;
			vis[xx][yy] = true;
			q.push({ xx,yy });
		}
	}
	return false;
}
int main() {
	cin >> n;
	int l = -1, r;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j], r = max(r, map[i][j]);
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		if (bfs(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}