#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, extend[9][9], dp[1 << 9][9], ans = 0x3f3f3f3f;
		memset(extend, 0x3f, sizeof(extend));
		memset(dp, 0x3f, sizeof(dp));
		cin >> n;
		vector<string> info(n);
		for (int i = 0; i < n; i++)
			cin >> info[i];
		for (int i = 0; i < info.size(); i++)//去除有包含关系的DNA串！！！
			for (int j = 0; j < info.size(); j++)
				if (i != j && info[i].find(info[j]) != string::npos)
					info.erase(info.begin() + j), n--;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k <= min(info[i].length(), info[j].length()); k++)
					if (info[i].substr(info[i].length() - k, k) == info[j].substr(0, k))
						extend[i][j] = min(extend[i][j], (int)info[j].length() - k);
		for (int i = 0; i < n; i++)
			dp[1 << i][i] = info[i].length();
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0, _j = 1; j < n; j++, _j <<= 1)//枚举状态i的最后一个DNA串
				if (i & _j)
					for (int k = 0, _k = 1; k < n; k++, _k <<= 1)//我为人人，给状态i加状态_k！！！
						if (j != k && (!(i & _k)))
							dp[i | _k][k] = min(dp[i | _k][k], dp[i][j] + extend[j][k]);
		for (int i = 0; i < n; i++)
			ans = min(ans, dp[(1 << n) - 1][i]);
		cout << ans << endl;
	}
}

//DFS TLE
/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, ans = 0x3f3f3f3f;
string info[9], tmp;
bool vis[9] = { false };
void f(int depth) {
	if (tmp.length() >= ans) return;
	if (depth == n) {
		ans = min(ans, (int)tmp.length());
		return;
	}
	for (int i = 0; i < n; i++)
		if (!vis[i])
			if (tmp.find(info[i]) != string::npos)
				vis[i] = true, f(depth + 1), vis[i] = false;
			else
				for (int j = min(tmp.length(), info[i].length()); j >= 0; j--)
					if (tmp.substr(tmp.length() - j, j) == info[i].substr(0, j)) {
						tmp += info[i].substr(j, info[i].length() - j);
						vis[i] = true;
						f(depth + 1);
						vis[i] = false;
						tmp.erase(tmp.length() - info[i].length() + j, info[i].length() - j);
						break;
					}
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		ans = 0x3f3f3f3f;
		memset(vis, 0, sizeof(vis));
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> info[i];
		for (int i = 0; i < n; i++)
			vis[i] = true, tmp = info[i], f(1), vis[i] = false;
		cout << ans << endl;
	}
}
*/