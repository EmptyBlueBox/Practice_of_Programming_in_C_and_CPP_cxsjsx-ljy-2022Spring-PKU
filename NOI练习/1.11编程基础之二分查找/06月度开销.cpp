#include <iostream>
#include <vector>
#define ll long long
using namespace std;
//一串数，将其分成m段，求每段中数的和的最大值的下确界
vector<ll> a;
ll m, n;
bool ok(ll x) {
	int cnt = 0, tmpsum = 0;
	for (int i = 0; i < n; i++) {
		if (tmpsum + a[i] > x) { //不要用左右指针，用tmpsum去peek下一个元素是不是会超限制
			tmpsum = a[i];
			cnt++;
		} else
			tmpsum += a[i];
	}
	cnt++;//无论如何最后一个月都不能在上述循环加上，补一个月
	return cnt <= m;
}
int main() {
	ll l = 0, r = 0, mid;
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		l = max(l, a[i]);
		r += a[i];
	}
	l--;//一定保证l与r都取不到
	r++;
	while (l + 1 != r) {
		mid = l + (r - l) / 2;
		if (ok(mid))//fajo月开销最多为mid是可以在m个月里安排下的
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}
