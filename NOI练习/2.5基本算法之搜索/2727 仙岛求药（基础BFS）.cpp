#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	typedef pair<int, int> pii;
	int m, n, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0,0,1,-1 };
	while (cin >> m >> n && m) {
		char map[22][22];
		int dis[22][22], ex, ey;
		queue<pii> q;
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') q.push({ i,j }), dis[i][j] = 0;
				if (map[i][j] == '*') ex = i, ey = j;
			}
		while (!q.empty()) {
			pii t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = t.first + dx[i], yy = t.second + dy[i], dd = dis[t.first][t.second] + 1;
				if (xx<1 || xx>m || yy<1 || yy>n || map[xx][yy] == '#' || dis[xx][yy] <= dd) continue;
				dis[xx][yy] = dd;
				q.push({ xx,yy });
			}
		}
		cout << (dis[ex][ey] == 0x3f3f3f3f ? -1 : dis[ex][ey]) << endl;
	}
}