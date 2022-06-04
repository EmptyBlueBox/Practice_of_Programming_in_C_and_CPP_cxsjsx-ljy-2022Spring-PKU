#include <iostream>
#include <vector>
using namespace std;

double eps = 1e-7, sum = 0;
vector<int> ans;
bool f(int leftt, int mint) {
	if (!leftt) {
		if (abs(sum - 1) < eps)
			return true;
		else
			return false;
	}
	ans.push_back(0);//扩容
	for (int i = mint; i <= leftt; i++) {
		if (sum + 1.0 / i - 1 >= eps) continue;//剪枝，中途发现大于1就不递归了
		ans.back() = i;
		sum += 1.0 / i;
		if (f(leftt - i, i))
			return true;
		sum -= 1.0 / i;
	}
	ans.pop_back();//这个分割不行，回溯的时候要缩小一个，用栈更方便，但是不方便输出答案
	return false;
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		sum = 0;
		ans.clear();
		int t;
		cin >> t;
		if (f(t, 1)) {
			cout << ans.size();
			for (int i : ans)
				cout << ' ' << i;
			cout << endl;
		} else
			cout << -1 << endl;
	}
}