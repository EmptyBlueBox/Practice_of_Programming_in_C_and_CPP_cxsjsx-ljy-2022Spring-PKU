#include <iostream>
using namespace std;

int main() {
	long long n, k, dp[51] = { 0 };
	cin >> n >> k;
	dp[0] = 1, dp[1] = 2;
	for (int i = 2; i <= k - 1; i++)//前k-1个坑怎么放都行
		dp[i] = 2 * dp[i - 1];
	dp[k] = dp[k - 1] * 2 - 1;//k个坑排除全放的情况
	for (int i = k+1; i <= n; i++)
		//dp[i] =（i不放的情况即dp[i-1]） + （i放即dp[i-1]减去放了i炸的情况，也就是i前k-1个放，1个不放的情况）
		dp[i] = dp[i - 1] * 2 - dp[i - k - 1];
	cout << dp[n] << endl;
}