#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, t, mod = 1000007, dp[5010][5010] = { {0} };//盒子，小球
int main() {
	cin >> n >> m >> t;
	for (long long i = 0; i <= n; i++)//初始化0个盒子
		dp[i][0] = 1;
	for (long long i = 1; i <= m; i++) {
		int sum = 1;//加入滚动和，下一次的答案是sum
		for (long long j = 0; j <= n; j++) {
			dp[i][j] = sum;
			sum += dp[i - 1][j + 1], sum %= mod;
			if (j >= t)
				sum = (sum - dp[i - 1][j - t] + mod) % mod;
		}
	}
	cout << dp[m][n] << endl;
}