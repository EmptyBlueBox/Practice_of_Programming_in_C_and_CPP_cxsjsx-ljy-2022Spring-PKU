#include <iostream>
#include <cstring>
using namespace std;

//不是动态规划，暴力搜索即可
int main() {
	int N;
	cin >> N;
	while (N--) {
		int cnt_of_1[1001] = { 0 };
		string a;
		cin >> a;
		int len = a.length();
		a.insert(0, "0");
		for (int i = 1; i <= len; i++)
			cnt_of_1[i] = cnt_of_1[i - 1] + (a[i] == '1' ? 1 : 0);
		int ans = len - cnt_of_1[len];
		for (int i = 1; i <= len; i++)//前i个变成0
			ans = min(ans, cnt_of_1[i] + len - i - cnt_of_1[len] + cnt_of_1[i - 1]);
		cout << ans << endl;
	}
}