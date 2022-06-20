#include <iostream>
#include <cstring>
using namespace std;

//对每一个公司，其显式控股的子公司控制的股票都会变成它的，对每一个公司，把它控股的所有公司控股的股票加在一起
int n, m = 0, info[101][101] = { {0} }, fa, son, per, hold[101];
bool vis[101];
void f(int x) {//用来更新x的所有控股，x最多控股m-1家
	if (vis[x]) return;
	vis[x] = true;
	for (int i = 1; i <= m; i++) {
		hold[i] += info[x][i];
		if (hold[i] > 50)
			f(i);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> fa >> son >> per, info[fa][son] = per, m = max(m, max(fa, son));
	for (int i = 1; i <= m; i++) {
		memset(hold, 0, sizeof(hold));
		memset(vis, 0, sizeof(vis));
		f(i);
		for (int j = 1; j <= m; j++)
			if (hold[j] > 50 && i != j)
				cout << i << ' ' << j << endl;
	}
}