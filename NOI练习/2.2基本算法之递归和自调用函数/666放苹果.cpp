#include <iostream>
#include <cstring>
using namespace std;

int dp[11][11];
int f(int m, int n) {
	if (dp[m][n] != 0)
		return dp[m][n];
	if (m == 0 || n == 1)
		return 1;
	if (m >= n) {
		dp[m][n] += f(m - n, n);
		dp[m][n] += f(m, n - 1);
	}
	else if (m < n)
		dp[m][n] += f(m, m);
	return dp[m][n];
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(dp, 0, sizeof(dp));
		int m, n;
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
}