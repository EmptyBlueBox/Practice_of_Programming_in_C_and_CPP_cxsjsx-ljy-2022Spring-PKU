#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool map[102][102] = { {0} };
int m, n, dx[8] = { 1,-1,0,0,1,1,-1,-1 }, dy[8] = { 0,0,1,-1,1,-1,-1,1 };
void dfs(int x, int y) {
	map[x][y] = false;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if ((!map[xx][yy]) || xx<1 || xx>m || yy<1 || yy>n)
			continue;
		dfs(xx, yy);
	}
}
int main() {
	cin >> m >> n;
	char c;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> c, map[i][j] = c == 'W';
	int ans = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j])//遇到水就把这一块都变成陆地
				dfs(i, j), ans++;
	cout << ans << endl;
}