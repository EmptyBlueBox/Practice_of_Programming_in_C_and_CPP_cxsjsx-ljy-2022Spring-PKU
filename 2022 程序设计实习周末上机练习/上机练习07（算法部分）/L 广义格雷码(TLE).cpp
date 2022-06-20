//TLE
/*
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k, len, order[500001];
bool vis[500001] = { false }, e = false;
string num[500001];//存储所有数，每个数是下标转换为k进制的数，之后只要找输出顺序即可
bool ctu(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (num[x][i] != num[y][i])
			cnt++;
		if (cnt > 1)
			return false;
	}
	return cnt == 1;
}
void f(int depth) {
	if (e) return;
	if (depth == len) {
		if (ctu(order[0], order[len - 1]))
			for (int i = 0; i < len; i++)
				cout << num[order[i]] << endl, e = true;
	}
	for (int i = 0; i < len; i++)//枚举所有数
		if ((!vis[i]) && ctu(order[depth - 1], i))
			order[depth] = i, vis[i] = true, f(depth + 1), vis[i] = false;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	len = pow(n, k);
	for (int i = 0; i < len; i++) {
		int tmp = i;
		while (tmp)
			num[i] += '0' + tmp % k, tmp /= k;
		while (num[i].length() != n)
			num[i] += '0';
		reverse(num[i].begin(), num[i].end());
	}
	order[0] = 0, vis[0] = true;
	f(1);
}
*/

#include<iostream>
#include<queue>
#include<cstring>//memset(flag,0,sizeof(bool)*12*50010);
using namespace std;
string  a[12][50010];
bool flag[12][50010];
queue<string> q;
int n, m;



int main() {
	cin >> n >> m;
	string temp = "";
	//n为1的时候
	if (n == 1) {
		for (int i = 0; i < m; i++) {
			cout << i << endl;
		}
		return 0;
	}

	//n大于2的时候 
	for (int i = 0; i < m; i++) {
		//			cout<<(temp+char(i+48))<<endl;
		q.push(temp + char(i + 48));//i=0,把字符0入队 
	}
	for (int time = 2; time <= n; time++) {
		memset(flag, 0, sizeof(bool) * 12 * 50010);
		int size = q.size(), l = 0;//l这里赋值0  因为要从1开始 
		while (!q.empty()) {
			a[0][++l] = q.front();
			//			cout<<a[0][l]<<" ";
			q.pop();
		}
		//复制一份 其他行数的
		for (int i = 1; i < m; i++) {
			for (int j = 1; j <= size; j++) {
				a[i][j] = a[0][j];
			}
		}
		//添加前面一个值: 0—(m-1) 
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= size; j++) {
				a[i][j] = char(i + 48) + a[i][j];
				//				cout<<a[i][j]<<" ";
				flag[i][j] = true;
			}
			//			cout<<endl;
		}
		//蛇形取值
		int t = size * m;//t表示当前总个数 
		//保存第一行到q队列中 
		for (int i = 1; i <= size; i++) {
			q.push(a[0][i]);
			flag[0][i] = false;
			t--;
		}
		//		cout<<q.size()<<endl;
		int x = 0, y = size;
		while (t > 0) {
			while (flag[x + 1][y] && t > 0) { flag[++x][y] = false; q.push(a[x][y]); t--; }//向下 
			if (flag[x][y - 1] && t > 0) { flag[x][--y] = false; q.push(a[x][y]); t--; }//向左一位 
			while (flag[x - 1][y] && t > 0) { flag[--x][y] = false; q.push(a[x][y]); t--; }//向上
			if (flag[x][y - 1] && t > 0) { flag[x][--y] = false; q.push(a[x][y]); t--; }//再向左一位 
		}
	}
	//输出 
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
