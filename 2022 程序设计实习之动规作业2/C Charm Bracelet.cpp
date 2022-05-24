#include <iostream>
using namespace std;

int main() {
	int n, c, w[3402], v[3402], dp[12881] = { 0 };//恰好装满才赋值负无穷
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];
	for (int i = 0; i < n; i++)
		for (int j = c; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[c] << endl;
}