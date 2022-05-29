#include <iostream>
using namespace std;

//不一定是两个相加！！！
int main() {
	int n, sum, info[21], dp[1001] = { 0 };
	cin >> n >> sum;
	for (int i = 1; i <= n; i++)
		cin >> info[i];
	dp[0] = 1;//0有一种组合方式
	for (int i = 1; i <= n; i++)
		for (int j = sum; j >= info[i]; j--)//类似01背包，下界要取等
			dp[j] += dp[j - info[i]];
	cout << dp[sum] << endl;
}