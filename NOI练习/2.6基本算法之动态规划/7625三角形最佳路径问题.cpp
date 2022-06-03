#include <iostream>
using namespace std;

int dp[101][101] = { {0} };
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> dp[i][j], dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]), ans = max(ans, dp[i][j]);
	cout << ans << endl;
}