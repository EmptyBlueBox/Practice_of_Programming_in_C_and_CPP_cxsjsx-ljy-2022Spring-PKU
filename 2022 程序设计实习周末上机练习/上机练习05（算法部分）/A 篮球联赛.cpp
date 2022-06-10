#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string a[4];
int ans = 4;
void f() { //枚举每一个？是什么
	for (int i = 0; i < 4; i++)
		for (int j = i; j < 4; j++)
			if (a[i][j] == '?') {
				a[i][j] = 'W', a[j][i] = 'L';
				f();
				a[i][j] = 'L', a[j][i] = 'W';
				f();
				a[i][j] = '?', a[j][i] = '?';//需要回溯
				return;
			}
	int win[4] = { 0 };
	for (int i = 0; i < 4; i++)
		win[i] = count(a[i].begin(), a[i].end(), 'W');
	int cnt = 0;
	for (int i = 1; i < 4; i++)
		if (win[i] > win[0])
			cnt++;
	ans = min(ans, cnt + 1);
	//ans = min(ans, count_if(win + 1, win + 4, [=](int x) { return win[0] < x; }) + 1);//Lambda表达式，但是oj和dev编译不通过
}
int main() {
	int N;
	cin >> N;
	while (N--) {
		ans = 4;
		for (int i = 0; i < 4; i++)
			cin >> a[i];
		f();
		cout << ans << endl;
	}
}