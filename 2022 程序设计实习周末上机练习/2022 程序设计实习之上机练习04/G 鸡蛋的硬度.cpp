#include <iostream>
#include <algorithm>
using namespace std;

int n, m, dp[101][11];//n层楼m个鸡蛋扔几次
int f(int n, int m) {
	if (dp[n][m] != 0x3f3f3f3f)return dp[n][m];
	if (m == 1)return n;//只有一个鸡蛋扔n次
	if (n == 0)return 0;//0层楼不用扔
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) //每一层楼都扔，看哪个扔的最少
		ans = min(ans, max(f(i - 1, m - 1), f(n - i, m)) + 1);//取所有楼层扔鸡蛋的最少次数加一，对于每一层楼取碎或不碎的最差情况
	return dp[n][m] = ans;
}
int main() {
	while (cin >> n >> m) {
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 11; j++)
				dp[i][j] = 0x3f3f3f3f;
		cout << f(n, m) << endl;
	}
}