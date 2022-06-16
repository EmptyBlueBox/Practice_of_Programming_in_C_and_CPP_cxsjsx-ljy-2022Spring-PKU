#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//数轴上变来变去用BFS
//求最短路径用BFS！！！
int main() {
	int m, n, dis[100001];
	queue<int> q;
	cin >> m >> n;
	memset(dis, 0x3f, sizeof(dis));
	dis[m] = 0;
	q.push(m);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t + 1 >= 0 && t + 1 <= 100000 && dis[t + 1] > dis[t] + 1 && dis[n] > dis[t] + 1)
			dis[t + 1] = dis[t] + 1, q.push(t + 1);
		if (t - 1 >= 0 && t - 1 <= 100000 && dis[t - 1] > dis[t] + 1 && dis[n] > dis[t] + 1)
			dis[t - 1] = dis[t] + 1, q.push(t - 1);
		if (t * 2 >= 0 && t * 2 <= 100000 && dis[t * 2] > dis[t] + 1 && dis[n] > dis[t] + 1)
			dis[t * 2] = dis[t] + 1, q.push(t * 2);
	}
	cout << dis[n] << endl;
}