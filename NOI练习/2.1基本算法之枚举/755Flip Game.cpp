#include <iostream>
using namespace std;
//0是白，1是黑，全变成一个颜色；1是按，0不按
int ori[6][6] = { {0} }, ans[6][6];
int ok() {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 2; i <= 5; i++)//全按成白的
		for (int j = 1; j <= 4; j++) {
			ans[i][j] = ori[i - 1][j] ^ ans[i - 1][j - 1] ^ ans[i - 1][j] ^ ans[i - 1][j + 1] ^ ans[i - 2][j];//(i,j)按or不按，能让ori[i-1][j]变成白色
			if (ans[i][j])
				cnt1++;
		}
	for (int i = 1; i <= 4; i++)
		if (ans[5][i])
			cnt1 = 0x7f7f7f7f;
	for (int i = 2; i <= 5; i++)//全按成黑的
		for (int j = 1; j <= 4; j++) {
			ans[i][j] = ori[i - 1][j] ^ ans[i - 1][j - 1] ^ ans[i - 1][j] ^ ans[i - 1][j + 1] ^ ans[i - 2][j] ^ 1;//把(i,j)反过来按能让ori[i-1][j]变成黑的
			if (ans[i][j])
				cnt2++;
		}
	for (int i = 1; i <= 4; i++)
		if (ans[5][i])
			cnt2 = 0x7f7f7f7f;
	return min(cnt1, cnt2);
}
int main() {
	int m = 0x7f7f7f7f;
	for(int i=1; i<=4; i++)
		for (int j = 1; j <= 4; j++) {
			char c;
			cin >> c;
			if (c == 'b')
				ori[i][j] = 1;
		}
	for (int i = 0; i < (1 << 4); i++) {
		int tmp = i, cnt = 0;
		for (int j = 1; j <= 4; j++) {
			ans[1][j] = tmp % 2;
			if (ans[1][j])
				cnt++;
			tmp /= 2;
		}
		cnt += ok();
		m = min(m, cnt);
	}
	if (m >= 0x7f7f7f7f)
		cout << "Impossible" << endl;
	else
		cout << m << endl;
}