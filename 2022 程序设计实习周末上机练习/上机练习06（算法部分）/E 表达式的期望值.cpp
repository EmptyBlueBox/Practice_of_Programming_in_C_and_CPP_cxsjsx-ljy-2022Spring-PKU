#include <iostream>
#include <iomanip>
using namespace std;

//E[i] = E[i - 1] * p(i) + a[i] * (1 - p(i))来算总期望，但是由于位运算和小数运算互斥，因此算出来每一位的期望相加即可
double f(double lhs, char op, int rhs) {
	if (op == '^') return rhs ? 1 - lhs : lhs;
	if (op == '|') return rhs ? 1. : lhs;
	if (op == '&') return rhs ? lhs : 0.;
}
int main() {
	int n, T = 0;
	while (cin >> n) {
		T++;
		printf("Case %d:\n", T);
		int a[201];
		char o[201];
		double p[201];
		for (int i = 0; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> o[i];
		for (int i = 1; i <= n; i++) cin >> p[i];
		double ans = 0.;
		for (int i = 0; i <= 20; i++) {
			double tmp = 0. + ((a[0] >> i) & 1);
			for (int j = 1; j <= n; j++)
				tmp = p[j] * tmp + (1. - p[j]) * f(tmp, o[j], (a[j] >> i) & 1);
			ans += (1 << i) * tmp;
		}
		cout << fixed << setprecision(6) << ans << endl;
	}
}