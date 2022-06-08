#include <iostream>
#include <cstring>
using namespace std;

//前缀和优化时间
//f[i][j] = f[i - 1][j] + f[i - 1][j - 1] + ... + f[i - 1][j - Ni]
//		  = f[i - 1][j] + (f[i - 1][j - 1] + ... + f[i - 1][j - Ni] + f[i - 1][j - Ni - 1]) - f[i - 1][j - Ni - 1]
//		  = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - Ni - 1]
int T, n, a, b, info[1001] = { 0 }, dp[100001] = { 0 }, former_dp[100001] = { 0 };
int main() {
	cin >> T >> n >> a >> b;
	int tmp;
	for (int i = 1; i <= n; i++)
		cin >> tmp, info[tmp]++;
	for (int i = 1; i <= T; i++) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int j = 1; j <= n; j++) {
			dp[j] = former_dp[j] + dp[j - 1];
			if(j>info[i])
				dp[j]-= former_dp[j - info[i] - 1];
			dp[j] %= 1000000;
		}
		for (int i = 1; i <= info[i]; i++)
			former_dp[i] = dp[i];
	}
	int ans = 0;
	for (int i = a; i <= b; i++)
		ans += dp[i], ans %= 1000000;
	cout << ans << endl;
}