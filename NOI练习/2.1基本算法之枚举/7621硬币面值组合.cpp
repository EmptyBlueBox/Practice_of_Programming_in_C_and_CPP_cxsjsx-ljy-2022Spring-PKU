#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, ans[3] = { 0 }, cnt = 0;
	cin >> n;
	for (ans[2] = 0; ans[2] <= n / 5; ans[2]++) {
		for (ans[1] = 0; ans[1] <= n / 2 && ans[1] * 2 + ans[2] * 5 <= n; ans[1]++) {
			cout << setw(3) << setfill('0') << ++cnt << setw(12) << setfill(' ') << n - ans[1] * 2 - ans[2] * 5\
			     << setw(12) << setfill(' ') << ans[1] << setw(12) << setfill(' ') << ans[2] << endl;//主要是注意格式
			//printf("%03d% 12d% 12d% 12d\n", ++cnt, n - ans[1] * 2 - ans[2] * 5, ans[1], ans[2]);
		}
	}
}