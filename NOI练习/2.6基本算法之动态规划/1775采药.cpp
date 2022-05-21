#include <iostream>
using namespace std;

//01背包
int main() {
	int v, n, c[100], w[100], dp[1001] = { 0 };//n个物品装进大小为v的背包
	cin >> v >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> w[i];
		if (c[i] > v)//注意特判！！！如果根本装不下就置为0
			c[i] = 0, w[i] = 0, i--, n--;//不减n，只c[i] = 0, w[i] = 0;也可以
	}
	for (int i = 0; i < n; i++)
		for (int j = v; j >= c[i]; j--)//这里下界应该是c[i]！！！
			dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
	cout << dp[v] << endl;
}