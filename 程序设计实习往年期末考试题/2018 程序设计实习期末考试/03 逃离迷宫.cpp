#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	int N, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	cin >> N;
	while (N--) {
		int n, t, dis[12][12];
		char map[12][12] = { {0} };
		queue<pair<int, int>> q;
		memset(dis, 0x3f, sizeof(dis));
		cin >> n >> t;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S') q.push({ i,j }), dis[i][j] = 0;
			}
		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = now.first + dx[i], yy = now.second + dy[i];
				if (map[xx][yy] == '#' || dis[xx][yy] != 0x3f3f3f3f || xx<1 || xx>n || yy<1 || yy>n)
					continue;
				dis[xx][yy] = dis[now.first][now.second] + 1;
				if (map[xx][yy] == 'E') {
					cout << (dis[xx][yy] <= t ? "YES\n" : "NO\n");
					goto loop;
				}
				q.push({ xx,yy });
			}
		}
		cout << "NO\n";
loop:
		;
	}
}