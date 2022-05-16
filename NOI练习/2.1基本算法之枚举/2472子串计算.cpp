#include <iostream>
#include <map>
#include <string>
using namespace std;
//使用map
int main() {
	map<string, int> a;
	string n;
	cin >> n;
	for (int i = 1; i <= n.length(); i++)
		for (int j = 0; j < n.length() - i + 1; j++)
			a[n.substr(j, i)]++;
	for (auto i : a)//这样遍历关联容器更方便！
		if (i.second > 1)
			cout << i.first << ' ' << i.second << endl;
}