#include <iostream>
#include <algorithm>
using namespace std;
inline int Binary_atoi(string tmp) { //把string看成二进制数换成int
	int ans = 0, len = tmp.length();
	for (int i = 0; i < len; i++)
		if (tmp[i] == '1')
			ans += (1 << (len - i - 1));
	return ans;
}
inline void flip(int& n, int pos) {
	if (pos == 1) { //特判摁第一位
		n ^= 1, n ^= 2;
		return;
	}
	for (int i = pos - 1; i <= pos + 1; i++)
		n ^= (1 << i - 1);
}
inline bool GetBit(int n, int pos) { //右边第一个是第1位,总共len位，最高位是len，这与平时的规定不一样，一般规定右边第一位是第0位
	return (n >> pos - 1) & 1;
}
int solve(int a, int len) {
	int ans = 0;
	for (int i = 1; i <= len; i++) {
		if (GetBit(a, i)) {
			if (i == len)//最高位在摁完之后是1就说明这种方法不行
				return 0x7f7f7f7f;
			ans++;
			flip(a, i + 1);
		}
	}
	return ans;
}
int main() {
	int a, len, ans = 0x7f7f7f7f;
	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;
	len = tmp1.length();
	//int32位，这里的密码可以存为一个int a
	//再将俩数异或，因此相当于将a全变成0
	a = Binary_atoi(tmp1) ^ Binary_atoi(tmp2);
	ans = min(ans, solve(a, len));
	flip(a, 1);
	ans = min(ans, solve(a, len) + 1);
	//不用reverse再算一遍
	if (ans >= 0x7f7f7f7f)
		cout << "impossible";
	else
		cout << ans;
}