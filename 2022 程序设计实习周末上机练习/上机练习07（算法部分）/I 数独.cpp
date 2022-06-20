#include <iostream>
#include <cstring>
using namespace std;

int map[9][9];
bool row[9][10] = { {0} }, col[9][10] = { {0} }, sq[9][10] = { {0} }, e = false;
void f(int x, int y) {
	if (e)
		return;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (map[i][j] == 0) {
				for (int k = 1; k <= 9; k++) {
					if (row[i][k] || col[j][k] || sq[i / 3 * 3 + j / 3][k])
						continue;
					map[i][j] = k;
					row[i][k] = col[j][k] = sq[i / 3 * 3 + j / 3][k] = true;
					f(i, j);
					row[i][k] = col[j][k] = sq[i / 3 * 3 + j / 3][k] = false;
					map[i][j] = 0;
				}
				return;
			}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << map[i][j];
		cout << endl;
		e = true;//别忘了设置全部结束！！！没设置有可能TLE！！！
	}
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(sq, 0, sizeof(sq));
		e = false;
		char c;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> c, map[i][j] = c - '0', row[i][map[i][j]] = col[j][map[i][j]] = sq[i / 3 * 3 + j / 3][map[i][j]] = true;
		f(0, 0);
	}
}