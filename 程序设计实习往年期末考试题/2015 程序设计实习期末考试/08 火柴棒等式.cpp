#include <iostream>
#include <string>
using namespace std;

//重点：最多三位数
int n, cnt[1000], ans = 0, info[10] = { 6,2,5,5,4,5,6,3,7,6 };
int stick(int x) {
	int cnt = 0;
	string a = to_string(x);
	for (int i = 0; i < a.length(); i++)
		cnt += info[a[i] - '0'];
	return cnt;
}
bool f(int x, int y) {
	return cnt[x] + cnt[y] + cnt[x + y] + 4 == n;
}
int main() {
	cin >> n;
	for (int i = 0; i <= 999; i++)
		cnt[i] = stick(i);
	for (int i = 0; i <= 999; i++)
		for (int j = i; j <= 999; j++)
			if (i == j && i + j <= 999)
				ans += f(i, j);
			else if (i != j && i + j <= 999)
				ans += f(i, j) + f(j, i);
	cout << ans << endl;
}