#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//0 000  1 001  2 010  3 011  4 100 6 110
int f[7][1000001] = { {0} };
int main() {
	int n;
	while (cin >> n) {
		memset(f, 0, sizeof(f));
		for (int i = 0; i < 7; i++)
			f[i][3] = 1;
		for (int i = 4; i <= n; i++) {
			f[0][i] = f[0][i - 1] + f[4][i - 1];
			f[1][i] = f[0][i - 1] + f[4][i - 1];
			f[2][i] = f[1][i - 1];
			f[3][i] = f[1][i - 1];
			f[4][i] = f[2][i - 1] + f[6][i - 1];
			f[6][i] = f[3][i - 1];
			for (int j = 0; j < 7; j++)
				f[j][i] %= 2005;
		}
		int ans = 0;
		for (int i = 0; i < 7; i++)
			ans += f[i][n];
		cout << ans % 2005 << endl;
	}
}