#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int t, len, ans[6];//i->字符串第ans[i]位
bool vis[13] = { false };//字符串第vis[i]位已用
bool found = false;
string s;
//用递归替代五重循环
void find(int depth) {
	if (depth == 6) {
		int lhs = 0;
		for(int i=1; i<=5; i++)
			lhs += pow(-(s[ans[i]] - 'A' + 1), i);
		lhs *= -1;
		if (lhs == t) {
			found = true;
			for (int i = 1; i <= 5; i++)
				cout << s[ans[i]];
			cout << endl;
		}
		return;
	}
	for (ans[depth] = 0; ans[depth] < len; ans[depth]++) {
		if (vis[ans[depth]])
			continue;
		vis[ans[depth]] = true;
		find(depth + 1);
		if (found)
			return;
		vis[ans[depth]] = false;
	}
}
int main() {
	while (cin >> t >> s && t != 0) {
		//所有全局变量要reset
		memset(vis, 0, sizeof(vis));//#include <cstring>
		found = false;
		sort(s.begin(), s.end(), greater<char>());//这里是函数对象greater<char>()，list用greater<int>，没有括号
		len = s.length();
		find(1);
		if (!found)
			cout << "no solution" << endl;
	}
}