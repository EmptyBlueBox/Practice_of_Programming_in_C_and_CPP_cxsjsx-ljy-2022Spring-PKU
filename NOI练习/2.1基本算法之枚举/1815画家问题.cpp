#include <iostream>
#define ll long long
using namespace std;
//和熄灯问题非常像
//都涂成黄色，0是黄色，1是白色;0是不涂，1是涂
ll n;
ll ori[17][17] = { {0} }, ans[17][17] = { {0} };
int ok() {
	int cnt = 0;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = ori[i - 1][j] ^ ans[i - 1][j - 1] ^ ans[i - 1][j] ^ ans[i - 1][j + 1] ^ ans[i - 2][j];
			if (ans[i][j])
				cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (ans[n + 1][i])
			return 0x7f7f7f7f;
	return cnt;
}
int main() {
	int zuixiao = 0x7f7f7f7f;
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == 'w')
				ori[i][j] = 1;
		}
	for (ll ans1 = 0; ans1 < (1 << n); ans1++) {
		ll tmp = ans1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			ans[1][i] = tmp % 2;
			if (ans[1][i])
				cnt++;
			tmp /= 2;
		}
		cnt += ok();
		zuixiao = min(zuixiao, cnt);
	}
	if (zuixiao < 0x7f7f7f7f)
		cout << zuixiao << endl;
	else
		cout << "inf" << endl;
}
