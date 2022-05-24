#include <iostream>
using namespace std;

//记忆化搜索
long long ans[251][251][251] = { {{0}} };//答案很大，用long long
int f(int n, int minfac, int maxfac) {//分n，最小的元素minfac，中间的数maxfac
	if (ans[n][minfac][maxfac])
		return ans[n][minfac][maxfac];
	else if (minfac == n)
		return 1;
	for (int i = minfac; i <= maxfac && i * 2 <= n; i++)
		ans[n][minfac][maxfac] += f(n - i, i, maxfac);
	if (n <= maxfac)//如果n比maxfac小直接放n也是一种情况
		ans[n][minfac][maxfac]++;
	return ans[n][minfac][maxfac];
}
int main() {
	int n;
	while (cin >> n && n != 0) {
		long long cnt = 1;//必须long long
		for (int i = 1; i * 2 <= n; i++) {//枚举除了中间的数前头的所有数
			if (2 * i == n)//没有中间的数就代表最大值多少都行
				cnt += f(i, 1, n);
			else
				cnt += f(i, 1, n - 2 * i);
		}
		cout << n << ' ' << cnt << endl;
	}
}