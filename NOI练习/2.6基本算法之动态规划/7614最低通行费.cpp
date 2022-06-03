#include <iostream>
#include <cstring>
using namespace std;

int dp[100][100] = { {0} };
int main() {
	memset(dp, 0x3f, sizeof(dp));//斜边dp可以进行恰当的初始化，从而不用严格卡循环什么时候停止
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dp[i][j];
	for (int i = 3; i <= 2 * n; i++)//i从3开始，不是2！！！
		for (int j = 1; j <= n && j < i; j++) {
			int k = i - j;
			dp[j][k] += min(dp[j - 1][k], dp[j][k - 1]);
		}
	cout << dp[n][n] << endl;
}