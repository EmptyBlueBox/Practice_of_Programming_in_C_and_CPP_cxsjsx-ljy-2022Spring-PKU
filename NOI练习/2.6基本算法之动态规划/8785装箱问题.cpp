#include <iostream>
using namespace std;

//简单的01背包，重量和价值一样
int main() {
	int v, n, tmp_v,dp[20001] = { 0 };
	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp_v;
		for (int j = v; j >= tmp_v; j--)
			dp[j] = max(dp[j], dp[j - tmp_v] + tmp_v);
	}
	cout << v - dp[v] << endl;
}