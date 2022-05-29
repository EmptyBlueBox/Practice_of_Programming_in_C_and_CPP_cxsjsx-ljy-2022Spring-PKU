#include <iostream>
using namespace std;

int main() {
	int m, n, dp[21][21] = { {0} };
	cin >> m >> n;
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			dp[i][j] = 1;
	for (int i = 3; i <= m + n; i++)
		for (int j = 2; j <= i - 1 && j <= m; j++)
			dp[j][i - j] = dp[j - 1][i - j] + dp[j][i - j - 1];
	cout << dp[m][n] << endl;
}