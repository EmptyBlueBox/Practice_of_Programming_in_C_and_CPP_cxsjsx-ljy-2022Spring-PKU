#include <iostream>
#include <cstring>
using namespace std;

int m, n, dx[8] = { -1,1,-2,2,-2,2,-1,1 }, dy[8] = { -2,-2,-1,-1,1,1,2,2 }, ans = 0;
bool vis[12][12] = { {0} };
void f(int x, int y, int pass) {
	if (pass == m * n) {
		ans++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || xx>m || yy<1 || yy>n || vis[xx][yy])
			continue;
		vis[xx][yy] = true;
		f(xx, yy, pass + 1);
		vis[xx][yy] = false;
	}
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		ans = 0, memset(vis, 0, sizeof(vis));
		int x, y;
		cin >> m >> n >> x >> y;
		x++, y++;
		vis[x][y] = true;
		f(x, y, 1);
		cout << ans << endl;
	}
}