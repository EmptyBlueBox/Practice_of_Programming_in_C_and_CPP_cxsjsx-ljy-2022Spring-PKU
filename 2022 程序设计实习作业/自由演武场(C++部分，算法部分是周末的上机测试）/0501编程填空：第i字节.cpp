#include <iostream>
using namespace std;
int getByte(int x, int i) {
	return
// 在此处补充你的代码
	    (x>>8 * i)&255;
// 在此处补充你的代码
	;
}
int main() {
	int n;
	cin >> n;
	while(n--) {
		int x, i;
		cin >> x >> i;
		cout << getByte(x, i) << endl;
	}
	return 0;
}