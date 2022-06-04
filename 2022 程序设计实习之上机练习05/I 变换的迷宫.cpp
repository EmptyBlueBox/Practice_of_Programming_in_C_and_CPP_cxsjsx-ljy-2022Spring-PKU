#include <iostream>
#include <queue>
using namespace std;

//bfs
enum BLOCK { ROCK, EMPTY, EXIT };//枚举变量很清晰，方便使用
int main() {
	int N, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
	cin >> N;
	while (N--) {
		int m, n, k, map[101][101];
		bool vis[101][101][10] = { {{false}} };//判断某个情形是否发生过
		queue<pair<pair<int, int>, int>> q;//第三个参量是时间
		pair<pair<int, int>, int> start;
		char tmp;
		cin >> m >> n >> k;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> tmp;
				if (tmp == '#') map[i][j] = ROCK;
				else if (tmp == '.') map[i][j] = EMPTY;
				else if (tmp == 'E') map[i][j] = EXIT;
				else if (tmp == 'S') map[i][j] = EMPTY, start = { { i,j }, 0 };
			}
		q.push(start);
		vis[start.first.first][start.first.second][start.second] = true;
		while (!q.empty()) {
			pair<pair<int, int>, int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = now.first.first + dx[i], yy = now.first.second + dy[i], tt = now.second + 1;
				if ((xx < 1 || xx > m || yy < 1 || yy > n) || (map[xx][yy] == ROCK && (tt % k)) || (vis[xx][yy][tt])) continue;//越界、走到石头、出现过这个情况就跳过
				vis[xx][yy][tt] = true;
				if (map[xx][yy] == EXIT) {
					cout << tt << endl;    //到了终点
					goto LOOP;
				}
				q.push({ {xx, yy}, tt });
			}
		}
		cout << "Oop!\n";
LOOP:
		;
	}
}