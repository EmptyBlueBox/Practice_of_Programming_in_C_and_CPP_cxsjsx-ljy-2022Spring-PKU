#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long dp[21];
	dp[1] = 1, dp[2] = 1;
	for (int i = 3; i <= 20; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	while (N--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
}