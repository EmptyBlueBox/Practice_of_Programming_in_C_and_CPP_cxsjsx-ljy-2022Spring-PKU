#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//莫名其妙倒序贪心！！！
//从前往后循环，每一天做的作业作为状态是有后效性的，因为前面每一天做什么会影响后几天做什么
//从后往前循环，可以保证每一天选择的是到了这一天
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, x, y, ans = 0;
	vector<int> info[10001];//以每一天为ddl的任务分别价值几分
	priority_queue<int, vector<int>, less<int>> q;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x >> y, info[y].push_back(x);
	for (int i = 10000; i >=1 ; i--) {//枚举每一天做哪个作业
		for (auto j : info[i])
			q.push(j);
		if (q.empty())
			continue;
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
}