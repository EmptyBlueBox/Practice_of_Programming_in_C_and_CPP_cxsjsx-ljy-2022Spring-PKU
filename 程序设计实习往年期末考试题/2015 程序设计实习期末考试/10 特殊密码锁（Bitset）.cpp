#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
	int n, cnt1 = 0, cnt2 = 0;
	string x, y;
	cin >> x >> y;
	bitset<31> a1(x), a2(x), b(y);//Bitset可以直接用01字符串初始化，但不能赋值
	a1 ^= b, a2 ^= b;
	n = x.length();
	for (int i = 0; i < n - 1; i++)
		if (a1[i])
			a1.flip(i), a1.flip(i + 1), a1.flip(i + 2), cnt1++;
	if (a1[n - 1])
		cnt1 = 0x3f3f3f3f;
	if (a2[0]) {
		a2.flip(0), a2.flip(1), cnt2++;
		for (int i = 0; i < n - 1; i++)
			if (a2[i])
				a2.flip(i), a2.flip(i + 1), a2.flip(i + 2), cnt2++;
		if (a2[n - 1])
			cnt2 = 0x3f3f3f3f;
	} else cnt2 = 0x3f3f3f3f;
	cout << (min(cnt1, cnt2) == 0x3f3f3f3f ? "impossible" : to_string(min(cnt1, cnt2))) << endl;
}