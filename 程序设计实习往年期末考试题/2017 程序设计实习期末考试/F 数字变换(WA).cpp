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
int main() {
	memset(ans, 0x3f, sizeof(ans));
	queue<node> q;
	q.push({ "12345",0,0,0 });
	ans[12345] = 0;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		string ss = now.a;
		for (int i = 0; i < 4; i++) {
			swap(ss[i], ss[i + 1]);
			int tmp = atoi(ss.c_str());
			if (ans[tmp] == 0x3f3f3f3f) {
				q.push({ ss,now.step + 1,now.t2,now.t3 });
				ans[tmp] = now.step + 1;
			}
			swap(ss[i], ss[i + 1]);
		}
		if (now.t2 < 3)
			for (int i = 0; i < 5; i++) {
				ss[i] = char((ss[i] - '0' + 1) % 10 + '0');
				int tmp = atoi(ss.c_str());
				if (ans[tmp] == 0x3f3f3f3f) {
					q.push({ ss,now.step + 1,now.t2 + 1,now.t3 });
					ans[tmp] = now.step + 1;
				}
				ss = now.a;
			}
		if (now.t3 < 2)
			for (int i = 0; i < 5; i++) {
				ss[i] = char(((ss[i] - '0') * 2) % 10 + '0');
				int tmp = atoi(ss.c_str());
				if (ans[tmp] == 0x3f3f3f3f) {
					q.push({ ss,now.step + 1,now.t2,now.t3 + 1 });
					ans[tmp] = now.step + 1;
				}
				ss = now.a;
			}
	}
	while (cin >> n)
		cout << (ans[n] == 0x3f3f3f3f ? -1 : ans[n]) << endl;
}