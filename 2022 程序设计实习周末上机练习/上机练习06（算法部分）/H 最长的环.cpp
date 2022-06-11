#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

//对每一块白色扩八个方向，与黑色的交集包括可能的环
//对这些可能的块扩四个方向判断是不是满足环的条件，同时取消标记
//走了一圈之后看是否还有未取消标记的环，如果有就说明这个环里有黑块，这不是满足条件的环
int m, n, map[1002][1002] = { {0} }, dx0[8] = { 0,1,0,-1,1,1,-1,-1 }, dy0[8] = { 1,0,-1,0,1,-1,-1,1 }, dx1[4] = { 0,1,0,-1 }, dy1[4] = { 1,0,-1,0 };
int mark1[1002][1002] = { {false} }, vis0[1002][1002] = { {false} };
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(map, 0, sizeof(map));
		memset(vis0, 0, sizeof(vis0));
		int ans = 0;
		char c;
		cin >> m >> n;
		bool has_no_0 = true;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> c, map[i][j] = c - '0';
				if (!map[i][j]) has_no_0 = false;
			}
		//特判没有0的一行一列矩阵
		if (has_no_0 && (m == 1 || n == 1)) {
			cout << 0 << endl;
			goto loop;
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if ((!map[i][j]) && (!vis0[i][j])) { //新的0格，从这个0格找对应的1环
					memset(mark1, 0, sizeof(mark1));//重置边缘1标记数组
					queue<pair<int, int>> q;
					//标记这块0在vis0，且标记这块0附近的1在mark1
					q.push({ i,j });//初始化的点不能直接标记vis！！！不然循环直接退出
					while (!q.empty()) {
						pair<int, int> now = q.front();
						q.pop();
						if (vis0[now.first][now.second] || now.first<1 || now.first>m || now.second<1 || now.second>n)
							continue;
						else if (map[now.first][now.second]) {
							mark1[now.first][now.second] = true;
							continue;
						}
						vis0[now.first][now.second] = true;
						for (int i = 0; i < 8; i++) {
							int xx = now.first + dx0[i], yy = now.second + dy0[i];
							q.push({ xx,yy });
						}
					}
					//找起点
					pair<int, int> start;
					for (int k = 1; k <= m; k++)
						for (int l = 1; l <= n; l++)
							if (mark1[k][l]) {
								mark1[k][l] = 0;
								start = { k,l };
								goto next_bfs;
							}
next_bfs:
					;
					//数边缘的1有几个，如果发现三个连起来或者边缘不连续就把cnt变成0，取消标记1
					int cnt = 1;
					pair<int, int> now = start;
					for (int i = 0; i < 4; i++) {
						int xx = now.first + dx1[i], yy = now.second + dy1[i];
						if (mark1[xx][yy] == 1) {
							now = { xx,yy };
							break;
						}
					}
					while (1) {
						cnt++, mark1[now.first][now.second] = 0;
						int tmp_cnt = 0, xx, yy;
						pair<int, int> tmp_now = now;
						for (int i = 0; i < 4; i++) {
							xx = tmp_now.first + dx1[i], yy = tmp_now.second + dy1[i];
							if (mark1[xx][yy] == 1)
								tmp_cnt++, now = { xx,yy };
						}
						if (tmp_cnt == 2 || tmp_cnt == 3) {
							cnt = 0;
							break;
						} else if (tmp_cnt == 0) { //特判如果回到了终点
							for (int i = 0; i < 4; i++) {
								int xx = now.first + dx1[i], yy = now.second + dy1[i];
								if (start == make_pair(xx, yy) && cnt >= 4)
									goto ring_end;
							}
							cnt = 0;
							break;
						}
					}
ring_end:
					;
					//找有无内点
					for (int k = 1; k <= m; k++)
						for (int l = 1; l <= n; l++)
							if (mark1[k][l])
								cnt = 0;
					ans = max(ans, cnt);
				}
		if (ans < 4) { //没找到环，特判有没有小四格
			for (int i = 1; i <= m; i ++)
				for (int j = 1; j <= n; j ++)
					if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)//有方块
						ans = 4;
		}
		cout << ans << endl;
loop:
		;
	}
}