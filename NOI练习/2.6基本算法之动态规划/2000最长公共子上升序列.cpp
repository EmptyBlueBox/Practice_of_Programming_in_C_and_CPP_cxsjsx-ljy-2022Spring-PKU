//https://blog.csdn.net/wall_f/article/details/8279733
//https://blog.csdn.net/witnessai1/article/details/78129051
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//最长上升子序列是dp[i]，dp[i]是以a[i]为结尾的最长上升子序列长度
//最长公共子序列是dp[i][j]，a[i]、b[j]内最长的
//最长上升公共子序列是dp[i][j]，i是以a[i]为结尾的，j是b[j]内的
class info {
	public:
		int Max_Length = 0;
		vector<long long> Num;
};
long long a[501], b[501];
info dp[501], ans;
int main() {
	int la, lb;
	cin >> la;
	for (int i = 1; i <= la; i++)
		cin >> a[i];
	cin >> lb;
	for (int i = 1; i <= lb; i++)
		cin >> b[i];
	for (int j = 1; j <= lb; j++) {
		info maxa;
		maxa.Max_Length = 0;
		for (int i = 1; i <= la; i++) {
			if (a[i] == b[j]) {
				dp[i] = maxa;
				dp[i].Max_Length++;
				dp[i].Num.push_back(a[i]);
				ans = ans.Max_Length > dp[i].Max_Length ? ans : dp[i];
			}
			//如果不等于dp[i]就不变，因为dp是滚动数组，dp[i][j]只与dp[i][j-1]有关，而与dp[i][j-2]及以前的无关
			//实际上还与dp[i-k][j]有关，因此应该从前往后滚动
			//（背包问题与dp[v-i][j-1]有关，因此应该从后往前滚动）
			//else if (a[i] != b[j])
			//	dp[i] = dp[i];
			if (a[i] < b[j])//维护maxa
				maxa = maxa.Max_Length > dp[i].Max_Length ? maxa : dp[i];
		}
	}
	cout << ans.Max_Length << endl;
	for (int i = 0; i < (int)ans.Num.size(); i++)
		cout << ans.Num[i] << ' ';
}
