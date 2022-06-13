#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

//先对蛋糕和箱子做一定w内最大v的两次多重dp[w]，使用单调队列优化
//蛋糕的w是蛋糕大小，v是能量，循环大小找到能量大于e的最小蛋糕大小
//箱子的w是价钱，v是箱子容量，循环价钱找到箱子容量大于上述蛋糕大小的最少价钱
int dp1[2000001] = { 0 }, dp2[50000] = { 0 }, tmp_dp[2000001];
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		int cake, chest, e, v1[101], w1[101], m1[101], v2[101], w2[101], m2[101], max_cake = 0, max_money = 0;
		cin >> cake >> chest >> e;
		for (int i = 1; i <= cake; i++)
			cin >> v1[i] >> w1[i] >> m1[i], max_cake += w1[i] * m1[i];
		for (int i = 1; i <= chest; i++)
			cin >> v2[i] >> w2[i] >> m2[i], max_money += w2[i] * m2[i];
			
		for (int i = 1; i <= cake; i++) {
			memcpy(tmp_dp, dp1, sizeof(dp1));
			for (int j = 0; j < w1[i]; j++) { //枚举每一个余数
				deque<int> q;//存储dp模m1[i]余j的下标
				for (int k = j; k <= max_cake; k += w1[i]) {
					if (!q.empty() && k - w1[i] * m1[i] > q.front())//队头超出滑动窗口大小
						q.pop_front();
					while (!q.empty() && tmp_dp[k] >= tmp_dp[q.back()] + (k - q.back()) / w1[i] * v1[i])//新的比队尾更有价值
						q.pop_back();
					if (!q.empty())
						dp1[k] = max(dp1[k], tmp_dp[q.front()] + (k - q.front()) / w1[i] * v1[i]);
					q.push_back(k);
				}
			}
		}
		int size_needed = 1;
		while (dp1[size_needed] < e) size_needed++;
		
		for (int i = 1; i <= chest; i++) {
			memcpy(tmp_dp, dp2, sizeof(dp2));
			for (int j = 0; j < w2[i]; j++) { //枚举每一个余数
				deque<int> q;//存储dp模m2[i]余j的下标
				for (int k = j; k <= max_money; k += w2[i]) {
					if (!q.empty() && k - w2[i] * m2[i] > q.front())//队头超出滑动窗口大小
						q.pop_front();
					while (!q.empty() && tmp_dp[k] >= tmp_dp[q.back()] + (k - q.back()) / w2[i] * v2[i])//新的比队尾更有价值
						q.pop_back();
					if (!q.empty())
						dp2[k] = max(dp2[k], tmp_dp[q.front()] + (k - q.front()) / w2[i] * v2[i]);
					q.push_back(k);
				}
			}
		}
		int money_needed = 1;
		while (dp2[money_needed] < size_needed && money_needed <= 50000) money_needed++;
		
		cout << (money_needed > 50000 ? "FAIL" : to_string(money_needed)) << endl;
	}
}