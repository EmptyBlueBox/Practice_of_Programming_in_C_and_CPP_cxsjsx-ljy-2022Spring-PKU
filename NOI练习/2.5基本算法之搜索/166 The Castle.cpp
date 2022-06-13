#include <iostream>
using namespace std;

int m, n, dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 }, map[52][52], cnt = 0, max_size = 0, tmp_max_size;
bool vis[52][52] = { {false} };
bool seperate(int x, int y, int dir) {
	if (dir == 3) return map[x][y] >= 8;
	else if (dir == 2)	return map[x][y] % 8 >= 4;
	else if (dir == 1) return map[x][y] % 4 >= 2;
	else return map[x][y] % 2 >= 1;
}
void dfs(int x, int y) {//在进入每个节点时保证这个节点是合法且不用对这个节点做任何事情
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || xx>m || yy<1 || yy>n || vis[xx][yy] || seperate(x, y, i))
			continue;
		vis[xx][yy] = true, tmp_max_size++, max_size = max(max_size, tmp_max_size);
		dfs(xx, yy);
	}
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (!vis[i][j])
				tmp_max_size = 1, vis[i][j] = true, cnt++, dfs(i, j);
	cout << cnt << endl << max_size << endl;
}