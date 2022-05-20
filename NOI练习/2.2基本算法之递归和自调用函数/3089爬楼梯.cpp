#include <iostream>
using namespace std;

int main() {
	int n, dp[31];
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 30; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	while (cin >> n)
		cout << dp[n] << endl;
}