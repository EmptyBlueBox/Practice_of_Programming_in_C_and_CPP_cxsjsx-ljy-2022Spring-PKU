#include <iostream>
using namespace std;

int n = 0, ans[8];//每行的皇后在第几个
bool row[8] = { 0 }, dig1[15] = { 0 }, dig2[15] = { 0 };
void dfs(int col) {
	if (col == 8) {
		printf("No. %d\n", ++n);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cout << (ans[i] == j) << (j == 7 ? "\n" : " ");
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (row[i] || dig1[i + col] || dig2[i - col + 7])
			continue;
		row[i] = dig1[i + col] = dig2[i - col + 7] = true;
		ans[i] = col;
		dfs(col + 1);
		row[i] = dig1[i + col] = dig2[i - col + 7] = false;
	}
}
int main() {
	dfs(0);
}