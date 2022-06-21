#include <iostream>
using namespace std;

int n, c, w[19], bag_used[19] = { 0 }, ans = 0x3f3f3f3f;
void dfs(int piece) {
	if (bag_used[0] >= ans)//已经用了比已知答案多，prune，等于的时候也要剪枝！！！
		return;
	if (piece == n + 1) {
		ans = min(ans, bag_used[0]);
		return;
	}
	for (int i = 1; i <= bag_used[0]; i++)
		if (w[piece] + bag_used[i] <= c) {
			bag_used[i] += w[piece];
			dfs(piece + 1);
			bag_used[i] -= w[piece];
		}
	bag_used[0]++;
	bag_used[bag_used[0]] = w[piece];
	dfs(piece + 1);
	bag_used[bag_used[0]] = 0;
	bag_used[0]--;
}
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	bag_used[0] = 1;//现在用了一个
	dfs(1);
	cout << ans << endl;
}