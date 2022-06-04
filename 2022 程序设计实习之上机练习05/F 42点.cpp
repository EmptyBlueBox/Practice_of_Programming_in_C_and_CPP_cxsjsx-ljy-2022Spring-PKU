#include <iostream>
#include <vector>
using namespace std;

bool f(vector<int> a) {
	if (a[0] == 42 && a.size() == 1)
		return true;
	int len = a.size();
	for (int i = 0; i < len; i++)//枚举任意两个数字
		for (int j = i + 1; j < len; j++) {
			vector<int> b;
			for (int k = 0; k < len; k++) {
				if (k == i || k == j)
					continue;
				b.push_back(a[k]);
			}
			b.resize(len - 1);
			b.back() = a[i] + a[j];
			if (f(b)) return true;
			b.back() = a[i] - a[j];
			if (f(b)) return true;
			b.back() = a[j] - a[i];
			if (f(b)) return true;
			b.back() = a[i] * a[j];
			if (f(b)) return true;
			if (a[j]) {
				b.back() = a[i] / a[j];
				if (f(b)) return true;
			}
			if (a[i]) {
				b.back() = a[j] / a[i];
				if (f(b)) return true;
			}
		}
	return false;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << (f(a) ? "YES\n" : "NO\n");
}