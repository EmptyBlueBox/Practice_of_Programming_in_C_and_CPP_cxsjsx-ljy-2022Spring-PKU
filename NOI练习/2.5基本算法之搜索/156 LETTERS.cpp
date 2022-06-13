#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

//这个题的vis是字母是否到过，不是是否走过，因此vis与dis不能合并
char map[22][22];
int m, n, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, ans = 1, dis[28][28];//与(1, 1)的距离
bool vis[26] = { false };//字母是否到过
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || xx>m || yy<1 || yy>n || (vis[map[xx][yy] - 'A'] == 1))
			continue;
		dis[xx][yy] = dis[x][y] + 1;
		vis[map[xx][yy] - 'A'] = 1;
		ans = max(ans, dis[xx][yy]);
		dfs(xx, yy);
		vis[map[xx][yy] - 'A'] = 0;
		dis[xx][yy] = 0x3f3f3f3f;
	}
}
int main() {
	memset(dis, 0x3f, sizeof(dis));
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j], vis[map[i][j] - 'A'] = 0;
	dis[1][1] = 1, vis[map[1][1] - 'A'] = true;
	dfs(1, 1);
	cout << ans << endl;
}