#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> a, b;
pair<int, int> s;
bool filled[12][12] = { {0} };
bool can_put(int x, int y) {
	for (int i = 0; i < m; i++)//枚举小块的每一个在大块有对应的
		for (int j = 0; j < m; j++)
			if (b[i][j] == '*') {
				int xx = x + i - s.first, yy = y + j - s.second;//注意可能出现负数！！！
				if (xx<0 || xx>n - 1 || yy<0 || yy>n - 1 || a[xx][yy] != '*' || filled[xx][yy])
					return false;
			}
	return true;
}
void put(int x, int y,int val) {
	for (int i = 0; i < m; i++)//枚举小块的每一个在大块有对应的
		for (int j = 0; j < m; j++)
			if (b[i][j] == '*') {
				int xx = x + i - s.first, yy = y + j - s.second;
				filled[xx][yy] = val;
			}
}
int main() {
	while (cin >> n >> m && n) {
		memset(filled, 0, sizeof(filled));
		int cnt1 = 0, cnt2 = 0;
		a.clear(), b.clear();
		a.resize(n), b.resize(m);
		for (auto& i : a)
			cin >> i, cnt1 += count(i.begin(), i.end(), '*');
		for (auto& i : b)
			cin >> i, cnt2 += count(i.begin(), i.end(), '*');
		if (cnt1 != 2 * cnt2) {
			cout << 0 << endl;
			continue;
		}
		for (int i = m - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--)
				if (b[i][j] == '*')
					s = make_pair(i, j);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][j] == '*' && can_put(i, j)) {
					put(i, j, 1);
					for (int k = 0; k < n; k++)
						for (int l = 0; l < n; l++)
							if (a[k][l] == '*' && (!filled[k][l]) && can_put(k, l)) {
								cout << 1 << endl;
								goto loop;
							}
					memset(filled, 0, sizeof(filled));
				}
		cout << 0 << endl;
loop:
		;
	}
}