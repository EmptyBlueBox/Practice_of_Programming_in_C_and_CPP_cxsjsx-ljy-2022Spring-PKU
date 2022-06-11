#include <iostream>
#include <cstring>
using namespace std;

int n, flight[11][11];
bool vis[11] = { false };
bool dfs(int now) {
	for (int i = 1; i <= n; i++) {
		if (vis[i] || flight[now][i] == -1 || now == i)//不是==0x3f3f3f3f，输入给了-1
			continue;
		vis[i] = true;
		if (dfs(i) || i == n)
			return true;
		vis[i] = false;
	}
	return false;
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(flight, 0x3f, sizeof(flight));
		memset(vis, 0, sizeof(vis));
		vis[1] = true;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> flight[i][j];
		cout << (dfs(1) ? "YES\n" : "NO\n");
	}
}