#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	typedef pair<int, int> pii;
	int T, m, n, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0,0,1,-1 }, dis[202][202];
	cin >> T;
	while (T--) {
		cin >> m >> n;
		char map[202][202];
		queue<pii> q;
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S') q.push({ i,j }), dis[i][j] = 0;
			}
		while (!q.empty()) {
			pii t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = t.first + dx[i], yy = t.second + dy[i], dd = dis[t.first][t.second] + 1;
				if (xx<1 || xx>m || yy<1 || yy>n || map[xx][yy] == '#' || dis[xx][yy] <= dd) continue;
				else if (map[xx][yy] == 'E') {
					cout << dd << endl;
					goto loop;
				}
				dis[xx][yy] = dd;
				q.push({ xx,yy });
			}
		}
		cout << "oop!\n";
loop:
		;
	}
}