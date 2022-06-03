#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, info[500], dis[500][500] = { {0} }, dp[500][500] = { {0} };//i个邮局j个学校的最小值
int main() {
	cin >> n >> m;
	for (int i = 2; i <= n; i++)
		cin >> info[i], info[i] += info[i - 1];
	//初始化数组
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			dis[i][j] = dis[i][j - 1] + info[j] - info[(i + j) / 2];//dis[i][j]是[i,j]区间有一个学校的最小总距离，info[j] - info[(i + j) / 2]重要！！！
	for (int i = 1; i <= n; i++)
		dp[1][i] = dis[1][i];//前i个村庄一个学校，最大值不是最后一个学校的坐标！！！
	//动态规划
	for (int i = 2; i <= m; i++)//i个学校
		for (int j = i; j <= n; j++)//前j个村庄,至少i个村庄
			for (int k = i - 1; k <= j - 1; k++)//在前k个村庄放i-1个学校
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + dis[k + 1][j]);//枚举最后一个学校的作用范围！！！
	cout << dp[m][n] << endl;
}