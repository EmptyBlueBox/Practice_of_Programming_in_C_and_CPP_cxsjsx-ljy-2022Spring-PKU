#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
vector<pii> s(4), e(4), t(4);
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool vis[8][8][8][8][8][8][8][8] = { {{{{{{{0}}}}}}} };
bool f(int step) {
	if (t == e)
		return true;
	else if (step >= 8)
		return false;
	for (int i = 0; i < 4; i++) { //枚举每一个棋子
		for (int j = 0; j < 4; j++) { //枚举每一个棋子前进的方向
			int x = t[i].first, y = t[i].second;
			t[i].first += dx[j], t[i].second += dy[j];
			for (int k = 0; k < 4; k++)//如果前面有其它棋子就跳一格
				if (make_pair(t[i].first, t[i].second) == t[k] && k != i) {
					t[i].first += dx[j], t[i].second += dy[j];
					break;
				}
			for (int k = 0; k < 4; k++)//跳了一格还冲突就continue
				if (make_pair(t[i].first, t[i].second) == t[k] && k != i) {
					t[i].first = x, t[i].second = y;
					goto next_dir;
				}
			if (t[i].first < 0 || t[i].first>7 || t[i].second<0 || t[i].second>7 || vis[t[0].first][t[0].second][t[1].first][t[1].second][t[2].first][t[2].second][t[3].first][t[3].second]) {
				t[i].first = x, t[i].second = y;
				continue;
			}
			//DFS
			vis[t[0].first][t[0].second][t[1].first][t[1].second][t[2].first][t[2].second][t[3].first][t[3].second] = true;
			if (f(step + 1))
				return true;
			t[i].first = x, t[i].second = y;
			vis[t[0].first][t[0].second][t[1].first][t[1].second][t[2].first][t[2].second][t[3].first][t[3].second] = false;
next_dir:
			;
		}
	}
}
int main() {
	for (int i = 0; i < 4; i++)
		cin >> s[i].first >> s[i].second, s[i].first--, s[i].second--;
	for (int i = 0; i < 4; i++)
		cin >> e[i].first >> e[i].second, e[i].first--, e[i].second--;
	vis[s[0].first][s[0].second][s[1].first][s[1].second][s[2].first][s[2].second][s[3].first][s[3].second] = true;
	t = s;
	cout << (f(0) ? "YES\n" : "NO\n");
}