#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	cin >> N;
	while (N--) {
		int n;
		char map[102][102];
		pair<int, int> s, e;
		bool vis[102][102] = { {false} };
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		cin >> s.first >> s.second >> e.first >> e.second;
		s.first++, s.second++, e.first++, e.second++;
		queue<pair<int, int>> q;
		q.push(s), vis[s.first][s.second] = true;
		if (s == e) {//告诉了起始点，特判起始点是否重合，是否是墙
			cout << "YES\n";
			goto loop;
		} else if (map[s.first][s.second] == '#' || map[e.first][e.second] == '#') {
			cout << "NO\n";
			goto loop;
		}
		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = now.first + dx[i], yy = now.second + dy[i];
				if (map[xx][yy] == '#' || vis[xx][yy] || xx<1 || xx>n || yy<1 || yy>n)
					continue;
				else if (make_pair(xx, yy) == e) {
					cout << "YES\n";
					goto loop;
				}
				vis[xx][yy] = true;
				q.push({ xx,yy });
			}
		}
		cout << "NO\n";
loop:
		;
	}
}