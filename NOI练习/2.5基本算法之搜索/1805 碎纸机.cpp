#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t, ans_sum = -1;
vector<int> ans, ans_tmp;
bool conflict = false;
void f(int sum,string a) {
	if (sum > t)
		return;
	else if (a.empty() && sum > ans_sum) {
		ans_sum = sum, ans = ans_tmp, conflict = false;//如果还有更优的答案，那么之前的两个答案冲突就作废
		return;
	} else if (a.empty() && sum == ans_sum) {
		conflict = true;
		return;
	}
	for (int i = 1; i <= a.length(); i++) {
		int next = atoi(a.substr(0, i).c_str());
		ans_tmp.push_back(next);
		f(sum + next, a.substr(i, a.length() - i));
		ans_tmp.pop_back();
	}
}
int main() {
	string a;
	while (cin >> t >> a && t) {
		ans_sum = -1, ans.clear(), ans_tmp.clear(), conflict = false;
		if (t == atoi(a.c_str())) {
			cout << a << ' ' << a << endl;
			continue;
		}
		f(0, a);
		if (conflict) {
			cout << "rejected\n";
			continue;
		}
		if (ans_sum == -1) {
			cout << "error\n";
			continue;
		}
		cout << ans_sum;
		for (auto i : ans)
			cout << ' ' << i;
		cout << endl;
	}
}