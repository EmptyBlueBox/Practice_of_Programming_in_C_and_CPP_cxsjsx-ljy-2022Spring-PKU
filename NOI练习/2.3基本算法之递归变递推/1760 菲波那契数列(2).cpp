#include <iostream>
using namespace std;

int n, dp[1000001], a;
int main() {
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= 1000000; i++)
		dp[i] = dp[i - 1] + dp[i - 2], dp[i] %= 1000;
	cin >> n;
	while (n--)
		cin >> a, cout << dp[a] << endl;
}