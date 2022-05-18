#include <iostream>
#include <vector>
using namespace std;
//一串数，去掉其中几个，使得剩余数之间的最短距离最长
int d, n, m, tmp;
vector<int> stone;
bool isleft(int mid) {
	int cnt = 0, j = 0;
	//不要双循环
	//j<i
	for (int i = 1; i <= n + 1; i++)//i要走到终点石头，如果距离小于mid则理解为拿走j
	{
		if (stone[i] - stone[j] < mid)//可以理解为拿走i也可以理解为拿走j
			cnt++;
		else
			j = i;
	}
	return cnt <= m;
}
int main() {
	cin >> d >> n >> m;//总共n个石头，最多拿走m个
	stone.resize(n + 2);//可以这样使用vector可变长的特性
	stone[0] = 0, stone[n + 1] = d;
	for (int i = 1; i <= n; i++)
		cin >> stone[i];
	//1.l与r初始化为不可能取到的值，防止所有的都是蓝色
	//2.程序保证ans不会越界，ans最大比r初始化小1，ans最小比l初始化大1
	//3.更新指针不要写ans+-1
	//4.这个程序保证不会死循环
	int l = 0, r = d + 1, ans;//ans是最短跳跃距离,现要让其最大
	while (l + 1 != r) {
		ans = (l + r) / 2;
		if (isleft(ans))
			l = ans;//更新指针不要写ans+-1
		else
			r = ans;
	}
	cout << l;
}
