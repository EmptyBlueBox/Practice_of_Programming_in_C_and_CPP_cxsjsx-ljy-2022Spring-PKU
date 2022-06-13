#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, T, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
	cin >> N;
	for (int T = 1; T <= N; T++) {
		printf("Case #%d: ", T);
		int m, n, dis[102][102];
		cin >> m >> n;
		memset(dis, 0x3f, sizeof(dis));
		char map[102][102];
		queue<pair<int, int>> q;
		vector<pair<int, int>> tp[26];//传送门坐标
		pair<int, int> start, end;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'B') start = make_pair(i, j), map[i][j] = '.';
				else if (map[i][j] == 'I') end = make_pair(i, j), map[i][j] = '.';
				else if (map[i][j] >= 'a' && map[i][j] <= 'z') tp[map[i][j] - 'a'].push_back({ i,j });
			}
		q.push(start), dis[start.first][start.second] = 0;
		while (!q.empty()) { //走四个方向，如果now是传送门就加钻洞
			pair<int, int> now = q.front();
			q.pop();
			int xx, yy;
			for (int i = 0; i < 4; i++) {
				xx = now.first + dx[i], yy = now.second + dy[i];
				if (dis[xx][yy] != 0x3f3f3f3f || map[xx][yy] == '#' || xx<1 || xx>m || yy<1 || yy>n)
					continue;
				else if (end == make_pair(xx, yy)) {
					cout << dis[now.first][now.second] + 1 << endl;
					goto loop;
				}
				dis[xx][yy] = dis[now.first][now.second] + 1;
				q.push({ xx, yy });
			}
			if (map[now.first][now.second] >= 'a' && map[now.first][now.second] <= 'z') {
				xx = (tp[map[now.first][now.second] - 'a'][0] == now ? tp[map[now.first][now.second] - 'a'][1].first : tp[map[now.first][now.second] - 'a'][0].first);
				yy = (tp[map[now.first][now.second] - 'a'][0] == now ? tp[map[now.first][now.second] - 'a'][1].second : tp[map[now.first][now.second] - 'a'][0].second);
				if (dis[xx][yy] != 0x3f3f3f3f || map[xx][yy] == '#' || xx<1 || xx>m || yy<1 || yy>n)
					continue;
				else if (end == make_pair(xx, yy)) {
					cout << dis[now.first][now.second] + 1 << endl;
					goto loop;
				}
				dis[xx][yy] = dis[now.first][now.second] + 1;
				q.push({ xx, yy });
			}
		}
		cout << -1 << endl;
loop:
		;
	}
}