#include <iostream>
using namespace std;
int ori[7][8] = { {0} }, ans[7][8] = { {0} };//要多留一圈0，代表熄灭的灯，不按
bool check() {
	for (int i = 2; i <= 6; i++)//枚举到最后一行的下一行，这第六行代表着第六行按什么才能让第五行是0
		for (int j = 1; j <= 6; j++)
			ans[i][j] = ori[i - 1][j] ^ ans[i - 1][j - 1] ^ ans[i - 1][j] ^ ans[i - 1][j + 1] ^ ans[i - 2][j];
	for (int i = 1; i <= 6; i++)
		if (ans[6][i] == 1)//第六行应该不用按就能让第五行是0
			return false;
	return true;
}
int main() {
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 6; j++)
			cin >> ori[i][j];
	for (int ans1 = 0; ans1 < (1 << 6); ans1++) { //枚举第一行
		int tmp = ans1;
		for (int i = 1; i <= 6; i++) { //把二进制每一位拆出来,到6而不是5
			ans[1][i] = tmp % 2;
			tmp /= 2;
		}
		if (check())//判断这样按第一行是不是可以
			for (int i = 1; i <= 5; i++) {
				for (int j = 1; j <= 6; j++)
					cout << ans[i][j] << ' ';
				cout << endl;
			}
	}
}