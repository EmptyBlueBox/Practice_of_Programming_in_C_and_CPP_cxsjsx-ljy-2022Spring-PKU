#include <iostream>
using namespace std;
//所有上下车的情况由第二站上下车的情况决定
int main() {
	int s[16], a[16], n, m, x;
	cin >> a[1] >> n >> m >> x;
	s[1] = a[1], s[2] = a[1];
	for (a[2] = 0;; a[2]++) {//第二站上下几个人都行，没有上界
		for (int i = 3; i <= n - 1; i++) {
			a[i] = a[i - 1] + a[i - 2];
			s[i] = s[i - 1] + a[i - 2];
		}
		if (s[n - 1] == m)
			break;
	}
	cout << s[x] << endl;
}