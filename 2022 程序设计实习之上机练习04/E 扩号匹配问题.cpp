#include <iostream>
#include <string>
#include <stack>
#include <map>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	while (cin >> a) {
		cout << a << endl;
		int len = a.length();
		stack<int> l;
		map<int, char> ans;
		for (int i = 0; i < len; i++) { //每一个字符都要在ans中有对应的键值
			if (a[i] == '(')
				l.push(i);
			else if (a[i] == ')') {
				if (l.empty())
					ans.insert({ i,'?' });
				else
					ans.insert({ l.top(),' ' }), ans.insert({ i,' ' }), l.pop();//一对括号左右位置都要向ans中加入空格
			} else
				ans.insert({ i,' ' });
		}
		while (!l.empty())
			ans.insert({ l.top(),'$' }), l.pop();
		for (auto i : ans)
			cout << i.second;
		cout << endl;
	}
}