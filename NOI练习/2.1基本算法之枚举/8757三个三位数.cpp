#include <iostream>
using namespace std;
//用dfs枚举
int ans[9] = { 0 };
bool vis[10] = { false };
void find(int step) {
	if (step == 9) {
		int a = 100 * ans[0] + 10 * ans[1] + ans[2], b = 100 * ans[3] + 10 * ans[4] + ans[5], c = 100 * ans[6] + 10 * ans[7] + ans[8];
		if (a * 2 == b && a * 3 == c)
			cout << a << ' ' << b << ' ' << c << endl;
		return;
	}
	for (ans[step] = 1; ans[step] < 10; ans[step]++) {
		if (vis[ans[step]])
			continue;
		vis[ans[step]] = true;
		find(step + 1);
		vis[ans[step]] = false;
	}
}
int main() {
	find(0);
}