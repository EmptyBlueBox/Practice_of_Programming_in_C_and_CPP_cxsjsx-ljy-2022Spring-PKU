#include <iostream>
using namespace std;

//找好状态，不好递推就增加信息，提供最后在哪里终结的信息
int main() {
	int n, tp, info[101][2] = { {0} }, dp[101][2] = { {0} };//前n个，以哪个城市终结
	cin >> n >> tp;
	for (int i = 1; i <= n; i++)
		cin >> info[i][0] >> info[i][1];
	dp[1][0] = info[1][0], dp[1][1] = info[1][1];
	for (int i = 2; i <= n; i++)
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - tp) + info[i][0], dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - tp) + info[i][1];
	cout << max(dp[n][0], dp[n][1]) << endl;
}