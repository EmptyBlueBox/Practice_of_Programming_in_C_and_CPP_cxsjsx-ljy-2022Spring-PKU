#include <iostream>
#include <cstring>
#include <bitset>
#include <unordered_map>
#include <queue>
using namespace std;

struct node {
	int x, y, key_num, trap, step;//trap 1 为已拆除
	node(int a, int b, int c, int d, int e) :x(a), y(b), key_num(c), trap(d), step(e) {}
};
int m, n, trap_cnt = 0, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, all_key = 0, no = 0, ans = 0x3f3f3f3f;
char map[102][102] = { {0} };
bool vis[102][102][10][1<<7] = { {{{0}}} };
unordered_map<int, int> trap_ID;
queue<node> q;
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') q.push({ i,j,0,0,0 }), vis[i][j][0][0] = true;
			else if (map[i][j] == 'G') trap_ID.insert({ i * 101 + j,trap_cnt++ });
			else if (map[i][j] >= '1' && map[i][j] <= '9') all_key = max(all_key, map[i][j] - '0');
		}
	while (!q.empty()) {
		node p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = p.x + dx[i], yy = p.y + dy[i], kk = p.key_num, tt = p.trap, step = p.step + 1;
			if (map[xx][yy] == ('0' + p.key_num + 1))
				kk++;
			else if (map[xx][yy] == 'G' && (!(tt & (1 << (trap_ID[xx * 101 + yy])))))
				tt |= (1 << (trap_ID[xx * 101 + yy])), step++;
			else if (map[xx][yy] == 'T' && kk == all_key)
				ans = min(ans, step);
			if (map[xx][yy] == 'X' || vis[xx][yy][kk][tt] || xx<1 || xx>m || yy<1 || yy>n)
				continue;
			vis[xx][yy][kk][tt] = true;
			q.push({ xx,yy,kk,tt,step });
		}
	}
	cout << ans << endl;
}