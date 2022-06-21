#include <iostream>
using namespace std;

int dp[11][11] = { {0} };
int f(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	if (x == 0 || y == 0 || y == 1) return 1;
	if (x >= y)//注意取等！！！
		dp[x][y] = f(x, y - 1) + f(x - y, y);
	else
		dp[x][y] = f(x, x);
	return dp[x][y];
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		int m, n;
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
}