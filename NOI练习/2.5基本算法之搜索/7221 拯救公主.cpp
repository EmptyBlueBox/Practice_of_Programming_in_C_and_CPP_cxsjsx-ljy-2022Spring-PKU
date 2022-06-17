#include <iostream>
#include <cstring>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int x, y;
	bitset<5> gem;
	node(int _x, int _y, bitset<5> _gem) :x(_x), y(_y), gem(_gem) {}
};
int dis[202][202][1 << 5];
int main() {
	int T, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0,0,1,-1 };
	cin >> T;
	while (T--) {
		int m, n, k, ans = 0x3f3f3f3f;
		cin >> m >> n >> k;
		char map[202][202];
		queue<node> q;
		vector<pair<int, int>> tp;
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S') q.push({ i,j,0 }), dis[i][j][0] = 0;
				else if (map[i][j] == '$') tp.push_back({ i,j });
			}
		while (!q.empty()) {
			node t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = t.x + dx[i], yy = t.y + dy[i], dd = dis[t.x][t.y][int(t.gem.to_ulong())] + 1;
				bitset<5> gg = t.gem;
				if (map[xx][yy] >= '0' && map[xx][yy] <= '4')//收集宝石
					gg[map[xx][yy] - '0'] = true;
				if (xx<1 || xx>m || yy<1 || yy>n || map[xx][yy] == '#')//越界
					continue;
				else if (map[xx][yy] == 'E' && gg.count() >= k)//到达终点
					ans = min(ans, dd);
				if (map[xx][yy] == '$') { //遇到传送门，枚举每一个能tp去的地方，如果dis比dd大就传送过去
					for (int i = 0; i < tp.size(); i++)
						if (dis[tp[i].first][tp[i].second][gg.to_ulong()] > dd)
							dis[tp[i].first][tp[i].second][gg.to_ulong()] = dd, q.push({ tp[i].first,tp[i].second,gg });
				} else if (dis[xx][yy][gg.to_ulong()] > dd)
					dis[xx][yy][gg.to_ulong()] = dd, q.push({ xx,yy,gg });
			}
		}
		cout << (ans == 0x3f3f3f3f ? "oop!" : to_string(ans)) << endl;
	}
}