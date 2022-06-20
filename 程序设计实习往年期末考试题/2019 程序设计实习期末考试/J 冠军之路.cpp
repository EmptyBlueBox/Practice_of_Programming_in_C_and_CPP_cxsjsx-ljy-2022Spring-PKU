#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct node {
	int x, y, mg, dis;//mg为1：召唤师被杀死
	node(int a, int b, int c, int d) :x(a), y(b), mg(c), dis(d) {}
};
bool vis[102][102][1 << 8] = { {{false}} };
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int m, n, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, summon_cnt = 0;
	char map[102][102], summon_sight[4] = { 'w','s','a','d' };
	unordered_map<int, int> summonID;
	queue<node> q;
	cin >> m >> n;
	for (int i = 0; i <= m + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			map[i][j] = '#';
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') q.push({ i,j,0,0 }), vis[i][j][0] = true;
			else if (map[i][j] == 'w' || map[i][j] == 'a' || map[i][j] == 's' || map[i][j] == 'd') summonID[i * 100 + j] = summon_cnt++;
		}
	while (!q.empty()) {
		node p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 105; j++) {
				int xx = p.x + dx[i] * j, yy = p.y + dy[i] * j;
				if (map[xx][yy] == '#')
					break;
				for (int k = 0; k < 4; k++)
					if (map[xx][yy] == summon_sight[k] && i != k)
						goto next_dir1;
					else if (map[xx][yy] == summon_sight[k] && i == k)
						p.mg |= (1 << (summonID[100 * xx + yy]));
			}
		next_dir1:;//注意next_dir要在方向循环的最后，而不是长度循环的最后！！！
		}
		vis[p.x][p.y][p.mg] = true;
		if (map[p.x][p.y] == 'O') {
			for (int j = 0; j < summon_cnt; j++)//注意summon_cnt是否取等！！！
				if (!(p.mg & (1 << j)))
					goto cannot_go;//不能直接搜下一个节点，因为可以经过O点而不离开山洞，否则就不能通过O点去别的地方了！！！
			cout << p.dis << endl;
			return 0;
		}
	cannot_go:;
		for (int i = 0; i < 4; i++) {
			int xx = p.x + dx[i], yy = p.y + dy[i], dd = p.dis + 1;
			if (map[xx][yy] == '#' || vis[xx][yy][p.mg] || xx<1 || xx>m || yy<1 || yy>n)
				continue;
			for (int j = 0; j < 4; j++)
				if (map[xx][yy] == summon_sight[j])//被召唤师挡住的格子一直不能走，即使召唤师被打败了也不可以！！！
					goto next_dir2;
			vis[xx][yy][p.mg] = true;//只要有机会就更新vis数组！！！否则有可能MLE、TLE！！！
			q.push({ xx,yy,p.mg,dd });
		next_dir2:;
		}
	}
	cout << -1 << endl;
}