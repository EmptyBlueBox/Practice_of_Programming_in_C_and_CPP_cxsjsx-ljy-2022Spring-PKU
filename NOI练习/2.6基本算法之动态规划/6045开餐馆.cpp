#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, k;
		cin >> n >> k;
		int dis[100] = { 0 }, profit[100] = { 0 }, dp[100] = { 0 };//前i个的最大利润
		for (int i = 1; i <= n; i++)
			cin >> dis[i];
		for (int i = 1; i <= n; i++)
			cin >> profit[i], dp[i] = profit[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++)
				if (dis[i] - dis[j] > k)
					//不选第i个：dp[i-1]，选第i个：dp[j]+profit[i]
					dp[i] = max(max(dp[i - 1], dp[j] + profit[i]), dp[i]);
		cout << dp[n] << endl;
	}
}