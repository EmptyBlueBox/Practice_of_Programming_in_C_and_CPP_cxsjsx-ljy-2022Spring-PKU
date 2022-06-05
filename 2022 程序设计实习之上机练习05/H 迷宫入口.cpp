#include <iostream>
#include <cstring>
using namespace std;

//看第一个空格的地方是否能放下某种小片，如果放不下必return false，不要枚举每一个空格，否则TLE！！！
int s, info[11];//每个边长的小片有几个
bool map[50][50] = { {false} };//题目没给锁的大小，大概最大50
bool can_put(int x, int y, int d) { //左上角(x,y)处可以放下d大小的小片
	if (x + d - 1 > s || y + d - 1 > s) return false;//越界也不能放下！！！
	for (int i = x; i <= x + d - 1; i++)
		for (int j = y; j <= y + d - 1; j++)
			if (map[i][j])
				return false;
	return true;
}
void put(int x, int y, int d, bool pred) { //左上角(x,y)处放下(true)或拿起(false)d大小的小片
	for (int i = x; i <= x + d - 1; i++)
		for (int j = y; j <= y + d - 1; j++)
			map[i][j] = pred;
}
bool f() {
	int x = 1, y = 1;
	for (x = 1; x <= s; x++)
		for (y = 1; y <= s; y++)//找到第一个空格
			if (!map[x][y])//空格
				goto A_Space;
A_Space:
	;
	if (x == s + 1 && y == s + 1)
		return true;//全被填满
	for (int i = 1; i <= 10; i++)//枚举放哪个小片
		if (info[i] && can_put(x, y, i)) {
			put(x, y, i, true);
			info[i]--;
			if (f())
				return true;
			info[i]++;
			put(x, y, i, false);
		}
	return false;
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(info, 0, sizeof(info));
		memset(map, 0, sizeof(map));
		int n;
		cin >> s >> n;
		for (int i = 1; i <= n; i++)
			cin >> info[0], info[info[0]]++;
		cout << (f() ? "YES\n" : "NO\n");
	}
}
