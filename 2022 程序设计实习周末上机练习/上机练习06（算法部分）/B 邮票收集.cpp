#include <iostream>
#include <algorithm>
using namespace std;

int n, m, stamp[101], ans = 0x3f3f3f3f;
void dfs(int piece, int min_stamp, int sum) {
	if (sum > m || piece > ans)
		return;
	else if (sum == m) {
		ans = min(ans, piece);
		return;
	}
	for (int i = min_stamp; i <= n; i++)
		dfs(piece + 1, i, sum + stamp[i]);
}
int main() {
	while (cin >> n >> m && n) {
		ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
			cin >> stamp[i];
		sort(stamp + 1, stamp + n + 1);
		dfs(0, 1, 0);
		cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
	}
}