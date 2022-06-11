#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int x, y, t;
	node(int _x, int _y, int _t) :x(_x), y(_y), t(_t) {}
	node(pair<int, int> p, int _t) :x(p.first), y(p.second), t(_t) {}
};
int main() {
	int N, T, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
	cin >> N;
	T = N;
	while (N--) {
		printf("Case #%d: ", T - N);
		int m, n, vis[102][102] = { {false} };
		char map[102][102];
		queue<node> q;
		vector<pair<int, int>> tp[26];//传送门坐标
		cin >> m >> n;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'B') q.push({ i,j,0 }), map[i][j] = '.';
				if (map[i][j] >= 'a' && map[i][j] <= 'z') tp[map[i][j] - 'a'].push_back({ i,j });
			}
		while (!q.empty()) { //走四个方向，如果now是传送门就加钻洞
			node now = q.front();
			q.pop();
			//判断是否撞墙、到过、越界可以在最开始进行
			if (map[now.x][now.y] == '#' || vis[now.x][now.y] || now.x<1 || now.x>m || now.y<1 || now.y>n)
				continue;
			if (map[now.x][now.y] == 'I') {
				cout << now.t << endl;
				goto loop;
			}
			vis[now.x][now.y] = true;
			if (map[now.x][now.y] >= 'a' && map[now.x][now.y] <= 'z')
				q.push(tp[map[now.x][now.y] - 'a'][0] == make_pair(now.x, now.y) ? node{ tp[map[now.x][now.y] - 'a'][1], now.t + 1 } : node{ tp[map[now.x][now.y] - 'a'][0], now.t + 1 });
			for (int i = 0; i < 4; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i];
				q.push({ xx, yy, now.t + 1 });
			}
		}
		cout << -1 << endl;
loop:
		;
	}
}