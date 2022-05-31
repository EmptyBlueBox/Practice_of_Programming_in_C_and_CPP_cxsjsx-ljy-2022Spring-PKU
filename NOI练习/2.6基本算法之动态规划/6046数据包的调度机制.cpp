#include <iostream>
#include <cstring>
using namespace std;

//区间dp，对每一个区间枚举将哪个数据包放在最后发送
int dp[101][101] = { {0} };//开到main函数外面否则WA！！！
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(dp, 0, sizeof(dp));
		int n, info[101] = { 0 };//只发送第i到j个数据包的最小延迟
		int presum[101] = { 0 };//前缀和
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> info[i], presum[i] = presum[i - 1] + info[i];//不要直接读到dp[i][i]里，dp[i][i]应该是0！！！
		for (int len = 1; len <= n; len++)//枚举区间长度，不要枚举右端点！！！
			for (int l = 1; l <= n; l++) { //枚举左端点
				int r = l + len - 1;//枚举右端点
				if (r > n)//防止溢出
					break;
				dp[l][r] = 0x3f3f3f3f;//区间dp要在得到l和r之后再初始化！！！
				for (int k = l; k <= r; k++)//枚举最后一个数据包
					dp[l][r] = min(dp[l][r], dp[l][k - 1] + info[k] * (len - 1) + dp[k + 1][r] + (presum[r] - presum[k]) * (k - l));
			}
		cout << dp[1][n] << endl;
	}
}
