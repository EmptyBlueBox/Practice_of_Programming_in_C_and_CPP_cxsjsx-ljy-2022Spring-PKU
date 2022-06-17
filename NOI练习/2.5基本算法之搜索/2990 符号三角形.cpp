//普通搜索一定TLE，n=22、23、24非常慢，需要打表
//多个位运算嵌套一定在每一层都加括号！！！
/*
#include <iostream>
using namespace std;

int n;
bool f(int x) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (x >> i) & 1;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			x = (((x ^ (x >> 1)) & (1 << j)) ? x & (~(1 << j)) : x | (1 << j)), cnt += (x >> j) & 1;
	return cnt * 2 == n * (n + 1) / 2;
}
int main() {
	while (cin >> n && n) {
		int cnt = 0;
		for (int i = 0; i < (1 << n); i++)
			if (f(i))
				cnt++;
		cout << n << ' ' << cnt << endl;
	}
}
*/
//打表
#include <iostream>
using namespace std;

int main() {
	int n, table[25] = { 0, 0, 0, 4, 6, 0, 0, 12, 40, 0, 0, 171, 410, 0, 0, 1896, 5160, 0, 0, 32757, 59984, 0, 0, 431095, 822229 };
	while (cin >> n && n)
		cout << n << ' ' << table[n] << endl;
}