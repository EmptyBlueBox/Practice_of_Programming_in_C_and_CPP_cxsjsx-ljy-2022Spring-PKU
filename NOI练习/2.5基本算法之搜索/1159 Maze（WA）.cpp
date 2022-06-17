#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//因为只要判断能不能走通就行，去找所有的钥匙，找到就减一，当需要找的钥匙a变成0个时，就能走A门了
int m, n, dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1,0,-1,0 };
int main() {
	while (cin >> m >> n && m) {
		char map[21][21] = { {0} }, tmp;
		queue<pair<int,int>> q;
		int step = 0, vis[21][21] = { {false} }, key[5] = { 0 };//还没找到的钥匙
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S')
					map[i][j] = '.', q.push({ i,j }), vis[i][j] = true;
				else if (map[i][j] >= 'a' && map[i][j] <= 'e')
					key[map[i][j] - 'a']++;
			}
		while (!q.empty() && step <= 100000) {
			pair<int,int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = now.first + dx[i], yy = now.second + dy[i];
				if (map[xx][yy] == 'G') {
					cout << "YES\n";
					goto loop;
				} else if (vis[xx][yy] || map[xx][yy] == 'X' || xx > m || xx < 1 || yy > n || yy < 1) //不合法
					continue;
				else if (map[xx][yy] >= 'A' && map[xx][yy] <= 'E' && key[map[xx][yy] - 'A'] >= 1) { //这个门暂时还开不开，放回父节点，将其挂起，以后可能能开，如果重复次数过多，就说明不能开
					q.push(now);
					step++;
					continue;
				} else if (map[xx][yy] >= 'a' && map[xx][yy] <= 'e')
					key[map[xx][yy] - 'a']--, map[xx][yy] = '.';//这个钥匙被找到了就删掉，可以保证每个钥匙只计数一次
				q.push({ xx, yy });
				vis[xx][yy] = true;
				step++;
			}
		}
		cout << "NO\n";
loop:
		;
	}
}