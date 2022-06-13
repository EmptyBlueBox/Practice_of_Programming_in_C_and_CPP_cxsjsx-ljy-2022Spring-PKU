#include <iostream>
using namespace std;

int main() {
	int map[5][5];
	bool a[5][5] = { {false} }, b[5][5] = { {false} };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	for (int i = 0; i < 5; i++) {
		int m = 0xc0c0c0c0;
		for (int j = 0; j < 5; j++)
			m = max(m, map[i][j]);
		for (int j = 0; j < 5; j++)
			a[i][j] = map[i][j] == m;
	}
	for (int i = 0; i < 5; i++) {
		int m = 0x3f3f3f3f;
		for (int j = 0; j < 5; j++)
			m = min(m, map[j][i]);
		for (int j = 0; j < 5; j++)
			b[j][i] = map[j][i] == m;
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (a[i][j] && b[i][j]) {
				cout << i + 1 << ' ' << j + 1 << ' ' << map[i][j];
				return 0;
			}
	cout << "not found\n";
}