#include <iostream>
#include <cstring>
#include <bitset>
#include <queue>
using namespace std;

int dis[1 << 16] = { 0 };
int main() {
	memset(dis, 0x3f, sizeof(dis));
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	string a[4], b[4], tmp;
	for (int i = 0; i < 4; i++)
		cin >> a[i], tmp += a[i];
	bitset<16> s(tmp);
	tmp.clear();
	for (int i = 0; i < 4; i++)
		cin >> b[i], tmp += b[i];
	bitset<16> e(tmp);
	if (s == e) {
		cout << 0 << endl;
		return 0;
	}
	queue<bitset<16>> q;
	q.push(s);
	dis[s.to_ulong()] = 0;
	while (!q.empty()) {
		bitset<16> now = q.front();
		q.pop();
		for (int i = 0; i < 16; i++)
			if (now[i]) {
				int x = i / 4, y = i % 4;
				for (int j = 0; j < 4; j++) {
					int xx = x + dx[j], yy = y + dy[j];
					if (xx < 0 || xx>=4 || yy < 0 || yy>=4 || now[xx * 4 + yy])
						continue;
					bitset<16> tmp = now;
					tmp[x * 4 + y] = 0, tmp[xx * 4 + yy] = 1;
					if (dis[tmp.to_ulong()] <= dis[now.to_ulong()] + 1)
						continue;
					else if (tmp == e) {
						cout << dis[now.to_ulong()] + 1 << endl;
						return 0;
					}
					dis[tmp.to_ulong()] = dis[now.to_ulong()] + 1;
					q.push(tmp);
				}
			}
	}
}