#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int pos, dp;
	node(int _pos, int _dp) :pos(_pos), dp(_dp) {}
	bool operator<(node a)const {
		return dp > a.dp;    //优先队列是>排列的
	}
};
int dp[1000010];
bool hascow[1000010] = { false };
int main() {
	int n, l, a, b;
	priority_queue<node> q;
	cin >> n >> l >> a >> b, a <<= 1, b <<= 1;//把a、b变成直径
	while (n--) { //初始化hascow，记录哪里有奶牛
		int s, e;
		cin >> s >> e;
		for (int i = s + 1; i < e; i++)
			hascow[i] = true;
	}
	fill(dp, dp + l, 0x3f3f3f3f);//初始化dp为最大值
	for (int i = a; i <= b; i++) {
		if (!hascow[i])//初始化dp，没有牛的地方放一个喷头
			dp[i] = 1;
		if (i <= b + 2 - a && !hascow[i])//初始化优先队列，b+2的前一个喷头处初始化为需要一个喷头
			q.push({ i,1 });
	}
	for (int i = b + 2; i <= l; i += 2) { //递推
		if (!hascow[i]) {
			while (!q.empty() && q.top().pos < i - b)//把位置太小的都清除掉
				q.pop();
			if (!q.empty())
				dp[i] = q.top().dp + 1;//不能pop，因为这个不一定是最前面的点，之后可能还会用到
		}
		q.push({ i - a + 2,dp[i - a + 2] });
	}
	if (dp[l] >= 0x3f3f3f3f)
		cout << -1 << endl;
	else
		cout << dp[l] << endl;
}