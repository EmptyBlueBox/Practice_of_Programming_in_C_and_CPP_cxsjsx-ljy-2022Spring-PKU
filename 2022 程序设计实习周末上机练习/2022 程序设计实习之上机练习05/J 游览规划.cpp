#include <iostream>
#include <cstring>
using namespace std;

//二维费用的01背包与完全背包混合
int dp[1001][2401] = { {0} };
int main() {
	int n, opendays, allmoney, v[101], w1[101], w2[101], ans = -1;//乐趣值，1：钱，2：时间
	bool is01[101];
	string tmp;
	cin >> opendays >> n >> allmoney;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w1[i] >> w2[i] >> tmp, is01[i] = tmp == "limited";
	for (int t = 1; t <= opendays; t++) { //枚举玩几天
		memset(dp, 0, sizeof(dp));
		int c1 = allmoney - (t / 3) * 200 - (t % 3 / 2) * 150 - (t % 3 % 2) * 100, c2 = t * 24;//t % 3 % 2要按顺序来，不能直接t % 2！！！
		if (c1 < 0) continue;
		for (int i = 1; i <= n; i++) {
			if (is01[i])
				for (int j = c1; j >= w1[i]; j--)
					for (int k = c2; k >= w2[i]; k--)
						dp[j][k] = max(dp[j][k], dp[j - w1[i]][k - w2[i]] + v[i]);
			else
				for (int j = w1[i]; j <= c1; j++)
					for (int k = w2[i]; k <= c2; k++)
						dp[j][k] = max(dp[j][k], dp[j - w1[i]][k - w2[i]] + v[i]);
		}
		ans = max(ans, dp[c1][c2]);
	}
	cout << ans << endl;
}