//WA
/*
#include <iostream>
using namespace std;

int main() {
	typedef pair<int, int> pii;
	int n, ans = 0xc0c0c0c0;
	pii a[1001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i].first <= a[j].first && a[i].second >= a[j].second)
				ans = max(ans, a[j].second - a[j].first + 1);
			else if (a[j].first <= a[i].first && a[j].second >= a[i].second)
				ans = max(ans, a[i].second - a[i].first + 1);
			else if (a[i].first <= a[j].first && a[i].second >= a[j].first)
				ans = max(ans, a[i].second - a[j].first + 1);
			else if (a[j].first <= a[i].first && a[j].second >= a[i].first)
				ans = max(ans, a[j].second - a[i].first + 1);
	cout << ans << endl;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	typedef pair<int, int> pii;
	int n, ans = 0xc0c0c0c0;
	pii a[1001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i].second >= a[j].first)
				ans = max(ans, min(a[j].second, a[i].second) - a[j].first + 1);
	cout << ans << endl;
}