#include <iostream>
using namespace std;

int main() {
	int n, k, dp[100001] = { 0 };
	dp[0] = 1;
	cin >> n >> k;
	for (int i = 1; i <= k + 1; i++)
		dp[i] = (dp[i - 1] + 1) % 5000011;
	for (int i = k + 2; i <= n; i++)
		//放奶牛 + 放公牛（前k个必须是奶牛，已经被决定）
		dp[i] = (dp[i - 1] + dp[i - k - 1]) % 5000011;
	cout << dp[n] << endl;
}