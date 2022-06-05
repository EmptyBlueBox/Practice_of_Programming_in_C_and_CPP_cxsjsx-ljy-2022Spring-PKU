#include <iostream>
using namespace std;

int main() {
	long long n, dp[51] = { 0 };
	dp[1] = 2, dp[2] = 3;//取一个数有两种情况不是一种！！！
	cin >> n;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n] << endl;
}