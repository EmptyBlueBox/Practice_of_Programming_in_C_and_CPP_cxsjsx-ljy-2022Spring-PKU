#include <iostream>
using namespace std;

int n, k, ans = 0;
int map[9][9] = { {0} };
bool col_vis[9] = { false };
void dfs(int row, int chs_left) {
	if (chs_left == 0) { //终点1
		ans++;
		return;
	} else if (row > n && chs_left > 0) //终点2，没放完棋盘就没地方了
		return;
	dfs(row + 1, chs_left);//要么这行不放
	for (int i = 1; i <= n; i++)//要么放一个
		if (map[row][i] && !col_vis[i]) {
			col_vis[i] = true;
			dfs(row + 1, chs_left - 1);
			col_vis[i] = false;
		}
}
int main() {
	while (cin >> n >> k && n != -1) {
		ans = 0;
		char c;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> c, map[i][j] = c == '#';//1是棋盘
		dfs(1, k);
		cout << ans << endl;
	}
}