#include <iostream>
#define endl '\n'//差十倍
using namespace std;

int m, n, info[102][102] = { {0} }, dp[102][102] = { {0} }, ans = -1, dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool vis[102][102] = { {false} };
bool valid(int x, int y) {
	return x >= 1 && x <= m && y >= 1 && y <= n;
}
void search(int x, int y) {
	vis[x][y] = true;
	dp[x][y] = max(dp[x][y], 1);//{{1}}没用
	for (int dir = 0; dir < 4; dir++) {
		int xx = x + dx[dir], yy = y + dy[dir];
		if (info[xx][yy] > info[x][y] && valid(xx, yy)) { //只递归比我高的，否则会循环递归，即我搜比我低的，比我低的搜我
			if (!vis[xx][yy])
				search(xx, yy);
			dp[x][y] = max(dp[x][y], dp[xx][yy] + 1);
		}
	}
	ans = max(ans, dp[x][y]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);//cin,cout解绑
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> info[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			search(i, j);
	cout << ans << endl;
}