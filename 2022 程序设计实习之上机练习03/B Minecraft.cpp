#include <iostream>
using namespace std;
//长方体互相接触的面积最大，尽量排成长方体
//因此要先排一层，使得能排成长方体，如果不能就只排一层
int main() {
	int n, ans = 0x7f7f7f7f;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (n % (i * j) == 0) {
				int k = n / i / j;
				ans = min(ans, 2 * (i * j + j * k + k * i));
			}
		}
	}
	cout << ans << endl;
}