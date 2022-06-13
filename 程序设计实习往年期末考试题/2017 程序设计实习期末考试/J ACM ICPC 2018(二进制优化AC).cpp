#include <iostream>
#include <cstring>
using namespace std;

//先对蛋糕和箱子做一定w内最大v的两次多重dp[w]，使用二进制优化
//蛋糕的w是蛋糕大小，v是能量，循环大小找到能量大于e的最小蛋糕大小
//箱子的w是价钱，v是箱子容量，循环价钱找到箱子容量大于上述蛋糕大小的最少价钱
int dp1[2000001] = { 0 }, dp2[50002] = { 0 };
vector<pair<int, int>> g1, g2;
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		g1.clear(), g2.clear();
		int cake, chest, energy, v, w, m, max_cake = 0, max_money = 0;
		cin >> cake >> chest >> energy;
		for (int i = 1; i <= cake; i++) {
			cin >> v >> w >> m, max_cake += w * m;
			for (int j = 1; j <= m; j *= 2) { //二进制拆分
				m -= j;
				g1.push_back({ v * j,w * j });
			}
			if (m) g1.push_back({ v * m,w * m });//拆剩下的也存进去
		}
		for (int i = 1; i <= chest; i++) {
			cin >> v >> w >> m, max_money += w * m;
			for (int j = 1; j <= m; j *= 2) {
				m -= j;
				g2.push_back({ v * j,w * j });
			}
			if (m) g2.push_back({ v * m,w * m });
		}
		//dp1，一定空间蛋糕最多，找最少空间
		for (int i = 0; i < g1.size(); i++)
			for (int j = max_cake; j >= g1[i].second; j--)
				dp1[j] = max(dp1[j], dp1[j - g1[i].second] + g1[i].first);
		int size_needed = 1;
		while (dp1[size_needed] < energy) size_needed++;
		//dp2，一定钱空间最大，找满足上述空间的最少钱
		max_money = min(max_money, 50001);//要限制钱数不能太多，否则TLE
		for (int i = 0; i < g2.size(); i++)
			for (int j = max_money; j >= g2[i].second; j--)
				dp2[j] = max(dp2[j], dp2[j - g2[i].second] + g2[i].first);
		int money_needed = 1;
		while (dp2[money_needed] < size_needed && money_needed <= 50000) money_needed++;

		cout << (money_needed > 50000 ? "FAIL" : to_string(money_needed)) << endl;
	}
}