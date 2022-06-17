#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	typedef pair<int, int> pii;
	int N, dx[8] = { -1,1,-2,2,-2,2,-1,1 }, dy[8] = { -2,-2,-1,-1,1,1,2,2 };
	cin >> N;
	while (N--) {
		int n, dis[302][302];
		pii s, e;
		queue<pii> q;
		cin >> n;
		memset(dis, 0x3f, sizeof(dis));
		cin >> s.first >> s.second >> e.first >> e.second;
		s.first++, s.second++, e.first++, e.second++;
		if (s == e) {
			cout << 0 << endl;
			goto loop;
		}
		dis[s.first][s.second] = 0;
		q.push(s);
		while (!q.empty()) {
			pii t = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int xx = t.first + dx[i], yy = t.second + dy[i], dd = dis[t.first][t.second] + 1;
				if (xx<1 || xx>n || yy<1 || yy>n || dis[xx][yy] <= dd) continue;
				else if (make_pair(xx, yy) == e) {
					cout << dd << endl;
					goto loop;
				}
				dis[xx][yy] = dd;
				q.push({ xx,yy });
			}
		}
loop:
		;
	}
}