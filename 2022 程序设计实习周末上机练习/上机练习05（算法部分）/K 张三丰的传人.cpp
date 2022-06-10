#include <iostream>
#include <vector>
using namespace std;

double eps = 1e-6;//不能1e-7！！！
vector<int> ans;
bool all_end = false;
void f(int leftt, int mint, double sum) {
	if (!leftt && abs(sum - 1) < eps) { //分完了满足要求
		all_end = true;
		cout << ans.size();
		for (int i : ans)
			cout << ' ' << i;
		cout << endl;
		return;
	} else if (!leftt) return; //分完了但是不满足要求

	for (int i = mint; i <= leftt; i++) {
		if (sum + 1.0 / i > 1 + eps)//剪枝，中途发现大于1就不递归了
			continue;
		ans.push_back(i);
		f(leftt - i, i, sum + 1.0 / i);
		if (all_end) return;//找到答案
		ans.pop_back();
	}
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		ans.clear();
		all_end = false;
		int t;
		cin >> t;
		f(t, 1, 0);
		if (!all_end)
			cout << -1 << endl;
	}
}