#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string info[27];
int n, min_col = 0x3f3f3f3f, col[27] = { 0 };//第几个节点是什么颜色,col[0]是总颜色数
void dfs(int depth) {
	if (col[0] > min_col)
		return;
	else if (depth == n + 1) {
		min_col = min(min_col, col[0]);
		return;
	}
	for (int i = 1; i <= col[0]; i++) { //第depth个节点能染i颜色吗
		for (int j = 0; j < info[depth].length(); j++)
			if (col[info[depth][j] - 'A' + 1] == i)
				goto next_col;
		col[depth] = i;//第depth个节点能染i颜色吗：能染，深搜下一个节点
		dfs(depth + 1);
		col[depth] = 0;
next_col:
		;
	}
	col[depth] = col[0] + 1, col[0]++;//第depth个节点染新的颜色，深搜下一个节点
	dfs(depth + 1);
	col[depth] = 0, col[0]--;
}
int main() {
	while (cin >> n && n) {
		min_col = 0x3f3f3f3f;
		memset(col, 0, sizeof(col));
		for (int i = 1; i <= n; i++)
			cin >> info[i], info[i].erase(0, 2);
		dfs(1);
		if (min_col == 1)
			cout << "1 channel needed.\n";
		else
			printf("%d channels needed.\n", min_col);
	}
}