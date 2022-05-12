#include <iostream>
#include <vector>
using namespace std;
long long d, n;//int不够用
vector<long long> a;//a[i]代表i及i之前的面积和
inline bool isleft(long long x) {//画在x处或左小于等于右
	return a[x - 1] <= a[d + 1] - a[x - 1];
}
int main() {
	cin >> d >> n;
	a.resize(d + 2, 0);
	//通过考虑画在哪里取等来看清数学模型，有取等的情况是一般的，先考虑能取等
	//如果存在等于就取upperbound-1
	//如果不存在等于就取upperbound
	for (long long i = 0; i < n; i++) {
		long long l, r, h;
		cin >> l >> h >> r >> h;
		r += l;
		for (long long j = l; j < r; j++)
			a[j] += h;
		if (n == 1 && r - l == 1) { //如果只有一个宽为1的小长方形，答案就是d！！！并且只有这样的情况才是d
			cout << d << endl;
			return 0;
		}
	}
	for (long long i = 1; i <= d + 1; i++)
		a[i] += a[i - 1];
	long long l = 0, r = d + 1, m = (d + 1) / 2;
	while (l + 1 != r) {
		m = (l + r) / 2;
		if (isleft(m))
			l = m;
		else
			r = m;
	}
	if (a[l - 1] * 2 != a[d + 1])//如果画在l处不取等，那么答案应该是r
		l = r;
	cout << l << endl;
}