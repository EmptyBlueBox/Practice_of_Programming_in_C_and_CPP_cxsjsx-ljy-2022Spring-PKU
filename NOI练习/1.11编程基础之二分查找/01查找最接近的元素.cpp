#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	int n, m, tmp;
	cin >> n;
	a.resize(n + 2);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = a[1] - 1, a[n + 1] = a[n] + 1;//保证初始l与r在范围之外
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		int l = 0, r = n + 1, mid;
		while (l + 1 != r) {
			mid = (l + r) >> 1;
			if (a[mid] <= tmp)
				l = mid;
			else
				r = mid;
		}
		l = max(l, 1), r = min(r, n);//判断是不是全蓝或全红
		if (a[l] + a[r] < 2 * tmp)
			cout << a[r] << endl;
		else
			cout << a[l] << endl;
	}
}