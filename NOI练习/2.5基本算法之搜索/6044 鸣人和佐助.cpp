#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

//除了x,y,step还有其它参数的BFS用多维bool vis[node]
struct node {
	int x, y, c, step;
	node(int _x, int _y, int _c,int _step) :x(_x), y(_y), c(_c),step(_step) {}
};
int main() {
	int m, n, cha, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0,0,1,-1 };
	cin >> m >> n >> cha;
	char map[202][202];
	bool vis[202][202][10] = { {{0}} };
	int ex, ey;
	queue<node> q;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '@') q.push({ i,j,cha,0 }), vis[i][j][cha] = true;
		}
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, c = q.front().c, t = q.front().step;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i], cc = c - (map[xx][yy] == '#'), tt = t + 1;
			if (xx<1 || xx>m || yy<1 || yy>n || cc < 0 || vis[xx][yy][cc]) continue;
			else if (map[xx][yy] == '+') {
				cout << tt << endl;
				return 0;
			}
			vis[xx][yy][cc] = true;
			q.push({ xx,yy,cc,tt });
		}
	}
	cout << -1 << endl;
}