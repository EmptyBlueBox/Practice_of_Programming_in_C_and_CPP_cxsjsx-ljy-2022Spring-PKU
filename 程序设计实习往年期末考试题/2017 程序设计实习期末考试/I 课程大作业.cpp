#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//把每一种完成情况都看成一个状态，每一种情况是其少完成一门课的子情况和只完成后一门课的情况之和的最小值
int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, ddl[15], req[15];
		string name[15];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> name[i] >> ddl[i] >> req[i];

		vector<int> sum(1 << n, 0);//某几个课所需完成时间之和
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					sum[i] = sum[i ^ (1 << j)] + req[j];//完成时间之和等于除去一位的sum加上这一位对应的课程的需要时间
		vector<int> dp(1 << n, 0x3f3f3f3f);//某几个课的最小扣分
		dp[0] = 0;
		vector<string> ans(1 << n);//某几个课的最小扣分的对应选课顺序
		for (int i = 1; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) { //枚举每一种少一门课的情况
					int plus_deduct = max(0, sum[i] - ddl[j]);
					if (dp[i ^ (1 << j)] + plus_deduct < dp[i])//扣分更少
						dp[i] = dp[i ^ (1 << j)] + plus_deduct, ans[i] = ans[i ^ (1 << j)] + name[j] + '\n';
					if (dp[i ^ (1 << j)] + plus_deduct == dp[i] && ans[i] > ans[i ^ (1 << j)] + name[j] + '\n')//扣分一样但是完成科目字典序更小
						ans[i] = ans[i ^ (1 << j)] + name[j] + '\n';
				}
		cout << dp[(1 << n) - 1] << endl << ans[(1 << n) - 1];
	}
}