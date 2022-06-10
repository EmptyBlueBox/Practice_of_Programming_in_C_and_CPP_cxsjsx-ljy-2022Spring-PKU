#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//将最长上升子序列与最长下降子序列在中间连接起来
int main() {
	int n, altitude[1001] = { 0 }, ans = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> altitude[i];

	int dp1[1001], dp2[1001];
	//最长上升子序列要把dp数组初始值设置为1，因为它自己就是长度为1的上升子序列
	for (auto& i : dp1)
		i = 1;
	for (auto& i : dp2)
		i = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (altitude[i] > altitude[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j > i; j--)
			if (altitude[i] > altitude[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
	for (int i = 0; i < n; i++)
		ans = max(ans, dp1[i] + dp2[i]);
	cout << ans - 1 << endl;
}