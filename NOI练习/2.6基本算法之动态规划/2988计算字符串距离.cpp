#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][1001];
int main() {
	int N;
	cin >> N;
	while (N--) {
		string a, b;
		cin >> a >> b;
		int la = a.length(), lb = b.length();
		a.insert(0, "0"), b.insert(0, "0");//字符串最大公共序列不能用0下标
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= 1000; i++)//初始化dp
			dp[0][i] = i, dp[i][0] = i;

		for (int i = 1; i <= la; i++)
			for (int j = 1; j <= lb; j++) {
				if (a[i] == b[j])//笔误，不是(a[i] == a[j])
					dp[i][j] = dp[i - 1][j - 1];
				else
					//因为可以选择修改字符串，可以是dp[i - 1][j - 1]修改了第i个字符得到了dp[i][j]
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		cout << dp[la][lb] << endl;
	}
}