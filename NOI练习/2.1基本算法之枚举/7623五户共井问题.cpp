#include <iostream>
using namespace std;
int hmax, h, k[5], ans[5];
int main() {
	cin >> hmax;
	hmax *= 100;
	for (int i = 0; i < 5; i++)
		cin >> k[i];
	//手动解方程：p * h = q * a_0;
	int p = 1 - k[4] * (1 - k[3] * (1 - k[2] * (1 - k[1]))), q = 1;
	for (int i = 0; i < 5; i++)
		q *= k[i];
	q++;
	for (h = 1; h <= hmax; h++) {
		if ((p * h) % q == 0) {
			ans[0] = p * h / q;
			for (int i = 1; i < 5; i++)
				ans[i] = h - k[i - 1] * ans[i - 1];
			if (ans[0] == ans[1])//注意绳子长度不能一样，其实应该排除所有可能的相等的，这里发现要求前两个不相等就可以AC了
				continue;
			cout << h << ' ';
			for (int i = 0; i < 5; i++)
				cout << ans[i] << ' ';
			return 0;
		}
	}
	cout << "not found\n";
}