#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int main() {
	int m, n, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, T = 0;
	while (cin >> n >> m && n) {
		printf("Board #%d:\n", ++T);
		char map[77][77] = { {0} };
		pair<int, int> s, e;
		for (int i = 1; i <= m; i++) {
			cin.get();
			for (int j = 1; j <= n; j++)
				map[i][j] = cin.get();
		}
		int Pair = 0;
		while (cin >> s.second >> s.first >> e.second >> e.first && s.second) {
			printf("Pair %d: ", ++Pair);
			int dis[77][77], ans = 0x3f3f3f3f;
			queue<pair<int, int>> q;
			memset(dis, 0x3f, sizeof(dis));
			q.push(s);
			dis[s.first][s.second] = 0;
			while (!q.empty()) {
				pair<int, int> now = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					for (int j = 1; j <= 76; j++) {//向前移动最大需要76，因为地图扩大了两格
						int xx = now.first + dx[i] * j, yy = now.second + dy[i] * j, d = dis[now.first][now.second] + 1;
						if (make_pair(xx, yy) == e) {
							ans = min(ans, d);
							break;
						}
						if (xx<0 || xx>m + 1 || yy<0 || yy>n + 1 || map[xx][yy] == 'X' || dis[xx][yy] < d)
							break;
						dis[xx][yy] = d;
						q.push({ xx,yy });
					}
				}
			}
			cout << (ans == 0x3f3f3f3f ? "impossible.\n" : to_string(ans) + " segments.\n");
		}
		cout << endl;
	}
}