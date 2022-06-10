#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x) {
	// 在此处补充你的代码
	string ans, ans0;
	for (int i = 0; i < 31; i++) {
		int tmp = x & 1;
		ans += char( tmp+ '0');
		x >>= 1;
	}
	for (int i = 30; i >= 0; i--)
		ans0 += ans[i];
	return ans0;
	// 在此处补充你的代码
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}