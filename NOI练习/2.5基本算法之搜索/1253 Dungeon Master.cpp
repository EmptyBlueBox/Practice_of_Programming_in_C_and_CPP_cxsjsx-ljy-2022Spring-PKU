#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//需要输出最短路径的bfs，将node里与起点的距离t和vis数组合并为dis数组，压缩空间，否则可能MLE
struct node {
	int x, y, z;
	node(int _x, int _y, int _z) :x(_x), y(_y), z(_z) {}
	node() {}
};
int main() {
	int dx[6] = { 1,-1,0,0,0,0 }, dy[6] = { 0,0,1,-1,0,0 }, dz[6] = { 0,0,0,0,1,-1 };
	int a, b, c;
	while (cin >> a >> b >> c && a) {
		char map[32][32][32] = { {{0}} };
		int dis[32][32][32];
		memset(dis, 0x3f, sizeof(dis));
		node begin, end;
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				for (int k = 1; k <= c; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') begin = { i,j,k };
				}
		queue<node> q;
		q.push(begin);
		dis[begin.x][begin.y][begin.z] = 0;
		while (!q.empty()) {
			node s = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int xx = s.x + dx[i], yy = s.y + dy[i], zz = s.z + dz[i], d = dis[s.x][s.y][s.z] + 1;
				if (dis[xx][yy][zz] != 0x3f3f3f3f || map[xx][yy][zz] == '#' || xx<1 || xx>a || yy<1 || yy>b || zz<1 || zz>c)
					continue;
				else if (map[xx][yy][zz] == 'E') {
					printf("Escaped in %d minute(s).\n", d);
					goto loop;
				}
				dis[xx][yy][zz] = d;
				q.push({ xx,yy,zz });
			}
		}
		cout << "Trapped!\n";
loop:
		;
	}
}