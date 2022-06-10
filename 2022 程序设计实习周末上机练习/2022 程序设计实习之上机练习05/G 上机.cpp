#include <iostream>
#include <cstring>
using namespace std;

//按座位顺序循环
int a[10001], b[10001], c[10001], dp[10002][2][2] = { {{{0}}} };//坐了前i个位置，第i个人坐的时候左边有无人，右边有无人
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	dp[1][0][0] = a[1], dp[1][1][0] = 0xc0c0c0c0, dp[1][0][1] = b[1], dp[1][1][1] = 0xc0c0c0c0;
	for (int i = 2; i <= n; i++) {
		//只考虑前i个人的总和！！！
		dp[i][0][0] = max(dp[i - 1][0][1], dp[i - 1][1][1]) + a[i];//相当于先坐i再坐i-1，坐i时左右都没有人的i前所有之和 = 坐i-1时右边有人的i-1前所有 + a[i]
		dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + b[i];//坐i时左有人的i前所有之和 = 坐i-1时右边无人的i-1前所有 + b[i]
		dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]) + b[i];
		dp[i][1][1] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + c[i];
	}
	cout << max(dp[n][1][0], dp[n][0][0]) << endl;
}