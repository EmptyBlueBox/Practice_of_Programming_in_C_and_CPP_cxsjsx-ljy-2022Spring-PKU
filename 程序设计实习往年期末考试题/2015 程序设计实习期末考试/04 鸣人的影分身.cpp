#include <iostream>
using namespace std;

int dp[11][11] = { {0} };
int f(int m, int n) {
	if (dp[m][n])
		return dp[m][n];
	else if (m == 0 || n == 0 || n == 1)
		return 1;
	if (m >= n)
		dp[m][n] = f(m, n - 1) + f(m - n, n);
	else if (m < n)
		dp[m][n] = f(m, m);
	return dp[m][n];
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		int m, n;
		cin >> m >> n;//能量、分身个数
		cout << f(m, n) << endl;
	}
}