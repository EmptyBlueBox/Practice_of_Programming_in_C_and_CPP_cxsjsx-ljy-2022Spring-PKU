#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//浮点二分查找
int m, n;
double l = 0x7f7f7f7f, r = 0, s[10010] = { 0 }, ans;
bool accept() {
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		cnt += int(s[i] / ans);
	return cnt >= n + 1;
}
int main() {
	const double pi = acos(-1.0);//用反三角函数表示pi
	const double eps = 1e-5;
	cin >> m >> n; //n得加一，因为没算自己
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
		s[i] = pi * s[i] * s[i];
		l = min(s[i], l);
		r = max(s[i], r);
	}
	l /= n + 1;//注意最小值不是最小的蛋糕大小
	while ((r - l) > eps) { //二分查找
		ans = (l + r) / 2;
		if (accept())
			l = ans;
		else
			r = ans;
	}
	cout << fixed << setprecision(3) << ans << endl;
	return 0;
}