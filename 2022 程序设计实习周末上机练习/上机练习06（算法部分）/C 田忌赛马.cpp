#include <iostream>
#include <algorithm>
using namespace std;

int n, x, opponent[10], my[10];
bool vis[10] = { false };
void dfs(int t, int win) { //现在是第几场，我赢了几场
	if (t == n + 1 && win > n - win) {
		for (int i = 1; i <= n; i++)
			cout << my[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		my[t] = i;
		vis[i] = true;
		dfs(t + 1, win + (i >= opponent[t] + x));
		vis[i] = false;
	}
}
int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> opponent[i];
	dfs(1, 0);
}