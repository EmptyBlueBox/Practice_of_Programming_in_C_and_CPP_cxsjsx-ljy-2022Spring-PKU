#include <iostream>
using namespace std;

int cnt = 0, tmp_ans[8] = { 0 }, ans[93][8];
bool col[8] = { 0 }, dig1[15] = { 0 }, dig2[15] = { 0 };
void dfs(int row) {
	if (row == 8) {
		cnt++;
		for (int i = 0; i < 8; i++)
			ans[cnt][i] = tmp_ans[i];
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (col[i] || dig1[i + row] || dig2[i - row + 7])
			continue;
		col[i] = dig1[i + row] = dig2[i - row + 7] = true;
		tmp_ans[row] = i;
		dfs(row + 1);
		col[i] = dig1[i + row] = dig2[i - row + 7] = false;
	}
}
int main() {
	dfs(0);
	int t;
	cin >> t;
	while (cin >> t) {
		for (int i = 0; i < 8; i++)
			cout << ans[t][i] + 1;
		cout << endl;
	}
}