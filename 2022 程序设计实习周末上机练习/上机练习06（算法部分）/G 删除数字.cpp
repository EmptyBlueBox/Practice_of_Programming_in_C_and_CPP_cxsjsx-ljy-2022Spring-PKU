#include <iostream>
#include <cstring>
using namespace std;

int n, info[1001], dp[1001][1001] = { {0} };//前i个删除j个有几个在自己的位置
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> info[i];
		dp[1][0] = info[1] == 1;
		for (int i = 2; i <= n; i++)//前i个数字
			for (int j = 0; j <= i; j++) { //删除j个
				if (j)
					dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j] + (info[i] == i - j)), dp[i][j]);//删除或不删除i位置
				else
					dp[i][0] = max(dp[i][j], dp[i - 1][0] + (info[i] == i));//不删除i位置
			}
		int ans = 0;
		for (int i = 0; i <= n; i++)
			ans = max(ans, dp[n][i]);
		cout << ans << endl;
	}
}