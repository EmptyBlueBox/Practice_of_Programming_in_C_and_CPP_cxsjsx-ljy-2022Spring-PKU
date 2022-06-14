#include <iostream>
using namespace std;

//看到15或者16想到位运算，直接枚举做哪些工作就行
int main() {
	int sp, w[15], s[15], ans = 0xc0c0c0c0;
	cin >> sp;
	for (int i = 0; i < 15; i++)
		cin >> w[i] >> s[i];
	for (int i = 0; i < (1 << 15); i++) {
		int cnt1 = 0, cnt2 = 0, w1 = 0, w2 = 0, s1 = 0;
		for (int j = 0; j < 10; j++)
			if (i & (1 << j))
				cnt1++, w1 += w[j], s1 += s[j];
		for (int j = 10; j < 15; j++)
			if (i & (1 << j))
				cnt2++, w2 += w[j], s1 += s[j];
		if (cnt1 <= cnt2 && s1 <= sp)
			ans = max(ans, w1 + w2);
	}
	cout << ans << endl;
}