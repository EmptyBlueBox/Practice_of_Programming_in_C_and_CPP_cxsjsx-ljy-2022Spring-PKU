#include <iostream>
#include <cstring>
using namespace std;

int n, info[4001][2], dp[4001][4001] = { {0} };//前i个sad j个的最小GPA和
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> info[1][0] >> info[1][1];
	memset(dp, 0x3f, sizeof(0x3f));
	dp[1][0] = min(info[1][0], info[1][1]);
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			for (int k = 0; k < 2; k++)
				if (info[i][k] * (i - 1) < dp[i - 1][j])
					dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + info[i][k]);
				else
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + info[i][k]);
	for (int i = 1; i <= n; i++)
		if (dp[n][i] != 0x3f3f3f3f) {
			cout << i << endl;
			return 0;
		}
}