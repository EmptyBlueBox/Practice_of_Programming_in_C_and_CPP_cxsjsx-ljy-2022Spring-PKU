#include <iostream>
using namespace std;

int main() {
	int n, sum, a[200], dp[10001];
	cin >> n >> sum;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = sum; j >= a[i]; j--)
			dp[j] += dp[j - a[i]];//先算出来所有硬币的组合数目（使用了滚动数组）

	int ans[201] = { 0 }, dp1[10001] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= sum; j++)
			dp[j] -= dp[j - a[i]];//回退最后一个硬币，如果不能组成sum则这是一个答案
		if (dp[sum] == 0)
			ans[++ans[0]] = a[i];
		for (int j = sum; j >= a[i]; j--)
			dp[j] += dp[j - a[i]];//再dp回去最后一个硬币
	}
	cout << ans[0] << endl;
	for (int i = 1; i <= ans[0]; i++)
		cout << ans[i] << ' ';
	cout << endl;
}
