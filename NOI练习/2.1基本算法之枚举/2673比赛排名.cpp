#include <iostream>
using namespace std;
bool vis[6] = { false };
int ans[6] = { 0 };
void find(int depth) {
	if (depth == 6) {
		if ((ans[1] > 2 && ans[5] == 1) || (ans[1] <= 2 && ans[5] != 1))//后三名猜对了或前两名猜错了
			return;
		if ((ans[2] > 2 && ans[2] == 2) || (ans[2] <= 2 && ans[2] != 2))
			return;
		if ((ans[3] > 2 && ans[1] == 5) || (ans[3] <= 2 && ans[1] != 5))
			return;
		if ((ans[4] > 2 && ans[3] != 1) || (ans[4] <= 2 && ans[3] == 1))
			return;
		if ((ans[5] > 2 && ans[4] == 1) || (ans[5] <= 2 && ans[4] != 1))
			return;
		if (ans[5] == 2 || ans[5] == 3)
			return;
		for (int i = 1; i <= 5; i++)
			cout << ans[i] << endl;
	}
	for (ans[depth] = 1; ans[depth] <= 5; ans[depth]++) {//枚举'A'+depth-1是第几名
		if (vis[ans[depth]])
			continue;
		vis[ans[depth]] = true;
		find(depth + 1);
		vis[ans[depth]] = false;
	}
}
int main() {
	find(1);
}