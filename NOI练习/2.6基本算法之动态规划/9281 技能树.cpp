#include <iostream>
using namespace std;

int n, d, dp[301][100] = { {0} }, sum[301][100] = { {0} };//n个节点，深度为d
int main() {
	//dp[i][j]：节点数为i，深度j；sum[i][j]：节点数为i深度小于等于j
	dp[1][1] = sum[1][1] = 1;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= d; j++) {
			for (int k = 1; k <= i - 1; k++)//拿走最上面的节点，分别看左右树，假设左树深d - 1，则右树种类为sum[i - 1 - k][j - 1],相乘，再乘二，减去重复
				dp[i][j] += dp[k][j - 1] * sum[i - 1 - k][j - 1] * 2 - dp[k][j - 1] * dp[i - 1 - k][j - 1], dp[i][j] %= 9901;
			sum[i][j] = sum[i][j - 1] + dp[i][j], sum[i][j] %= 9901;
		}
	cout << dp[n][d] << endl;
}