#include <iostream>
#include <cstring>
using namespace std;

//对每一个公司，其显式控股的子公司控制的股票都会变成它的，对每一个公司，把它控股的所有公司控股的股票加在一起
int n, m = 0, info[101][101] = { {0} }, fa, son, per, hold[101];
bool vis[101];
void f(int x) {//x是主公司的子公司，x的所有股票加到主公司持有的股票hold[]里
	if (vis[x]) return;
	vis[x] = true;
	for (int i = 1; i <= m; i++) {
		hold[i] += info[x][i];
		if (hold[i] > 50)//说明是主公司的子公司
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
		f(i);//算i持有的m个公司的所有股票
		for (int j = 1; j <= m; j++)
			if (hold[j] > 50 && i != j)
				cout << i << ' ' << j << endl;
	}
}