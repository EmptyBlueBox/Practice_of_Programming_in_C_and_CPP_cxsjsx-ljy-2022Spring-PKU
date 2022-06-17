#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, used[21] = { 0 }, extend[21][21] = { {0} }, ans = 0xc0c0c0c0;
string info[21];
void f(int former, int len) {
	ans = max(ans, len);
	for (int i = 1; i <= n; i++) {
		if (extend[former][i] == 0 || used[i] >= 2)
			continue;
		used[i]++;
		f(i, len + extend[former][i]);
		used[i]--;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> info[i];
	cin >> info[0];
	for (int i = 1; i <= n; i++)
		if (info[i][0] == info[0][0])
			extend[0][i] = info[i].length() - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = min(info[i].length(), info[j].length()) - 1; k >= 1; k--)//重合字符串从大往小循环，才能让伸长的最多
				if (info[i].substr(info[i].length() - k, k) == info[j].substr(0, k))
					extend[i][j] = info[j].length() - k;
	f(0, 1);
	cout << ans << endl;
}