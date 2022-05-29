#include <iostream>
using namespace std;

int main() {
	int n, k, tmp, dp[101][101] = { {0} }; //通过模k的余数缩小数组大小，dp[i][j]代表前i包糖总共模k余j最多的糖数
	for (int i = 1; i <= 100; i++)
		dp[0][i] = 0xc0c0c0c0;//没得可装不可能模k余正数，因此都是负无穷（类似背包问题初始化）
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 0; j < k; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - tmp % k + k) % k] + tmp);//j - tmp % k可能会出现负数，一个小技巧是加k再模k
	}
	cout << dp[n][0] << endl;
}