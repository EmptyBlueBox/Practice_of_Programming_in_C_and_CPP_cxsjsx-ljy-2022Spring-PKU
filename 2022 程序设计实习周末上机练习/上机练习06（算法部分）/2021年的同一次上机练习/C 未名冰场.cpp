#include <iostream>
using namespace std;

int m, n, dx[8] = { 0,1,0,-1,1,1,-1,-1 }, dy[8] = { 1,0,-1,0,1,-1,-1,1 };
bool iced[102][102] = { {false} }, vis[102][102] = { {false} };
void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (vis[xx][yy] || (!iced[xx][yy]) || xx<1 || xx>m || yy<1 || yy>n)
			continue;
		dfs(xx, yy);
	}
}
int main() {
	while (cin >> m >> n && m) {
		memset(iced, 0, sizeof(iced));
		memset(vis, 0, sizeof(vis));
		char tmp;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> tmp, iced[i][j] = tmp == '@';
		int ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (iced[i][j] && !vis[i][j])
					ans++, dfs(i, j);
		cout << ans << endl;
	}
}