#include <iostream>
#include <bitset>
using namespace std;

//f[i][j]：j可以赢；g[i][j]：i可以赢
//第二个区间可以头或尾赢，第一个区间可以头或尾赢第二个区间的胜者
int main() {
	int n;
	bool map[300][300], g[300][300] = { {0} }, f[300][300] = { {0} };
	char c;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> c, map[i][j] = c == 'W';
	for (int i = 0; i < n; i++)
		g[i][i] = f[i][i] = true;
	for (int len = 2; len <= n; len++)
		for (int i = 0, j = i + len - 1; j < n; i++, j++)
			for (int k = i; k <= j; k++) {
				f[i][j] |= f[i][k] & f[k + 1][j] & (map[j][k] | map[k + 1][k]);
				f[i][j] |= g[i][k] & f[k + 1][j] & (map[j][i] | map[k + 1][i]);
				g[i][j] |= g[i][k] & g[k + 1][j] & (map[i][k + 1] | map[k][k + 1]);
				g[i][j] |= g[i][k] & f[k + 1][j] & (map[i][j] | map[k][j]);
			}
	for (int i = 0; i < n; i++)
		if (f[0][i] & g[i][n - 1])
			cout << i + 1 << ' ';
}