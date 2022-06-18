#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
vector<long long> a;
long long N, n;
bool ok(long long x) {
	if (x == 0)
		return true;
	long long cnt = 0;
	for (long long i = 0; i < N; i++)
		cnt += a[i] / x;
	return cnt >= n;
}
int main() {
	cin >> N >> n;
	a.resize(N, 0);
	double tmp;
	for (long long i = 0; i < N; i++) {
		cin >> tmp;
		//这道题虽然是浮点二分，但是double好像被卡精度，因此用整型变量,乘100再处理
		a[i] = 100 * tmp;
	}
	long long l = 0, r = 10000010, mid;
	while (l + 1 != r) {
		mid = (l + r) / 2;//如果用int会溢出,所以用long long
		if (ok(mid))
			l = mid;
		else
			r = mid;
	}
	cout << fixed << setprecision(2) << l / 100.0 << endl;
}