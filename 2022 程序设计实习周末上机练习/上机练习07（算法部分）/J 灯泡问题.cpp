#include <iostream>
#include <cstring>
using namespace std;

bool a[15][100];
int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(a, 0, sizeof(a));
		int m, n, ans = -1;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		for (int i = 0; i < (1 << m); i++) { //枚举行开关的状态
			int tmp = 0;
			for (int j = 0; j < m; j++)//操作行开关
				if (i & (1 << j))
					for (int k = 0; k < n; k++)
						a[j][k] = !a[j][k];
			for (int j = 0; j < n; j++) { //每一个列开关取最优
				int cnt = 0;
				for (int k = 0; k < m; k++)
					if (a[k][j])
						cnt++;
				tmp += max(cnt, m - cnt);
			}
			ans = max(ans, tmp);
			for (int j = 0; j < m; j++)
				if (i & (1 << j))
					for (int k = 0; k < n; k++)
						a[j][k] = !a[j][k];
		}
		cout << ans << endl;
	}
}