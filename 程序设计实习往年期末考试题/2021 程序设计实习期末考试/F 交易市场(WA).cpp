//WA
/*
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[1001][1001], vis[1001];//某种物品得到的时候有过多少钱
int main() {
	int m, n, r, s, t, ans = 0xc0c0c0c0;
	cin >> m >> n;
	memset(a, 0xc0, sizeof(a));
	memset(vis, 0xc0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		cin >> r >> s >> t, a[r][s] = t;
	queue<pair<int, int>> q;
	q.push({ 1,0 }), vis[1] = 0;
	while (!q.empty()) {
		pair<int, int> nn = q.front();
		q.pop();
		for (int i = 1; i <= m; i++) {
			if (a[nn.first][i] == 0xc0c0c0c0 || vis[i] >= nn.second + a[nn.first][i])
				continue;
			vis[i] = max(vis[i], nn.second + a[nn.first][i]);
			ans = max(ans, vis[i]);
			if (ans > 400000) {
				cout << "1000000000\n";
				return 0;
			}
			q.push({ i,nn.second + a[nn.first][i] });
		}
	}
	cout << ans << endl;
}
*/

//https://www.cnblogs.com/erable/p/15032362.html
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 1000000000
using namespace std;
struct exchangeTo {
	int target;
	int p;
	exchangeTo(int a, int b) :target(a), p(b) {}
};
struct path {
	int pre;
	int val;
} dp[1005];
map<int, vector<exchangeTo> >tables;
bool inPath(int n, int k) {
	while (k != -1) {
		if (n == k)
			return true;
		k = dp[k].pre;
	}
	return false;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tables[x].push_back(exchangeTo(y, z));
	}
	dp[1].val = 0, dp[1].pre = 0;
	bool done = false;
	int result = 0;
	queue<int>myqueues;
	myqueues.push(1);
	while (!myqueues.empty()) {
		int top = myqueues.front();
		myqueues.pop();
		if (!tables[top].empty()) {
			vector<exchangeTo>::iterator ii;
			for (ii = tables[top].begin(); ii != tables[top].end(); ii++) {
				if (inPath(ii->target, top)) {
					result = INF;
					done = true;
					break;
				}
				if (dp[top].val + ii->p > dp[ii->target].val) {
					dp[ii->target].val = dp[top].val + ii->p;
					dp[ii->target].pre = top;
					myqueues.push(ii->target);//注意这里的更新
				}
				result = max(result, dp[ii->target].val);
			}
			if (done)break;
		}
	}
	cout << result << endl;
	return 0;
}