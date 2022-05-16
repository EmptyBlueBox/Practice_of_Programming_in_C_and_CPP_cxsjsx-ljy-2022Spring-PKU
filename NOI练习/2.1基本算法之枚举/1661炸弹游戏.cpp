#include <iostream>
using namespace std;
int info[100][4], n;
inline bool inside(int x, int y, int m, int n, int r) {
	r /= 2;
	return x <= m + r && x >= m - r && y <= n + r && y >= n - r;
}
inline bool ok(int x, int y) {
	for (int i = 0; i < n; i++) {
		if (info[i][3] && (!inside(x, y, info[i][0], info[i][1], info[i][2])))
			return false;
		else if ((!info[i][3]) && inside(x, y, info[i][0], info[i][1], info[i][2]))
			return false;
	}
	return true;
}
int main() {
	int a, b, cnt = 0;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++)
		cin >> info[i][0] >> info[i][1] >> info[i][2] >> info[i][3];
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			if (ok(i, j))
				cnt++;
	cout << cnt << endl;
}