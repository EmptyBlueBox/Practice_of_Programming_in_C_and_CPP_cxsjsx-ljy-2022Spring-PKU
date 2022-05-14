#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	double l0, l1, n, c, eps = 1e-12;//需要很高的精度，1e-6不行
	cin >> l0 >> n >> c;
	l1 = l0 * (1 + n * c);
	double l = 0, r = acos(-1), mid;//二分查找圆心角而不是半径更方便确定上界
	while (r - l > eps) {
		mid = (l + r) / 2;
		if (sin(mid) / mid > l0 / l1)
			l = mid;
		else
			r = mid;
	}
	cout << fixed << setprecision(3) << l0 / 2.0 / sin(mid) * (1 - cos(mid)) << endl;
}
