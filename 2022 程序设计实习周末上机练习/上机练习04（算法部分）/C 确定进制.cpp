#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

//将p、q、r转换为10进制判断是否满足p*q==r
inline ll convert(int x, int base) { //将base进制下的x转换为10进制
	ll ans = 0;
	for (auto c : to_string(x))//从高位到低位
		ans = ans * base + c - '0';//每经过一位就乘base，再加这一位（相当于这一位是个位）
	return ans;
}
int main() {
	int a[3], minbase = 0;
	cin >> a[0] >> a[1] >> a[2];
	for (auto x : a)
		for (auto c : to_string(x))//按区间循环,循环三个数的每一位
			minbase = max(minbase, c - '0');//找最大的数，答案的进制数至少是这个数加一
	for (int base = minbase + 1; base <= 16; base++) {
		if (convert(a[0], base) * convert(a[1], base) == convert(a[2], base)) {
			cout << base << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}