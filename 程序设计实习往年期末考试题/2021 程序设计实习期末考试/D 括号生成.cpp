#include <iostream>
#include <string>
using namespace std;

int not_paired, n;
string ans;
void f(int depth) { //深度是放了几个左括号
	if (depth == n + 1) {
		for (int i = 0; i < not_paired; i++)
			ans += ')';
		cout << ans << endl;
		for (int i = 0; i < not_paired; i++)
			ans.pop_back();
		return;
	}
	ans += '(', not_paired++, f(depth + 1), not_paired--, ans.pop_back();
	if (not_paired)
		ans += ')', not_paired--, f(depth), not_paired++, ans.pop_back();
}
int main() {
	cin >> n;
	f(1);
}