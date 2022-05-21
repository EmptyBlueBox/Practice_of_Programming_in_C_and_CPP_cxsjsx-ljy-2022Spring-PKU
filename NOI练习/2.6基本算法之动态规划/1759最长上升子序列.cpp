#include <iostream>
using namespace std;

int main() {
	int n, a[1001], dp[1001], ans = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++)
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}