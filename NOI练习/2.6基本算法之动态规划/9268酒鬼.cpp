#include <iostream>
using namespace std;

int main()
{
	int n, info[701] = { 0 }, dp[701] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> info[i];
	dp[1] = info[1], dp[2] = info[1] + info[2];
	for (int i = 3; i <= n; i++)
		//不能将dp[i]看成前i个必喝i的最大值！！！
		//因为递推的时候不一定必须喝i-3或者i-1，可能i-4、i-5非常大，dp[i-3]不划算
		//7 5 8 7 1 6 10 10答案是35，如果将dp[i]看成前i个必喝i的最大值，答案就是34
		dp[i] = max(max(dp[i - 3] + info[i - 1], dp[i - 2]) + info[i], dp[i - 1]);
	cout << dp[n] << endl;
}