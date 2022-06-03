#include <iostream>
#include <algorithm>
using namespace std;

//多线程dp，同时模拟两个人走
int n, x, y, v, map[11][11] = { {0} }, dp[11][11][11][11] = { {{{0}}} };
int main() {
	cin >> n;
	while (cin >> x >> y >> v && x)
		map[x][y] = v;
	dp[1][1][1][1] = map[1][1];
	for (int i = 1; i <= n; i++)//方形对角线遍历可以这么写！！！
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)//别写成i++！！！
				for (int l = 1; l <= n; l++)
					dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l], dp[i][j - 1][k][l - 1]), max(dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1])) + map[i][j] + map[k][l] * (!(i == k && j == l));
	cout << dp[n][n][n][n] << endl;
}