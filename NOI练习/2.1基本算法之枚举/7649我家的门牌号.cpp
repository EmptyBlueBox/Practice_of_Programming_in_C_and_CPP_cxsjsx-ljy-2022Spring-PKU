#include <iostream>
using namespace std;
//《奥数典型题举一反三（小学六年级）》 (ISBN 978-7-5445-2883-2) 第二章 第七讲 例2 拓展一
int main() {
	int x, n, my;
	cin >> x;
	for (n = 1;; n++)
		for (my = 1; my <= n; my++)
			if (n * (n + 1) / 2 - 2 * my == x) {
				cout << my << ' ' << n << endl;
				return 0;
			}
}