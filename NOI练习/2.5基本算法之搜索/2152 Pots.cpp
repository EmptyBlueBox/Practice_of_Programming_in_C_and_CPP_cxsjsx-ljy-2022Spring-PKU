#include <iostream>
#include <queue>
using namespace std;

struct info {
	int a, b, t;
	string ans;
	info(int _a, int _b, int _t, string _ans) :a(_a), b(_b), t(_t), ans(_ans) {}
};
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	bool vis[101][101] = { {false} };
	queue<info> q;
	q.push({ 0,0,0,"" });
	while (!q.empty()) {
		info now = q.front();
		q.pop();
		if (vis[now.a][now.b])
			continue;
		else
			vis[now.a][now.b] = true;
		if (now.a == c || now.b == c) {
			cout << now.t << endl << now.ans;
			return 0;
		}
		q.push({ a,now.b,now.t + 1,now.ans + "FILL(1)\n" });
		q.push({ now.a,b,now.t + 1,now.ans + "FILL(2)\n" });
		q.push({ 0,now.b,now.t + 1,now.ans + "DROP(1)\n" });
		q.push({ now.a,0,now.t + 1,now.ans + "DROP(2)\n" });
		q.push({ (now.a > b - now.b ? now.a + now.b - b : 0),(now.a > b - now.b ? b : now.a + now.b),now.t + 1,now.ans + "POUR(1,2)\n" });
		q.push({ (now.b > a - now.a ? a : now.a + now.b),(now.b > a - now.a ? now.a + now.b - a : 0),now.t + 1,now.ans + "POUR(2,1)\n" });
	}
	cout << "impossible\n";
}