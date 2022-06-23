#include <iostream>
using namespace std;

int m, n, h[102][102], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, dp[102][102] = { {0} };
int f(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || xx>m || yy<1 || yy>n)
			continue;
		if (h[xx][yy] > h[x][y])
			dp[x][y] = max(dp[x][y], f(xx, yy) + 1);
	}
	return dp[x][y];
}
int main() {
	int ans = 1;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> h[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			ans = max(ans, f(i, j));
	cout << ans << endl;
}