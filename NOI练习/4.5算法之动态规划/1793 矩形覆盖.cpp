//WA 6分
/*
#include <iostream>
#include <cstring>
using namespace std;

int dp[1 << 15];
int main() {
	int n;
	while (cin >> n && n) {
		memset(dp, 0x3f, sizeof(dp));
		pair<int, int> info[15];
		for (int i = 0; i < n; i++)
			cin >> info[i].first >> info[i].second;
		for (int i = 0; i < (1 << n); i++) { //用一个矩形盖住每个状态的所有点
			int u = 0xc0c0c0c0, d = 0x3f3f3f3f, l = 0x3f3f3f3f, r = 0xc0c0c0c0, cnt = 0;
			for (int j = 0, _j = 1; j < n; j++, _j <<= 1)
				if (i & _j)
					u = max(u, info[j].first), d = min(d, info[j].first), l = min(l, info[j].second), r = max(r, info[j].second), cnt++;
			if (cnt >= 2)
				dp[i] = max(u - d, 1) * max(r - l, 1);//防止退化成线段
		}
		for (int i = 0; i < (1 << n); i++)//每个状态分成两堆完全分隔
			for (int j = i; j; j = j & (j - 1))//除去最低位的1
				dp[i] = min(dp[i], dp[j] + dp[i - j]);
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0, _j = 1; j < n; j++, _j <<= 1)//枚举后加进去的点
				for (int k = j + 1, _k = (_j << 1); k < n; k++, _k <<= 1)//我为人人
					dp[i | _j | _k] = min(dp[i | _j | _k], dp[_j | _k] + dp[i]);
		cout << dp[(1 << n) - 1] << endl;
	}
}
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int in() {
	int k = 0, fh = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar())
		if (c == '-') fh = -1;
	for(; c >= '0' && c <= '9'; c = getchar())
		k = k * 10 + c - 48;
	return k * fh;
}
int sum[20][20], f[40000], n, x[20], y[20], tot, id[20], cnt, a, b, from, h, l, X0, X1, Y0, Y1;
int main() {
	while (n = in()) {
		memset(f, 60, sizeof(f));
		f[0] = 0;

		for(int i = 0; i < n; ++i)
			x[i] = in(), y[i] = in();
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j) {
				if (i == j) sum[i][j] = 0;
				h = abs(x[i] - x[j]);
				l = abs(y[i] - y[j]);
				if (!h) h = 1;
				if (!l) l = 1;
				sum[i][j] = sum[j][i] = h * l;
			}//预处理
		for(int i = 0; i < n; ++i) {
			tot = (1 << i);
			for(int j = 0; j < n; ++j)
				if (i != j)
					f[tot] = min(f[tot], sum[i][j]);
		}//预处理只有一个点
		tot = 1 << n;
		for(int i = 1; i < tot; ++i) {
			cnt = 0;
			for(int j = 0; j < n; ++j)
				if ((1 << j) & i) {
					id[++cnt] = j;
					f[i] = min(f[i], f[i ^ (1 << j)] + f[1 << j]);//枚举去掉一个点的状态和去掉的这个点的状态，防止状态包含的这些点的最小矩形覆盖没有一个同时覆盖了状态中的两个点
				}
			for(int j = 1; j < cnt; ++j) {
				a = id[j];
				for(int k = j + 1; k <= cnt; ++k) {
					b = id[k];
					from = i;
					if (x[a] < x[b]) {
						X0 = x[a];
						X1 = x[b];
					} else {
						X0 = x[b];
						X1 = x[a];
					}
					if (y[a] < y[b]) {
						Y0 = y[a];
						Y1 = y[b];
					} else {
						Y0 = y[b];
						Y1 = y[a];
					}
					if (X0 == X1) {//分向左向右
						++X1;
						for(int l = 1; l <= cnt; ++l)
							if (X0 <= x[id[l]] && x[id[l]] <= X1 && Y0 <= y[id[l]] && y[id[l]] <= Y1)
								from ^= (1 << id[l]);
						f[i] = min(f[i], f[from] + sum[a][b]);

						--X1;
						--X0;
						from = i;
						for(int l = 1; l <= cnt; ++l)
							if (X0 <= x[id[l]] && x[id[l]] <= X1 && Y0 <= y[id[l]] && y[id[l]] <= Y1)
								from ^= (1 << id[l]);
						f[i] = min(f[i], f[from] + sum[a][b]);
					} else if (Y0 == Y1) {//分向上向下
						++Y1;
						for(int l = 1; l <= cnt; ++l)
							if (X0 <= x[id[l]] && x[id[l]] <= X1 && Y0 <= y[id[l]] && y[id[l]] <= Y1)
								from ^= (1 << id[l]);
						f[i] = min(f[i], f[from] + sum[a][b]);

						--Y1;
						--Y0;
						from = i;
						for(int l = 1; l <= cnt; ++l)
							if (X0 <= x[id[l]] && x[id[l]] <= X1 && Y0 <= y[id[l]] && y[id[l]] <= Y1)
								from ^= (1 << id[l]);
						f[i] = min(f[i], f[from] + sum[a][b]);
					} else {
						for(int l = 1; l <= cnt; ++l)
							if (X0 <= x[id[l]] && x[id[l]] <= X1 && Y0 <= y[id[l]] && y[id[l]] <= Y1)
								from ^= (1 << id[l]);
						f[i] = min(f[i], f[from] + sum[a][b]);
					}
				}
			}
		}
		printf("%d\n", f[tot - 1]);
	}
	return 0;
}