#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, dp[20] = { 0 };
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= 20; i++)
		dp[i] = dp[i - 1] + dp[i - 2];//一天吃一个第二天再吃一个跟dp[n-1]重复了
	cin >> n;
	cout << dp[n] << endl;
}