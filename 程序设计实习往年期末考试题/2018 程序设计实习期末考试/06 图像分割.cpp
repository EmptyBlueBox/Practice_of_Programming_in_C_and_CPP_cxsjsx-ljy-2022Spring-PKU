#include <iostream>
#include <cstring>
using namespace std;

int m, n, d, map[52][52] = { {0} }, ans = 0, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool vis[52][52] = { {false} };
void f(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (vis[xx][yy] || abs(map[xx][yy] - map[x][y]) > d || xx<1 || xx>m || yy<1 || yy>n)
			continue;
		vis[xx][yy] = true;
		f(xx, yy);
	}
}
int main() {
	while (cin >> m >> n >> d && m) {
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (!vis[i][j])
					vis[i][j] = true, ans++, f(i, j);
		cout << ans << endl;
	}
}