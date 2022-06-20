#include <iostream>
#include <string>
using namespace std;

//long long！！！
//根据各位之和为3的倍数进行动态规划，DFS超时
long long n, info[19][3] = { {0} }, dp[19][3] = { {0} };
int main() {
	cin >> n;
	long long cnt, tmp;
	for (long long i = 1; i <= n; i++) {
		cin >> cnt;
		for (long long j = 1; j <= cnt; j++)
			cin >> tmp, info[i][tmp % 3]++;
	}
	for (int i = 0; i < 3; i++)
		dp[1][i] = info[1][i];
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j] += dp[i - 1][k] * info[i][(3 + j - k) % 3];
	cout << dp[n][0] << endl;
}