#include <iostream>
using namespace std;

int dp[11][11] = { {0} };
int f(int n, int m) {
	if (dp[n][m])
		return dp[n][m];
	if (n == 0 || n == 1 || m == 1)
		return 1;
	if (n <= m)
		dp[n][m] = f(n - 1, m) + f(n, m - n);
	else
		dp[n][m] = f(m, m);
	return dp[n][m];
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, m;
		cin >> m >> n;
		cout << f(n, m) << endl;
	}
}