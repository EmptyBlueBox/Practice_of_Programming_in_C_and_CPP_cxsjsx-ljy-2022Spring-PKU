#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, k, l[100], p[100], dp[100] = { 0 }, ans;//必须选第i个的最大利润
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> l[i];
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		dp[1] = p[1], ans = p[1];
		for (int i = 1; i <= n; i++) {
			dp[i] = p[i];
			for (int j = 0; j < i; j++)
				if (l[i] - l[j] > k)
					dp[i] = max(dp[i], dp[j] + p[i]), ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
}