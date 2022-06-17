#include <iostream>
#include <cstring>
using namespace std;

int n, k, ans = 0;
char map[10][10];
bool col[10];
void f(int row,int chess) {
	if (chess == k + 1) {
		ans++;
		return;
	} else if (k - chess > n - row)
		return;
	f(row + 1, chess);
	for (int i = 1; i <= n; i++)
		if (map[row][i] == '#'&&col[i]==false) {
			col[i] = true;
			f(row + 1, chess + 1);
			col[i] = false;
		}
}
int main() {
	while (cin >> n >> k && n != -1) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		memset(col, 0, sizeof(col));
		ans = 0;
		f(1, 1);
		cout << ans << endl;
	}
}