#include <iostream>
#include <cmath>
using namespace std;

char ans[2189][2189] = { {0} };
void f(int x,int y, int n) {
	if (n == 1) {
		ans[x][y] = 'X';
		return;
	}
	int len = pow(3, n - 2);
	f(x, y, n - 1);
	f(x - len, y - len, n - 1);
	f(x - len, y + len, n - 1);
	f(x + len, y - len, n - 1);
	f(x + len, y + len, n - 1);
}
int main() {
	int n;
	while (cin >> n && n != -1) {
		if (n == 1) {
			cout << 'X' << endl << '-' << endl;
			continue;
		}
		int len = pow(3, n - 1);//不是2的幂次
		for (int i = 0; i <= len; i++)
			for (int j = 0; j <= len; j++)
				ans[i][j] = ' ';
		f(len / 2 + 1, len / 2 + 1, n);
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= len; j++)
				cout << ans[i][j];
			cout << endl;
		}
		cout << '-' << endl;
	}
}