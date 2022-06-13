#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct node {
	string a;
	int step, t2, t3;
	node(string _a, int _step, int _t2, int _t3) :a(_a), step(_step), t2(_t2), t3(_t3) {}
};
int ans[100000], n;
bool vis[100000][4][3] = { {{false}} };//vis不能只有五位数，经过了几个2、3类变换会影响之后的搜索，也要记录进入vis，反例：12376，如果不记录经过了几个2、3类变换就会输出5，应该是4
int main() {
	memset(ans, 0x3f, sizeof(ans));
	queue<node> q;
	q.push({ "12345",0,0,0 });
	ans[12345] = 0, vis[12345][0][0] = true;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		string ss;
		for (int i = 0; i < 4; i++) {
			ss = now.a;
			swap(ss[i], ss[i + 1]);
			int tmp = atoi(ss.c_str());
			if (!vis[tmp][now.t2][now.t3]) {
				vis[tmp][now.t2][now.t3] = true;
				q.push({ ss,now.step + 1,now.t2,now.t3 });
				ans[tmp] = min(ans[tmp], now.step + 1);
			}
		}
		if (now.t2 <= 2)
			for (int i = 0; i < 5; i++) {
				ss = now.a;
				ss[i] = char((ss[i] - '0' + 1) % 10 + '0');
				int tmp = atoi(ss.c_str());
				if (!vis[tmp][now.t2 + 1][now.t3]) {
					vis[tmp][now.t2 + 1][now.t3] = true;
					q.push({ ss,now.step + 1,now.t2 + 1,now.t3 });
					ans[tmp] = min(ans[tmp], now.step + 1);
				}
			}
		if (now.t3 <= 1)
			for (int i = 0; i < 5; i++) {
				ss = now.a;
				ss[i] = char(((ss[i] - '0') * 2) % 10 + '0');
				int tmp = atoi(ss.c_str());
				if (!vis[tmp][now.t2][now.t3 + 1]) {
					vis[tmp][now.t2][now.t3 + 1] = true;
					q.push({ ss,now.step + 1,now.t2,now.t3 + 1 });
					ans[tmp] = min(ans[tmp], now.step + 1);
				}
			}
	}
	while (cin >> n)
		cout << (ans[n] == 0x3f3f3f3f ? -1 : ans[n]) << endl;
}