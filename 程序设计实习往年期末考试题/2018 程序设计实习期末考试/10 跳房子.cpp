#include <iostream>
#include <string>
using namespace std;

int m, n, min_step = 0x3f3f3f3f;
string ans, tmp;
void f(int x,int step) { //参数不能传string，否则会非常慢！！！
	if (x == 0 || x > 10000 || step > 25 || step >= min_step)
		return;
	if (x == n) {
		ans = tmp, min_step = step;
		return;
	}
	tmp += 'H';
	f(3 * x, step + 1);
	tmp.back() = 'O';
	f(x / 2, step + 1);
	tmp.pop_back();
}
int main() {
	while (cin >> m >> n && m) {
		min_step = 0x3f3f3f3f, ans.clear(), tmp.clear();
		f(m, 0);
		cout << min_step << endl << ans << endl;
	}
}