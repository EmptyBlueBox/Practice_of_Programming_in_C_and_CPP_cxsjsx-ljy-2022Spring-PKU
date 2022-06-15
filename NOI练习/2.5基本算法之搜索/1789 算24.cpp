#include <iostream>
#include <vector>
using namespace std;

vector<double> a(4), tmp;
double eps = 1e-6;
bool f() {
	if (abs(tmp[0] - 24.) < eps && tmp.size() == 1)
		return true;
	for (int i = 0; i < tmp.size(); i++) {
		for (int j = i + 1; j < tmp.size(); j++) {
			double x = tmp[i], y = tmp[j];
			tmp.erase(tmp.begin() + j);
			tmp[i] = x + y;
			if (f()) return true;
			tmp[i] = x - y;
			if (f()) return true;
			tmp[i] = y - x;//不止除法，减法也是不对称的，也要算两次
			if (f()) return true;
			tmp[i] = x * y;
			if (f()) return true;
			if (abs(y) > eps) {
				tmp[i] = x / y;
				if (f()) return true;
			}
			if (abs(x) > eps) {
				tmp[i] = y / x;
				if (f()) return true;
			}
			tmp[i] = x, tmp.insert(tmp.begin() + j, y);
		}
	}
	return false;
}
int main() {
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] && a[0]) {
		tmp = a;
		cout << (f() ? "YES\n" : "NO\n");
	}
}