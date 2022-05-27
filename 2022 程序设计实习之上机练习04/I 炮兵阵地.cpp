#include <iostream>
#include <algorithm>
using namespace std;

//状态压缩动态规划
//每一行只与前两行有关，先初始化前两行的dp值，在从第三行开始递推
int n, m, dp[101][100][100] = { {{0}} };//第几行，这一行的状态是valid的第几个，前一行的状态是valid的第几个
int main() {
	cin >> n >> m;
	int map[101] = { 0 };
	char x;
	if (n == 1 && m == 1) { //特判1行1列
		cin >> x;
		cout << (x == 'P') << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x == 'H') //1位代表山
				map[i] += (1 << j);
		}
	int valid[101] = { 0 }, cnt1[101] = { 0 };//每一行在满足这一行不互炸的情况下的所有情况，valid[0]储存这些情况的个数
	for (int i = 0; i < (1 << m); i++) {
		if ((i & (i << 1)) == 0 && (i & (i >> 1)) == 0 && (i & (i << 2)) == 0 && (i & (i >> 2)) == 0) {
			valid[++valid[0]] = i;
			int cnt = 0;
			for (int j = 0; j < m; j++)
				if ((1 & (i >> j)) == 1)
					cnt++;
			cnt1[valid[0]] = cnt;
		}
	}
	for (int i = 1; i <= valid[0]; i++)//第二行
		for (int j = 1; j <= valid[0]; j++)//第一行
			if ((valid[i] & valid[j]) == 0 && (valid[j] & map[1]) == 0 && (valid[i] & map[2]) == 0)
				dp[2][i][j] = cnt1[i] + cnt1[j];//初始化第二行
	for (int i = 3; i <= n; i++)//一行一行递推
		for (int j = 1; j <= valid[0]; j++)//枚举第i行状态
			if ((map[i] & valid[j]) == 0)//第i行与地形不冲突
				for (int k = 1; k <= valid[0]; k++)//枚举i-1行
					if ((map[i - 1] & valid[k]) == 0 && (valid[k] & valid[j]) == 0)//i-1行与地形不冲突，i-1行与i行不冲突
						for (int l = 1; l <= valid[0]; l++)//枚举i-2行
							if ((map[i - 2] & valid[l]) == 0 && (valid[l] & valid[k]) == 0 && (valid[l] & valid[j]) == 0)//i-2行与地形不冲突，i-2行与i-1行不冲突，i-2行与i行不冲突
								dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + cnt1[j]);
	int ans = 0;
	for (int i = 1; i <= valid[0]; i++)
		for (int j = 1; j <= valid[0]; j++)
			ans = max(ans, dp[n][i][j]);
	cout << ans << endl;
}