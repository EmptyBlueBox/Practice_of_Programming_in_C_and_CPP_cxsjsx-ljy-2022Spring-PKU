#include <iostream>
using namespace std;

int main()
{
	int n, info[220] = { 0 }, dp[220] = { 0 }, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> info[i], info[i + n] = info[i];
	for (int i = 1; i <= n * 2; i++)
		dp[i] = 1;
	for (int i = 2; i <= n * 2; i++)
		if (info[i] < info[i - 1])
			dp[i] = dp[i - 1] + 1, ans = max(ans, dp[i]);
	cout << ans << endl;
}