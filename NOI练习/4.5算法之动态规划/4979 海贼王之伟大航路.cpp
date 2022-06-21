#include <iostream>
#include <cstring>
using namespace std;

int n, a[17][17] = { {0} }, dp[17][1 << 16] = { {0} };//最后一步走到了i，总状态是j
int main() {
	memset(dp, 0x3f, sizeof(dp));//memset用一个字节
	dp[1][1] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 0; i < (1 << n); i++)//枚举每一个状态最后走的那一步的起始点
		for (int j = 1, _j = 1; j <= n; j++, _j <<= 1)//最后一步的起点j
			for (int k = 1, _k = 1; k <= n; k++, _k <<= 1)//最后一步的终点k
				if (i & _j && i & _k)
					dp[k][i] = min(dp[k][i], dp[j][i ^ _k] + a[j][k]);//最后一步是从j到k
	cout << dp[n][(1<<n)-1] << endl;//按位运算符（除了按位取反）优先级小于加减运算和比大小运算，一定加括号！！！
}