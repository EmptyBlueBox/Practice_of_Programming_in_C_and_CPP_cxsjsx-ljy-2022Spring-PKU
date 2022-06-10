#include <iostream>
using namespace std;

//a_n = 3 * a_n - 2 + 2 * a_n - 4 + 2 * a_n - 6 + ... + 2 * a_0
int main() {
	int dp[31] = { 0 };
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= 30; i++) {
		if (i % 4 == 1 || i % 4 == 3)
			continue;
		dp[i] += 3 * dp[i - 2];
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}
	int n;
	while (cin >> n && n != -1)
		cout << dp[n] << endl;
}