#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 合法序列个数 = (C(m)(m + n) – C(m + 1)(m + n)) * m!*n!= (m - n + 1) * (m + n)! / (m + 1);
const int N = 380;//200!有375位
string Big_Integer_Mul(string a, int b) { //高精度a乘单精度b，复杂度o(n)
	string ans;
	int na[N] = { 0 }, la = a.size(), w = 0;
	for (int i = la - 1; i >= 0; i--) na[la - i - 1] = a[i] - '0';
	for (int i = 0; i < la; i++) na[i] = na[i] * b + w, w = na[i] / 10, na[i] = na[i] % 10;
	while (w) na[la++] = w % 10, w /= 10;
	la--;
	while (la >= 0) ans += na[la--] + '0';
	return ans;
}
string Big_Integer_Div(string a, int b, int nn) { //高精度a除以单精度b
	string r;
	int d = 0;
	if (b == 0) return a;//特判
	for (int i = 0; i < a.size(); i++) {
		r += (d * 10 + a[i] - '0') / b + '0';//求出商
		d = (d * 10 + (a[i] - '0')) % b;//求出余数
	}
	int p = 0;
	for (int i = 0; i < r.size(); i++)
		if (r[i] != '0') {
			p = i;
			break;
		}
	if (nn == 1)
		return r.substr(p);
	else if (nn == 2)
		return to_string(d);
}
int main() {
	int m, n, len = 1;
	string f[210] = { "1","1" };
	while (cin >> m >> n && m) {
		if (m < n) {
			cout << 0 << endl;
			continue;
		}
		for (int i = len + 1; i <= m + n; i++)
			f[i] = Big_Integer_Mul(f[i - 1], i);
		len = max(len, m + n);
		cout << Big_Integer_Div(Big_Integer_Mul(f[m + n], m - n + 1), m + 1, 1) << endl;
	}
}