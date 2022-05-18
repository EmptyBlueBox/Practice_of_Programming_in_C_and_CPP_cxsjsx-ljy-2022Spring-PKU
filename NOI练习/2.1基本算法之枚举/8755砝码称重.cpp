#include <iostream>
#include <set>
using namespace std;
int value[6] = { 1,2,3,5,10,20 }, cnt[6], tmpsum = 0;//tmpsum初始化
set<int> ans;
void solve(int step) {
	if (step == 6) {
		ans.insert(tmpsum);
		return;
	}
	for (int i = 0; i <= cnt[step]; i++) {
		tmpsum += i * value[step];//最简单的dfs，不要瞎搞
		solve(step + 1);
		tmpsum -= i * value[step];
	}
	return;
}
int main() {
	for (int i = 0; i < 6; i++)
		cin >> cnt[i];
	solve(0);
	cout << "Total=" << ans.size() - 1 << endl;
}