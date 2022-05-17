#include <iostream>
using namespace std;
//第n个猴子拿了几个桃子决定了整个过程，于是枚举第n个猴子拿几个桃
int n;
int main() {
	int ans;
	cin >> n;
	for (int i = 1;; i++) { //第n个猴子拿几个桃
		ans = i * n + 1;
		for (int j = n - 1; j >= 1; j--) { //第j个猴看见几个桃
			if (ans % (n - 1) != 0)
				goto loop;
			ans = ans / (n - 1) * n + 1;
		}
		cout << ans << endl;
		return 0;
loop:
		;
	}
}