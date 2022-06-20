#include <iostream>
#include <string>
using namespace std;

int n;
string ans;
void f(int left, int not_paired) { //已经放了几个左括号,还有几个左括号没匹配
	if (left == n && not_paired == 0) {
		cout << ans << endl;
		return;
	}
	if (left < n)
		ans += '(', f(left + 1, not_paired + 1), ans.pop_back();
	if (not_paired)
		ans += ')', f(left, not_paired - 1), ans.pop_back();
}
int main() {
	cin >> n;
	f(0, 0);
}