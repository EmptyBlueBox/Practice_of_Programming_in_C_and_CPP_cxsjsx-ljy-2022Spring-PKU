#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main() {//取最长上升子序列与最长下降子序列更长的那个
	ios::sync_with_stdio(false), cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int n, ans = -1;
		vector<int> h, dp1, dp2;
		cin >> n;
		h.resize(n), dp1.resize(n, 1), dp2.resize(n, 1);
		for (int i = 0; i < n; i++)
			cin >> h[i];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++)
				if (h[j] > h[i])
					dp1[i] = max(dp1[i], dp1[j] + 1);
				else if (h[j] < h[i])
					dp2[i] = max(dp2[i], dp2[j] + 1);
			ans = max(ans, dp1[i]);//每循环一个就维护，不能直接ans = max(ans, dp1[n-1])。因为是以它为终点而不是在它之前最长的
			ans = max(ans, dp2[i]);
		}
		cout << ans << endl;
	}
}