#include <iostream>
#include <algorithm>
using namespace std;
//把每一行加起来
int n, a[101][101];
//动态规划寻找最大连续子序列和
inline int Max_Sum(int* sum) {
	int dp[101] = { 0 };
	int ans = 0xc0c0c0c0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + sum[i], sum[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}
int main() {
	cin >> n;
	if (n == 1) {
		cin >> n;
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	int ans = 0xc0c0c0c0;
	for (int i = 1; i <= n; i++) {
		int sum[101] = { 0 };
		for (int j = i; j <= n; j++) {
			//从第i行加n-i次,每次加第j行
			for (int k = 1; k <= n; k++)
				sum[k] += a[j][k];
			ans = max(ans, Max_Sum(sum));
		}
	}
	cout << ans << endl;
}