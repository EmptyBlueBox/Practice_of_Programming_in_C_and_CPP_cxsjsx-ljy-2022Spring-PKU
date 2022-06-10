#include <iostream>
using namespace std;

int main() {
	int n, a[1001], dp[1001] = { 0 }, ans = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], dp[i] = a[i];//最大上升子序列要注意自己一个也算一个上升子序列，要特殊初始化dp
		for (int j = 1; j < i; j++)
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + a[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}