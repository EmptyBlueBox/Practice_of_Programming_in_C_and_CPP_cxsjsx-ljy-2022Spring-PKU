#include <iostream>
using namespace std;

bool dp[10001][100] = { {0} };
int main() {
	dp[0][0] = true;
	int n, k, tmp;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 0; j < k; j++)
			dp[i][j] = dp[i - 1][(j - tmp % k + k) % k] | dp[i - 1][(j + tmp % k) % k];
	}
	if (dp[n][0])
		cout << "Divisible\n";
	else
		cout << "Not divisible\n";
}