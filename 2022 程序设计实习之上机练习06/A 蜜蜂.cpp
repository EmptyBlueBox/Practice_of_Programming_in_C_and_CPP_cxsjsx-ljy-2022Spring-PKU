#include <iostream>
using namespace std;

int main() {
	long long dp[50], N, a, b;
	dp[1] = 1, dp[2] = 1;
	for (int i = 3; i <= 49; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cin >> N;
	while (N--)
		cin >> a >> b, cout << dp[b - a + 1] << endl;
}