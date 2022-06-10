#include <iostream>
#include <cstring>
using namespace std;

const int up = 1, down = 0;//第一个比第二个短是up型排列，反之为down型排列
long long dp[21][21][2] = { {{0}} };//dp[木板总数][以第几短的木板开头][上升还是下降]
void ini() { //dp出来dp数组的基础数据
	dp[1][1][up] = dp[1][1][down] = 1;//可以这样连等
	for (int i = 2; i <= 20; i++)//木板个数
		for (int j = 1; j <= i; j++) { //枚举i个木板中第一个木板
			for (int k = 1; k <= j - 1; k++)
				//i个木板以第j短为第一块木板的上升型排列个数是i-1个木板以第1，……，j-1短为第一块木板的下降型排列个数之和
				dp[i][j][down] += dp[i - 1][k][up];
			for (int k = j; k <= i - 1; k++)
				//i个木板以第j短为第一块木板的下降型排列个数是i-1个木板以第j，……，i-1短为第一块木板的上升型排列个数之和
				dp[i][j][up] += dp[i - 1][k][down];
		}
}
void f(int n, long long c) {
	int ans[21] = { 0 };
	bool used[21] = { false };
	//第i个位置长j
	for (int i = 1; i <= n; i++) { //第i个位置
		int tmp_no = 1;//i位置的木板在剩下的木板中排第几短
		for (int j = 1; j <= n; j++) { //i位置的木板长度j
			if (used[j])
				continue;
			long long skipped = 0;
			if (i == 1)
				skipped = dp[n][tmp_no][up] + dp[n][tmp_no][down];
			else { //i不是第一木板就会被前一个木板限制up型还是down型
				if (j > ans[i - 1] && (i == 2 || ans[i - 1] < ans[i - 2]))
					skipped = dp[n - i + 1][tmp_no][down];
				else if (j < ans[i - 1] && (i == 2 || ans[i - 1] > ans[i - 2]))
					skipped = dp[n - i + 1][tmp_no][up];
			}
			if (skipped >= c) {
				used[j] = true;
				ans[i] = j;
				break;
			} else
				c -= skipped;
			tmp_no++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
}
int main() {
	int N;
	cin >> N;
	ini();
	while (N--) {
		int n;
		long long c;//排列数目很大，需要用long long
		cin >> n >> c;
		f(n, c);
	}
}