#include <iostream>
using namespace std;

int n, m, pokemon, dp[1001][501] = { {0} };//用了几个精灵球，用了多少体力，相当于从三维利用滚动数组变成二维；并且不用全装满
int main() {
	cin >> n >> m >> pokemon;
	for (int i = 1; i <= pokemon; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = n; j >= x; j--)
			for (int k = m; k >= y; k--)
				dp[j][k] = max(dp[j][k], dp[j - x][k - y] + 1);
	}

	int max_pokemon = 0xc0c0c0c0, min_used_effort = 0x3f3f3f3f;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			max_pokemon = max(max_pokemon, dp[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (dp[i][j] == max_pokemon)
				min_used_effort = min(min_used_effort, j);
	if (max_pokemon == 0)//特判一个都收不了
		min_used_effort = 0;
	cout << max_pokemon << ' ' << m - min_used_effort << endl;
}