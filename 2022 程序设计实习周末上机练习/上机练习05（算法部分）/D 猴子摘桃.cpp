#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int h;
	while (cin >> h && h != -1) {
		int v[101], c[101], n = 1, ans = 0;
		while (cin >> v[n] >> c[n] && v[n] != -1) {
			n++;
		}
		n--;
		for (int i = 1; i <= n; i++) {
			int tmp_h = h, peach = 0;
			for (int j = i; j <= n; j++) {
				tmp_h -= c[j];
				if (tmp_h < 0)
					break;
				peach += v[j];
			}
			ans = max(ans, peach);
		}
		cout << ans << endl;
	}
}