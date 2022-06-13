#include <iostream>
#include <cstring>
using namespace std;

int n, m;
long long info[1001];
bool valid(int x) {
	int needed = 0;
	for (int i = 1; i <= n; i++)
		needed += (info[i] % x ? info[i] / x + 1 : info[i] / x);
	return needed <= m;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> info[i];
	int l = 0, r = 10000001, mid;//承重最大值不是车最大值！！！
	while (l + 1 != r) {
		mid = (l + r) / 2;
		if (valid(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}