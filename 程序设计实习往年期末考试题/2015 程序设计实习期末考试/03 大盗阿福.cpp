#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, tmp, ans = 0, dp[100001] = { 0 };//以i为结尾的最多偷窃数额
		cin >> n;
		if (n == 1) {
			cin >> dp[1];
			cout << dp[1] << endl;
			continue;
		}
		cin >> dp[1] >> dp[2];
		ans = max(dp[1], dp[2]);
		for (int i = 3; i <= n; i++)
			cin >> dp[i], dp[i] += max(dp[i - 2], dp[i - 3]), ans = max(ans, dp[i]);
		cout << ans << endl;
	}
}