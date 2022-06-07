#include <iostream>
using namespace std;

enum DIR { UP, LEFT, RIGHT };
int main() {
	int n, dp[3][1001] = { {0} };
	dp[UP][1] = dp[LEFT][1] = dp[RIGHT][1] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
		dp[UP][i] = (dp[UP][i - 1] + dp[LEFT][i - 1] + dp[RIGHT][i - 1]) % 12345, dp[LEFT][i] = (dp[LEFT][i - 1] + dp[UP][i - 1]) % 12345, dp[RIGHT][i] = dp[LEFT][i];//利用对称性
	cout << (dp[UP][n] + 2 * dp[LEFT][n]) % 12345 << endl;//要模12345太坑了
}