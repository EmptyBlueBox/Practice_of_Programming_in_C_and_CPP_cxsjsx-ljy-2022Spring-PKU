#include <iostream>
using namespace std;

//每份不能为0的分苹果！！！
int dp[201][7] = { {0} };
int f(int n, int k) {
	if (dp[n][k])
		return dp[n][k];
	else if (n == 0 || n < k)//必出现一份是0
		return 0;
	else if (k == 1 || n == k)//只有一种分法
		return 1;
	dp[n][k] = f(n - k, k) + f(n - 1, k - 1);//dp[n][k] = 每一份至少俩 + 有一份只有一个！！！
	return dp[n][k];
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << f(n, k) << endl;
}