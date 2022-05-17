#include <iostream>
using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	int n, a, b, ansp, ansq;
	cin >> n >> a >> b;
	double max = 0;
	for (int q = 2; q <= n; q++)
		for (int p = 1; p < q; p++)
			if (p * b<a * q && gcd(p, q) == 1 && p * 1.0 / q>max)
				ansp = p, ansq = q, max = p * 1.0 / q;
	cout << ansp << ' ' << ansq << endl;
}