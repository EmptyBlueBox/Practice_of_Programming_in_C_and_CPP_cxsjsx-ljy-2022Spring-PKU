#include <iostream>
using namespace std;

int main() {
	int n, m, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, ans = 0;
	char map[102][102];
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	cin >> m, m--;
	while (m--) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][j] == '@')
					for (int k = 0; k < 4; k++)
						if (map[i + dx[k]][j + dy[k]] == '.')
							map[i + dx[k]][j + dy[k]] = '$';
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][j] == '$')
					map[i][j] = '@';
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j] == '@')
				ans++;
	cout << ans << endl;
}