#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N, T;
	cin >> N;
	for (int T = 1; T <= N; T++) {
		int n, info[205], dp[205][205] = { {0} };
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> info[i];
		for (int i = 1; i <= n; i++)
			dp[i][i] = 1;
		for (int len = 2; len <= n; len++)
			for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
				dp[l][r] = 0x3f3f3f3f;//区间dp要在得到l、r之后再初始化为0x3f3f3f3f
				for (int k = l; k < r; k++)
					dp[l][r] = min(dp[l][r], dp[l][k] + (info[k] == info[r] ? dp[k + 1][r - 1] : dp[k + 1][r]));
			}
		printf("Case %d: ", T);
		cout << dp[1][n] << endl;
	}
}