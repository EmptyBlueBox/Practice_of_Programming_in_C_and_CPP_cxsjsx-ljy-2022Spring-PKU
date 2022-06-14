#include <iostream>
#include <queue>
using namespace std;

//可行节点->判断是否可以做下一步->更新xx、yy并push
struct node {
	int m, h, frog, round;
	node(int _m, int _h, int _frog, int _round) :m(_m), h(_h), frog(_frog), round(_round) {}
};
int main() {
	int n, k, m, h, a[1001], b[1001], c[1001];
	cin >> n >> k >> m >> h;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	queue<node> q;
	q.push({ m,h,k,0 });
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		int mm, hh, ff, rr = now.round + 1;
		if (rr > n)
			continue;
		if (now.frog)
			q.push({ now.m,now.h,now.frog - 1,rr });
		if (now.m <= a[rr])//boss能杀死hero，就不能回复或治疗了
			continue;
		else if (now.h <= b[rr]) { //hero能杀死boss，就找到答案
			cout << rr << endl;
			return 0;
		}
		if (c[rr] && now.m - a[rr] < m)
			q.push({ (now.m - a[rr] + c[rr]) % m,now.h,now.frog,rr });
		if (b[rr])
			q.push({ (now.m - a[rr]) % m,now.h - b[rr],now.frog,rr });
	}
	cout << "Fail\n";
}