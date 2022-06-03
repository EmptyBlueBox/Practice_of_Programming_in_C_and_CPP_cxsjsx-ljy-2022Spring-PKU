#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, k, dp[7][41] = { {0} };
	string a;
	cin >> n >> k >> a;
	a.insert(0, "0");
	for (int i = 1; i <= n; i++)
		dp[0][i] = atoi(a.substr(1, i).c_str());
	for (int i = 1; i <= k; i++)//几个乘号
		for (int j = i + 1; j <= n; j++)//前几个字母
			for (int k = i + 1; k <= j; k++)//最后一个乘号后的部分
				dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] * atoi(a.substr(k, j - k + 1).c_str()));
	cout << dp[k][n] << endl;
}