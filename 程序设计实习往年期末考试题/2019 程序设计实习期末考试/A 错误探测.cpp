#include <iostream>
using namespace std;

int main() {
	int n, a[100][100] = { {0} }, x = 0, y = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j]) a[i][0]++, a[0][j]++;
		}
	for (int i = 1; i <= n; i++)
		if (a[i][0] % 2 && x == 0)
			x = i;
		else if (a[i][0] % 2 && x) {
			cout << "Corrupt\n";
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (a[0][i] % 2 && y == 0)
			y = i;
		else if (a[0][i] % 2 && y) {
			cout << "Corrupt\n";
			return 0;
		}
	if (x || y)
		cout << x << ' ' << y << endl;
	else
		cout << "OK\n";
}