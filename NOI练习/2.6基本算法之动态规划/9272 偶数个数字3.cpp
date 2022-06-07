#include <iostream>
using namespace std;

int main() {
	int n, dp[2][1001] = { {0} };
	dp[0][1] = 8, dp[1][1] = 1;
	cin >> n;
	if (n == 1) {
		cout << 9 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++)
		dp[0][i] = (dp[0][i - 1] * 9 + dp[1][i - 1]) % 12345, dp[1][i] = (dp[0][i - 1] + dp[1][i - 1] * 9) % 12345;
	cout << dp[0][n] << endl;
}