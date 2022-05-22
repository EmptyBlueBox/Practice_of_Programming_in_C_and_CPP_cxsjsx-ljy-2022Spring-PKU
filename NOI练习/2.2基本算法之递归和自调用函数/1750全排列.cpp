#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void next_permutation(string a, int s) {
	if (s == a.length() - 1) {
		cout << a << endl;
		return;
	}
	//把s和它以后的每一个都拿到s的位置上再对s+1做同样操作
	//s+1到i需要再排序，因为这一段不是按照字典序来的
	for (int i = s; i < a.length(); i++) {
		swap(a[s], a[i]);
		sort(a.begin() + s + 1, a.begin() + i + 1);
		next_permutation(a, s + 1);
		swap(a[s], a[i]);
	}
	return;
}

int main() {
	/*
	string a;
	cin >> a;
	vector<char> v;
	for (auto i : a)
		v.push_back(i);
	do {
		for (auto i : v)
			cout << i;
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
	*/
	string a;
	cin >> a;
	sort(a.begin(), a.end());
	next_permutation(a, 0);
}
