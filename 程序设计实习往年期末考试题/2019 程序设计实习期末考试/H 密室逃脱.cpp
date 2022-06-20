#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
int m, n, a[102][102], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int bfs(pii s, pii e) {
	if (s == e) return 0;//注意特判起始点相等！！！
	queue<pii> q;
	int dis[102][102];
	q.push(s);
	memset(dis, 0x3f, sizeof(dis));
	dis[s.first][s.second] = 0;
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = p.first + dx[i], yy = p.second + dy[i], dd = dis[p.first][p.second] + 1;
			if (a[xx][yy] == 0 || dis[xx][yy] <= dd || xx<1 || xx>m || yy<1 || yy>n)
				continue;
			else if (make_pair(xx, yy) == e)
				return dd;
			dis[xx][yy] = dd;
			q.push({ xx,yy });
		}
	}
	return 0xc0c0c0c0;
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		int ans = 0;
		map<int, pii> node;
		map<int, pii>::iterator itr1, itr2;
		cin >> m >> n;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] > 1) node.insert({ a[i][j],{i,j} });
			}
		node.insert({ 1,{1,1} });//注意判断(1, 1)点是不是1、2、3，如果不是1也要从(1, 1)开始走！！！
		itr1 = itr2 = node.begin(), itr2++;
		while (itr2 != node.end() && ans >= 0) {
			ans += bfs(itr1->second, itr2->second);
			itr1++, itr2++;
		}
		cout << (ans < 0 ? -1 : ans) << endl;
	}
}