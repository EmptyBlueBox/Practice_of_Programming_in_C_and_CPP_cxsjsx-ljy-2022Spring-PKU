#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, m,info[302], dis[302][302] = { {0} }, dp[32][302] = { {0} };//i个邮局j个村庄的最小值
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> info[i];
	//初始化数组
	//dis[i,j]是[i,j]区间有一个邮局的最小距离和
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			dis[i][j] = dis[i][j - 1] + info[j] - info[(i + j) / 2];
	for (int i = 1; i <= 31; i++)
		for (int j = 1; j <= 301; j++)
			dp[i][j] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		//前i个村庄一个邮局，最大值不是最后一个邮局的坐标！！！
		dp[1][i] = dis[1][i];
	//动态规划
	for (int i = 2; i <= m; i++)//i个邮局
		for (int j = i; j <= n; j++)//前j个村庄,至少i个村庄
			for (int k = i - 1; k <= j - 1; k++)//在前k个村庄放i-1个邮局
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + dis[k + 1][j]);
	cout << dp[m][n] << endl;
}