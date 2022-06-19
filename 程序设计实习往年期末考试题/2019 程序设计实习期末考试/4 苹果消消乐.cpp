#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int n, k, info[102] = { 0 }, ans = 0;
		cin >> n >> k;
		k = min(k, n);
		for (int i = 1; i <= n; i++)
			cin >> info[i];
		info[n + 1] = 101;
		for (int i = k + 1; i <= n + 1; i++)
			ans = max(ans, info[i] - info[i - k - 1]);
		cout << ans - 1 << endl;
	}
}