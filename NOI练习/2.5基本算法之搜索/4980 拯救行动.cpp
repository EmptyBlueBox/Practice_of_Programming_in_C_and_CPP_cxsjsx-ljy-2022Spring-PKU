#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	int N, m, n, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0,0,1,-1 };
	cin >> N;
	while (N--) {
		cin >> m >> n;
		char map[202][202];
		int dis[202][202], ex, ey;
		queue<pair<int, int>> q;
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'r') q.push({ i,j }), dis[i][j] = 0;
				if (map[i][j] == 'a') ex = i, ey = j;
			}
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i], dd = dis[x][y] + 1;
				if (xx<1 || xx>m || yy<1 || yy>n || map[xx][yy] == '#' || dis[xx][yy] <= dd) continue;
				else if (map[xx][yy] == 'x') dd++;
				dis[xx][yy] = dd;
				q.push({ xx,yy });
			}
		}
		cout << (dis[ex][ey] == 0x3f3f3f3f ? "Impossible" : to_string(dis[ex][ey])) << endl;
	}
}