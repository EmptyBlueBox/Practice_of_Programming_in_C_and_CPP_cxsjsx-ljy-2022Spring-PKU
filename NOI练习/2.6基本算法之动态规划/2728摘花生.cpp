#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int m, n, dp[101][101];
		cin >> m >> n;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> dp[i][j];
		for (int i = 2; i <= m + n; i++)
			for (int j = 1; j <= i && j <= m; j++)
				dp[j][i - j] += max(dp[j - 1][i - j], dp[j][i - j - 1]);
		cout << dp[m][n] << endl;
	}
}