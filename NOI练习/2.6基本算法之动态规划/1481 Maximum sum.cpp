#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int n, ans = 0xc0c0c0c0;
		cin >> n;
		//dp[i]是i为结尾的最大子段和，ans[i]是i及其之前的最大字段和的最大值
		vector<int> info(n + 2, 0), dp1(n + 2, 0), dp2(n + 2, 0), ans1(n + 2, 0), ans2(n + 2, 0);
		for (int i = 1; i <= n; i++)
			cin >> info[i];
		dp1[1] = info[1], ans1[1] = info[1];
		for (int i = 2; i <= n; i++)
			dp1[i] = max(dp1[i - 1] + info[i], info[i]), ans1[i] = max(ans1[i - 1], dp1[i]);
		dp2[n] = info[n], ans2[n] = info[n];
		for (int i = n - 1; i >= 1; i--)//从n-1开始不是从n开始
			dp2[i] = max(dp2[i + 1] + info[i], info[i]), ans2[i] = max(ans2[i + 1], dp2[i]);
		for (int i = 1; i <= n - 1; i++)
			ans = max(ans, ans1[i] + ans2[i + 1]);
		cout << ans << endl;
	}
}