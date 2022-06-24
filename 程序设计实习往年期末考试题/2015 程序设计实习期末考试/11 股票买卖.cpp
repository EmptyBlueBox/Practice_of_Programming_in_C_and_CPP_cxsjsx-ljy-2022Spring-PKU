#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//分成两部分，左部分内买卖的最大值和右部分买卖的最大值之和
int n, info[100001], ansl[100001] = { 0 }, ansr[100001] = { 0 }, ans = 0xc0c0c0c0;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		cin >> n;
		memset(info, 0, sizeof(info)), memset(ansl, 0, sizeof(ansl)), memset(ansr, 0, sizeof(ansr)), ans = 0xc0c0c0c0;
		for (int i = 1; i <= n; i++)
			cin >> info[i];
		int premin = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
			ansl[i] = max(ansl[i - 1], info[i] - premin), premin = min(premin, info[i]);//类似最长子串和，是以i为结尾的最大值
		int nxtmax = 0xc0c0c0c0;
		for (int i = n; i >= 1; i--)
			ansr[i] = max(ansr[i + 1], nxtmax - info[i]), nxtmax = max(nxtmax, info[i]);
		for (int i = 1; i <= n; i++)
			ans = max(ans, ansl[i] + ansr[i]);
		cout << ans << endl;
	}
}