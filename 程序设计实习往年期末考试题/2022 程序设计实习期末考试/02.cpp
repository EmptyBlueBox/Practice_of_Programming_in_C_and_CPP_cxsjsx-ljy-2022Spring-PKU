#include <iostream>
#include <string>
using namespace std;

long long m, n, x, y;
int ans = 0x3f3f3f3f;
void f(long long now, int step) {
	if (step > 52 || step >= ans || now < 0 || (now - (52 - step) * x)>n)//重要剪枝！！！
		return;
	if (now == n) {
		ans = step;
		return;
	}
	f(now * y, step + 1);
	if (now >= x)
		f(now - x, step + 1);
}
int main() {
	cin >> m >> n >> x >> y;
	f(m, 0);
	cout << (ans == 0x3f3f3f3f ? "Failed" : to_string(ans)) << endl;
}