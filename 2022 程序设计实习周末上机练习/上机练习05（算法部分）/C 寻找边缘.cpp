#include <iostream>
#include <cstring>
using namespace std;

int m, n, map[502][502] = { {0} }, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool is_edge[502][502] = { {false} };
void f(int x, int y) {
	is_edge[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (!map[xx][yy] && !is_edge[xx][yy] && xx >= 1 && xx <= m && yy >= 1 && yy <= n)//不能去过，不能重复递归！！！地图条件、不重复、边界内！！！
			f(xx, yy);
	}
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(map, 0, sizeof(map));
		memset(is_edge, 0, sizeof(is_edge));
		cin >> m >> n;
		char tmp;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> tmp, map[i][j] = tmp == 'X';
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (!map[i][j] && (i == 1 || i == m || j == 1 || j == n))//X不能递归
					f(i, j);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][j] == 0 && !is_edge[i][j])
					map[i][j] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				cout << (map[i][j] ? 'X' : 'O');
			cout << endl;
		}
		cout << endl;
	}
}