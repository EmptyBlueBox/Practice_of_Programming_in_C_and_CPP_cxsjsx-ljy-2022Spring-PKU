#include <iostream>
#include <cstring>
using namespace std;

//最大上升子序列
int main() {
	int n, info[16], dp[16], ans = 0;
	for (int i = 1; i <= 15; i++)
		dp[i] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> info[i];
		for (int j = 1; j < i; j++)
			if (info[j] >= info[i])
				dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}