#include <iostream>
using namespace std;

int main() {
	int n, tp, dp[101][2] = { {0} }, info[101][2] = { 0 };
	cin >> n >> tp;
	for (int i = 1; i <= n; i++)
		cin >> info[i][0] >> info[i][1];
	dp[1][0] = info[1][0], dp[1][1] = info[1][1];
	for (int i = 2; i <= n; i++)
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - tp) + info[i][0], dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] - tp) + info[i][1];
	cout << max(dp[n][0], dp[n][1]) << endl;
}