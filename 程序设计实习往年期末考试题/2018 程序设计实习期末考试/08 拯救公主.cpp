#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//BFS在时间不是单调排列的时候不能以bool作为vis数组的形式，因为可能时间较长的时候有节点令vis[node]成为true造成时间较短的节点被剪枝
//要将时间与vis合并为dis，初始化为0x3f3f3f3f，在 dis[xx][yy][vv][ee] <= tt 时剪枝，注意还要取等于！！！
//DFS在合并的时候只用在dis[node] != 0x3f3f3f3f的时候剪枝就行
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, dis[102][102][4][11];
struct node {
	int x, y, v, e;
	node(int _x, int _y, int _v, int _e) :x(_x), y(_y), v(_v), e(_e) {}
};
int main() {
	int m, n, tot_e, T = 0;
	while (cin >> m >> n >> tot_e && m) {
		memset(dis, 0x3f, sizeof(dis));
		char map[102][102];
		queue<node> q;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S') q.push({ i,j,0,tot_e }), dis[i][j][0][tot_e] = dis[i][j][1][tot_e] = dis[i][j][2][tot_e] = dis[i][j][3][tot_e] = 0;
			}
		int ans = 0x3f3f3f3f;
		while (!q.empty()) {
			node now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i], vv = i, ee = now.e, tt = dis[now.x][now.y][now.v][now.e] + 1;
				if (map[xx][yy] == '#' || dis[xx][yy][vv][ee] <= tt || xx<1 || xx>m || yy<1 || yy>n)
					continue;
				else if (map[xx][yy] == 'T')
					ans = min(ans, tt);
				dis[xx][yy][vv][ee] = tt;
				if (map[xx][yy] != 'E')
					dis[xx][yy][0][ee] = dis[xx][yy][1][ee] = dis[xx][yy][2][ee] = dis[xx][yy][3][ee] = tt;
				q.push({ xx,yy,vv,ee });
			}
			if (map[now.x][now.y] == 'E') {
				for (int i = 1; i <= now.e; i++) { //剩下几个电池
					int xx = now.x + dx[now.v] * i, yy = now.y + dy[now.v] * i, vv = now.v, ee = i, tt = dis[now.x][now.y][now.v][now.e];
					xx = max(1, xx), xx = min(m, xx);//被边界挡下了
					yy = max(1, yy), yy = min(n, yy);
					if (map[xx][yy] == '#' || dis[xx][yy][vv][ee] <= tt)
						continue;
					else if (map[xx][yy] == 'T')
						ans = min(ans, tt);
					dis[xx][yy][vv][ee] = tt;
					if (map[xx][yy] != 'E')
						dis[xx][yy][0][ee] = dis[xx][yy][1][ee] = dis[xx][yy][2][ee] = dis[xx][yy][3][ee] = tt;
					q.push({ xx,yy,vv,ee });
				}
			}
		}
		printf("Case #%d: ", ++T);
		cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
	}
}