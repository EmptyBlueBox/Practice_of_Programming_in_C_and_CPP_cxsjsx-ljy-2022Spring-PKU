#include <iostream>
#define endl '\n'
using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	while (cin >> x >> y) {
		cout << "x=" << x << ' ' << "y=" << y << endl;
		cout << "x和y的最大公因数是" << gcd(x, y) << endl << endl;
	}
}