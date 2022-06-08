#include <iostream>
using namespace std;

int main() {
	int n, dp[4][1001] = { {0} }, step = 1;
	dp[1][1] = 1;
	while (cin >> n) {
		if (n <= step) {
			cout << dp[0][n] << endl;
			continue;
		}
		for (int i = step + 1; i <= n; i++) {
			dp[0][i] = dp[1][i - 1];
			dp[1][i] = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1] + 2 * dp[3][i - 1];
			dp[2][i] = 2 * dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1];
			dp[3][i] = dp[2][i - 1];
		}
		step = n;
		cout << dp[0][n] << endl;
	}
}