#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[205][205][4] = { {{0}} }, door_dis[205][205];
int main() {
	typedef pair<int, int> pii;
	enum { EMPTY, WALL, DOOR };
	int wall, door, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
	while (cin >> wall >> door && wall != -1) {
		int m = 0, n = 0;
		memset(map, 0, sizeof(map)), memset(door_dis, 0x3f, sizeof(door_dis));
		for (int i = 0; i < wall; i++) {
			int x, y, d, t;
			cin >> x >> y >> d >> t;
			m = max(m, x + 2 + dx[d] * t), n = max(n, y + 2 + dy[d] * t);
			for (int j = 0; j <= t; j++) {
				int xx = x + dx[d] * j, yy = y + dy[d] * j;
				map[xx][yy][3 - d] = map[xx + dx[3 - d]][yy + dy[3 - d]][1 - d] = WALL;
			}
		}
		for (int i = 0; i < door; i++) {
			int x, y, d;
			cin >> x >> y >> d;
			m = max(m, x + 2), n = max(n, y + 2);
			map[x][y][3 - d] = map[x + dx[3 - d]][y + dy[3 - d]][1 - d] = DOOR;
		}
		double ex, ey;
		cin >> ex >> ey;
		if (ex<0 || ex > m || ey<0 || ey>n) {
			cout << 0 << endl;
			continue;
		}
		queue<pii> q;
		q.push({ 0,0 }), door_dis[0][0] = 0;
		while (!q.empty()) {
			pii nn = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = nn.first + dx[i], yy = nn.second + dy[i], dd = door_dis[nn.first][nn.second] + (map[nn.first][nn.second][i] == DOOR);
				if (xx < 0 || xx>m || yy < 0 || yy>n || map[nn.first][nn.second][i] == WALL || door_dis[xx][yy] <= dd)
					continue;
				door_dis[xx][yy] = dd;
				q.push({ xx,yy });
			}
		}
		cout << (door_dis[int(ex)][int(ey)] == 0x3f3f3f3f ? -1 : door_dis[int(ex)][int(ey)]) << endl;
	}
}