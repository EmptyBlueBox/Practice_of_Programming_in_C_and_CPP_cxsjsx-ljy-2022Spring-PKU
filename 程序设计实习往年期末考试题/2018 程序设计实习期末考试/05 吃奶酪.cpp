#include <iostream>
using namespace std;

long long info[100001] = { 0 }, dp[100001] = { 0 };
int main() {
	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> info[i];
		dp[1] = info[1] > 0 ? info[1] : 0;//注意初始化，info[1]可能是负数
		for (int i = 2; i <= n; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + info[i]);
		cout << dp[n] << endl;
	}
}