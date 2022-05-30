#include <iostream>
#include <cstring>
using namespace std;

//整除问题第二个参数是余数
bool dp[10001][100] = { {false} };
int main() {
	int n, k, tmp;
	dp[0][0] = true;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 0; j < k; j++)
			dp[i][j] = ((dp[i - 1][(j - tmp % k + k) % k] == true) || (dp[i - 1][(j + tmp % k) % k] == true));
	}
	if (dp[n][0])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}