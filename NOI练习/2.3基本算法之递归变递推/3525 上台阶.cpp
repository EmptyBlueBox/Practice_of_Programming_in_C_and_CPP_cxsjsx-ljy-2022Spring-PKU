#include <iostream>
using namespace std;

long long n, dp[100];
int main() {
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (long long i = 4; i < 100; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	while (cin >> n && n)
		cout << dp[n] << endl;
}