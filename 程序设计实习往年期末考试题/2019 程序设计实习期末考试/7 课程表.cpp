#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//每一门课程依赖的课程是一棵树
vector<int> rely[1000];
bool can[1000] = { 0 }, vis[1000] = { 0 };
bool can_learn(int x) {
	if (can[x])
		return true;
	else if (vis[x]) {
		can[x] = false;
		return false;
	}
	vis[x] = true;
	for (int i = 0; i < rely[x].size(); i++)
		if (!can_learn(rely[x][i])) {
			can[rely[x][i]] = false;
			return false;
		}
	can[x] = true;
	return true;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < 1000; i++)
			rely[i].clear();
		memset(can, 1, sizeof(can));
		int tx, ty;
		for (int i = 0; i < m; i++)
			cin >> tx >> ty, rely[tx].push_back(ty), can[tx] = false;
		for (int i = 0; i < n; i++) {
			memset(vis, 0, sizeof(vis));
			if (!can_learn(i)) {
				cout << "False\n";
				goto loop;
			}
		}
		cout << "True\n";
loop:
		;
	}
}