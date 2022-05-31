#include <iostream>
using namespace std;

int main() {
	int n, dp[1001] = { 0 }, v[4] = { 10,20,50,100 };
	cin >> n;
	dp[0] = 1;
	for (int i = 0; i < 4; i++)
		for (int j = v[i]; j <= n; j++)//完全背包从小到大循环
			dp[j] += dp[j - v[i]];
	cout << dp[n] << endl;
}