#include <iostream>
using namespace std;

//必须互相挨着在一起！！！
int main() {
	int N, n, dp[200001] = { 0 }, sum = 1, M = 1;//用前缀和做到O(N)
	dp[1] = 1;
	cin >> N;
	while (N--) {
		cin >> n;
		if (dp[n])
			goto LOOP;
		for (int i = M + 1; i <= n; i++)
			dp[i] = (dp[i - 1] + sum) % 100000, sum = (sum + dp[i]) % 100000;//不是10000
		M = n;
LOOP:
		;
		cout << dp[n] << endl;
	}
}