#include<iostream>
using namespace std;
unsigned int calc(unsigned int n,unsigned m,int x,int y) {
	// 在此处补充你的代码
	for (int i = x; i <= 31 - y; i++) {
		if ((m >> i) & 1) //第32位 前！ 00000000000000000000000000000101 后！ 第1位
			n = n | (1 << i);

		else
			n = n & (~(1 << i));
	}
	return n;
	// 在此处补充你的代码
}
int main() {
	int x, y, t;
	unsigned int n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x >> y;
		cout << calc(n, m, x, y) << endl;
	}
	return 0;
}