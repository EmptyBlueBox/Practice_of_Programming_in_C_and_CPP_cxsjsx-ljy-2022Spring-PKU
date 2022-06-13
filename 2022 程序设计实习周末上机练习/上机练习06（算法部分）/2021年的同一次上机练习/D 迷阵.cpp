#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, hp, t;
	node(int _x, int _y, int _hp, int _t) :x(_x), y(_y), hp(_hp), t(_t) {}
};
enum BLOCK { EMPTY, WALL, TRAP };
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int main() {
	int N;
	cin >> N;
	while (N--) {
		int m, n, hp;
		bool vis[257][257][6] = { {{false}} };
		char tmp, map[257][257] = { {0} };
		cin >> m >> n >> hp;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		queue<node> q;
		q.push({ 1,1,hp,0 });
		while (!q.empty()) {
			node now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i], hpp = now.hp, tt = now.t + 1;
				if (vis[xx][yy][hpp] || map[xx][yy] == '#' || (map[xx][yy] == '*' && hpp == 1) || xx<1 || xx>m || yy<1 || yy>n)
					continue;
				else if (xx == m && yy == n) {
					cout << tt << endl;
					goto loop;
				} else if (map[xx][yy] == '*')
					hpp--;
				vis[xx][yy][hpp] = true;
				q.push({ xx,yy,hpp,tt });
			}
		}
loop:
		;
	}
}