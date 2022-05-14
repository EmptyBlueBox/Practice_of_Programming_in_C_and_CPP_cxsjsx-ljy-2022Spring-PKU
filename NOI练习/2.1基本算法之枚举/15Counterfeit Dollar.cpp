#include <iostream>
using namespace std;
string a[3][3];
bool check(int x, int heavy) {//用heavy=1代表偏重，0代表偏轻
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (a[i][j].find(x + 'A') != string::npos) {//string中的find如果找到返回第一次出现的下标，否则返回string：：npos
				//类似真值表将应该是up还是down与j+heavy对应起来
				if ((!j^heavy) && a[i][2] != "down")//j=0，heavy=0或者j=1，heavy=1
					return false;
				if (j^heavy && a[i][2] != "up")//j=0，heavy=1或者j=1，heavy=0
					return false;
			} else if (a[i][0].find(x + 'A') == string::npos && a[i][1].find(x + 'A') == string::npos && a[i][2] != "even")
				return false;
		}
	}
	return true;
}
int main() {
	int N;
	cin >> N;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
		for (int i = 0; i < 12; i++) {
			if (check(i, 1)) {
				printf("%c is the counterfeit coin and it is heavy.\n", 'A' + i);
				break;
			} else if (check(i, 0)) {
				printf("%c is the counterfeit coin and it is light.\n", 'A' + i);
				break;
			}
		}
	}
}