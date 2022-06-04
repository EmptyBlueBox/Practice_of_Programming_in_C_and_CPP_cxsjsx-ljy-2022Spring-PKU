#include <iostream>
using namespace std;

int map[22][22] = { {0} }, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool vis[101] = { false };
int f(int x, int y) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (!vis[map[xx][yy]] && map[xx][yy])//没去过且不是边界
			vis[map[xx][yy]] = true, ans = max(ans, f(xx, yy)), vis[map[xx][yy]] = false;//dfs
	}
	return ans + 1;
}
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	vis[map[1][1]] = true;
	cout << f(1, 1) << endl;
}