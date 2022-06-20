#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, ans = 0;//不能初始化为最小值，有可能所有课都不冲突！！！
	pair<int, int> a[1001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);//sort不能从0开始，0处没有定义！！！
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i].second >= a[j].first)
				ans = max(ans, min(a[j].second, a[i].second) - a[j].first + 1);
	cout << ans << endl;
}